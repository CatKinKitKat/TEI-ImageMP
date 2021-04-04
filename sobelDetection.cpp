#include <iostream>
#include "CImg.h"
#include <fstream>
#include <cmath>

using namespace cimg_library;
using namespace std;

int main() {

    int w;
    int h;
    int SUM;
    int sumX, sumY;
    int y;
    int x;

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

    const char *fileName = "./gray4k.tif";
    CImg<float> image = CImg<float>(fileName);
    w = image.width();
    h = image.height();

    const unsigned int width = w;
    const unsigned int height = h;


    int **px;
#pragma omp parallel
    {
        px = new int *[width];
#pragma omp for schedule(static)
        for (y = 0; y < image.height(); y++) {
            px[y] = new int[height];
            for (x = 0; x < image.width(); x++) {
                sumX = 0;
                sumY = 0;
                if (y == 0 || y == image.height() - 1)
                    SUM = 0;
                else if (x == 0 || x == image.width() - 1)
                    SUM = 0;
                else {
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            sumX = sumX + GX[j + 1][i + 1] * (int) image(x + j, y + i);
                        }
                    }

                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            sumY = sumY + GY[j + 1][i + 1] * (int) image(x + j, y + i);
                        }
                    }
                    SUM = sqrt(pow((double) sumX, 2) + pow((double) sumY, 2));
                }

                if (SUM > 255)
                    SUM = 255;
                if (SUM < 0)
                    SUM = 0;
                float newPixel = (255 - (float) (SUM));
                px[y][x] = newPixel;
            }
        }
    }

    CImg<float> oimage(width, height, 1, 1, 0.0);
    for (y = 0; y < image.height(); y++) {
        for (x = 0; x < image.width(); x++) {
            oimage(x, y) = px[y][x];
        }
    }
    oimage.save_bmp("oima2ge.bmp");

    return 0;
}