all: sobelDetection sobel

sobelDetection: sobelDetection.cpp
	g++ -g3 sobelDetection.cpp -o sobelDetection.out -lpthread -lX11

sobel: sobel.cpp
	g++ -g3 sobel.cpp -o sobel.out -lpthread -lX11
