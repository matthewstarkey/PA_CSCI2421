# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/starkey/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/starkey/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/starkey/Desktop/CSCI2421/PA_CSCI2421

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/starkey/Desktop/CSCI2421/PA_CSCI2421/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PA_CSCI2421.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PA_CSCI2421.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PA_CSCI2421.dir/flags.make

CMakeFiles/PA_CSCI2421.dir/main.cpp.o: CMakeFiles/PA_CSCI2421.dir/flags.make
CMakeFiles/PA_CSCI2421.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/starkey/Desktop/CSCI2421/PA_CSCI2421/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PA_CSCI2421.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA_CSCI2421.dir/main.cpp.o -c /Users/starkey/Desktop/CSCI2421/PA_CSCI2421/main.cpp

CMakeFiles/PA_CSCI2421.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA_CSCI2421.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/starkey/Desktop/CSCI2421/PA_CSCI2421/main.cpp > CMakeFiles/PA_CSCI2421.dir/main.cpp.i

CMakeFiles/PA_CSCI2421.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA_CSCI2421.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/starkey/Desktop/CSCI2421/PA_CSCI2421/main.cpp -o CMakeFiles/PA_CSCI2421.dir/main.cpp.s

# Object files for target PA_CSCI2421
PA_CSCI2421_OBJECTS = \
"CMakeFiles/PA_CSCI2421.dir/main.cpp.o"

# External object files for target PA_CSCI2421
PA_CSCI2421_EXTERNAL_OBJECTS =

PA_CSCI2421: CMakeFiles/PA_CSCI2421.dir/main.cpp.o
PA_CSCI2421: CMakeFiles/PA_CSCI2421.dir/build.make
PA_CSCI2421: CMakeFiles/PA_CSCI2421.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/starkey/Desktop/CSCI2421/PA_CSCI2421/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PA_CSCI2421"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PA_CSCI2421.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PA_CSCI2421.dir/build: PA_CSCI2421

.PHONY : CMakeFiles/PA_CSCI2421.dir/build

CMakeFiles/PA_CSCI2421.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PA_CSCI2421.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PA_CSCI2421.dir/clean

CMakeFiles/PA_CSCI2421.dir/depend:
	cd /Users/starkey/Desktop/CSCI2421/PA_CSCI2421/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/starkey/Desktop/CSCI2421/PA_CSCI2421 /Users/starkey/Desktop/CSCI2421/PA_CSCI2421 /Users/starkey/Desktop/CSCI2421/PA_CSCI2421/cmake-build-debug /Users/starkey/Desktop/CSCI2421/PA_CSCI2421/cmake-build-debug /Users/starkey/Desktop/CSCI2421/PA_CSCI2421/cmake-build-debug/CMakeFiles/PA_CSCI2421.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PA_CSCI2421.dir/depend
