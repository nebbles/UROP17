# Week 2

## Project Planning

Project planning is a key part in achieving any long term academic goal. As such, an approximate initial Gantt chart was created to start informing deadlines for various aspects of the projects, and to start identifying dependencies.

## Hardware Design

Hardware design began with modelling the tilt mechanism and maze in 3D modelling software SolidWorks & Fusion 360. This would inform the manufacturing of the hardware set-up and is a necessary step in the usage of workshops. Workshop build will begin next week with ordering of hardware electronics and machining of the maze. Renders and engineering drawings will be added to the repository upon completion.

## Image Recognition

Initial work into image feature recognition involved using OpenCV 3 and the new tracking API to identify different shapes of different colours in precaptured video footage.

GStreamer 1.0 was configured with OpenCV 3.3-rc to allow access to the on-board camera through C++ programs making use of the OpenCV library. The following line was required to access the camera feed:  
`nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1920, height=(int)1080,format=(string)I420, framerate=(fraction)60/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink`  
