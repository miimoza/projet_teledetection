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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bug/TELE/NUAGES_SRC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bug/TELE/NUAGES_SRC/EXE

# Include any dependencies generated for this target.
include CMakeFiles/imaProjet.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imaProjet.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imaProjet.exe.dir/flags.make

CMakeFiles/imaProjet.exe.dir/main.c.o: CMakeFiles/imaProjet.exe.dir/flags.make
CMakeFiles/imaProjet.exe.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bug/TELE/NUAGES_SRC/EXE/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/imaProjet.exe.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imaProjet.exe.dir/main.c.o   -c /home/bug/TELE/NUAGES_SRC/main.c

CMakeFiles/imaProjet.exe.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imaProjet.exe.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bug/TELE/NUAGES_SRC/main.c > CMakeFiles/imaProjet.exe.dir/main.c.i

CMakeFiles/imaProjet.exe.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imaProjet.exe.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bug/TELE/NUAGES_SRC/main.c -o CMakeFiles/imaProjet.exe.dir/main.c.s

CMakeFiles/imaProjet.exe.dir/compute.c.o: CMakeFiles/imaProjet.exe.dir/flags.make
CMakeFiles/imaProjet.exe.dir/compute.c.o: ../compute.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bug/TELE/NUAGES_SRC/EXE/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/imaProjet.exe.dir/compute.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imaProjet.exe.dir/compute.c.o   -c /home/bug/TELE/NUAGES_SRC/compute.c

CMakeFiles/imaProjet.exe.dir/compute.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imaProjet.exe.dir/compute.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bug/TELE/NUAGES_SRC/compute.c > CMakeFiles/imaProjet.exe.dir/compute.c.i

CMakeFiles/imaProjet.exe.dir/compute.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imaProjet.exe.dir/compute.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bug/TELE/NUAGES_SRC/compute.c -o CMakeFiles/imaProjet.exe.dir/compute.c.s

# Object files for target imaProjet.exe
imaProjet_exe_OBJECTS = \
"CMakeFiles/imaProjet.exe.dir/main.c.o" \
"CMakeFiles/imaProjet.exe.dir/compute.c.o"

# External object files for target imaProjet.exe
imaProjet_exe_EXTERNAL_OBJECTS =

imaProjet.exe: CMakeFiles/imaProjet.exe.dir/main.c.o
imaProjet.exe: CMakeFiles/imaProjet.exe.dir/compute.c.o
imaProjet.exe: CMakeFiles/imaProjet.exe.dir/build.make
imaProjet.exe: CMakeFiles/imaProjet.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bug/TELE/NUAGES_SRC/EXE/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable imaProjet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imaProjet.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imaProjet.exe.dir/build: imaProjet.exe

.PHONY : CMakeFiles/imaProjet.exe.dir/build

CMakeFiles/imaProjet.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imaProjet.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imaProjet.exe.dir/clean

CMakeFiles/imaProjet.exe.dir/depend:
	cd /home/bug/TELE/NUAGES_SRC/EXE && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bug/TELE/NUAGES_SRC /home/bug/TELE/NUAGES_SRC /home/bug/TELE/NUAGES_SRC/EXE /home/bug/TELE/NUAGES_SRC/EXE /home/bug/TELE/NUAGES_SRC/EXE/CMakeFiles/imaProjet.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imaProjet.exe.dir/depend

