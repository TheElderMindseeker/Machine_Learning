cmake_minimum_required (VERSION 3.8)
project (TomMitchell)

set (CMAKE_CXX_STANDARD 14)

set (CONCEPT_LEARNING_FILES
        concept_learning/concept_learning.cpp
        concept_learning/concept_learning.hpp
        concept_learning/main.cpp
        )
add_executable (ConceptLearning ${CONCEPT_LEARNING_FILES})

set (DECISION_TREES_FILES
        decision_trees/sample_point.hpp
        decision_trees/tree_node.hpp
        decision_trees/decision_node.cpp
        decision_trees/decision_node.hpp
        decision_trees/result_node.cpp
        decision_trees/result_node.hpp
        decision_trees/tree_builder.cpp
        decision_trees/tree_builder.hpp
        decision_trees/main.cpp)
add_executable (DecisionTrees ${DECISION_TREES_FILES})