/**
 * @author Eduardo Oliveira;
 * @copyright INSTITUTO POLITÉCNICO DO CÁVADO E DO AVE - 2019/2020 - ENGENHARIA DE SISTEMAS INFORMÁTICOS - VISÃO POR COMPUTADOR
 * @email eduardo.oliveira@ieee.org; 
 * @create date 13-02-2020 12:00:36
 * @modify date 31-07-2020 12:36:00
 * @desc Minimal Image Library for Computer Vision - Lowpass filter methods for Netpbm images
 * @version 0.1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "cvision.h"

/**
 * Lowpass filters - Gaussian, Mean and Median
*/
int main(int argc, char const *argv[])
{
    // Verify argument insertion
    if (!argv[1] || !argv[2] || !argv[3])
    {
        fprintf(stderr, "Error! Wrong argument specification.    ./program @inputname @outputname @lowpass_filter @kernel_optional[must be odd]");
        getchar();
        exit(1);
    }

    // Convert argv to int
    int kernel = 5;
    if (argv[4])
        if((atoi(argv[4]) & 1) != 0) kernel = atoi(argv[4]); else puts(">> Kernel set to default -> 5. Must be odd."); // Kernel must be odd

#pragma region Memory allocation and image reading
    /** 
     * Initialization
     */
    IVC *origin = NULL, *destination = NULL, *aux = NULL;

    // Read image
    origin = vc_read_image(argv[1]);

    // Create destination and aux images
    destination = vc_image_new(origin->width, origin->height, 1, origin->levels);
    aux = vc_image_new(origin->width, origin->height, 1, origin->levels);

    // Check memory alloc
    if (!origin || !destination || !aux)
    {
        fprintf(stderr, "Memory alloc error!\nPress any key...");
        getchar();
        exit(1);
    }
#pragma endregion

#pragma region Black and White
    if (origin->channels != 1 && vc_rgb_to_gray(origin, aux)  == 1)
        puts(">> Image converted to grayscale.");
    else if (origin->channels == 1)
        memcpy(aux, origin, origin->bytesperline * origin->height);
    else
    {
        fprintf(stderr, ">> Error! Image was not converted to grayscale.\nPress any key...");
        getchar();
        exit(1);
    }
#pragma endregion

#pragma region Lowpass filters
    if (strcmp(argv[3], "gaussian")  == 0)
    {
        if (vc_gray_lowpass_gaussian_filter(aux, destination) == 1)
            puts(">> Lowpass Gaussian filter applied.");
        else
        {
            fprintf(stderr, ">> Error! Lowpass Gaussian filter not applied.\nPress any key...");
            getchar();
            exit(1);
        }
    }
    else if (strcmp(argv[3], "mean") == 0)
    {
        if (vc_gray_lowpass_mean_filter(aux, destination, kernel) == 1)
            puts(">> Lowpass Mean filter applied.");
        else
        {
            fprintf(stderr, ">> Error! Lowpass Mean filter not applied.\nPress any key...");
            getchar();
            exit(1);
        }
    }
    else if (strcmp(argv[3], "median") == 0)
    {
        if (vc_gray_lowpass_median_filter(aux, destination, kernel) == 1)
            puts(">> Lowpass Median filter applied.");
        else
        {
            fprintf(stderr, ">> Error! Lowpass Median filter not applied.\nPress any key...");
            getchar();
            exit(1);
        }
    }
    else
    {
        fprintf(stderr, ">> Error! Wrong edge method. Please input \"gaussian\", \"mean\" or \"median\" on the @lowpass_filter specification.\n./program @inputname @outputname @lowpass_filter @kernel_optional[must be odd]\nPress any key...");
        getchar();
        exit(1);
    }
#pragma endregion

#pragma region Save image to file
    // Save destination image
    if (vc_write_image(argv[2], destination) == 1)
        puts(">> Image saved.");
    else{
        fprintf(stderr, ">> Error! Image not saved!\nPress any key...");
        getchar();
        exit(1);
    }
#pragma endregion

#pragma region Memory free
    /** 
     * Free memory and exit.
     */
    vc_image_free(origin);
    vc_image_free(aux);
    vc_image_free(destination);
#pragma endregion

    printf("Press any key to exit...");
    getchar();

    return 0;
}