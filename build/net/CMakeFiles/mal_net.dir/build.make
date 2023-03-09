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
include net/CMakeFiles/mal_net.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include net/CMakeFiles/mal_net.dir/compiler_depend.make

# Include the progress variables for this target.
include net/CMakeFiles/mal_net.dir/progress.make

# Include the compile flags for this target's objects.
include net/CMakeFiles/mal_net.dir/flags.make

net/CMakeFiles/mal_net.dir/EventLoop.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/EventLoop.cpp.o: /home/rain/src/muduo/malIO_uring/net/EventLoop.cpp
net/CMakeFiles/mal_net.dir/EventLoop.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object net/CMakeFiles/mal_net.dir/EventLoop.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/EventLoop.cpp.o -MF CMakeFiles/mal_net.dir/EventLoop.cpp.o.d -o CMakeFiles/mal_net.dir/EventLoop.cpp.o -c /home/rain/src/muduo/malIO_uring/net/EventLoop.cpp

net/CMakeFiles/mal_net.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/EventLoop.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/EventLoop.cpp > CMakeFiles/mal_net.dir/EventLoop.cpp.i

net/CMakeFiles/mal_net.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/EventLoop.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/EventLoop.cpp -o CMakeFiles/mal_net.dir/EventLoop.cpp.s

net/CMakeFiles/mal_net.dir/Channel.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/Channel.cpp.o: /home/rain/src/muduo/malIO_uring/net/Channel.cpp
net/CMakeFiles/mal_net.dir/Channel.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object net/CMakeFiles/mal_net.dir/Channel.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/Channel.cpp.o -MF CMakeFiles/mal_net.dir/Channel.cpp.o.d -o CMakeFiles/mal_net.dir/Channel.cpp.o -c /home/rain/src/muduo/malIO_uring/net/Channel.cpp

net/CMakeFiles/mal_net.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/Channel.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/Channel.cpp > CMakeFiles/mal_net.dir/Channel.cpp.i

net/CMakeFiles/mal_net.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/Channel.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/Channel.cpp -o CMakeFiles/mal_net.dir/Channel.cpp.s

net/CMakeFiles/mal_net.dir/Poller.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/Poller.cpp.o: /home/rain/src/muduo/malIO_uring/net/Poller.cpp
net/CMakeFiles/mal_net.dir/Poller.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object net/CMakeFiles/mal_net.dir/Poller.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/Poller.cpp.o -MF CMakeFiles/mal_net.dir/Poller.cpp.o.d -o CMakeFiles/mal_net.dir/Poller.cpp.o -c /home/rain/src/muduo/malIO_uring/net/Poller.cpp

net/CMakeFiles/mal_net.dir/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/Poller.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/Poller.cpp > CMakeFiles/mal_net.dir/Poller.cpp.i

net/CMakeFiles/mal_net.dir/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/Poller.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/Poller.cpp -o CMakeFiles/mal_net.dir/Poller.cpp.s

net/CMakeFiles/mal_net.dir/TimerQueue.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/TimerQueue.cpp.o: /home/rain/src/muduo/malIO_uring/net/TimerQueue.cpp
net/CMakeFiles/mal_net.dir/TimerQueue.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object net/CMakeFiles/mal_net.dir/TimerQueue.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/TimerQueue.cpp.o -MF CMakeFiles/mal_net.dir/TimerQueue.cpp.o.d -o CMakeFiles/mal_net.dir/TimerQueue.cpp.o -c /home/rain/src/muduo/malIO_uring/net/TimerQueue.cpp

net/CMakeFiles/mal_net.dir/TimerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/TimerQueue.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/TimerQueue.cpp > CMakeFiles/mal_net.dir/TimerQueue.cpp.i

net/CMakeFiles/mal_net.dir/TimerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/TimerQueue.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/TimerQueue.cpp -o CMakeFiles/mal_net.dir/TimerQueue.cpp.s

net/CMakeFiles/mal_net.dir/EventLoopThread.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/EventLoopThread.cpp.o: /home/rain/src/muduo/malIO_uring/net/EventLoopThread.cpp
net/CMakeFiles/mal_net.dir/EventLoopThread.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object net/CMakeFiles/mal_net.dir/EventLoopThread.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/EventLoopThread.cpp.o -MF CMakeFiles/mal_net.dir/EventLoopThread.cpp.o.d -o CMakeFiles/mal_net.dir/EventLoopThread.cpp.o -c /home/rain/src/muduo/malIO_uring/net/EventLoopThread.cpp

