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
CMAKE_COMMAND = /home/samuel/Descargas/clion-2018.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/samuel/Descargas/clion-2018.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samuel/CLionProjects/sfml

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samuel/CLionProjects/sfml/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MySFML.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MySFML.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MySFML.dir/flags.make

CMakeFiles/MySFML.dir/main.cpp.o: CMakeFiles/MySFML.dir/flags.make
CMakeFiles/MySFML.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/CLionProjects/sfml/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MySFML.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MySFML.dir/main.cpp.o -c /home/samuel/CLionProjects/sfml/main.cpp

CMakeFiles/MySFML.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MySFML.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/CLionProjects/sfml/main.cpp > CMakeFiles/MySFML.dir/main.cpp.i

CMakeFiles/MySFML.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MySFML.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/CLionProjects/sfml/main.cpp -o CMakeFiles/MySFML.dir/main.cpp.s

CMakeFiles/MySFML.dir/window.cpp.o: CMakeFiles/MySFML.dir/flags.make
CMakeFiles/MySFML.dir/window.cpp.o: ../window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/CLionProjects/sfml/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MySFML.dir/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MySFML.dir/window.cpp.o -c /home/samuel/CLionProjects/sfml/window.cpp

CMakeFiles/MySFML.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MySFML.dir/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/CLionProjects/sfml/window.cpp > CMakeFiles/MySFML.dir/window.cpp.i

CMakeFiles/MySFML.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MySFML.dir/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/CLionProjects/sfml/window.cpp -o CMakeFiles/MySFML.dir/window.cpp.s

CMakeFiles/MySFML.dir/soldado.cpp.o: CMakeFiles/MySFML.dir/flags.make
CMakeFiles/MySFML.dir/soldado.cpp.o: ../soldado.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/CLionProjects/sfml/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MySFML.dir/soldado.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MySFML.dir/soldado.cpp.o -c /home/samuel/CLionProjects/sfml/soldado.cpp

CMakeFiles/MySFML.dir/soldado.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MySFML.dir/soldado.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/CLionProjects/sfml/soldado.cpp > CMakeFiles/MySFML.dir/soldado.cpp.i

CMakeFiles/MySFML.dir/soldado.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MySFML.dir/soldado.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/CLionProjects/sfml/soldado.cpp -o CMakeFiles/MySFML.dir/soldado.cpp.s

CMakeFiles/MySFML.dir/Enemigo.cpp.o: CMakeFiles/MySFML.dir/flags.make
CMakeFiles/MySFML.dir/Enemigo.cpp.o: ../Enemigo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/CLionProjects/sfml/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MySFML.dir/Enemigo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MySFML.dir/Enemigo.cpp.o -c /home/samuel/CLionProjects/sfml/Enemigo.cpp

CMakeFiles/MySFML.dir/Enemigo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MySFML.dir/Enemigo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samuel/CLionProjects/sfml/Enemigo.cpp > CMakeFiles/MySFML.dir/Enemigo.cpp.i

CMakeFiles/MySFML.dir/Enemigo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MySFML.dir/Enemigo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samuel/CLionProjects/sfml/Enemigo.cpp -o CMakeFiles/MySFML.dir/Enemigo.cpp.s

# Object files for target MySFML
MySFML_OBJECTS = \
"CMakeFiles/MySFML.dir/main.cpp.o" \
"CMakeFiles/MySFML.dir/window.cpp.o" \
"CMakeFiles/MySFML.dir/soldado.cpp.o" \
"CMakeFiles/MySFML.dir/Enemigo.cpp.o"

# External object files for target MySFML
MySFML_EXTERNAL_OBJECTS =

MySFML: CMakeFiles/MySFML.dir/main.cpp.o
MySFML: CMakeFiles/MySFML.dir/window.cpp.o
MySFML: CMakeFiles/MySFML.dir/soldado.cpp.o
MySFML: CMakeFiles/MySFML.dir/Enemigo.cpp.o
MySFML: CMakeFiles/MySFML.dir/build.make
MySFML: /usr/lib/x86_64-linux-gnu/libsfml-system.so
MySFML: /usr/lib/x86_64-linux-gnu/libsfml-window.so
MySFML: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
MySFML: /usr/lib/x86_64-linux-gnu/libsfml-network.so
MySFML: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
MySFML: CMakeFiles/MySFML.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samuel/CLionProjects/sfml/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable MySFML"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MySFML.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MySFML.dir/build: MySFML

.PHONY : CMakeFiles/MySFML.dir/build

CMakeFiles/MySFML.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MySFML.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MySFML.dir/clean

CMakeFiles/MySFML.dir/depend:
	cd /home/samuel/CLionProjects/sfml/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samuel/CLionProjects/sfml /home/samuel/CLionProjects/sfml /home/samuel/CLionProjects/sfml/cmake-build-debug /home/samuel/CLionProjects/sfml/cmake-build-debug /home/samuel/CLionProjects/sfml/cmake-build-debug/CMakeFiles/MySFML.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MySFML.dir/depend

