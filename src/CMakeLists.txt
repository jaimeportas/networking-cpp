cmake_minimum_required(VERSION 3.5)

project(net-main-project)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall)
endif()


add_executable(net-main main.cpp)
target_compile_features(net-main PRIVATE cxx_lambda_init_captures cxx_std_14)