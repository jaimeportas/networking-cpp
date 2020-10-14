cmake_minimum_required(VERSION 3.5)

project(net-main-project)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall)
endif()


add_library(asio INTERFACE)
if(WIN32)
    target_compile_definitions(asio INTERFACE _WIN32_WINNT=0x0A00)
endif()
target_compile_definitions(asio INTERFACE ASIO_STANDALONE)
target_include_directories(asio INTERFACE D:/sdk/asio-1.18.0/include)


add_executable(SimpleExample main.cpp)
target_compile_features(SimpleExample PRIVATE cxx_lambda_init_captures cxx_std_14)
target_link_libraries(SimpleExample PRIVATE asio)