add_executable(main
    add/add.c
    mul/mul.c
    op/op.c
)

target_include_directories(main PRIVATE
    .
)

set_target_properties(main PROPERTIES
    C_STANDARD 99
    C_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(main PRIVATE
    common_options
)

target_compile_definitions(main PRIVATE
    "_SOURCE"
    "_GNU_SOURCE"
)
