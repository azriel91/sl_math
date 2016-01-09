project(sl_math)
cmake_minimum_required(VERSION 3.4)

include(conanbuildinfo.cmake)
conan_basic_setup()

include(slBundleFunctions)

# This must be called from the project root's CMakeLists.txt, otherwise the 'test' target doesn't get created
enable_testing()
sl_include_test_dir()
