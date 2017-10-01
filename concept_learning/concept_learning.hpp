//
// Created by Даниил on 01.10.2017.
//

#ifndef TOMMITCHELL_CONCEPT_LEARNING_HPP
#define TOMMITCHELL_CONCEPT_LEARNING_HPP


#include <tuple>


const int LOGO_FORM = 0;
const int LOGO_MAIN_COLOR = 1;
const int LOGO_COMPLEXITY = 2;

// LOGO_FORM
const int SQUARE = 0x01;
const int ROUND  = 0x02;

// LOGO_MAIN_COLOR
const int RED   = 0x01;
const int BLUE  = 0x02;
const int GREEN = 0x04;

// LOGO_COMPLEXITY
const int COMPLEX = 0x01;
const int SIMPLE  = 0x02;


typedef std::tuple<int, int, int> hypothesis_t;


bool conforms (hypothesis_t instance, hypothesis_t hypothesis);
hypothesis_t merge (hypothesis_t hyp_1, hypothesis_t hyp_2);
bool target (hypothesis_t instance);


#endif //TOMMITCHELL_CONCEPT_LEARNING_HPP
