all: jasnau sobelDetection sobel test

jasnau: jasnau.cpp
	g++ jasnau.cpp -o jasnau -fopenmp -lX11

sobelDetection: sobelDetection.cpp
	g++ sobelDetection.cpp -o sobelDetection -lpthread -lX11

sobel: sobel.cpp
	g++ sobel.cpp -o sobel -lpthread -lX11

test: test.cpp
	g++ test.cpp -o test -lpthread -lz -lX11