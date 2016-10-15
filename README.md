# PdStarterKit

[![Travis](https://img.shields.io/travis/paccpp/PdStarterKit.svg?label=travis)](https://travis-ci.org/paccpp/PdStarterKit) [![Appveyor](https://img.shields.io/appveyor/ci/eliottparis/PdStarterKit.svg?label=appveyor)](https://ci.appveyor.com/project/eliottparis/PdStarterKit/history)

This repository contains a starter kit to write [Pure Data](https://puredata.info/) externals.

## Prerequisites and dependencies

To build the externals in this repository you will need a compiler on your system.

* On the Mac you can use [Xcode](https://developer.apple.com/xcode/) (get it for free from the App Store).
* On Windows you can use a free version of [Visual Studio](https://www.visualstudio.com/).
* You can also build directly on the command line using Makefiles.

You will also need to install [CMake](https://cmake.org/download/).

## Building

1. Create an empty directory (ex. "PdStarterKit").
2. In the Terminal or Console app of your choice, change directories into the folder you created in step 1 (`cd "path_to_your_folder"`).
3. `git clone --recursive https://github.com/paccpp/PdStarterKit.git .` to clone this repository in the folder you created.
4. `mkdir build` to create a folder with your various build files.
5. `cd build` to put yourself into that folder.
6. Now you can generate the projects for your choosen build environment:

### Mac

To generate an Xcode project and use this IDE to build :
- Run `cmake -G Xcode ..` and then run `cmake --build .` or open the Xcode project from this "build" folder.

### Windows

The exact command line you need to use will depend on the version of Visual Studio you have installed.
- Run `cmake --help` to get a list of the options available.
- Assuming some version of Visual Studio 2013, the commands to generate the projects will look like this:
 * 32 bit: `cmake -G "Visual Studio 12" ..`
 * 64 bit: `cmake -G "Visual Studio 12 Win64" -DWIN64:Bool=True ..`

Having generated the projects, you can now build by opening the .sln file in the build folder with the Visual Studio app.

### Using Makefiles

To build on the command line using Makefiles:
- run `cmake ..` and then run `cmake --build .` or `make .`
