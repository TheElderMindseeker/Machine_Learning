//
// Created by Даниил on 25.10.2017.
//

#include <cmath>
#include <map>
#include <iostream>
#include "tree_builder.hpp"
#include "result_node.hpp"
#include "decision_node.hpp"


tree_node *ID3 (const std::vector <sample_point *> &training_data, std::set <int> &attributes) {
//    std::cout << "[ID3] Started ID3 with data size " << training_data.size ()
//              << " and attributes number " << attributes.size () << std::endl;

    // Check for the same target attribute among training_data
    bool first_ta = training_data.at (0)->target_attribute;
    bool same = true;
    for (auto iter = training_data.begin () + 1; iter != training_data.end (); iter++) {
        if ((*iter)->target_attribute != first_ta) {
            same = false;
            break;
        }
    }
    if (same) {
//        std::cout << "[ID3] Creating result node with " << first_ta << std::endl;
        return new result_node (first_ta);
    }
    // End Check

    // Check for the presence of attributes
    if (attributes.empty ()) {
        int positive = 0, negative = 0;
        for (auto iter = training_data.begin (); iter != training_data.end (); iter++) {
            if ((*iter)->target_attribute)
                ++positive;
            else
                ++negative;
        }
//        std::cout << "[ID3] Generated result_node with " << (positive > negative) << std::endl;
        return new result_node (positive > negative);
    }
    // End Check

    int A = best_attribute (training_data, attributes);
//    std::cout << "[ID3] Best attribute is " << A << std::endl;

    decision_node *root = new decision_node (A);
//    std::cout << "[ID3] Created new empty decision node" << root << std::endl;

    std::set<int> values;
    for (const auto &point : training_data) {
        values.insert (point->attributes [A]);
    }

    for (const auto &value : values) {
//        std::cout << "[ID3] Current value is " << value << std::endl;
        std::vector <sample_point *> sample_valued;
        for (const auto &point : training_data) {
            if (point->attributes [A] == value) {
                sample_valued.push_back (point);
            }
        }

        if (sample_valued.empty ()) {
            int positive = 0, negative = 0;
            for (auto iter = training_data.begin (); iter != training_data.end (); iter++) {
                if ((*iter)->target_attribute)
                    ++positive;
                else
                    ++negative;
            }
            root->subtrees.emplace (value, new result_node (positive > negative));
//            std::cout << "[ID3] Generated result_node with " << (positive > negative) << " for decision node " << root << std::endl;
        }
        else {
            attributes.erase (A);
            root->subtrees.emplace (value, ID3 (sample_valued, attributes));
//            std::cout << "[ID3] Generated tree_node for decision node " << root << std::endl;
            attributes.insert (A);
        }
    }

    return root;
}


int best_attribute (const std::vector <sample_point *> &training_data, std::set <int> attributes) {
    int best = *attributes.begin ();
    float best_info_gain = information_gain (training_data, best);

    for (const auto &candidate : attributes) {
        float cand_info_gain = information_gain (training_data, candidate);

//        std::cout << "[best attribute] Current candidate: " << candidate << std::endl;
//        std::cout << "[best attribute] Current information gain: " << cand_info_gain << std::endl;

        if (cand_info_gain > best_info_gain) {
            best = candidate;
            best_info_gain = cand_info_gain;
        }
    }
    return best;
}


float information_gain (const std::vector <sample_point *> &training_data, int attribute_id) {
    return entropy (training_data) - mean_entropy_reduction (training_data, attribute_id);
}


float entropy (const std::vector <sample_point *> &training_data) {
    auto count = count_points_by_target (training_data);
    int positive = count.first, negative = count.second;

    if (positive == 0 || negative == 0)
        return 0.0f;

    float total = positive + negative;
    float p_pos = (float) positive / total;
    float p_neg = (float) negative / total;

    return - p_pos * std::log2f (p_pos) - p_neg * std::log2f (p_neg);
}


float mean_entropy_reduction (const std::vector <sample_point *> &training_data, int attribute_id) {
    float sum = 0.0f;
    auto values = get_values (training_data, attribute_id);

    for (const auto &value : values) {
        std::vector <sample_point *> S_v = extract_value_subset (training_data, attribute_id, value);
        sum += (float) S_v.size () / (float) training_data.size () * entropy (S_v);
        S_v.clear ();
    }

    // std::cout << "[Entropy reduction] Mean entropy reduction: " << sum << std::endl;
    return sum;
}


std::set <int> get_values (const std::vector <sample_point *> &training_data, int attribute_id) {
    std::set<int> result;
    for (const auto &point : training_data) {
        result.insert (point->attributes [attribute_id]);
    }
    return result;
}


std::vector <sample_point *> extract_value_subset (const std::vector <sample_point *> &training_data,
                                                 int attribute_id, int value) {
    std::vector <sample_point *> result;
    for (const auto &point : training_data) {
        if (point->attributes [attribute_id] == value) {
            result.push_back (new sample_point (*point));
        }
    }
//    std::cout << "[S_v extraction] result size: " << result.size () << std::endl;
//    std::cout << "[S_v extraction] result entropy: " << entropy (result) << std::endl;

    return result;
}


std::pair <int, int> count_points_by_target (const std::vector <sample_point *> &training_data) {
    int positive = 0, negative = 0;
    for (const auto &point : training_data) {
        if (point->target_attribute)
            ++positive;
        else
            ++negative;
    }

//    std::cout << "[counting points] Positive: " << positive << std::endl;
//    std::cout << "[counting points] Negative: " << negative << std::endl;

    return std::make_pair (positive, negative);
}