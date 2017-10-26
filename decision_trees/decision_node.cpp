//
// Created by Даниил on 25.10.2017.
//

#include <iostream>
#include "decision_node.hpp"


decision_node::decision_node (int attribute_id) : attribute_id (attribute_id) {}


decision_node::~decision_node () {
    for (auto iter = subtrees.begin (); iter != subtrees.end (); iter++)
        delete iter->second;
}


bool decision_node::decide (const sample_point &point) {
    if (subtrees.count (point.attributes.at ((unsigned) attribute_id)) > 0)
        return subtrees.at (point.attributes.at ((unsigned) attribute_id))->decide (point);
    return false;
}


void decision_node::visualize () {
    std::cout << "decision_node with attribute_id = " << attribute_id << std::endl;
    for (auto &subtree : subtrees) {
        std::cout << "{ on attr = " << subtree.first << std::endl;
        subtree.second->visualize ();
        std::cout << "} // end of attr = " << subtree.first << std::endl;
    }
}
