# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Minesweeper.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Minesweeper.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Minesweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Minesweeper.dir/flags.make

CMakeFiles/Minesweeper.dir/main.cpp.o: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/main.cpp.o: /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/main.cpp
CMakeFiles/Minesweeper.dir/main.cpp.o: CMakeFiles/Minesweeper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Minesweeper.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Minesweeper.dir/main.cpp.o -MF CMakeFiles/Minesweeper.dir/main.cpp.o.d -o CMakeFiles/Minesweeper.dir/main.cpp.o -c /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/main.cpp

CMakeFiles/Minesweeper.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/main.cpp > CMakeFiles/Minesweeper.dir/main.cpp.i

CMakeFiles/Minesweeper.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/main.cpp -o CMakeFiles/Minesweeper.dir/main.cpp.s

CMakeFiles/Minesweeper.dir/Random.cpp.o: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/Random.cpp.o: /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Random.cpp
CMakeFiles/Minesweeper.dir/Random.cpp.o: CMakeFiles/Minesweeper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Minesweeper.dir/Random.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Minesweeper.dir/Random.cpp.o -MF CMakeFiles/Minesweeper.dir/Random.cpp.o.d -o CMakeFiles/Minesweeper.dir/Random.cpp.o -c /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Random.cpp

CMakeFiles/Minesweeper.dir/Random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/Random.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Random.cpp > CMakeFiles/Minesweeper.dir/Random.cpp.i

CMakeFiles/Minesweeper.dir/Random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/Random.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Random.cpp -o CMakeFiles/Minesweeper.dir/Random.cpp.s

CMakeFiles/Minesweeper.dir/TextureManager.cpp.o: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/TextureManager.cpp.o: /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/TextureManager.cpp
CMakeFiles/Minesweeper.dir/TextureManager.cpp.o: CMakeFiles/Minesweeper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Minesweeper.dir/TextureManager.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Minesweeper.dir/TextureManager.cpp.o -MF CMakeFiles/Minesweeper.dir/TextureManager.cpp.o.d -o CMakeFiles/Minesweeper.dir/TextureManager.cpp.o -c /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/TextureManager.cpp

CMakeFiles/Minesweeper.dir/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/TextureManager.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/TextureManager.cpp > CMakeFiles/Minesweeper.dir/TextureManager.cpp.i

CMakeFiles/Minesweeper.dir/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/TextureManager.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/TextureManager.cpp -o CMakeFiles/Minesweeper.dir/TextureManager.cpp.s

CMakeFiles/Minesweeper.dir/Board.cpp.o: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/Board.cpp.o: /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Board.cpp
CMakeFiles/Minesweeper.dir/Board.cpp.o: CMakeFiles/Minesweeper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Minesweeper.dir/Board.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Minesweeper.dir/Board.cpp.o -MF CMakeFiles/Minesweeper.dir/Board.cpp.o.d -o CMakeFiles/Minesweeper.dir/Board.cpp.o -c /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Board.cpp

CMakeFiles/Minesweeper.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/Board.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Board.cpp > CMakeFiles/Minesweeper.dir/Board.cpp.i

CMakeFiles/Minesweeper.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/Board.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Board.cpp -o CMakeFiles/Minesweeper.dir/Board.cpp.s

CMakeFiles/Minesweeper.dir/Tile.cpp.o: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/Tile.cpp.o: /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Tile.cpp
CMakeFiles/Minesweeper.dir/Tile.cpp.o: CMakeFiles/Minesweeper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Minesweeper.dir/Tile.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Minesweeper.dir/Tile.cpp.o -MF CMakeFiles/Minesweeper.dir/Tile.cpp.o.d -o CMakeFiles/Minesweeper.dir/Tile.cpp.o -c /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Tile.cpp

CMakeFiles/Minesweeper.dir/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/Tile.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Tile.cpp > CMakeFiles/Minesweeper.dir/Tile.cpp.i

CMakeFiles/Minesweeper.dir/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/Tile.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Tile.cpp -o CMakeFiles/Minesweeper.dir/Tile.cpp.s

