//
// Created by Даниил on 25.10.2017.
//

#include <iostream>
#include "result_node.hpp"


result_node::result_node (bool result) : result (result) {}


bool result_node::decide (const sample_point &point) {
    return result;
}


void result_node::visualize () {
    std::cout << "result_node with result = " << result << std::endl;
}
