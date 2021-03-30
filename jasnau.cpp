#include <iostream>
#include <omp.h>
#include "CImg.h"
using namespace std;
using namespace cimg_library;

int main() {
    const char* fileName = "lena_gray_512.tif";
    CImg<float> img = CImg<float>(fileName);
    
    int colunas = img.width();
    int linhas = img.height();
    CImg<float> output = CImg<float>(colunas, linhas, 1, 1, 0.0);
    
    cout << colunas << endl; 
    cout << linhas << endl; 
    
    int k = 0;
    #pragma omp parallel
    {
        while(k < 1000) {
            for(int i = 0; i < colunas; i++)
            {
                for(int j = 0; j < linhas; j++)
                {
                    float v = 0.0;
                    v = img(j, i) / 2;
                    output(j, i) = v;
    //                 if(i == 300 && j == 256)
    //                 {
    //                     cout << output(j, i) << " " << v << endl;
    //                 }
                }
            }
            k++;
        }
    }
    output.save("imagem1.pgm");
    
    cout << "Hello World" << endl; 

     // cout << omp_get_thread_num() << endl;
 
 return 0;
}