net/CMakeFiles/mal_net.dir/EventLoopThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/EventLoopThread.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/EventLoopThread.cpp > CMakeFiles/mal_net.dir/EventLoopThread.cpp.i

net/CMakeFiles/mal_net.dir/EventLoopThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/EventLoopThread.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/EventLoopThread.cpp -o CMakeFiles/mal_net.dir/EventLoopThread.cpp.s

net/CMakeFiles/mal_net.dir/InetAddress.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/InetAddress.cpp.o: /home/rain/src/muduo/malIO_uring/net/InetAddress.cpp
net/CMakeFiles/mal_net.dir/InetAddress.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object net/CMakeFiles/mal_net.dir/InetAddress.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/InetAddress.cpp.o -MF CMakeFiles/mal_net.dir/InetAddress.cpp.o.d -o CMakeFiles/mal_net.dir/InetAddress.cpp.o -c /home/rain/src/muduo/malIO_uring/net/InetAddress.cpp

net/CMakeFiles/mal_net.dir/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/InetAddress.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/InetAddress.cpp > CMakeFiles/mal_net.dir/InetAddress.cpp.i

net/CMakeFiles/mal_net.dir/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/InetAddress.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/InetAddress.cpp -o CMakeFiles/mal_net.dir/InetAddress.cpp.s

net/CMakeFiles/mal_net.dir/Acceptor.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/Acceptor.cpp.o: /home/rain/src/muduo/malIO_uring/net/Acceptor.cpp
net/CMakeFiles/mal_net.dir/Acceptor.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object net/CMakeFiles/mal_net.dir/Acceptor.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/Acceptor.cpp.o -MF CMakeFiles/mal_net.dir/Acceptor.cpp.o.d -o CMakeFiles/mal_net.dir/Acceptor.cpp.o -c /home/rain/src/muduo/malIO_uring/net/Acceptor.cpp

net/CMakeFiles/mal_net.dir/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/Acceptor.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/Acceptor.cpp > CMakeFiles/mal_net.dir/Acceptor.cpp.i

net/CMakeFiles/mal_net.dir/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/Acceptor.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/Acceptor.cpp -o CMakeFiles/mal_net.dir/Acceptor.cpp.s

net/CMakeFiles/mal_net.dir/Socket.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/Socket.cpp.o: /home/rain/src/muduo/malIO_uring/net/Socket.cpp
net/CMakeFiles/mal_net.dir/Socket.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object net/CMakeFiles/mal_net.dir/Socket.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/Socket.cpp.o -MF CMakeFiles/mal_net.dir/Socket.cpp.o.d -o CMakeFiles/mal_net.dir/Socket.cpp.o -c /home/rain/src/muduo/malIO_uring/net/Socket.cpp

net/CMakeFiles/mal_net.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/Socket.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/Socket.cpp > CMakeFiles/mal_net.dir/Socket.cpp.i

net/CMakeFiles/mal_net.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/Socket.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/Socket.cpp -o CMakeFiles/mal_net.dir/Socket.cpp.s

net/CMakeFiles/mal_net.dir/TcpServer.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/TcpServer.cpp.o: /home/rain/src/muduo/malIO_uring/net/TcpServer.cpp
net/CMakeFiles/mal_net.dir/TcpServer.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object net/CMakeFiles/mal_net.dir/TcpServer.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/TcpServer.cpp.o -MF CMakeFiles/mal_net.dir/TcpServer.cpp.o.d -o CMakeFiles/mal_net.dir/TcpServer.cpp.o -c /home/rain/src/muduo/malIO_uring/net/TcpServer.cpp

net/CMakeFiles/mal_net.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/TcpServer.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/TcpServer.cpp > CMakeFiles/mal_net.dir/TcpServer.cpp.i

net/CMakeFiles/mal_net.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/TcpServer.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/TcpServer.cpp -o CMakeFiles/mal_net.dir/TcpServer.cpp.s

net/CMakeFiles/mal_net.dir/TcpConnection.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/TcpConnection.cpp.o: /home/rain/src/muduo/malIO_uring/net/TcpConnection.cpp
net/CMakeFiles/mal_net.dir/TcpConnection.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object net/CMakeFiles/mal_net.dir/TcpConnection.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/TcpConnection.cpp.o -MF CMakeFiles/mal_net.dir/TcpConnection.cpp.o.d -o CMakeFiles/mal_net.dir/TcpConnection.cpp.o -c /home/rain/src/muduo/malIO_uring/net/TcpConnection.cpp

