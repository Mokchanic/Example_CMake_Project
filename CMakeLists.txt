cmake_minimum_required(VERSION 3.22)

set(PACKAGE_NAME EXAMPLE_CMAKE_PROJECT)
set(PACKAGE_VERSION 1.4.5)

project(${PACKAGE_NAME} VERSION ${PACKAGE_VERSION} LANGUAGES CXX
        DESCRIPTION "CMake Eaxmple"
        HOMEPAGE_URL "https://github.com/Mokchanic"
)

# ## example if
# set(LOCAL_BOOL_VAL TRUE)
# if(LOCAL_BOOL_VAL)
#   message(STATUS "[Status] Check bool variable")
# endif()

# ## example for
# set(LIST "0" "1" "2" "3" "4")
# foreach(VAR IN LISTS LIST)
#   message(STATUS "VAR: ${VAR}")
# endforeach()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message(STATUS "[Status] PROJECT_NAME: ${CPACK_PROJECT_NAME}")
message(STATUS "[Status] PROJECT_VERSION: ${CPACK_PROJECT_VERSION}") # 1.4.5
message(STATUS "[Status] PROJECT_VERSION_MAJOR: ${PROJECT_VERSION_MAJOR}") # 1
message(STATUS "[Status] PROJECT_VERSION_MINOR: ${PROJECT_VERSION_MINOR}") # 4
message(STATUS "[Status] PROJECT_VERSION_PATCH: ${PROJECT_VERSION_PATCH}") # 5
message(STATUS "[Status] PROJECT_DESCRIPTION: ${PROJECT_DESCRIPTION}")
message(STATUS "[Status] PROJECT_HOMEPAGE_URL: ${PROJECT_HOMEPAGE_URL}")
message(STATUS "[Status] PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "[Status] PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

set(${PACKAGE_NAME}_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(${PACKAGE_NAME}_MODULE_PATH "${${PACKAGE_NAME}_PATH}/module")

message(STATUS "[Status] ${${PACKAGE_NAME}_MODULE_PATH}")

# Get the CMakeLists.txt of the subdirectory
add_subdirectory(example)
add_subdirectory(${${PACKAGE_NAME}_MODULE_PATH})

# Output Global variables.
message(STATUS "[Status] ${GLOBAL_STRINT_VARIABLE}, ${GLOBAL_BOOL_VARIABLE}")

add_executable(${PROJECT_NAME}_MAIN main.cpp)
target_link_libraries(${PROJECT_NAME}_MAIN
  CMAKE_EXAMPLE_MODULE
)

target_compile_options(${PACKAGE_NAME}_MAIN PRIVATE
	-Wall -Wextra -Wpedantic -Werror
)
