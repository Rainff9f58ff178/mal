# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/rain/src/muduo/malIO_uring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rain/src/muduo/malIO_uring/build

# Include any dependencies generated for this target.
include base/CMakeFiles/mal_base.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include base/CMakeFiles/mal_base.dir/compiler_depend.make

# Include the progress variables for this target.
include base/CMakeFiles/mal_base.dir/progress.make

# Include the compile flags for this target's objects.
include base/CMakeFiles/mal_base.dir/flags.make

base/CMakeFiles/mal_base.dir/Thread.cpp.o: base/CMakeFiles/mal_base.dir/flags.make
base/CMakeFiles/mal_base.dir/Thread.cpp.o: /home/rain/src/muduo/malIO_uring/base/Thread.cpp
base/CMakeFiles/mal_base.dir/Thread.cpp.o: base/CMakeFiles/mal_base.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base/CMakeFiles/mal_base.dir/Thread.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT base/CMakeFiles/mal_base.dir/Thread.cpp.o -MF CMakeFiles/mal_base.dir/Thread.cpp.o.d -o CMakeFiles/mal_base.dir/Thread.cpp.o -c /home/rain/src/muduo/malIO_uring/base/Thread.cpp

base/CMakeFiles/mal_base.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_base.dir/Thread.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/base/Thread.cpp > CMakeFiles/mal_base.dir/Thread.cpp.i

base/CMakeFiles/mal_base.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_base.dir/Thread.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/base/Thread.cpp -o CMakeFiles/mal_base.dir/Thread.cpp.s

base/CMakeFiles/mal_base.dir/TimeStamp.cpp.o: base/CMakeFiles/mal_base.dir/flags.make
base/CMakeFiles/mal_base.dir/TimeStamp.cpp.o: /home/rain/src/muduo/malIO_uring/base/TimeStamp.cpp
base/CMakeFiles/mal_base.dir/TimeStamp.cpp.o: base/CMakeFiles/mal_base.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object base/CMakeFiles/mal_base.dir/TimeStamp.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT base/CMakeFiles/mal_base.dir/TimeStamp.cpp.o -MF CMakeFiles/mal_base.dir/TimeStamp.cpp.o.d -o CMakeFiles/mal_base.dir/TimeStamp.cpp.o -c /home/rain/src/muduo/malIO_uring/base/TimeStamp.cpp

base/CMakeFiles/mal_base.dir/TimeStamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_base.dir/TimeStamp.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/base/TimeStamp.cpp > CMakeFiles/mal_base.dir/TimeStamp.cpp.i

base/CMakeFiles/mal_base.dir/TimeStamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_base.dir/TimeStamp.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/base/TimeStamp.cpp -o CMakeFiles/mal_base.dir/TimeStamp.cpp.s

base/CMakeFiles/mal_base.dir/log.cpp.o: base/CMakeFiles/mal_base.dir/flags.make
base/CMakeFiles/mal_base.dir/log.cpp.o: /home/rain/src/muduo/malIO_uring/base/log.cpp
base/CMakeFiles/mal_base.dir/log.cpp.o: base/CMakeFiles/mal_base.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object base/CMakeFiles/mal_base.dir/log.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT base/CMakeFiles/mal_base.dir/log.cpp.o -MF CMakeFiles/mal_base.dir/log.cpp.o.d -o CMakeFiles/mal_base.dir/log.cpp.o -c /home/rain/src/muduo/malIO_uring/base/log.cpp

base/CMakeFiles/mal_base.dir/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_base.dir/log.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/base/log.cpp > CMakeFiles/mal_base.dir/log.cpp.i

base/CMakeFiles/mal_base.dir/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_base.dir/log.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/base && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/base/log.cpp -o CMakeFiles/mal_base.dir/log.cpp.s

# Object files for target mal_base
mal_base_OBJECTS = \
"CMakeFiles/mal_base.dir/Thread.cpp.o" \
"CMakeFiles/mal_base.dir/TimeStamp.cpp.o" \
"CMakeFiles/mal_base.dir/log.cpp.o"

# External object files for target mal_base
mal_base_EXTERNAL_OBJECTS =

/home/rain/src/muduo/malIO_uring/lib/libmal_base.a: base/CMakeFiles/mal_base.dir/Thread.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_base.a: base/CMakeFiles/mal_base.dir/TimeStamp.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_base.a: base/CMakeFiles/mal_base.dir/log.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_base.a: base/CMakeFiles/mal_base.dir/build.make
/home/rain/src/muduo/malIO_uring/lib/libmal_base.a: base/CMakeFiles/mal_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library /home/rain/src/muduo/malIO_uring/lib/libmal_base.a"
	cd /home/rain/src/muduo/malIO_uring/build/base && $(CMAKE_COMMAND) -P CMakeFiles/mal_base.dir/cmake_clean_target.cmake
	cd /home/rain/src/muduo/malIO_uring/build/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mal_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/CMakeFiles/mal_base.dir/build: /home/rain/src/muduo/malIO_uring/lib/libmal_base.a
.PHONY : base/CMakeFiles/mal_base.dir/build

base/CMakeFiles/mal_base.dir/clean:
	cd /home/rain/src/muduo/malIO_uring/build/base && $(CMAKE_COMMAND) -P CMakeFiles/mal_base.dir/cmake_clean.cmake
.PHONY : base/CMakeFiles/mal_base.dir/clean

base/CMakeFiles/mal_base.dir/depend:
	cd /home/rain/src/muduo/malIO_uring/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rain/src/muduo/malIO_uring /home/rain/src/muduo/malIO_uring/base /home/rain/src/muduo/malIO_uring/build /home/rain/src/muduo/malIO_uring/build/base /home/rain/src/muduo/malIO_uring/build/base/CMakeFiles/mal_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/CMakeFiles/mal_base.dir/depend

