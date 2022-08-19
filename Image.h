//
// Created by tommytim on 17.08.22.
//

#ifndef IMAGE_MANIPULATION_IMAGE1_H
#define IMAGE_MANIPULATION_IMAGE1_H


#include <cstdio>
#include <cstdint>

enum ImageType {
    PNG, JPG, BMP, TGA
};


struct Image {
    uint8_t* data = NULL;
    size_t size =0;
    int im_width;
    int im_height;
    int channels;

    Image(const char* filename);
    Image(int im_width,int im_height, int channels);
    Image(const Image& img);
    ~Image();

    bool read(const char* filename);
    bool write(const char* filename);

    ImageType getFileType(const char* filename);

    Image& grayscale_avg();
    Image& grayscale_lum();
};



#endif //IMAGE_MANIPULATION_IMAGE1_H
