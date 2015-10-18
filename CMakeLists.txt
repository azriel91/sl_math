project(${BII_BLOCK_NAME})

include(azriel/sl_cmake/slBlockFunctions)
include(biicode/cmake/tools)

# Bii variables
set(BII_LIB_SRC )
set(BII_test_main_SRC test/main.cpp)

# Actually create targets: executables and libraries.
ADD_BII_TARGETS()

ACTIVATE_CPP11(${BII_test_main_TARGET})

SL_INCLUDE_TESTS(${BII_test_main_TARGET})
