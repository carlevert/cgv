# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:
.PHONY : .NOTPARALLEL

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dv14/dv14cks/cgv/assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dv14/dv14cks/cgv/assignment

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dv14/dv14cks/cgv/assignment/CMakeFiles /home/dv14/dv14cks/cgv/assignment/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dv14/dv14cks/cgv/assignment/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named 3dstudio

# Build rule for target.
3dstudio: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 3dstudio
.PHONY : 3dstudio

# fast build rule for target.
3dstudio/fast:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/build
.PHONY : 3dstudio/fast

AppWrap.o: AppWrap.cpp.o
.PHONY : AppWrap.o

# target to build an object file
AppWrap.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/AppWrap.cpp.o
.PHONY : AppWrap.cpp.o

AppWrap.i: AppWrap.cpp.i
.PHONY : AppWrap.i

# target to preprocess a source file
AppWrap.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/AppWrap.cpp.i
.PHONY : AppWrap.cpp.i

AppWrap.s: AppWrap.cpp.s
.PHONY : AppWrap.s

# target to generate assembly for a file
AppWrap.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/AppWrap.cpp.s
.PHONY : AppWrap.cpp.s

Application.o: Application.cpp.o
.PHONY : Application.o

# target to build an object file
Application.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Application.cpp.o
.PHONY : Application.cpp.o

Application.i: Application.cpp.i
.PHONY : Application.i

# target to preprocess a source file
Application.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Application.cpp.i
.PHONY : Application.cpp.i

Application.s: Application.cpp.s
.PHONY : Application.s

# target to generate assembly for a file
Application.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Application.cpp.s
.PHONY : Application.cpp.s

Camera.o: Camera.cpp.o
.PHONY : Camera.o

# target to build an object file
Camera.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Camera.cpp.o
.PHONY : Camera.cpp.o

Camera.i: Camera.cpp.i
.PHONY : Camera.i

# target to preprocess a source file
Camera.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Camera.cpp.i
.PHONY : Camera.cpp.i

Camera.s: Camera.cpp.s
.PHONY : Camera.s

# target to generate assembly for a file
Camera.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Camera.cpp.s
.PHONY : Camera.cpp.s

Face.o: Face.cpp.o
.PHONY : Face.o

# target to build an object file
Face.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Face.cpp.o
.PHONY : Face.cpp.o

Face.i: Face.cpp.i
.PHONY : Face.i

# target to preprocess a source file
Face.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Face.cpp.i
.PHONY : Face.cpp.i

Face.s: Face.cpp.s
.PHONY : Face.s

# target to generate assembly for a file
Face.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Face.cpp.s
.PHONY : Face.cpp.s

LineReader.o: LineReader.cpp.o
.PHONY : LineReader.o

# target to build an object file
LineReader.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/LineReader.cpp.o
.PHONY : LineReader.cpp.o

LineReader.i: LineReader.cpp.i
.PHONY : LineReader.i

# target to preprocess a source file
LineReader.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/LineReader.cpp.i
.PHONY : LineReader.cpp.i

LineReader.s: LineReader.cpp.s
.PHONY : LineReader.s

# target to generate assembly for a file
LineReader.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/LineReader.cpp.s
.PHONY : LineReader.cpp.s

Model.o: Model.cpp.o
.PHONY : Model.o

# target to build an object file
Model.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Model.cpp.o
.PHONY : Model.cpp.o

Model.i: Model.cpp.i
.PHONY : Model.i

# target to preprocess a source file
Model.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Model.cpp.i
.PHONY : Model.cpp.i

Model.s: Model.cpp.s
.PHONY : Model.s

# target to generate assembly for a file
Model.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Model.cpp.s
.PHONY : Model.cpp.s

Object.o: Object.cpp.o
.PHONY : Object.o

# target to build an object file
Object.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Object.cpp.o
.PHONY : Object.cpp.o

Object.i: Object.cpp.i
.PHONY : Object.i

# target to preprocess a source file
Object.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Object.cpp.i
.PHONY : Object.cpp.i

Object.s: Object.cpp.s
.PHONY : Object.s

# target to generate assembly for a file
Object.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Object.cpp.s
.PHONY : Object.cpp.s

OffParser.o: OffParser.cpp.o
.PHONY : OffParser.o

# target to build an object file
OffParser.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/OffParser.cpp.o
.PHONY : OffParser.cpp.o

OffParser.i: OffParser.cpp.i
.PHONY : OffParser.i

# target to preprocess a source file
OffParser.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/OffParser.cpp.i
.PHONY : OffParser.cpp.i

