# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chivora_cisco_mac/CLionProjects/NourishClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NourishClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NourishClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NourishClient.dir/flags.make

CMakeFiles/NourishClient.dir/main.cpp.o: CMakeFiles/NourishClient.dir/flags.make
CMakeFiles/NourishClient.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NourishClient.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NourishClient.dir/main.cpp.o -c /Users/chivora_cisco_mac/CLionProjects/NourishClient/main.cpp

CMakeFiles/NourishClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NourishClient.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chivora_cisco_mac/CLionProjects/NourishClient/main.cpp > CMakeFiles/NourishClient.dir/main.cpp.i

CMakeFiles/NourishClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NourishClient.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chivora_cisco_mac/CLionProjects/NourishClient/main.cpp -o CMakeFiles/NourishClient.dir/main.cpp.s

CMakeFiles/NourishClient.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/NourishClient.dir/main.cpp.o.requires

CMakeFiles/NourishClient.dir/main.cpp.o.provides: CMakeFiles/NourishClient.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/NourishClient.dir/build.make CMakeFiles/NourishClient.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/NourishClient.dir/main.cpp.o.provides

CMakeFiles/NourishClient.dir/main.cpp.o.provides.build: CMakeFiles/NourishClient.dir/main.cpp.o


CMakeFiles/NourishClient.dir/Client.cpp.o: CMakeFiles/NourishClient.dir/flags.make
CMakeFiles/NourishClient.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NourishClient.dir/Client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NourishClient.dir/Client.cpp.o -c /Users/chivora_cisco_mac/CLionProjects/NourishClient/Client.cpp

CMakeFiles/NourishClient.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NourishClient.dir/Client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chivora_cisco_mac/CLionProjects/NourishClient/Client.cpp > CMakeFiles/NourishClient.dir/Client.cpp.i

CMakeFiles/NourishClient.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NourishClient.dir/Client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chivora_cisco_mac/CLionProjects/NourishClient/Client.cpp -o CMakeFiles/NourishClient.dir/Client.cpp.s

CMakeFiles/NourishClient.dir/Client.cpp.o.requires:

.PHONY : CMakeFiles/NourishClient.dir/Client.cpp.o.requires

CMakeFiles/NourishClient.dir/Client.cpp.o.provides: CMakeFiles/NourishClient.dir/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/NourishClient.dir/build.make CMakeFiles/NourishClient.dir/Client.cpp.o.provides.build
.PHONY : CMakeFiles/NourishClient.dir/Client.cpp.o.provides

CMakeFiles/NourishClient.dir/Client.cpp.o.provides.build: CMakeFiles/NourishClient.dir/Client.cpp.o


CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o: CMakeFiles/NourishClient.dir/flags.make
CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o: ../ProtocolMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o -c /Users/chivora_cisco_mac/CLionProjects/NourishClient/ProtocolMessage.cpp

CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chivora_cisco_mac/CLionProjects/NourishClient/ProtocolMessage.cpp > CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.i

CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chivora_cisco_mac/CLionProjects/NourishClient/ProtocolMessage.cpp -o CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.s

CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o.requires:

.PHONY : CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o.requires

CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o.provides: CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o.requires
	$(MAKE) -f CMakeFiles/NourishClient.dir/build.make CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o.provides.build
.PHONY : CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o.provides

CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o.provides.build: CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o


CMakeFiles/NourishClient.dir/MyThread.cpp.o: CMakeFiles/NourishClient.dir/flags.make
CMakeFiles/NourishClient.dir/MyThread.cpp.o: ../MyThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NourishClient.dir/MyThread.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NourishClient.dir/MyThread.cpp.o -c /Users/chivora_cisco_mac/CLionProjects/NourishClient/MyThread.cpp

CMakeFiles/NourishClient.dir/MyThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NourishClient.dir/MyThread.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chivora_cisco_mac/CLionProjects/NourishClient/MyThread.cpp > CMakeFiles/NourishClient.dir/MyThread.cpp.i

CMakeFiles/NourishClient.dir/MyThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NourishClient.dir/MyThread.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chivora_cisco_mac/CLionProjects/NourishClient/MyThread.cpp -o CMakeFiles/NourishClient.dir/MyThread.cpp.s

CMakeFiles/NourishClient.dir/MyThread.cpp.o.requires:

.PHONY : CMakeFiles/NourishClient.dir/MyThread.cpp.o.requires

CMakeFiles/NourishClient.dir/MyThread.cpp.o.provides: CMakeFiles/NourishClient.dir/MyThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/NourishClient.dir/build.make CMakeFiles/NourishClient.dir/MyThread.cpp.o.provides.build
.PHONY : CMakeFiles/NourishClient.dir/MyThread.cpp.o.provides

CMakeFiles/NourishClient.dir/MyThread.cpp.o.provides.build: CMakeFiles/NourishClient.dir/MyThread.cpp.o


# Object files for target NourishClient
NourishClient_OBJECTS = \
"CMakeFiles/NourishClient.dir/main.cpp.o" \
"CMakeFiles/NourishClient.dir/Client.cpp.o" \
"CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o" \
"CMakeFiles/NourishClient.dir/MyThread.cpp.o"

# External object files for target NourishClient
NourishClient_EXTERNAL_OBJECTS =

NourishClient: CMakeFiles/NourishClient.dir/main.cpp.o
NourishClient: CMakeFiles/NourishClient.dir/Client.cpp.o
NourishClient: CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o
NourishClient: CMakeFiles/NourishClient.dir/MyThread.cpp.o
NourishClient: CMakeFiles/NourishClient.dir/build.make
NourishClient: CMakeFiles/NourishClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable NourishClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NourishClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NourishClient.dir/build: NourishClient

.PHONY : CMakeFiles/NourishClient.dir/build

CMakeFiles/NourishClient.dir/requires: CMakeFiles/NourishClient.dir/main.cpp.o.requires
CMakeFiles/NourishClient.dir/requires: CMakeFiles/NourishClient.dir/Client.cpp.o.requires
CMakeFiles/NourishClient.dir/requires: CMakeFiles/NourishClient.dir/ProtocolMessage.cpp.o.requires
CMakeFiles/NourishClient.dir/requires: CMakeFiles/NourishClient.dir/MyThread.cpp.o.requires

.PHONY : CMakeFiles/NourishClient.dir/requires

CMakeFiles/NourishClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NourishClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NourishClient.dir/clean

CMakeFiles/NourishClient.dir/depend:
	cd /Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chivora_cisco_mac/CLionProjects/NourishClient /Users/chivora_cisco_mac/CLionProjects/NourishClient /Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug /Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug /Users/chivora_cisco_mac/CLionProjects/NourishClient/cmake-build-debug/CMakeFiles/NourishClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NourishClient.dir/depend

