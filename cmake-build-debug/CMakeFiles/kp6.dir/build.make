# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\Clion\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Clion\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\c++\kp6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\c++\kp6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/kp6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kp6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kp6.dir/flags.make

CMakeFiles/kp6.dir/kp6.c.obj: CMakeFiles/kp6.dir/flags.make
CMakeFiles/kp6.dir/kp6.c.obj: ../kp6.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\c++\kp6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/kp6.dir/kp6.c.obj"
	G:\Clion\MinGW\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\kp6.dir\kp6.c.obj   -c D:\Projects\c++\kp6\kp6.c

CMakeFiles/kp6.dir/kp6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kp6.dir/kp6.c.i"
	G:\Clion\MinGW\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projects\c++\kp6\kp6.c > CMakeFiles\kp6.dir\kp6.c.i

CMakeFiles/kp6.dir/kp6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kp6.dir/kp6.c.s"
	G:\Clion\MinGW\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projects\c++\kp6\kp6.c -o CMakeFiles\kp6.dir\kp6.c.s

# Object files for target kp6
kp6_OBJECTS = \
"CMakeFiles/kp6.dir/kp6.c.obj"

# External object files for target kp6
kp6_EXTERNAL_OBJECTS =

kp6.exe: CMakeFiles/kp6.dir/kp6.c.obj
kp6.exe: CMakeFiles/kp6.dir/build.make
kp6.exe: CMakeFiles/kp6.dir/linklibs.rsp
kp6.exe: CMakeFiles/kp6.dir/objects1.rsp
kp6.exe: CMakeFiles/kp6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\c++\kp6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable kp6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\kp6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kp6.dir/build: kp6.exe

.PHONY : CMakeFiles/kp6.dir/build

CMakeFiles/kp6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kp6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/kp6.dir/clean

CMakeFiles/kp6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\c++\kp6 D:\Projects\c++\kp6 D:\Projects\c++\kp6\cmake-build-debug D:\Projects\c++\kp6\cmake-build-debug D:\Projects\c++\kp6\cmake-build-debug\CMakeFiles\kp6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kp6.dir/depend

