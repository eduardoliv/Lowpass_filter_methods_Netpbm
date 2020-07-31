/**
 * @author Eduardo Oliveira;
 * @copyright INSTITUTO POLITÉCNICO DO CÁVADO E DO AVE - 2019/2020 - ENGENHARIA DE SISTEMAS INFORMÁTICOS - VISÃO POR COMPUTADOR
 * @email eduardo.oliveira@ieee.org; 
 * @create date 13-02-2020 12:00:36
 * @modify date 31-07-2020 12:36:00
 * @desc Minimal Image Library for Computer Vision - Lowpass filter methods for Netpbm images
 * @version 0.1.0
 */

#define VC_DEBUG

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

#define MINWIDTH 0
#define MINHEIGHT 0

#define VC_CH_1 1
#define VC_CH_2 2
#define VC_CH_3 3

#define GRAYLEVELS 256

#define SIZEOFUCHAR 255

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// IMAGE STRUCTURE
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct
{
	unsigned char *data;
	int width, height;
	int channels;	  // Binary/Gray = 1; RGB = 3
	int levels;		  // Binary = 1; Gray [1,255]; RGB [1,255]
	int bytesperline; // width * channels
} IVC;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// LOWPASS FILTERS
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
 * @summary: Gray Scale Lowpass gaussian filter
 * @src: Receives the source image pointer
 * @dst: Receives the destination image pointer
 * @return true if the operation succeeds, false if not
*/
int vc_gray_lowpass_gaussian_filter(IVC *src, IVC *dst);

/**
 * @summary: Gray Scale Lowpass mean filter
 * @src: Receives the source image pointer
 * @dst: Receives the destination image pointer
 * @kernelsize: Receives the kernel size to consider when applying filter
 * @return true if the operation succeeds, false if not
*/
int vc_gray_lowpass_mean_filter(IVC *src, IVC *dst, int kernelsize);

/**
 * @summary: Gray Scale Lowpass median filter
 * @src: Receives the source image pointer
 * @dst: Receives the destination image pointer
 * @kernelsize: Receives the kernel size to consider when applying filter
 * @return true if the operation succeeds, false if not
*/
int vc_gray_lowpass_median_filter(IVC *src, IVC *dst, const int kernelsize);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Image Convertion
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * @summary: Converts a rgb image to gray scale 
 * @src: Receives the source image pointer
 * @dst: Receives the destination image pointer
 * @return true if the operation succeeds, false if not
*/
int vc_rgb_to_gray(IVC *src, IVC *dst);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Image Decomposition
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * @summary: Decomposition of the red component of a rgb scale image to gray
 * @srcdst: Receives the souce/destination image pointer
 * @return true if the operation succeeds, false if not
*/
int vc_rgb_get_red_gray(IVC *srcdst);

/**
 * @summary: Decomposition of the green component of a rgb scale image to gray
 * @srcdst: Receives the souce/destination image pointer
 * @return true if the operation succeeds, false if not
*/
int vc_rgb_get_green_gray(IVC *srcdst);

/**
 * @summary: Decomposition of the blue component of a rgb scale image to gray
 * @srcdst: Receives the souce/destination image pointer
 * @return true if the operation succeeds, false if not
*/
int vc_rgb_get_blue_gray(IVC *srcdst);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Image Memory Alloc & Free
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * @summary: Memory alloc for a image by parameters
 * @width: Receives the image width
 * @height: Receives the image height
 * @channels: Receives the number of image channels
 * @levels: Receives the image levels
 * @return pointer to the image structure
*/
IVC *vc_image_new(int width, int height, int channels, int levels);

/**
 * @summary: Image memory free
 * @image: Receives the image pointer
 * @return NULL if the image pointer was set free
*/
IVC *vc_image_free(IVC *image);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Image Read and Write (PBM, PGM E PPM)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * @summary: Read Image
 * @filename: Receives the file name and extension
 * @return Pointer to the struct or NULL
*/
IVC *vc_read_image(char *filename);

/**
 * @summary: Save Image
 * @filename: Receives the file name and extension
 * @image: Receives the pointer to the image in memory
 * @return True if success, or false if not
*/
int vc_write_image(char *filename, IVC *image);