OffParser.s: OffParser.cpp.s
.PHONY : OffParser.s

# target to generate assembly for a file
OffParser.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/OffParser.cpp.s
.PHONY : OffParser.cpp.s

PrintMatrix.o: PrintMatrix.cpp.o
.PHONY : PrintMatrix.o

# target to build an object file
PrintMatrix.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/PrintMatrix.cpp.o
.PHONY : PrintMatrix.cpp.o

PrintMatrix.i: PrintMatrix.cpp.i
.PHONY : PrintMatrix.i

# target to preprocess a source file
PrintMatrix.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/PrintMatrix.cpp.i
.PHONY : PrintMatrix.cpp.i

PrintMatrix.s: PrintMatrix.cpp.s
.PHONY : PrintMatrix.s

# target to generate assembly for a file
PrintMatrix.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/PrintMatrix.cpp.s
.PHONY : PrintMatrix.cpp.s

ProgramObject.o: ProgramObject.cpp.o
.PHONY : ProgramObject.o

# target to build an object file
ProgramObject.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/ProgramObject.cpp.o
.PHONY : ProgramObject.cpp.o

ProgramObject.i: ProgramObject.cpp.i
.PHONY : ProgramObject.i

# target to preprocess a source file
ProgramObject.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/ProgramObject.cpp.i
.PHONY : ProgramObject.cpp.i

ProgramObject.s: ProgramObject.cpp.s
.PHONY : ProgramObject.s

# target to generate assembly for a file
ProgramObject.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/ProgramObject.cpp.s
.PHONY : ProgramObject.cpp.s

Projection.o: Projection.cpp.o
.PHONY : Projection.o

# target to build an object file
Projection.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Projection.cpp.o
.PHONY : Projection.cpp.o

Projection.i: Projection.cpp.i
.PHONY : Projection.i

# target to preprocess a source file
Projection.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Projection.cpp.i
.PHONY : Projection.cpp.i

Projection.s: Projection.cpp.s
.PHONY : Projection.s

# target to generate assembly for a file
Projection.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Projection.cpp.s
.PHONY : Projection.cpp.s

Shader.o: Shader.cpp.o
.PHONY : Shader.o

# target to build an object file
Shader.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Shader.cpp.o
.PHONY : Shader.cpp.o

Shader.i: Shader.cpp.i
.PHONY : Shader.i

# target to preprocess a source file
Shader.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Shader.cpp.i
.PHONY : Shader.cpp.i

Shader.s: Shader.cpp.s
.PHONY : Shader.s

# target to generate assembly for a file
Shader.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/Shader.cpp.s
.PHONY : Shader.cpp.s

ass2gui.o: ass2gui.c.o
.PHONY : ass2gui.o

# target to build an object file
ass2gui.c.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/ass2gui.c.o
.PHONY : ass2gui.c.o

ass2gui.i: ass2gui.c.i
.PHONY : ass2gui.i

# target to preprocess a source file
ass2gui.c.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/ass2gui.c.i
.PHONY : ass2gui.c.i

ass2gui.s: ass2gui.c.s
.PHONY : ass2gui.s

# target to generate assembly for a file
ass2gui.c.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/ass2gui.c.s
.PHONY : ass2gui.c.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/3dstudio.dir/build.make CMakeFiles/3dstudio.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... 3dstudio"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... AppWrap.o"
	@echo "... AppWrap.i"
	@echo "... AppWrap.s"
	@echo "... Application.o"
	@echo "... Application.i"
	@echo "... Application.s"
	@echo "... Camera.o"
	@echo "... Camera.i"
	@echo "... Camera.s"
	@echo "... Face.o"
	@echo "... Face.i"
	@echo "... Face.s"
	@echo "... LineReader.o"
	@echo "... LineReader.i"
	@echo "... LineReader.s"
	@echo "... Model.o"
	@echo "... Model.i"
	@echo "... Model.s"
	@echo "... Object.o"
	@echo "... Object.i"
	@echo "... Object.s"
	@echo "... OffParser.o"
	@echo "... OffParser.i"
	@echo "... OffParser.s"
	@echo "... PrintMatrix.o"
	@echo "... PrintMatrix.i"
	@echo "... PrintMatrix.s"
	@echo "... ProgramObject.o"
	@echo "... ProgramObject.i"
	@echo "... ProgramObject.s"
	@echo "... Projection.o"
	@echo "... Projection.i"
	@echo "... Projection.s"
	@echo "... Shader.o"
	@echo "... Shader.i"
	@echo "... Shader.s"
	@echo "... ass2gui.o"
	@echo "... ass2gui.i"
	@echo "... ass2gui.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
