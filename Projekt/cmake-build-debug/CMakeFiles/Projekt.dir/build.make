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
CMAKE_COMMAND = /home/ElderDrop/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5087.36/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ElderDrop/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5087.36/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ElderDrop/workspace/PK/Projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ElderDrop/workspace/PK/Projekt/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projekt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projekt.dir/flags.make

CMakeFiles/Projekt.dir/main.c.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ElderDrop/workspace/PK/Projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Projekt.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projekt.dir/main.c.o   -c /home/ElderDrop/workspace/PK/Projekt/main.c

CMakeFiles/Projekt.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projekt.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ElderDrop/workspace/PK/Projekt/main.c > CMakeFiles/Projekt.dir/main.c.i

CMakeFiles/Projekt.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projekt.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ElderDrop/workspace/PK/Projekt/main.c -o CMakeFiles/Projekt.dir/main.c.s

CMakeFiles/Projekt.dir/main.c.o.requires:

.PHONY : CMakeFiles/Projekt.dir/main.c.o.requires

CMakeFiles/Projekt.dir/main.c.o.provides: CMakeFiles/Projekt.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Projekt.dir/build.make CMakeFiles/Projekt.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Projekt.dir/main.c.o.provides

CMakeFiles/Projekt.dir/main.c.o.provides.build: CMakeFiles/Projekt.dir/main.c.o


CMakeFiles/Projekt.dir/gameOfLife.c.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/gameOfLife.c.o: ../gameOfLife.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ElderDrop/workspace/PK/Projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Projekt.dir/gameOfLife.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projekt.dir/gameOfLife.c.o   -c /home/ElderDrop/workspace/PK/Projekt/gameOfLife.c

CMakeFiles/Projekt.dir/gameOfLife.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projekt.dir/gameOfLife.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ElderDrop/workspace/PK/Projekt/gameOfLife.c > CMakeFiles/Projekt.dir/gameOfLife.c.i

CMakeFiles/Projekt.dir/gameOfLife.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projekt.dir/gameOfLife.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ElderDrop/workspace/PK/Projekt/gameOfLife.c -o CMakeFiles/Projekt.dir/gameOfLife.c.s

CMakeFiles/Projekt.dir/gameOfLife.c.o.requires:

.PHONY : CMakeFiles/Projekt.dir/gameOfLife.c.o.requires

CMakeFiles/Projekt.dir/gameOfLife.c.o.provides: CMakeFiles/Projekt.dir/gameOfLife.c.o.requires
	$(MAKE) -f CMakeFiles/Projekt.dir/build.make CMakeFiles/Projekt.dir/gameOfLife.c.o.provides.build
.PHONY : CMakeFiles/Projekt.dir/gameOfLife.c.o.provides

CMakeFiles/Projekt.dir/gameOfLife.c.o.provides.build: CMakeFiles/Projekt.dir/gameOfLife.c.o


CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o: ../gameOfLifeArguments.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ElderDrop/workspace/PK/Projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o   -c /home/ElderDrop/workspace/PK/Projekt/gameOfLifeArguments.c

CMakeFiles/Projekt.dir/gameOfLifeArguments.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projekt.dir/gameOfLifeArguments.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ElderDrop/workspace/PK/Projekt/gameOfLifeArguments.c > CMakeFiles/Projekt.dir/gameOfLifeArguments.c.i

CMakeFiles/Projekt.dir/gameOfLifeArguments.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projekt.dir/gameOfLifeArguments.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ElderDrop/workspace/PK/Projekt/gameOfLifeArguments.c -o CMakeFiles/Projekt.dir/gameOfLifeArguments.c.s

CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o.requires:

.PHONY : CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o.requires

CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o.provides: CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o.requires
	$(MAKE) -f CMakeFiles/Projekt.dir/build.make CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o.provides.build
.PHONY : CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o.provides

CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o.provides.build: CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o


CMakeFiles/Projekt.dir/Ant.c.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/Ant.c.o: ../Ant.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ElderDrop/workspace/PK/Projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Projekt.dir/Ant.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projekt.dir/Ant.c.o   -c /home/ElderDrop/workspace/PK/Projekt/Ant.c

CMakeFiles/Projekt.dir/Ant.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projekt.dir/Ant.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ElderDrop/workspace/PK/Projekt/Ant.c > CMakeFiles/Projekt.dir/Ant.c.i

CMakeFiles/Projekt.dir/Ant.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projekt.dir/Ant.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ElderDrop/workspace/PK/Projekt/Ant.c -o CMakeFiles/Projekt.dir/Ant.c.s

