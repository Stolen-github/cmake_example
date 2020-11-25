cmake_minimum_required(VERSION 3.8)
project(fake_project VERSION 0.0.42 LANGUAGES C)

add_library(common_options INTERFACE)
target_compile_options(common_options INTERFACE
    "-Wall"
    "-Wextra"
    "-pedantic"
    $<IF:$<CONFIG:Debug>, -fsanitize=address, -Werror>
)
target_link_libraries(common_options INTERFACE
    $<$<CONFIG:Debug>: -fsanitize=address>
)

add_subdirectory(src)

find_library(CRITERION_LIB criterion)
add_executable(unit_test
    test/unit/test.c
    src/mul/mul.c
    src/add/add.c
)
target_include_directories(unit_test PRIVATE
    src
)
target_link_libraries(unit_test PRIVATE
    ${CRITERION_LIB}
    common_options
)

enable_testing()

add_test(NAME unit COMMAND unit_test --verbose)
add_test(NAME functional COMMAND pytest ${CMAKE_SOURCE_DIR})

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