net/CMakeFiles/mal_net.dir/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/TcpConnection.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/TcpConnection.cpp > CMakeFiles/mal_net.dir/TcpConnection.cpp.i

net/CMakeFiles/mal_net.dir/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/TcpConnection.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/TcpConnection.cpp -o CMakeFiles/mal_net.dir/TcpConnection.cpp.s

net/CMakeFiles/mal_net.dir/SocketsOps.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/SocketsOps.cpp.o: /home/rain/src/muduo/malIO_uring/net/SocketsOps.cpp
net/CMakeFiles/mal_net.dir/SocketsOps.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object net/CMakeFiles/mal_net.dir/SocketsOps.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/SocketsOps.cpp.o -MF CMakeFiles/mal_net.dir/SocketsOps.cpp.o.d -o CMakeFiles/mal_net.dir/SocketsOps.cpp.o -c /home/rain/src/muduo/malIO_uring/net/SocketsOps.cpp

net/CMakeFiles/mal_net.dir/SocketsOps.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/SocketsOps.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/SocketsOps.cpp > CMakeFiles/mal_net.dir/SocketsOps.cpp.i

net/CMakeFiles/mal_net.dir/SocketsOps.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/SocketsOps.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/SocketsOps.cpp -o CMakeFiles/mal_net.dir/SocketsOps.cpp.s

net/CMakeFiles/mal_net.dir/Buffer.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/Buffer.cpp.o: /home/rain/src/muduo/malIO_uring/net/Buffer.cpp
net/CMakeFiles/mal_net.dir/Buffer.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object net/CMakeFiles/mal_net.dir/Buffer.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/Buffer.cpp.o -MF CMakeFiles/mal_net.dir/Buffer.cpp.o.d -o CMakeFiles/mal_net.dir/Buffer.cpp.o -c /home/rain/src/muduo/malIO_uring/net/Buffer.cpp

net/CMakeFiles/mal_net.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/Buffer.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/Buffer.cpp > CMakeFiles/mal_net.dir/Buffer.cpp.i

net/CMakeFiles/mal_net.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/Buffer.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/Buffer.cpp -o CMakeFiles/mal_net.dir/Buffer.cpp.s

net/CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o: /home/rain/src/muduo/malIO_uring/net/IgnoreSigpipe.cpp
net/CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object net/CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o -MF CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o.d -o CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o -c /home/rain/src/muduo/malIO_uring/net/IgnoreSigpipe.cpp

net/CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/IgnoreSigpipe.cpp > CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.i

net/CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/IgnoreSigpipe.cpp -o CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.s

net/CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o: /home/rain/src/muduo/malIO_uring/net/EventLoopThreadPool.cpp
net/CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object net/CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o -MF CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o.d -o CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o -c /home/rain/src/muduo/malIO_uring/net/EventLoopThreadPool.cpp

net/CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/EventLoopThreadPool.cpp > CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.i

net/CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/EventLoopThreadPool.cpp -o CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.s

net/CMakeFiles/mal_net.dir/Connector.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/Connector.cpp.o: /home/rain/src/muduo/malIO_uring/net/Connector.cpp
net/CMakeFiles/mal_net.dir/Connector.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object net/CMakeFiles/mal_net.dir/Connector.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/Connector.cpp.o -MF CMakeFiles/mal_net.dir/Connector.cpp.o.d -o CMakeFiles/mal_net.dir/Connector.cpp.o -c /home/rain/src/muduo/malIO_uring/net/Connector.cpp

net/CMakeFiles/mal_net.dir/Connector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/Connector.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/Connector.cpp > CMakeFiles/mal_net.dir/Connector.cpp.i

net/CMakeFiles/mal_net.dir/Connector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/Connector.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/Connector.cpp -o CMakeFiles/mal_net.dir/Connector.cpp.s

net/CMakeFiles/mal_net.dir/Timer.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/Timer.cpp.o: /home/rain/src/muduo/malIO_uring/net/Timer.cpp
net/CMakeFiles/mal_net.dir/Timer.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object net/CMakeFiles/mal_net.dir/Timer.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/Timer.cpp.o -MF CMakeFiles/mal_net.dir/Timer.cpp.o.d -o CMakeFiles/mal_net.dir/Timer.cpp.o -c /home/rain/src/muduo/malIO_uring/net/Timer.cpp

net/CMakeFiles/mal_net.dir/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/Timer.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/Timer.cpp > CMakeFiles/mal_net.dir/Timer.cpp.i

net/CMakeFiles/mal_net.dir/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/Timer.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/Timer.cpp -o CMakeFiles/mal_net.dir/Timer.cpp.s

