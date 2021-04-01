#include <iostream>
#include "CImg.h"

using namespace cimg_library;
int main()
{
    CImg<unsigned char> alphabet = CImg<unsigned char>("gray4k.tif");
    CImg<unsigned char> tmp = CImg<unsigned char>(512, 512, 1, 4);


    //tmp = alphabet.get_crop(0, 0, 0, 0, 511, 511, 0, 3);
    tmp = alphabet.get_crop(0, 0, 180, 320);
    tmp.save_tiff("lena.png");
}