#include <iostream>
#include <omp.h>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

CImg<unsigned char> sobel(CImg<unsigned char> image) {


    CImg<unsigned char> oimage(image.width(), image.height());

    return oimage;
}

int main() {

    const char *fileName = "./gray4k.tif";
    CImg<unsigned char> img = CImg<unsigned char>(fileName);

    int numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    int width = img.width();
    int height = img.height();
    CImg<unsigned char> output = CImg<unsigned char>(width, height, 1, 1, 0.0);


    CImg<unsigned char> imgChunks[numCPU];
    char *imgPartName;

    int lineCounter = 0;
    int step = (width / numCPU);

    cout << width << "x" << height << endl << numCPU << " CPUs" << endl;

    for (int i = 0; i < numCPU; i++) {
        imgPartName = (char *) malloc(8 * sizeof(char));
        imgChunks[i] = img.get_crop(lineCounter, 0, (lineCounter + step) - 1, height);
        lineCounter += step;

        cout << "New " << step << "x" << height << " chunk." << endl;

        sprintf(imgPartName, "imagem%i.tif", i);
        imgChunks[i].save_tiff(imgPartName);
        free(imgPartName);
    }

    CImg<unsigned char> oimage(width, height);
    for (int j = 0; j < numCPU; j++) {
        //oimage.draw_image(0, (j + step), sobel(imgChunks[j]));
    }

    return 0;
}