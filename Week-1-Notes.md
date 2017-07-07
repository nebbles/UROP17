# Week 1 Notes

## Set-up of Nvidia Tegra X2

Commence setting up process. This involved sourcing a display, connection with HDMI cable. TX2 was flashed using the set-up process described in a [video](https://www.youtube.com/watch?v=D7lkth34rgM) by another developer.

When installing the [Nvidia JetPack 3.0 package](https://developer.nvidia.com/embedded/jetpack) the post-flash installation procedure was started manually after connecting the TX2 to the internet via WiFi. This was important due to connection restrictions at Imperial. Post-installation the TX2 was ready for use with preinstalled packages providing a number of ML examples.

Workflow initially established included using CyberDuck for the SFTP protocol to directly edit and transfer files to the TX2. In parallel, FileZilla was used on linux. Compilation was decidedly done for all programs thus far on the target machine due to cross-compilation errors when compiling on host due to different hardware.

On-target-compilation was at first successfully executed using:
```
g++ test.cpp -o test `pkg-config opencv --cflags --libs
```  
