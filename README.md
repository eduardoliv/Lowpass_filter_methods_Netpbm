# Lowpass_filter_methods_Netpbm
Minimal Image Library for Computer Vision - Lowpass filter methods example for Netpbm images

<img src="https://user-images.githubusercontent.com/49571967/87052481-bf138880-c1f8-11ea-9224-a76cc4cbab88.jpg" width="45%"></img> 
<img src="https://user-images.githubusercontent.com/49571967/89087769-4df56a00-d38d-11ea-8b47-bfd9594d82e8.jpg" width="45%"></img> 

## Usage
* Open Linux terminal, navigate to the application folder and run ./lowpass \[inputname] \[outputname] \[lowpass_filter] \[kernel_size]
    * \[inputname] Is the origin Netpbm image name and extension. Must be in the same folder as the executable.
    * \[outputname] Is the destination Netpbm image name and extension. For a correct use, save the image with the .pgm extension.
    * \[lowpass_filter] The lowpass filter method, must be \"gaussian\", \"mean\" or \"median\".
    * \[kernel_size] Must be an odd number. Only for mean and median methods. Default value = 5.
    
## Compilation
* Compile via Linux make command
    * Use \<make\> to create the executable
    * Use \<make clean\> to clean the object files
    
## Dependencies
* To compile, you need the make command
    * make: sudo apt-get install make

## Release History
* 0.0.1
    * Create README.md
 
## Meta
> Eduardo Oliveira - eduardo.oliveira@ieee.org;