CMakeFiles/Projekt.dir/Ant.c.o.requires:

.PHONY : CMakeFiles/Projekt.dir/Ant.c.o.requires

CMakeFiles/Projekt.dir/Ant.c.o.provides: CMakeFiles/Projekt.dir/Ant.c.o.requires
	$(MAKE) -f CMakeFiles/Projekt.dir/build.make CMakeFiles/Projekt.dir/Ant.c.o.provides.build
.PHONY : CMakeFiles/Projekt.dir/Ant.c.o.provides

CMakeFiles/Projekt.dir/Ant.c.o.provides.build: CMakeFiles/Projekt.dir/Ant.c.o


CMakeFiles/Projekt.dir/AntProperties.c.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/AntProperties.c.o: ../AntProperties.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ElderDrop/workspace/PK/Projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Projekt.dir/AntProperties.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projekt.dir/AntProperties.c.o   -c /home/ElderDrop/workspace/PK/Projekt/AntProperties.c

CMakeFiles/Projekt.dir/AntProperties.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projekt.dir/AntProperties.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ElderDrop/workspace/PK/Projekt/AntProperties.c > CMakeFiles/Projekt.dir/AntProperties.c.i

CMakeFiles/Projekt.dir/AntProperties.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projekt.dir/AntProperties.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ElderDrop/workspace/PK/Projekt/AntProperties.c -o CMakeFiles/Projekt.dir/AntProperties.c.s

CMakeFiles/Projekt.dir/AntProperties.c.o.requires:

.PHONY : CMakeFiles/Projekt.dir/AntProperties.c.o.requires

CMakeFiles/Projekt.dir/AntProperties.c.o.provides: CMakeFiles/Projekt.dir/AntProperties.c.o.requires
	$(MAKE) -f CMakeFiles/Projekt.dir/build.make CMakeFiles/Projekt.dir/AntProperties.c.o.provides.build
.PHONY : CMakeFiles/Projekt.dir/AntProperties.c.o.provides

CMakeFiles/Projekt.dir/AntProperties.c.o.provides.build: CMakeFiles/Projekt.dir/AntProperties.c.o


# Object files for target Projekt
Projekt_OBJECTS = \
"CMakeFiles/Projekt.dir/main.c.o" \
"CMakeFiles/Projekt.dir/gameOfLife.c.o" \
"CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o" \
"CMakeFiles/Projekt.dir/Ant.c.o" \
"CMakeFiles/Projekt.dir/AntProperties.c.o"

# External object files for target Projekt
Projekt_EXTERNAL_OBJECTS =

Projekt: CMakeFiles/Projekt.dir/main.c.o
Projekt: CMakeFiles/Projekt.dir/gameOfLife.c.o
Projekt: CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o
Projekt: CMakeFiles/Projekt.dir/Ant.c.o
Projekt: CMakeFiles/Projekt.dir/AntProperties.c.o
Projekt: CMakeFiles/Projekt.dir/build.make
Projekt: CMakeFiles/Projekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ElderDrop/workspace/PK/Projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Projekt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projekt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projekt.dir/build: Projekt

.PHONY : CMakeFiles/Projekt.dir/build

CMakeFiles/Projekt.dir/requires: CMakeFiles/Projekt.dir/main.c.o.requires
CMakeFiles/Projekt.dir/requires: CMakeFiles/Projekt.dir/gameOfLife.c.o.requires
CMakeFiles/Projekt.dir/requires: CMakeFiles/Projekt.dir/gameOfLifeArguments.c.o.requires
CMakeFiles/Projekt.dir/requires: CMakeFiles/Projekt.dir/Ant.c.o.requires
CMakeFiles/Projekt.dir/requires: CMakeFiles/Projekt.dir/AntProperties.c.o.requires

.PHONY : CMakeFiles/Projekt.dir/requires

CMakeFiles/Projekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projekt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projekt.dir/clean

CMakeFiles/Projekt.dir/depend:
	cd /home/ElderDrop/workspace/PK/Projekt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ElderDrop/workspace/PK/Projekt /home/ElderDrop/workspace/PK/Projekt /home/ElderDrop/workspace/PK/Projekt/cmake-build-debug /home/ElderDrop/workspace/PK/Projekt/cmake-build-debug /home/ElderDrop/workspace/PK/Projekt/cmake-build-debug/CMakeFiles/Projekt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projekt.dir/depend

