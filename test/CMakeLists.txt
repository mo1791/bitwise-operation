cmake_minimum_required(VERSION 3.5)

project(
    Test_Bits_Lib
    VERSION 1.0.0
    DESCRIPTION "test bits lib"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(m_out main.c)

set(CMAKE_PREFIX_PATH "../build")

find_package(BitsLib REQUIRED)

target_link_libraries(m_out bits_l)
