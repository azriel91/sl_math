set(test_main_TARGET ${PROJECT_NAME}_test_main)
add_executable(${test_main_TARGET} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${test_main_TARGET} ${CONAN_LIBS})

sl_include_tests(${test_main_TARGET})
