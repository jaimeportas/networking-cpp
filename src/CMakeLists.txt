cmake_minimum_required(VERSION 3.5)

project(net-main-project)

add_compile_options(-Wall)

add_executable(net-main main.cpp)
target_compile_features(net-main PRIVATE cxx_lambda_init_captures)