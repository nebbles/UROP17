## First Object-Tracking Program

The first effective object-tracking program made use of the Tracking API in the OpenCV 3 extra modules. More precisely, through `"opencv2/tracking.hpp"`. At the start of the program, the user chooses whether to use a video or the on-board camera. The user then draws a rectangle around the object that they wish to track, on the first frame of video input. 

The next task is to have a pre-determined image for the machine to recognise and detect at the start, without a user's input.
