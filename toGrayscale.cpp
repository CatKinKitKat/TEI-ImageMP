#include "CImg.h"
#include <iostream>

using namespace cimg_library;
using namespace std;

int main()
{

    CImg<unsigned char> image("images/lena.jpg"),
        gray(image.width(), image.height(), 1, 1, 0),
        grayWeight(image.width(), image.height(), 1, 1, 0),
        imgR(image.width(), image.height(), 1, 3, 0),
        imgG(image.width(), image.height(), 1, 3, 0),
        imgB(image.width(), image.height(), 1, 3, 0);

    cimg_forXY(image, x, y)
    {
        imgR(x, y, 0, 0) = image(x, y, 0, 0),
                      imgG(x, y, 0, 1) = image(x, y, 0, 1),
                      imgB(x, y, 0, 2) = image(x, y, 0, 2);

        cout << image.width() << "x" << image.height() << endl;
        cout << "(" << x << "," << y << ") ="
             << " R:" << (int)image(x, y, 0, 0)
             << " G:" << (int)image(x, y, 0, 1)
             << " B:" << (int)image(x, y, 0, 2) << endl;

        int R = (int)image(x, y, 0, 0);
        int G = (int)image(x, y, 0, 1);
        int B = (int)image(x, y, 0, 2);
        int grayValue = (int)(0.33 * R + 0.33 * G + 0.33 * B);
        int grayValueWeight = (int)(0.299 * R + 0.587 * G + 0.114 * B);
        gray(x, y, 0, 0) = grayValue;
        grayWeight(x, y, 0, 0) = grayValueWeight;
    }

    CImgDisplay main_disp(image, "Original"),
        draw_dispR(imgR, "Red"),
        draw_dispG(imgG, "Green"),
        draw_dispB(imgB, "Blue"),
        draw_dispGr(gray, "Gray"),
        draw_dispGrWeight(grayPond, "Gray (Weighted)");

    while (!main_disp.is_closed())
    {
        main_disp.wait();
    }

    return 0;
}