all: sobelMulti sobelSingle


sobelMulti: sobelMulti.cpp
	g++ -g3 sobelMulti.cpp -o sobelMulti -lpthread -lX11

sobelSingle: sobelSingle.cpp
	g++ -g3 sobelSingle.cpp -o sobelSingle -lpthread -lX11

