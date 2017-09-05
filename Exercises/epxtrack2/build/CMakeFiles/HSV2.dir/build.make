# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nvidia/UROP17/Exercises/epxtrack2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nvidia/UROP17/Exercises/epxtrack2/build

# Include any dependencies generated for this target.
include CMakeFiles/HSV2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HSV2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HSV2.dir/flags.make

CMakeFiles/HSV2.dir/epxtrack2.cpp.o: CMakeFiles/HSV2.dir/flags.make
CMakeFiles/HSV2.dir/epxtrack2.cpp.o: ../epxtrack2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvidia/UROP17/Exercises/epxtrack2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HSV2.dir/epxtrack2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HSV2.dir/epxtrack2.cpp.o -c /home/nvidia/UROP17/Exercises/epxtrack2/epxtrack2.cpp

CMakeFiles/HSV2.dir/epxtrack2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HSV2.dir/epxtrack2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/UROP17/Exercises/epxtrack2/epxtrack2.cpp > CMakeFiles/HSV2.dir/epxtrack2.cpp.i

CMakeFiles/HSV2.dir/epxtrack2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HSV2.dir/epxtrack2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/UROP17/Exercises/epxtrack2/epxtrack2.cpp -o CMakeFiles/HSV2.dir/epxtrack2.cpp.s

CMakeFiles/HSV2.dir/epxtrack2.cpp.o.requires:

.PHONY : CMakeFiles/HSV2.dir/epxtrack2.cpp.o.requires

CMakeFiles/HSV2.dir/epxtrack2.cpp.o.provides: CMakeFiles/HSV2.dir/epxtrack2.cpp.o.requires
	$(MAKE) -f CMakeFiles/HSV2.dir/build.make CMakeFiles/HSV2.dir/epxtrack2.cpp.o.provides.build
.PHONY : CMakeFiles/HSV2.dir/epxtrack2.cpp.o.provides

CMakeFiles/HSV2.dir/epxtrack2.cpp.o.provides.build: CMakeFiles/HSV2.dir/epxtrack2.cpp.o


# Object files for target HSV2
HSV2_OBJECTS = \
"CMakeFiles/HSV2.dir/epxtrack2.cpp.o"

# External object files for target HSV2
HSV2_EXTERNAL_OBJECTS =

HSV2: CMakeFiles/HSV2.dir/epxtrack2.cpp.o
HSV2: CMakeFiles/HSV2.dir/build.make
HSV2: /usr/local/lib/libopencv_stitching.so.3.3.0
HSV2: /usr/local/lib/libopencv_superres.so.3.3.0
HSV2: /usr/local/lib/libopencv_videostab.so.3.3.0
HSV2: /usr/local/lib/libopencv_aruco.so.3.3.0
HSV2: /usr/local/lib/libopencv_bgsegm.so.3.3.0
HSV2: /usr/local/lib/libopencv_bioinspired.so.3.3.0
HSV2: /usr/local/lib/libopencv_ccalib.so.3.3.0
HSV2: /usr/local/lib/libopencv_dpm.so.3.3.0
HSV2: /usr/local/lib/libopencv_face.so.3.3.0
HSV2: /usr/local/lib/libopencv_freetype.so.3.3.0
HSV2: /usr/local/lib/libopencv_fuzzy.so.3.3.0
HSV2: /usr/local/lib/libopencv_img_hash.so.3.3.0
HSV2: /usr/local/lib/libopencv_line_descriptor.so.3.3.0
HSV2: /usr/local/lib/libopencv_optflow.so.3.3.0
HSV2: /usr/local/lib/libopencv_reg.so.3.3.0
HSV2: /usr/local/lib/libopencv_rgbd.so.3.3.0
HSV2: /usr/local/lib/libopencv_saliency.so.3.3.0
HSV2: /usr/local/lib/libopencv_stereo.so.3.3.0
HSV2: /usr/local/lib/libopencv_structured_light.so.3.3.0
HSV2: /usr/local/lib/libopencv_surface_matching.so.3.3.0
HSV2: /usr/local/lib/libopencv_tracking.so.3.3.0
HSV2: /usr/local/lib/libopencv_xfeatures2d.so.3.3.0
HSV2: /usr/local/lib/libopencv_ximgproc.so.3.3.0
HSV2: /usr/local/lib/libopencv_xobjdetect.so.3.3.0
HSV2: /usr/local/lib/libopencv_xphoto.so.3.3.0
HSV2: /usr/local/lib/libopencv_shape.so.3.3.0
HSV2: /usr/local/lib/libopencv_photo.so.3.3.0
HSV2: /usr/local/lib/libopencv_calib3d.so.3.3.0
HSV2: /usr/local/lib/libopencv_phase_unwrapping.so.3.3.0
HSV2: /usr/local/lib/libopencv_dnn.so.3.3.0
HSV2: /usr/local/lib/libopencv_video.so.3.3.0
HSV2: /usr/local/lib/libopencv_datasets.so.3.3.0
HSV2: /usr/local/lib/libopencv_plot.so.3.3.0
HSV2: /usr/local/lib/libopencv_text.so.3.3.0
HSV2: /usr/local/lib/libopencv_features2d.so.3.3.0
HSV2: /usr/local/lib/libopencv_flann.so.3.3.0
HSV2: /usr/local/lib/libopencv_highgui.so.3.3.0
HSV2: /usr/local/lib/libopencv_ml.so.3.3.0
HSV2: /usr/local/lib/libopencv_videoio.so.3.3.0
HSV2: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
HSV2: /usr/local/lib/libopencv_objdetect.so.3.3.0
HSV2: /usr/local/lib/libopencv_imgproc.so.3.3.0
HSV2: /usr/local/lib/libopencv_core.so.3.3.0
HSV2: CMakeFiles/HSV2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvidia/UROP17/Exercises/epxtrack2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HSV2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HSV2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HSV2.dir/build: HSV2

.PHONY : CMakeFiles/HSV2.dir/build

CMakeFiles/HSV2.dir/requires: CMakeFiles/HSV2.dir/epxtrack2.cpp.o.requires

.PHONY : CMakeFiles/HSV2.dir/requires

CMakeFiles/HSV2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HSV2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HSV2.dir/clean

CMakeFiles/HSV2.dir/depend:
	cd /home/nvidia/UROP17/Exercises/epxtrack2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/UROP17/Exercises/epxtrack2 /home/nvidia/UROP17/Exercises/epxtrack2 /home/nvidia/UROP17/Exercises/epxtrack2/build /home/nvidia/UROP17/Exercises/epxtrack2/build /home/nvidia/UROP17/Exercises/epxtrack2/build/CMakeFiles/HSV2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HSV2.dir/depend