net/CMakeFiles/mal_net.dir/Epoller.cpp.o: net/CMakeFiles/mal_net.dir/flags.make
net/CMakeFiles/mal_net.dir/Epoller.cpp.o: /home/rain/src/muduo/malIO_uring/net/Epoller.cpp
net/CMakeFiles/mal_net.dir/Epoller.cpp.o: net/CMakeFiles/mal_net.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object net/CMakeFiles/mal_net.dir/Epoller.cpp.o"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/mal_net.dir/Epoller.cpp.o -MF CMakeFiles/mal_net.dir/Epoller.cpp.o.d -o CMakeFiles/mal_net.dir/Epoller.cpp.o -c /home/rain/src/muduo/malIO_uring/net/Epoller.cpp

net/CMakeFiles/mal_net.dir/Epoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mal_net.dir/Epoller.cpp.i"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rain/src/muduo/malIO_uring/net/Epoller.cpp > CMakeFiles/mal_net.dir/Epoller.cpp.i

net/CMakeFiles/mal_net.dir/Epoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mal_net.dir/Epoller.cpp.s"
	cd /home/rain/src/muduo/malIO_uring/build/net && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rain/src/muduo/malIO_uring/net/Epoller.cpp -o CMakeFiles/mal_net.dir/Epoller.cpp.s

# Object files for target mal_net
mal_net_OBJECTS = \
"CMakeFiles/mal_net.dir/EventLoop.cpp.o" \
"CMakeFiles/mal_net.dir/Channel.cpp.o" \
"CMakeFiles/mal_net.dir/Poller.cpp.o" \
"CMakeFiles/mal_net.dir/TimerQueue.cpp.o" \
"CMakeFiles/mal_net.dir/EventLoopThread.cpp.o" \
"CMakeFiles/mal_net.dir/InetAddress.cpp.o" \
"CMakeFiles/mal_net.dir/Acceptor.cpp.o" \
"CMakeFiles/mal_net.dir/Socket.cpp.o" \
"CMakeFiles/mal_net.dir/TcpServer.cpp.o" \
"CMakeFiles/mal_net.dir/TcpConnection.cpp.o" \
"CMakeFiles/mal_net.dir/SocketsOps.cpp.o" \
"CMakeFiles/mal_net.dir/Buffer.cpp.o" \
"CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o" \
"CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o" \
"CMakeFiles/mal_net.dir/Connector.cpp.o" \
"CMakeFiles/mal_net.dir/Timer.cpp.o" \
"CMakeFiles/mal_net.dir/Epoller.cpp.o"

# External object files for target mal_net
mal_net_EXTERNAL_OBJECTS =

/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/EventLoop.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/Channel.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/Poller.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/TimerQueue.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/EventLoopThread.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/InetAddress.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/Acceptor.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/Socket.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/TcpServer.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/TcpConnection.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/SocketsOps.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/Buffer.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/IgnoreSigpipe.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/EventLoopThreadPool.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/Connector.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/Timer.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/Epoller.cpp.o
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/build.make
/home/rain/src/muduo/malIO_uring/lib/libmal_net.a: net/CMakeFiles/mal_net.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rain/src/muduo/malIO_uring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX static library /home/rain/src/muduo/malIO_uring/lib/libmal_net.a"
	cd /home/rain/src/muduo/malIO_uring/build/net && $(CMAKE_COMMAND) -P CMakeFiles/mal_net.dir/cmake_clean_target.cmake
	cd /home/rain/src/muduo/malIO_uring/build/net && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mal_net.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
net/CMakeFiles/mal_net.dir/build: /home/rain/src/muduo/malIO_uring/lib/libmal_net.a
.PHONY : net/CMakeFiles/mal_net.dir/build

net/CMakeFiles/mal_net.dir/clean:
	cd /home/rain/src/muduo/malIO_uring/build/net && $(CMAKE_COMMAND) -P CMakeFiles/mal_net.dir/cmake_clean.cmake
.PHONY : net/CMakeFiles/mal_net.dir/clean

net/CMakeFiles/mal_net.dir/depend:
	cd /home/rain/src/muduo/malIO_uring/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rain/src/muduo/malIO_uring /home/rain/src/muduo/malIO_uring/net /home/rain/src/muduo/malIO_uring/build /home/rain/src/muduo/malIO_uring/build/net /home/rain/src/muduo/malIO_uring/build/net/CMakeFiles/mal_net.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : net/CMakeFiles/mal_net.dir/depend

