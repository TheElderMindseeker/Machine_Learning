//
// Created by Даниил on 25.10.2017.
//

#ifndef TOMMITCHELL_TREE_NODE_HPP
#define TOMMITCHELL_TREE_NODE_HPP


#include "sample_point.hpp"


class tree_node {
public:
    virtual ~tree_node () = default;

    virtual bool decide (const sample_point &point) = 0;

    virtual void visualize () = 0;

protected:
    tree_node () = default;
};


#endif //TOMMITCHELL_TREE_NODE_HPP
