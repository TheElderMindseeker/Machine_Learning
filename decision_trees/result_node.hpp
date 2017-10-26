//
// Created by Даниил on 25.10.2017.
//

#ifndef TOMMITCHELL_RESULT_NODE_HPP
#define TOMMITCHELL_RESULT_NODE_HPP


#include "tree_node.hpp"


class result_node : public tree_node {
public:
    result_node (bool result);

    bool decide (const sample_point &point) override;

    void visualize () override;

private:
    bool result;
};


#endif //TOMMITCHELL_RESULT_NODE_HPP
