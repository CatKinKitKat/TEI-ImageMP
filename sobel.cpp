#include <iostream>
#include <omp.h>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

int main() {

    int GX[3][3];
    int GY[3][3];

    GX[0][0] = 1;
    GX[0][1] = 0;
    GX[0][2] = -1;
    GX[1][0] = 2;
    GX[1][1] = 0;
    GX[1][2] = -2;
    GX[2][0] = 1;
    GX[2][1] = 0;
    GX[2][2] = -1;

    GY[0][0] = 1;
    GY[0][1] = 2;
    GY[0][2] = 1;
    GY[1][0] = 0;
    GY[1][1] = 0;
    GY[1][2] = 0;
    GY[2][0] = -1;
    GY[2][1] = -2;
    GY[2][2] = -1;

    const char *fileName = "./lion4k.jpg";
    CImg<float> img = CImg<float>(fileName);

    int colunas = img.width();
    int linhas = img.height();
    CImg<float> output = CImg<float>(colunas, linhas, 1, 1, 0.0);

    cout << colunas << endl;
    cout << linhas << endl;

    CImg<float> imgData[12];

    int lineCounter = 0;
    int columnCounter = 0;
    for (int i = 0; i < 12; i++) {
        imgData[i] = img.get_crop(lineCounter, columnCounter, lineCounter + 960, columnCounter + 720);
        if (lineCounter + 960 > 3840) {
            lineCounter = 0;
            columnCounter += 720;
        } else {
            lineCounter += 980;
        }
        imgData[i].save("imagem%d.pgm", i);
    }

#pragma omp parallel
    {

    }
    return 0;
}