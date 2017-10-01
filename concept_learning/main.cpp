//
// Created by Даниил on 01.10.2017.
//


#include <list>
#include <iostream>
#include <iomanip>
#include "concept_learning.hpp"


int main (int argc, char **argv) {
    std::list<std::pair<hypothesis_t, bool>> training_examples;

    training_examples.push_back (std::pair<hypothesis_t, bool> (hypothesis_t (ROUND, RED, COMPLEX), true));
    training_examples.push_back (std::pair<hypothesis_t, bool> (hypothesis_t (ROUND, BLUE, SIMPLE), true));
    training_examples.push_back (std::pair<hypothesis_t, bool> (hypothesis_t (SQUARE, GREEN, COMPLEX), false));
    training_examples.push_back (std::pair<hypothesis_t, bool> (hypothesis_t (ROUND, RED, SIMPLE), true));
    training_examples.push_back (std::pair<hypothesis_t, bool> (hypothesis_t (SQUARE, RED, SIMPLE), false));

    hypothesis_t training_hypothesis (0, 0, 0);

    for (auto iter = training_examples.begin (); iter != training_examples.end (); iter++) {
        if (iter->second) {
            training_hypothesis = merge (training_hypothesis, iter->first);

            // Debug
            std::cout << "Training hypo [0] = " << std::get<0> (training_hypothesis) << '\n';
            std::cout << "Training hypo [1] = " << std::get<1> (training_hypothesis) << '\n';
            std::cout << "Training hypo [2] = " << std::get<2> (training_hypothesis) << '\n';
            std::cout << std::endl;
        }
    }

    std::cout << "<round, blue, complex> must conform to training hypothesis: "
              << std::setiosflags (std::ios_base::boolalpha)
              << conforms (hypothesis_t (ROUND, BLUE, COMPLEX), training_hypothesis) << std::endl;
    std::cout << "<round, green, complex> must not conform to training hypothesis: "
              << std::setiosflags (std::ios_base::boolalpha)
              << conforms (hypothesis_t (ROUND, GREEN, COMPLEX), training_hypothesis) << std::endl;
}
