target_include_directories(${BII_test_main_TARGET} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Run the test
enable_testing()

add_test(NAME ${BII_test_main_TARGET}
         COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BII_test_main_TARGET})
