//
// Created by Даниил on 25.10.2017.
//

#ifndef TOMMITCHELL_DECISION_NODE_HPP
#define TOMMITCHELL_DECISION_NODE_HPP


#include <map>
#include "tree_node.hpp"
#include "tree_builder.hpp"


class decision_node : public tree_node {
    friend tree_node *ID3 (const std::vector <sample_point *> &training_data, std::set <int> &attributes);

public:
    decision_node (int attribute_id);

    ~decision_node () override;

    /**
     * @brief Deduce the target attribute of the given sample point
     *
     * @param point Sample point
     *
     * @return The target attribute of the given sample point
     */
    bool decide (const sample_point &point) override;

    void visualize () override;

private:
    /**
     * @brief List of all subtrees indexed by the corresponding attribute values
     */
    std::map<int, tree_node *> subtrees;

    /**
     * @brief Decision attribute index
     */
    int attribute_id;
};


#endif //TOMMITCHELL_DECISION_NODE_HPP
