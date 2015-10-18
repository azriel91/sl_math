[![Build Status](https://travis-ci.org/azriel91/sl_math.svg?branch=master)](https://travis-ci.org/azriel91/sl_math) [![Build status](https://ci.appveyor.com/api/projects/status/dbpu2vkdf9iv4lrn/branch/master?svg=true)](https://ci.appveyor.com/project/azriel91/sl-math/branch/master) [![Build Status](https://webapi.biicode.com/v1/badges/azriel/azriel/sl_math/master)](https://www.biicode.com/azriel/sl_math)

## sl\_math

Contains template classes for N-dimension Point objects.

## Development

This is built using [biicode](https://www.biicode.com/).

### Requirements

* [biicode](https://www.biicode.com/downloads)
* [CMake](http://www.cmake.org/install/)
* [g++ 4.8](https://gcc.gnu.org/)

### Building

#### Linux

After cloning, in the repository directory run the following to build the block:

```bash
git submodule update --init        # initialize git submodules
bii-support/linux/build/shared.sh  # builds shared libraries
```

The test executable will be output as `bin/azriel_sl_math_test_main`.

#### Windows

After cloning, in the repository directory run the following to build the block:

```bat
git submodule update --init           :: initialize git submodules
bii-support\windows\build\shared.bat  :: builds shared libraries
```

The test executable will be output as `bin\azriel_sl_math_test_main.exe`.

## License

Copyright (c) Azriel Hoh. Licensed under the [Apache License v2.0](http://www.apache.org/licenses/LICENSE-2.0).
