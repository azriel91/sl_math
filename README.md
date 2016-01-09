[![Build Status](https://travis-ci.org/azriel91/sl_math.svg?branch=master)](https://travis-ci.org/azriel91/sl_math) [![Build status](https://ci.appveyor.com/api/projects/status/dbpu2vkdf9iv4lrn/branch/master?svg=true)](https://ci.appveyor.com/project/azriel91/sl-math/branch/master)

## sl\_math

Contains template classes for N-dimension Point objects.

## Development

This is built using [conan](https://www.conan.io/).

### Requirements

* [conan](https://www.conan.io/downloads)
* [CMake 3.4](https://cmake.org/download/)
* [g++ 5.2](https://gcc.gnu.org/) or
* [clang 3.6](http://clang.llvm.org/) - _note: does not work with 3.7_

### Building

After cloning, in the repository directory run the following to build the block:

```bash
conan install --build=missing
conan build
```

## License

Copyright (c) Azriel Hoh. Licensed under the [Apache License v2.0](http://www.apache.org/licenses/LICENSE-2.0).
