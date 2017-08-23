# Weekly Note Log of Progress

## Contents

1. [Week 1](#week-1)
2. [Week 2](#week-2)
3. [Week 3](#week-3)
4. [Week 4 & 5](#week-4-&-5)
5. [Week 6](#week-6)

# Week ```1```

## Contents

1. [Set-up of Nvidia Tegra X2](#set-up-of-nvidia-tegra-x2)
2. [Workflow](#workflow)
3. [Idea Generation](#idea-generation)

## Set-up of Nvidia Tegra X2

Commence setting up process. This involved sourcing a display, connection with HDMI cable. TX2 was flashed using the set-up process described in a [video](https://www.youtube.com/watch?v=D7lkth34rgM) by another developer.

When installing the [Nvidia JetPack 3.0 package](https://developer.nvidia.com/embedded/jetpack) the post-flash installation procedure was started manually after connecting the TX2 to the internet via WiFi. This was important due to connection restrictions at Imperial. Post-installation the TX2 was ready for use with preinstalled packages providing a number of ML examples.

## Workflow

### Host computers

Workflow initially established included using CyberDuck for the SFTP protocol to directly edit and transfer files to the TX2. In parallel, FileZilla was used on linux. Ubuntu and MacOS were both used to write initial example code and send to the TX2.

### Compiling

Compilation was decidedly done for all programs thus far on the target machine due to cross-compilation errors when compiling on host due to different hardware.

On-target-compilation of __test.cpp__ was at first successfully executed (to __Test__) using:
```bash
g++ test.cpp -o Test `pkg-config opencv --cflags --libs`
# Followed by executing the output file
./Test
```
However this was not the recommended approach due to usage of OpenCV usually requiring `cmake` and a `CMakeList.txt`. As such with further investigation on why this approach wouldn't work using Nvidia's [official guide](https://www.youtube.com/watch?v=gvmP0WRVUxI), a fic was found to ensure the CMake would properly compile. This was with:
```bash
cmake -D CUDA_USE_STATIC_CUDA_RUNTIME=OFF
```
## Idea Generation

A number of initial ideas on the application on computer vision and machine learning were discussed and analysed in the first week for potential projects.

 - __Concept: Indoor Guidance for the visually impaired__ - this concept would deliver an example into the possible future of indoor mapping and guidance systems for the visually impaired. The system would rely on a image mapping system and machine learning to allow the guidance system to locate itself accurately in an indoor environment and provide useful informaiton to the user about getting to their target location.
 - __Concept: Dynamic control of a lightweight drone in busy areas__ - this concept aims to provide intelligent control of a drone populated by unpredicatble moving items (such as a person walking through the flying zone) and to intelligently control the drone so as to avoid these disruptions and still maintain flight to pre-determined goal.
 - __Concept: Control and mastery of a balancing puzzle maze__ - this concept aims to provide a control unit with two axis tilt output on a ball bearing maze. The control unit would use a camera input to analyse the puzzle just as a human would and work out a number of dynamic puzzle simultaneously such as balancing the ball bearing, finding optimal routes through a maze, and avoiding failure conditions (such as holes in the maze).

Additional modifications on these concepts included a possible RC vehicle that had to navigate through unknown terrain using ML techniques to improve driving.

# Week 2

## Project Planning

Project planning is a key part in achieving any long term academic goal. As such, an approximate initial Gantt chart was created to start informing deadlines for various aspects of the projects, and to start identifying dependencies.

## Hardware Design

Hardware design began with modelling the tilt mechanism and maze in 3D modelling software SolidWorks & Fusion 360. This would inform the manufacturing of the hardware set-up and is a necessary step in the usage of workshops. Workshop build will begin next week with ordering of hardware electronics and machining of the maze. Renders and engineering drawings will be added to the repository upon completion.

## Image Recognition

Initial work into image feature recognition involved using OpenCV 3 and the new tracking API to identify different shapes of different colours in precaptured video footage.

GStreamer 1.0 was configured with OpenCV 3.3-rc to allow access to the on-board camera through C++ programs making use of the OpenCV library. The following line was required to access the camera feed:
`nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1920, height=(int)1080,format=(string)I420, framerate=(fraction)60/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink`

# Week 3

## First Object-Tracking Program

The first effective object-tracking program made use of the Tracking API in the OpenCV 3 extra modules. More precisely, through `"opencv2/tracking.hpp"`. At the start of the program, the user chooses whether to use a video or the on-board camera. The user then draws a rectangle around the object that they wish to track, on the first frame of video input.

The next task is to have a pre-determined image for the machine to recognise and detect at the start, without a user's input.

# Week 4 & 5 Notes

Over the two week period:
- First iterations of the maze were produced.
- First design of mechanism was assembled.
- Initial work into Arduino motor control was established.

Work to follow up with:
- Complete Arduino control of two stepper motors.
- Redesign of maze and mechanism to eliminate problems.
- Assembly of maze with motors.
- Establish Serial connection between Tegra program and Arduino (with custom written library).

# Week 6

## Maze Redesign

The maze mechanism and build had to be redesigned and manufactured to implement new changes and improve on the previous two versions.

Mk.III has a design which streamlines the tilting mechanism as much as possible, whilst preparing for the inevitable addition of the stepper motors and timing belts.
