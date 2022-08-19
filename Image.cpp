//
// Created by tommytim on 17.08.22.
//

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Image.h"
#include "stb_image.h"
#include "stb_image_write.h"


    Image::Image(const char* filename) {
        if (read(filename)) {
            printf("Read %s\n", filename);
            size = im_width * im_height * channels;
        } else {
            printf("File not read %s\n", filename);
        };

    }

    Image::Image(int im_width, int im_height, int channels) : im_width(im_width), im_height(im_height),
                                                              channels(channels) {
        size = im_width * im_height * channels;
        data = new uint8_t[size];
    }

    Image::Image(const Image& img) : Image(img.im_width, img.im_height, img.channels) {
        memcpy(data, img.data, img.size);
    }

    Image::~Image() {
        stbi_image_free(data);
    }

    bool Image::read(const char* filename) {
        data = stbi_load(filename, &im_width, &im_height, &channels, 0);
        return data != NULL;
    }

    bool Image::write(const char* filename) {
        ImageType type = getFileType(filename);
        int success;
        switch (type) {
            case PNG:
                success = stbi_write_png(filename, im_width, im_height, channels, data, im_width * channels);
                break;
            case JPG:
                success = stbi_write_jpg(filename, im_width, im_height, channels, data, 100);
                break;
            case BMP:
                success = stbi_write_bmp(filename, im_width, im_height, channels, data);
                break;
            case TGA:
                success = stbi_write_tga(filename, im_width, im_height, channels, data);
                break;
        }
        return success != 0;
    }

    ImageType Image::getFileType(const char* filename) {
        const char *ext = strrchr(filename, '.');
        if (ext != nullptr) {
            if (strcmp(ext, ".png") == 0) {
                return PNG;
            } else if (strcmp(ext, ".jpg") == 0) {
                return JPG;
            } else if (strcmp(ext, ".bmp") == 0) {
                return BMP;
            } else if (strcmp(ext, ".tga") == 0) {
                return TGA;
            }
        }
        return PNG;
    }

	Image& Image::grayscale_avg(){
		if(channels < 3){
			printf("This image have less then 3 channels, it is already in a gray scale");
		}
		else{
			for(int i = 0; i<size; i+=channels){
				int gray = (data[i]+ data[i+1]+data[i+2])/3;
				memset(data+i, gray, 3);
			}
		}

		return *this;
	}

	Image& Image::grayscale_lum(){
		if(channels < 3){
			printf("This image have less then 3 channels, it is already in a gray scale");
		}
		else{
			for(int i=0; i<size; i+=channels){
				int gray = 0.2126*data[i] + 0.7152*data[i+1]+ 0.0722*data[i+2];
				memset(data+i, gray, 3);
			}
		}
		return *this;
	}

