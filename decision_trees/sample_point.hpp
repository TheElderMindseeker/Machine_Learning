//
// Created by Даниил on 25.10.2017.
//

#ifndef TOMMITCHELL_SAMPLE_POINT_HPP
#define TOMMITCHELL_SAMPLE_POINT_HPP


#include <vector>


struct sample_point {
    sample_point () = default;

    sample_point (const sample_point &other) : attributes (other.attributes), target_attribute (target_attribute) {}

    const sample_point &operator = (const sample_point &other) {
        this->attributes = other.attributes;
        this->target_attribute = other.target_attribute;
    }

    /**
     * @brief List of attributes with their values
     */
    std::vector<int> attributes;

    /**
     * @brief Target attribute
     */
    bool target_attribute;
};


#endif //TOMMITCHELL_SAMPLE_POINT_HPP
