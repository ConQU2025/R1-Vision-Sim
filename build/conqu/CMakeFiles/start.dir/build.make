# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rc1/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rc1/catkin_ws/build

# Include any dependencies generated for this target.
include conqu/CMakeFiles/start.dir/depend.make

# Include the progress variables for this target.
include conqu/CMakeFiles/start.dir/progress.make

# Include the compile flags for this target's objects.
include conqu/CMakeFiles/start.dir/flags.make

conqu/CMakeFiles/start.dir/src/start.cpp.o: conqu/CMakeFiles/start.dir/flags.make
conqu/CMakeFiles/start.dir/src/start.cpp.o: /home/rc1/catkin_ws/src/conqu/src/start.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rc1/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object conqu/CMakeFiles/start.dir/src/start.cpp.o"
	cd /home/rc1/catkin_ws/build/conqu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/start.dir/src/start.cpp.o -c /home/rc1/catkin_ws/src/conqu/src/start.cpp

conqu/CMakeFiles/start.dir/src/start.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/start.dir/src/start.cpp.i"
	cd /home/rc1/catkin_ws/build/conqu && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rc1/catkin_ws/src/conqu/src/start.cpp > CMakeFiles/start.dir/src/start.cpp.i

conqu/CMakeFiles/start.dir/src/start.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/start.dir/src/start.cpp.s"
	cd /home/rc1/catkin_ws/build/conqu && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rc1/catkin_ws/src/conqu/src/start.cpp -o CMakeFiles/start.dir/src/start.cpp.s

# Object files for target start
start_OBJECTS = \
"CMakeFiles/start.dir/src/start.cpp.o"

# External object files for target start
start_EXTERNAL_OBJECTS =

/home/rc1/catkin_ws/devel/lib/conqu/start: conqu/CMakeFiles/start.dir/src/start.cpp.o
/home/rc1/catkin_ws/devel/lib/conqu/start: conqu/CMakeFiles/start.dir/build.make
/home/rc1/catkin_ws/devel/lib/conqu/start: conqu/CMakeFiles/start.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rc1/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/rc1/catkin_ws/devel/lib/conqu/start"
	cd /home/rc1/catkin_ws/build/conqu && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/start.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
conqu/CMakeFiles/start.dir/build: /home/rc1/catkin_ws/devel/lib/conqu/start

.PHONY : conqu/CMakeFiles/start.dir/build

conqu/CMakeFiles/start.dir/clean:
	cd /home/rc1/catkin_ws/build/conqu && $(CMAKE_COMMAND) -P CMakeFiles/start.dir/cmake_clean.cmake
.PHONY : conqu/CMakeFiles/start.dir/clean

conqu/CMakeFiles/start.dir/depend:
	cd /home/rc1/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rc1/catkin_ws/src /home/rc1/catkin_ws/src/conqu /home/rc1/catkin_ws/build /home/rc1/catkin_ws/build/conqu /home/rc1/catkin_ws/build/conqu/CMakeFiles/start.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : conqu/CMakeFiles/start.dir/depend

