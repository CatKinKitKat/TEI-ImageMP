all: sobel

sobel: sobel.cpp
	g++ -g3 sobel.cpp -o sobel.out -lpthread -lX11
