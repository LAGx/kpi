# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/kvark/tools/cpp/clion-2018.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kvark/tools/cpp/clion-2018.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kvark/kpi/kpi_reps/ro_graph_editor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kvark/kpi/kpi_reps/ro_graph_editor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ro_graph_editor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ro_graph_editor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ro_graph_editor.dir/flags.make

CMakeFiles/ro_graph_editor.dir/main.cpp.o: CMakeFiles/ro_graph_editor.dir/flags.make
CMakeFiles/ro_graph_editor.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kvark/kpi/kpi_reps/ro_graph_editor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ro_graph_editor.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ro_graph_editor.dir/main.cpp.o -c /home/kvark/kpi/kpi_reps/ro_graph_editor/main.cpp

CMakeFiles/ro_graph_editor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ro_graph_editor.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kvark/kpi/kpi_reps/ro_graph_editor/main.cpp > CMakeFiles/ro_graph_editor.dir/main.cpp.i

CMakeFiles/ro_graph_editor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ro_graph_editor.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kvark/kpi/kpi_reps/ro_graph_editor/main.cpp -o CMakeFiles/ro_graph_editor.dir/main.cpp.s

# Object files for target ro_graph_editor
ro_graph_editor_OBJECTS = \
"CMakeFiles/ro_graph_editor.dir/main.cpp.o"

# External object files for target ro_graph_editor
ro_graph_editor_EXTERNAL_OBJECTS =

ro_graph_editor: CMakeFiles/ro_graph_editor.dir/main.cpp.o
ro_graph_editor: CMakeFiles/ro_graph_editor.dir/build.make
ro_graph_editor: CMakeFiles/ro_graph_editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kvark/kpi/kpi_reps/ro_graph_editor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ro_graph_editor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ro_graph_editor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ro_graph_editor.dir/build: ro_graph_editor

.PHONY : CMakeFiles/ro_graph_editor.dir/build

CMakeFiles/ro_graph_editor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ro_graph_editor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ro_graph_editor.dir/clean

CMakeFiles/ro_graph_editor.dir/depend:
	cd /home/kvark/kpi/kpi_reps/ro_graph_editor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kvark/kpi/kpi_reps/ro_graph_editor /home/kvark/kpi/kpi_reps/ro_graph_editor /home/kvark/kpi/kpi_reps/ro_graph_editor/cmake-build-debug /home/kvark/kpi/kpi_reps/ro_graph_editor/cmake-build-debug /home/kvark/kpi/kpi_reps/ro_graph_editor/cmake-build-debug/CMakeFiles/ro_graph_editor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ro_graph_editor.dir/depend

