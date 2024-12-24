# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robot/human_ws/src/apriltag_ros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robot/human_ws/build/apriltag_ros

# Include any dependencies generated for this target.
include CMakeFiles/pose_estimation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pose_estimation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pose_estimation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pose_estimation.dir/flags.make

CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o: CMakeFiles/pose_estimation.dir/flags.make
CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o: /home/robot/human_ws/src/apriltag_ros/src/pose_estimation.cpp
CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o: CMakeFiles/pose_estimation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robot/human_ws/build/apriltag_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o -MF CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o.d -o CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o -c /home/robot/human_ws/src/apriltag_ros/src/pose_estimation.cpp

CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robot/human_ws/src/apriltag_ros/src/pose_estimation.cpp > CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.i

CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robot/human_ws/src/apriltag_ros/src/pose_estimation.cpp -o CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.s

# Object files for target pose_estimation
pose_estimation_OBJECTS = \
"CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o"

# External object files for target pose_estimation
pose_estimation_EXTERNAL_OBJECTS =

libpose_estimation.a: CMakeFiles/pose_estimation.dir/src/pose_estimation.cpp.o
libpose_estimation.a: CMakeFiles/pose_estimation.dir/build.make
libpose_estimation.a: CMakeFiles/pose_estimation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robot/human_ws/build/apriltag_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpose_estimation.a"
	$(CMAKE_COMMAND) -P CMakeFiles/pose_estimation.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pose_estimation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pose_estimation.dir/build: libpose_estimation.a
.PHONY : CMakeFiles/pose_estimation.dir/build

CMakeFiles/pose_estimation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pose_estimation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pose_estimation.dir/clean

CMakeFiles/pose_estimation.dir/depend:
	cd /home/robot/human_ws/build/apriltag_ros && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robot/human_ws/src/apriltag_ros /home/robot/human_ws/src/apriltag_ros /home/robot/human_ws/build/apriltag_ros /home/robot/human_ws/build/apriltag_ros /home/robot/human_ws/build/apriltag_ros/CMakeFiles/pose_estimation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pose_estimation.dir/depend
