#include "Image.h"


int main() {
    Image test("Nokia.jpg");
    test.write("Nokia.png");
    Image copy = test;
    for(int i = 0; i<copy.im_width*copy.channels;i++){
        copy.data[i] = 255;
    }
    copy.write("Nokia-copy.png");
    Image blank(100,100,3);
    blank.write("blank.png");
	Image gray_avg =test;
	gray_avg.grayscale_avg();
	gray_avg.write("avg.png");
	Image gray_lum = test;
	gray_lum.grayscale_lum();
	gray_lum.write("lum.png");
    return 0;
}
