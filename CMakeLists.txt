cmake_minimum_required (VERSION 3.8)
project (TomMitchell)

set (CMAKE_CXX_STANDARD 14)

set (CONCEPT_LEARNING_FILES
        concept_learning/concept_learning.cpp
        concept_learning/concept_learning.hpp
        concept_learning/main.cpp)
add_executable (ConceptLearning ${CONCEPT_LEARNING_FILES})