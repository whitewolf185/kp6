# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/103/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/103/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/im/CLionProjects/kp6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/im/CLionProjects/kp6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KP6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KP6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KP6.dir/flags.make

CMakeFiles/KP6.dir/maks.c.o: CMakeFiles/KP6.dir/flags.make
CMakeFiles/KP6.dir/maks.c.o: ../maks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/im/CLionProjects/kp6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/KP6.dir/maks.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/KP6.dir/maks.c.o   -c /home/im/CLionProjects/kp6/maks.c

CMakeFiles/KP6.dir/maks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/KP6.dir/maks.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/im/CLionProjects/kp6/maks.c > CMakeFiles/KP6.dir/maks.c.i

CMakeFiles/KP6.dir/maks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/KP6.dir/maks.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/im/CLionProjects/kp6/maks.c -o CMakeFiles/KP6.dir/maks.c.s

# Object files for target KP6
KP6_OBJECTS = \
"CMakeFiles/KP6.dir/maks.c.o"

# External object files for target KP6
KP6_EXTERNAL_OBJECTS =

KP6: CMakeFiles/KP6.dir/maks.c.o
KP6: CMakeFiles/KP6.dir/build.make
KP6: CMakeFiles/KP6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/im/CLionProjects/kp6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable KP6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KP6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KP6.dir/build: KP6

.PHONY : CMakeFiles/KP6.dir/build

CMakeFiles/KP6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KP6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KP6.dir/clean

CMakeFiles/KP6.dir/depend:
	cd /home/im/CLionProjects/kp6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/im/CLionProjects/kp6 /home/im/CLionProjects/kp6 /home/im/CLionProjects/kp6/cmake-build-debug /home/im/CLionProjects/kp6/cmake-build-debug /home/im/CLionProjects/kp6/cmake-build-debug/CMakeFiles/KP6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KP6.dir/depend

