# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jiaru/Desktop/CS-homework/FIFO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jiaru/Desktop/CS-homework/FIFO/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FIFO.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FIFO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FIFO.dir/flags.make

CMakeFiles/FIFO.dir/main.cpp.o: CMakeFiles/FIFO.dir/flags.make
CMakeFiles/FIFO.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiaru/Desktop/CS-homework/FIFO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FIFO.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FIFO.dir/main.cpp.o -c /Users/jiaru/Desktop/CS-homework/FIFO/main.cpp

CMakeFiles/FIFO.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FIFO.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jiaru/Desktop/CS-homework/FIFO/main.cpp > CMakeFiles/FIFO.dir/main.cpp.i

CMakeFiles/FIFO.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FIFO.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jiaru/Desktop/CS-homework/FIFO/main.cpp -o CMakeFiles/FIFO.dir/main.cpp.s

CMakeFiles/FIFO.dir/deque.cpp.o: CMakeFiles/FIFO.dir/flags.make
CMakeFiles/FIFO.dir/deque.cpp.o: ../deque.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiaru/Desktop/CS-homework/FIFO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FIFO.dir/deque.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FIFO.dir/deque.cpp.o -c /Users/jiaru/Desktop/CS-homework/FIFO/deque.cpp

CMakeFiles/FIFO.dir/deque.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FIFO.dir/deque.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jiaru/Desktop/CS-homework/FIFO/deque.cpp > CMakeFiles/FIFO.dir/deque.cpp.i

CMakeFiles/FIFO.dir/deque.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FIFO.dir/deque.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jiaru/Desktop/CS-homework/FIFO/deque.cpp -o CMakeFiles/FIFO.dir/deque.cpp.s

# Object files for target FIFO
FIFO_OBJECTS = \
"CMakeFiles/FIFO.dir/main.cpp.o" \
"CMakeFiles/FIFO.dir/deque.cpp.o"

# External object files for target FIFO
FIFO_EXTERNAL_OBJECTS =

FIFO: CMakeFiles/FIFO.dir/main.cpp.o
FIFO: CMakeFiles/FIFO.dir/deque.cpp.o
FIFO: CMakeFiles/FIFO.dir/build.make
FIFO: CMakeFiles/FIFO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jiaru/Desktop/CS-homework/FIFO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FIFO"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FIFO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FIFO.dir/build: FIFO

.PHONY : CMakeFiles/FIFO.dir/build

CMakeFiles/FIFO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FIFO.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FIFO.dir/clean

CMakeFiles/FIFO.dir/depend:
	cd /Users/jiaru/Desktop/CS-homework/FIFO/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jiaru/Desktop/CS-homework/FIFO /Users/jiaru/Desktop/CS-homework/FIFO /Users/jiaru/Desktop/CS-homework/FIFO/cmake-build-debug /Users/jiaru/Desktop/CS-homework/FIFO/cmake-build-debug /Users/jiaru/Desktop/CS-homework/FIFO/cmake-build-debug/CMakeFiles/FIFO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FIFO.dir/depend

