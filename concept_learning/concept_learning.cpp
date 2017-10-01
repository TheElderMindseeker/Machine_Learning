//
// Created by Даниил on 01.10.2017.
//

#include "concept_learning.hpp"


hypothesis_t target_hypothesis (ROUND, RED | BLUE, COMPLEX | SIMPLE);


bool conforms (hypothesis_t instance, hypothesis_t hypothesis) {
    return ((std::get<LOGO_FORM> (instance) & std::get<LOGO_FORM> (hypothesis)) != 0)
            && ((std::get<LOGO_MAIN_COLOR> (instance) & std::get<LOGO_MAIN_COLOR> (hypothesis)) != 0)
            && ((std::get<LOGO_COMPLEXITY> (instance) & std::get<LOGO_COMPLEXITY> (hypothesis)) != 0);
}


hypothesis_t merge (hypothesis_t hyp_1, hypothesis_t hyp_2) {
    return hypothesis_t (std::get<LOGO_FORM> (hyp_1) | std::get<LOGO_FORM> (hyp_2),
                         std::get<LOGO_MAIN_COLOR> (hyp_1) | std::get<LOGO_MAIN_COLOR> (hyp_2),
                         std::get<LOGO_COMPLEXITY> (hyp_1) | std::get<LOGO_COMPLEXITY> (hyp_2));
}


bool target (hypothesis_t instance) {
    return conforms (instance, target_hypothesis);
}
