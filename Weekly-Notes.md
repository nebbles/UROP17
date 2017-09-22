# Weekly Note Log of Progress

## Contents

- [x] [Week 1](#week-1)
- [x] [Week 2](#week-2)
- [x] [Week 3](#week-3)
- [x] [Week 4 & 5](#week-4--5)
- [x] [Week 6](#week-6)
- [ ] [Week 7](#week-7)
- [ ] [Week 8](#week-8)

# Week ```1```
[_Back to top_](#contents)

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

# Week ```2```
[_Back to top_](#contents)

## Project Planning

Project planning is a key part in achieving any long term academic goal. As such, an approximate initial Gantt chart was created to start informing deadlines for various aspects of the projects, and to start identifying dependencies.

## Hardware Design

Hardware design began with modelling the tilt mechanism and maze in 3D modelling software SolidWorks & Fusion 360. This would inform the manufacturing of the hardware set-up and is a necessary step in the usage of workshops. Workshop build will begin next week with ordering of hardware electronics and machining of the maze. Renders and engineering drawings will be added to the repository upon completion.

## Image Recognition

Initial work into image feature recognition involved using OpenCV 3 and the new tracking API to identify different shapes of different colours in precaptured video footage.

GStreamer 1.0 was configured with OpenCV 3.3-rc to allow access to the on-board camera through C++ programs making use of the OpenCV library. The following line was required to access the camera feed:
`nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1920, height=(int)1080,format=(string)I420, framerate=(fraction)60/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink`

# Week ```3```
[_Back to top_](#contents)

## First Object-Tracking Program

The first effective object-tracking program made use of the Tracking API in the OpenCV 3 extra modules. More precisely, through `"opencv2/tracking.hpp"`. At the start of the program, the user chooses whether to use a video or the on-board camera. The user then draws a rectangle around the object that they wish to track, on the first frame of video input.

The next task is to have a pre-determined image for the machine to recognise and detect at the start, without a user's input.

# Week ```4``` & ```5```
[_Back to top_](#contents)

Over the two week period:
- First iterations of the maze were produced.
- First design of mechanism was assembled.
- Initial work into Arduino motor control was established.

Work to follow up with:
- Complete Arduino control of two stepper motors.
- Redesign of maze and mechanism to eliminate problems.
- Assembly of maze with motors.
- Establish Serial connection between Tegra program and Arduino (with custom written library).

# Week ```6```
[_Back to top_](#contents)

## Maze Redesign

The maze mechanism and build had to be redesigned and manufactured to implement new changes and improve on the previous two versions.

Mk.III has a design which streamlines the tilting mechanism as much as possible, whilst preparing for the inevitable addition of the stepper motors and timing belts.

Final addition and repairs still to be made include the upgraded ramp (v2) and fixed MAZE_BOARD. These fixes can all be found under v2 prefix of the model files.

## Arduino & Motors

Motor 1 using GPIO 3-6, connected to IN1-4 MOTOR A.  
Power supply set at 4.8 V with maximum 0.5 A.  
Motor 2 using GPIO 8-11, connected to IN1-4 MOTOR B.  

Support for communicating to the Arduino from the TX2 has been implemented. In order fo the USB drivers to work properly on the Tegra, a new kernal had to be installed. This allowed for communication over port ```/dev/ttyACM1```. In additon to this, a [quick program](/coms/arduino_com_v2.cpp) has been written to send simple commands over Serial. This will be deveoped into a library that the machine learner or algorithm can do to balance and control the maze.

The Arduino runs [the slave](/coms/TX2Read_v3/) to the controller program. This has integrated motor control referencing earlier work done with [**stepper_new**](/arduino/stepper_new), a custom test Arduino program. In uses a number of custom built functions such as ```getSerial()``` to understand what the controller is commanding. This as of the end of the week was working until the ```switch(command.motor)``` was implemented. As a result a number of ```// TODO``` comments have been made to improve this program.

# Week ```7```
[_Back to top_](#contents)

Week began with fixing bugs in the Arduino program. These issues will be expanded on...  
The controller program running on the Tegra was adjusted for minor fixes to work with the latest version of `TX2Read.ino`.

A [belt and pulley](https://www.amazon.co.uk/MyArmor-Timing-Pulley-2GT-6mm-Opening/dp/B018DZ28V2/) was utilised to connect the two tilting planes to connect to two 4mm aluminium rods in the lower section of the maze assembly. A gear transmission was selected for conversion from the stepper motor to the rods. As a result of neglecting the design in earlier iterations, the outer casing had to be redesigned to accomodate the stepper motors and two rods. In addition there were a number of fixes to earlier designs of the Mk.III maze design.

Transmission was designed on [Gear Generator](http://geargenerator.com/#200,200,100,6,1,0,13521.300000005276,2,1,8,2,4,27,-90,0,0,16,4,4,27,-60,0,0,2,154) where the designs were saved as an SVG. These were converted to DXF with [CloudConvert](https://cloudconvert.com/svg-to-dxf) for the sake of CAD modelling in SolidWorks. These designs were then further modified to be compaitble with the 4mm rods and the [28BYJ-48 Stepper Motors](http://www.instructables.com/id/BYJ48-Stepper-Motor/).

The following files were used in the CAD modelling of the maze casing for reference:
- [Stepper motor (GrabCAD)](https://grabcad.com/library/28byj-48-5v-stepper-motor-1)
- [Stepper driver (GrabCAD)](https://grabcad.com/library/uln2003-unipolar-stepper-driver-board-1)
- [Arduino Uno (GrabCAD)](https://grabcad.com/library/arduino-uno-r3-1)

Version 4 of the Mark III hardware designs were created to implement these new additions. Mostly all were further laser cut pieces to replace or add to the existing hardware, however the gears were custom modelled and 3D printed for purpose. The files for these can be found in the Mark III CAD folder.

# Week ```8``` & onwards...
[_Back to top_](#contents)

Mark III V6 marked the final version of the iterative design. It fixed a number of issues with the hardware which prevented the the two axis tilt from working along one axis. This resulted in a redesign to ensure the pulleys were positioned centrally in line with the pivots on each of the maze supporting sections.

A brief look into the interface of the built-in camera module on the TX2 revealed that they use an expensive propretory connector made by Samtec. Related searches to this camera module and I/O port include:
- Samtec HQCD
- Samtec Q strip
- Samtec [interface catalogue](http://suddendocs.samtec.com/catalog_english/eqcd.pdf)
- Samtec [EQCD](https://www.samtec.com/products/eqcd#related)

Small alterations were brought to TX2Read which brought it forward to version 4. This included an updated command library so that quick control to bring both stepper motors to a halt and to deselect any active motors available. This was used, as before, in tandem with the [AccelStepper library](http://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#a5dce13ab2a1b02b8f443318886bf6fc5) which provides enhanced stepper control over the standard stepper library.

Xcode was used to begin writing the main TX2 program. `ai-maze` was created and initially included the adapted `TX2Write` program developed for testing the maze control with motors. It then was updated to include PID control within the command setting procedure so as to take the current position of the ball and move it toward a target coordinate.

For the complete program, it became apparent that multiple threads (or processes) would be needed to manage the multiple resources and updating required by different components of the maze controller. The functions were split into three threads running from the main thread.

- **Tracking**  
This thread manages the rapid updating of the current position of the ball using OpenCV and its tracking features. This thread needs to manage this resource separately as it needs to be highly accurate and updated regularly.

- **Navigation**  
This thread manages the updating of the target coordinate used by the Balance thread and also uses the current ball position resource provided by the tracking thread. It uses this and its end goal to determine a route through the maze. The maze is recognised and analysed using the birds eye camera feed of the maze and then selects the next required target for the Balance thread.

- **Balance (Control & Command)**  
This consists of taking the current position of the ball and using PID to determine what the motor commands should be to get the ball to its target position. It also sends these commands over USB Serial to the Arduino which interprets and changes the motors.
