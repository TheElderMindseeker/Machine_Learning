//
// Created by Даниил on 25.10.2017.
//

#ifndef TOMMITCHELL_TREE_BUILDER_HPP
#define TOMMITCHELL_TREE_BUILDER_HPP


#include <set>
#include "tree_node.hpp"


tree_node *ID3 (const std::vector <sample_point *> &training_data, std::set <int> &attributes);

int best_attribute (const std::vector <sample_point *> &training_data, std::set <int> attributes);

float information_gain (const std::vector <sample_point *> &training_data, int attribute_id);

float entropy (const std::vector <sample_point *> &training_data);

float mean_entropy_reduction (const std::vector <sample_point *> &training_data, int attribute_id);

std::set <int> get_values (const std::vector <sample_point *> &training_data, int attribute_id);

std::vector <sample_point *> extract_value_subset (const std::vector <sample_point *> &training_data,
                                                 int attribute_id, int value);

std::pair <int, int> count_points_by_target (const std::vector <sample_point *> &training_data);


#endif //TOMMITCHELL_TREE_BUILDER_HPP
