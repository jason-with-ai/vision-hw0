#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    // x: row, y: col
    return im.data[im.w*x + y + c*im.w*im.h];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
    // x: row, y: col
    im.data[(im.w*x + y) + c*im.w*im.h] = v;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);

    // TODO Fill this in
    memcpy(copy.data, im.data, im.h*im.w*im.c);
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);

    // TODO Fill this in
    for(int row = 0; row < im.h; row++)
        for(int col = 0; col < im.w; col++)
        {
            float R = get_pixel(im,row,col,0);
            float G = get_pixel(im,row,col,1);
            float B = get_pixel(im,row,col,2);
           
            // gray.data[row*im.w + col] = (R + G + B)/3;
            gray.data[row*im.w + col] = 0.299*R + 0.587*G + 0.114*B;
        }
    
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
    for(int row = 0; row < im.h; row++)
        for(int col = 0; col < im.w; col++)
        {
            im.data[(im.w*row + col) + c*im.w*im.h] += v;
        }
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
