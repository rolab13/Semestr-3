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
	, pixelMatrix(pixelMatrix)
	, xIndex(xIndex)
	, yIndex(yIndex) {
}

//konstruktor kopiujacy
obraz::obraz(const obraz &secondObr)
	: obraz(secondObr.fileName, secondObr.pixelMatrix, secondObr.xIndex, secondObr.yIndex) {
	for (int i = 0; i < xIndex; i++) {
		pixelMatrix[i] = new color[yIndex];
	}
	pixelMatrix = secondObr.pixelMatrix;
}

//destruktor wirtualny
obraz::~obraz() {
	for (int i = 0; i < xIndex; i++) {
		delete[] pixelMatrix[i];
	}
	delete[] pixelMatrix;
}


