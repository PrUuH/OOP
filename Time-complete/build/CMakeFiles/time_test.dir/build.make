# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /snap/cmake/1429/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1429/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/с++/Time-complete

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/с++/Time-complete/build

# Include any dependencies generated for this target.
include CMakeFiles/time_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/time_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/time_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/time_test.dir/flags.make

CMakeFiles/time_test.dir/codegen:
.PHONY : CMakeFiles/time_test.dir/codegen

CMakeFiles/time_test.dir/test_time.cpp.o: CMakeFiles/time_test.dir/flags.make
CMakeFiles/time_test.dir/test_time.cpp.o: /mnt/d/с++/Time-complete/test_time.cpp
CMakeFiles/time_test.dir/test_time.cpp.o: CMakeFiles/time_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/с++/Time-complete/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/time_test.dir/test_time.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/time_test.dir/test_time.cpp.o -MF CMakeFiles/time_test.dir/test_time.cpp.o.d -o CMakeFiles/time_test.dir/test_time.cpp.o -c /mnt/d/с++/Time-complete/test_time.cpp

CMakeFiles/time_test.dir/test_time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/time_test.dir/test_time.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/с++/Time-complete/test_time.cpp > CMakeFiles/time_test.dir/test_time.cpp.i

CMakeFiles/time_test.dir/test_time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/time_test.dir/test_time.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/с++/Time-complete/test_time.cpp -o CMakeFiles/time_test.dir/test_time.cpp.s

# Object files for target time_test
time_test_OBJECTS = \
"CMakeFiles/time_test.dir/test_time.cpp.o"

# External object files for target time_test
time_test_EXTERNAL_OBJECTS =

time_test: CMakeFiles/time_test.dir/test_time.cpp.o
time_test: CMakeFiles/time_test.dir/build.make
time_test: CMakeFiles/time_test.dir/compiler_depend.ts
time_test: libtime.a
time_test: lib/libgtest_main.a
time_test: lib/libgtest.a
time_test: CMakeFiles/time_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/d/с++/Time-complete/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable time_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/time_test.dir/link.txt --verbose=$(VERBOSE)
	/snap/cmake/1429/bin/cmake -D TEST_TARGET=time_test -D TEST_EXECUTABLE=/mnt/d/с++/Time-complete/build/time_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/mnt/d/с++/Time-complete/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=time_test_TESTS -D CTEST_FILE=/mnt/d/с++/Time-complete/build/time_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_DISCOVERY_EXTRA_ARGS= -D TEST_XML_OUTPUT_DIR= -P /snap/cmake/1429/share/cmake-3.31/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/time_test.dir/build: time_test
.PHONY : CMakeFiles/time_test.dir/build

CMakeFiles/time_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/time_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/time_test.dir/clean

CMakeFiles/time_test.dir/depend:
	cd /mnt/d/с++/Time-complete/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/с++/Time-complete /mnt/d/с++/Time-complete /mnt/d/с++/Time-complete/build /mnt/d/с++/Time-complete/build /mnt/d/с++/Time-complete/build/CMakeFiles/time_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/time_test.dir/depend

