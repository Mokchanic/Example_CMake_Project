// Copyright (c) 2023 Mokchanic, All Rights Reserved.

/**
 * @file main.cpp
 * @author JinWoo Mok
 * @brief Example_CMake_Project
 * @version 1.0
 * @date 2023-12-27
 */

#include <iostream>
#include <cstdint>
#include "module_example.hpp"

int32_t main(){
    std::cout << "Hello CMake Project!" << std::endl;
    std::cout << "check_update" << std::endl;
    mokchanic::example::Print("check module target_link_libraries");
    return 0;
}
