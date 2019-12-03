#include "obraz.h"

//konstruktor bezparametrowy
obraz::obraz()
	: fileName("test")
	, pixelMatrix(0)
	, xIndex(0)
	, yIndex(0) {
}

//konstruktor parametrowy
obraz::obraz(const std::string &fileName, color** pixelMatrix, int xIndex, int yIndex)
	: fileName(fileName)
	, pixelMatrix(0)
	, xIndex(xIndex)
	, yIndex(yIndex) {
	this->pixelMatrix = new color*[xIndex];
	for (int i = 0; i < xIndex; i++) {
		this->pixelMatrix[i] = new color[yIndex];
	}
	this->pixelMatrix = pixelMatrix;
}

//konstruktor kopiujacy
obraz::obraz(const obraz &secondObr)
	: obraz(secondObr.fileName, secondObr.pixelMatrix, secondObr.xIndex, secondObr.yIndex) {
}

//destruktor wirtualny
obraz::~obraz() {
	for (int i = 0; i < xIndex; i++) {
		delete[] pixelMatrix[i];
	}
	delete[] pixelMatrix;
}


