//
// Created by Даниил on 25.10.2017.
//


#include <set>
#include <fstream>
#include <iostream>

#include "sample_point.hpp"
#include "tree_node.hpp"
#include "tree_builder.hpp"
#include "decision_node.hpp"


int main (int argc, char **argv) {
    std::ifstream input ("input.txt");

    int num_attrs, num_points;
    input >> num_attrs >> num_points;

    std::set<int> attributes;
    for (int i = 0; i < num_attrs; i++)
        attributes.insert (i);

    std::vector<sample_point *> training_data ((unsigned) num_points);
    for (auto &point : training_data) {
        point = new sample_point;
    }

    for (int i = 0; i < num_points; i++) {
        int attr;
        for (int j = 0; j < num_attrs; j++) {
            input >> attr;
            training_data [i]->attributes.push_back (attr);
        }
        input >> attr;
        training_data [i]->target_attribute = (bool) attr;
    }

    tree_node *tree = ID3 (training_data, attributes);

    sample_point sp;
    sp.attributes.push_back (1);
    sp.attributes.push_back (1);
    sp.attributes.push_back (0);
    sp.target_attribute = 0;
    bool answer = tree->decide (sp);
    std::cout << "[main answer] tree (test_point) = " << answer << "\n\n";
    tree->visualize ();

    return 0;
}