CMakeFiles/Minesweeper.dir/Window.cpp.o: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/Window.cpp.o: /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Window.cpp
CMakeFiles/Minesweeper.dir/Window.cpp.o: CMakeFiles/Minesweeper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Minesweeper.dir/Window.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Minesweeper.dir/Window.cpp.o -MF CMakeFiles/Minesweeper.dir/Window.cpp.o.d -o CMakeFiles/Minesweeper.dir/Window.cpp.o -c /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Window.cpp

CMakeFiles/Minesweeper.dir/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/Window.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Window.cpp > CMakeFiles/Minesweeper.dir/Window.cpp.i

CMakeFiles/Minesweeper.dir/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/Window.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Window.cpp -o CMakeFiles/Minesweeper.dir/Window.cpp.s

CMakeFiles/Minesweeper.dir/Worker.cpp.o: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/Worker.cpp.o: /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Worker.cpp
CMakeFiles/Minesweeper.dir/Worker.cpp.o: CMakeFiles/Minesweeper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Minesweeper.dir/Worker.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Minesweeper.dir/Worker.cpp.o -MF CMakeFiles/Minesweeper.dir/Worker.cpp.o.d -o CMakeFiles/Minesweeper.dir/Worker.cpp.o -c /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Worker.cpp

CMakeFiles/Minesweeper.dir/Worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/Worker.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Worker.cpp > CMakeFiles/Minesweeper.dir/Worker.cpp.i

CMakeFiles/Minesweeper.dir/Worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/Worker.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/Worker.cpp -o CMakeFiles/Minesweeper.dir/Worker.cpp.s

# Object files for target Minesweeper
Minesweeper_OBJECTS = \
"CMakeFiles/Minesweeper.dir/main.cpp.o" \
"CMakeFiles/Minesweeper.dir/Random.cpp.o" \
"CMakeFiles/Minesweeper.dir/TextureManager.cpp.o" \
"CMakeFiles/Minesweeper.dir/Board.cpp.o" \
"CMakeFiles/Minesweeper.dir/Tile.cpp.o" \
"CMakeFiles/Minesweeper.dir/Window.cpp.o" \
"CMakeFiles/Minesweeper.dir/Worker.cpp.o"

# External object files for target Minesweeper
Minesweeper_EXTERNAL_OBJECTS =

Minesweeper: CMakeFiles/Minesweeper.dir/main.cpp.o
Minesweeper: CMakeFiles/Minesweeper.dir/Random.cpp.o
Minesweeper: CMakeFiles/Minesweeper.dir/TextureManager.cpp.o
Minesweeper: CMakeFiles/Minesweeper.dir/Board.cpp.o
Minesweeper: CMakeFiles/Minesweeper.dir/Tile.cpp.o
Minesweeper: CMakeFiles/Minesweeper.dir/Window.cpp.o
Minesweeper: CMakeFiles/Minesweeper.dir/Worker.cpp.o
Minesweeper: CMakeFiles/Minesweeper.dir/build.make
Minesweeper: /opt/homebrew/lib/libsfml-graphics.2.6.2.dylib
Minesweeper: /opt/homebrew/lib/libsfml-audio.2.6.2.dylib
Minesweeper: /opt/homebrew/lib/libsfml-network.2.6.2.dylib
Minesweeper: /opt/homebrew/lib/libsfml-window.2.6.2.dylib
Minesweeper: /opt/homebrew/lib/libsfml-system.2.6.2.dylib
Minesweeper: CMakeFiles/Minesweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Minesweeper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Minesweeper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Minesweeper.dir/build: Minesweeper
.PHONY : CMakeFiles/Minesweeper.dir/build

CMakeFiles/Minesweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Minesweeper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Minesweeper.dir/clean

CMakeFiles/Minesweeper.dir/depend:
	cd /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug /Users/bharri503@cable.comcast.com/Project_Minesweeper/Minesweeper/cmake-build-debug/CMakeFiles/Minesweeper.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Minesweeper.dir/depend

