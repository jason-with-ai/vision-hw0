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
    for (int c = 0; c < im.c; c++)
        for(int row = 0; row < im.h; row++)
            for(int col = 0; col < im.w; col++)
            {
                if(im.data[(im.w*row + col) + c*im.w*im.h] < 0) 
                    im.data[(im.w*row + col) + c*im.w*im.h] = 0;
                else if(im.data[(im.w*row + col) + c*im.w*im.h] > 1) 
                    im.data[(im.w*row + col) + c*im.w*im.h] = 1; 
            }
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
     for(int row = 0; row < im.h; row++)
        for(int col = 0; col < im.w; col++)
        {
            // rgb
            float R = 0.0f, G = 0.0f, B = 0.0f;
            
            // hsv
            float H = 0.0f,_H = 0.0f, S = 0.0f, V = 0.0f, m = 0.0f, C = 0.0f;

            R = im.data[(im.w*row + col) + 0*im.w*im.h];
            G = im.data[(im.w*row + col) + 1*im.w*im.h];
            B = im.data[(im.w*row + col) + 2*im.w*im.h];

            // V = max(R,G,B)
            V = three_way_max(R,G,B);

            // m = min(R,G,B)
            m = three_way_min(R,G,B);

            // C = V - m
            C = V - m;

            // S = C/V
            if (R == 0.0f && B == 0.0f && C == 0.0f) S = 0.0f; 
            S = C / V;

            // H
            if (C == 0.0) _H = 0.0f;
            
            if (V == R) _H = (G - B) / 2;

            if (V == G) _H = (B - R) / C + 2;

            if (V == B) _H = (R - G) / C + 4;

            if (_H < 0) H = _H/6 + 1;
            else { H = _H/6; }

            // rgb -> hsv
            im.data[(im.w*row + col) + 0*im.w*im.h] = H;
            im.data[(im.w*row + col) + 1*im.w*im.h] = S;
            im.data[(im.w*row + col) + 2*im.w*im.h] = V;
        }
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
   
}
