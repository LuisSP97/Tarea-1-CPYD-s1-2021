# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\cmake-build-relwithdebinfo

# Include any dependencies generated for this target.
include CMakeFiles/Codigo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Codigo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Codigo.dir/flags.make

CMakeFiles/Codigo.dir/main.cpp.obj: CMakeFiles/Codigo.dir/flags.make
CMakeFiles/Codigo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Codigo.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Codigo.dir\main.cpp.obj -c C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\main.cpp

CMakeFiles/Codigo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Codigo.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\main.cpp > CMakeFiles\Codigo.dir\main.cpp.i

CMakeFiles/Codigo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Codigo.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\main.cpp -o CMakeFiles\Codigo.dir\main.cpp.s

CMakeFiles/Codigo.dir/estudiante.cpp.obj: CMakeFiles/Codigo.dir/flags.make
CMakeFiles/Codigo.dir/estudiante.cpp.obj: ../estudiante.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Codigo.dir/estudiante.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Codigo.dir\estudiante.cpp.obj -c C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\estudiante.cpp

CMakeFiles/Codigo.dir/estudiante.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Codigo.dir/estudiante.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\estudiante.cpp > CMakeFiles\Codigo.dir\estudiante.cpp.i

CMakeFiles/Codigo.dir/estudiante.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Codigo.dir/estudiante.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\estudiante.cpp -o CMakeFiles\Codigo.dir\estudiante.cpp.s

# Object files for target Codigo
Codigo_OBJECTS = \
"CMakeFiles/Codigo.dir/main.cpp.obj" \
"CMakeFiles/Codigo.dir/estudiante.cpp.obj"

# External object files for target Codigo
Codigo_EXTERNAL_OBJECTS =

Codigo.exe: CMakeFiles/Codigo.dir/main.cpp.obj
Codigo.exe: CMakeFiles/Codigo.dir/estudiante.cpp.obj
Codigo.exe: CMakeFiles/Codigo.dir/build.make
Codigo.exe: CMakeFiles/Codigo.dir/linklibs.rsp
Codigo.exe: CMakeFiles/Codigo.dir/objects1.rsp
Codigo.exe: CMakeFiles/Codigo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Codigo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Codigo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Codigo.dir/build: Codigo.exe

.PHONY : CMakeFiles/Codigo.dir/build

CMakeFiles/Codigo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Codigo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Codigo.dir/clean

CMakeFiles/Codigo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021 C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021 C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\cmake-build-relwithdebinfo C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\cmake-build-relwithdebinfo C:\Users\pika_\Documents\Proyectos\Tarea-1-CPYD-s1-2021\cmake-build-relwithdebinfo\CMakeFiles\Codigo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Codigo.dir/depend

