# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/ElderDrop/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4668.70/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ElderDrop/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4668.70/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ElderDrop/workspace/PK/Lab3G

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ElderDrop/workspace/PK/Lab3G/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab3G.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab3G.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab3G.dir/flags.make

CMakeFiles/Lab3G.dir/main.c.o: CMakeFiles/Lab3G.dir/flags.make
CMakeFiles/Lab3G.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ElderDrop/workspace/PK/Lab3G/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab3G.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab3G.dir/main.c.o   -c /home/ElderDrop/workspace/PK/Lab3G/main.c

CMakeFiles/Lab3G.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab3G.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ElderDrop/workspace/PK/Lab3G/main.c > CMakeFiles/Lab3G.dir/main.c.i

CMakeFiles/Lab3G.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab3G.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ElderDrop/workspace/PK/Lab3G/main.c -o CMakeFiles/Lab3G.dir/main.c.s

CMakeFiles/Lab3G.dir/main.c.o.requires:

.PHONY : CMakeFiles/Lab3G.dir/main.c.o.requires

CMakeFiles/Lab3G.dir/main.c.o.provides: CMakeFiles/Lab3G.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Lab3G.dir/build.make CMakeFiles/Lab3G.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Lab3G.dir/main.c.o.provides

CMakeFiles/Lab3G.dir/main.c.o.provides.build: CMakeFiles/Lab3G.dir/main.c.o


# Object files for target Lab3G
Lab3G_OBJECTS = \
"CMakeFiles/Lab3G.dir/main.c.o"

# External object files for target Lab3G
Lab3G_EXTERNAL_OBJECTS =

Lab3G: CMakeFiles/Lab3G.dir/main.c.o
Lab3G: CMakeFiles/Lab3G.dir/build.make
Lab3G: CMakeFiles/Lab3G.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ElderDrop/workspace/PK/Lab3G/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab3G"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab3G.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab3G.dir/build: Lab3G

.PHONY : CMakeFiles/Lab3G.dir/build

CMakeFiles/Lab3G.dir/requires: CMakeFiles/Lab3G.dir/main.c.o.requires

.PHONY : CMakeFiles/Lab3G.dir/requires

CMakeFiles/Lab3G.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab3G.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab3G.dir/clean

CMakeFiles/Lab3G.dir/depend:
	cd /home/ElderDrop/workspace/PK/Lab3G/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ElderDrop/workspace/PK/Lab3G /home/ElderDrop/workspace/PK/Lab3G /home/ElderDrop/workspace/PK/Lab3G/cmake-build-debug /home/ElderDrop/workspace/PK/Lab3G/cmake-build-debug /home/ElderDrop/workspace/PK/Lab3G/cmake-build-debug/CMakeFiles/Lab3G.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab3G.dir/depend

