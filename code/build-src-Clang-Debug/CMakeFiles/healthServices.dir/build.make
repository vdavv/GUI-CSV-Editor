# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug

# Include any dependencies generated for this target.
include CMakeFiles/healthServices.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/healthServices.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/healthServices.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/healthServices.dir/flags.make

CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o: CMakeFiles/healthServices.dir/flags.make
CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o: healthServices_autogen/mocs_compilation.cpp
CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o: CMakeFiles/healthServices.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o -MF CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o -c /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/healthServices_autogen/mocs_compilation.cpp

CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/healthServices_autogen/mocs_compilation.cpp > CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.i

CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/healthServices_autogen/mocs_compilation.cpp -o CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.s

CMakeFiles/healthServices.dir/main.cpp.o: CMakeFiles/healthServices.dir/flags.make
CMakeFiles/healthServices.dir/main.cpp.o: /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/main.cpp
CMakeFiles/healthServices.dir/main.cpp.o: CMakeFiles/healthServices.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/healthServices.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/healthServices.dir/main.cpp.o -MF CMakeFiles/healthServices.dir/main.cpp.o.d -o CMakeFiles/healthServices.dir/main.cpp.o -c /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/main.cpp

CMakeFiles/healthServices.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/healthServices.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/main.cpp > CMakeFiles/healthServices.dir/main.cpp.i

CMakeFiles/healthServices.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/healthServices.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/main.cpp -o CMakeFiles/healthServices.dir/main.cpp.s

CMakeFiles/healthServices.dir/mainwindow.cpp.o: CMakeFiles/healthServices.dir/flags.make
CMakeFiles/healthServices.dir/mainwindow.cpp.o: /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/mainwindow.cpp
CMakeFiles/healthServices.dir/mainwindow.cpp.o: CMakeFiles/healthServices.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/healthServices.dir/mainwindow.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/healthServices.dir/mainwindow.cpp.o -MF CMakeFiles/healthServices.dir/mainwindow.cpp.o.d -o CMakeFiles/healthServices.dir/mainwindow.cpp.o -c /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/mainwindow.cpp

CMakeFiles/healthServices.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/healthServices.dir/mainwindow.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/mainwindow.cpp > CMakeFiles/healthServices.dir/mainwindow.cpp.i

CMakeFiles/healthServices.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/healthServices.dir/mainwindow.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/mainwindow.cpp -o CMakeFiles/healthServices.dir/mainwindow.cpp.s

CMakeFiles/healthServices.dir/csvmodel.cpp.o: CMakeFiles/healthServices.dir/flags.make
CMakeFiles/healthServices.dir/csvmodel.cpp.o: /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/csvmodel.cpp
CMakeFiles/healthServices.dir/csvmodel.cpp.o: CMakeFiles/healthServices.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/healthServices.dir/csvmodel.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/healthServices.dir/csvmodel.cpp.o -MF CMakeFiles/healthServices.dir/csvmodel.cpp.o.d -o CMakeFiles/healthServices.dir/csvmodel.cpp.o -c /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/csvmodel.cpp

CMakeFiles/healthServices.dir/csvmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/healthServices.dir/csvmodel.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/csvmodel.cpp > CMakeFiles/healthServices.dir/csvmodel.cpp.i

CMakeFiles/healthServices.dir/csvmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/healthServices.dir/csvmodel.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/csvmodel.cpp -o CMakeFiles/healthServices.dir/csvmodel.cpp.s

CMakeFiles/healthServices.dir/roweditdialog.cpp.o: CMakeFiles/healthServices.dir/flags.make
CMakeFiles/healthServices.dir/roweditdialog.cpp.o: /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/roweditdialog.cpp
CMakeFiles/healthServices.dir/roweditdialog.cpp.o: CMakeFiles/healthServices.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/healthServices.dir/roweditdialog.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/healthServices.dir/roweditdialog.cpp.o -MF CMakeFiles/healthServices.dir/roweditdialog.cpp.o.d -o CMakeFiles/healthServices.dir/roweditdialog.cpp.o -c /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/roweditdialog.cpp

CMakeFiles/healthServices.dir/roweditdialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/healthServices.dir/roweditdialog.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/roweditdialog.cpp > CMakeFiles/healthServices.dir/roweditdialog.cpp.i

CMakeFiles/healthServices.dir/roweditdialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/healthServices.dir/roweditdialog.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src/roweditdialog.cpp -o CMakeFiles/healthServices.dir/roweditdialog.cpp.s

# Object files for target healthServices
healthServices_OBJECTS = \
"CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/healthServices.dir/main.cpp.o" \
"CMakeFiles/healthServices.dir/mainwindow.cpp.o" \
"CMakeFiles/healthServices.dir/csvmodel.cpp.o" \
"CMakeFiles/healthServices.dir/roweditdialog.cpp.o"

# External object files for target healthServices
healthServices_EXTERNAL_OBJECTS =

healthServices.app/Contents/MacOS/healthServices: CMakeFiles/healthServices.dir/healthServices_autogen/mocs_compilation.cpp.o
healthServices.app/Contents/MacOS/healthServices: CMakeFiles/healthServices.dir/main.cpp.o
healthServices.app/Contents/MacOS/healthServices: CMakeFiles/healthServices.dir/mainwindow.cpp.o
healthServices.app/Contents/MacOS/healthServices: CMakeFiles/healthServices.dir/csvmodel.cpp.o
healthServices.app/Contents/MacOS/healthServices: CMakeFiles/healthServices.dir/roweditdialog.cpp.o
healthServices.app/Contents/MacOS/healthServices: CMakeFiles/healthServices.dir/build.make
healthServices.app/Contents/MacOS/healthServices: /opt/homebrew/lib/QtWidgets.framework/Versions/A/QtWidgets
healthServices.app/Contents/MacOS/healthServices: /opt/homebrew/lib/QtGui.framework/Versions/A/QtGui
healthServices.app/Contents/MacOS/healthServices: /opt/homebrew/lib/QtCore.framework/Versions/A/QtCore
healthServices.app/Contents/MacOS/healthServices: CMakeFiles/healthServices.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable healthServices.app/Contents/MacOS/healthServices"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/healthServices.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/healthServices.dir/build: healthServices.app/Contents/MacOS/healthServices
.PHONY : CMakeFiles/healthServices.dir/build

CMakeFiles/healthServices.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/healthServices.dir/cmake_clean.cmake
.PHONY : CMakeFiles/healthServices.dir/clean

CMakeFiles/healthServices.dir/depend:
	cd /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/src /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug /Users/vdav/Yandex.Disk.localized/HSE/Cpp/BigHW/dsba-itop2023-hw/code/build-src-Clang-Debug/CMakeFiles/healthServices.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/healthServices.dir/depend

