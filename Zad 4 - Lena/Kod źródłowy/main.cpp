////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 4 - Lenna
//
// Program sluzacy do zliczania liczby unikalnych kolorow z obrazka w rozszerzeniu ppm
//
// Autor - Mateusz Krzeszewski
//
// 24.11.2018 - utworzenie programu
//
////////////////////////////////////////////////////////////////

//potrzebujemy <algorithm> dla funkcji sort za pomoca ktorej sortujemy vector wszystkich kolorow
#include <algorithm>
#include "ppm.h"

//funkcja liczkolory zwracaja ilosc unikalnych kolorow w obrazku
int liczkolory(obraz &ob);

int main()
{
	obraz *ob;
	ob = new ppm("allcolors.ppm");
	//ob->write("output.ppm");
	int kolor;
	kolor = liczkolory(*ob);
	std::cout << "kolorow" << kolor;
	delete ob;
	system("pause");
	return 0;
}

int liczkolory(obraz &ob) {

	
	std::vector<long> uniqueColors;
	color **pixelMatrix = new color*[ob.getXIndex()];
	for (int i = 0; i < ob.getXIndex(); i++) {
		pixelMatrix[i] = new color[ob.getYIndex()];
	}
	pixelMatrix = ob.returnMatrix();

	for (int i = 0; i < ob.getXIndex(); i++) {
		for (int j = 0; j < ob.getYIndex(); j++) {
			uniqueColors.push_back(pixelMatrix[i][j].getRGBValue());
		}
	}

	//std::cout << "Wszystkich kolorow : " << uniqueColors.size() << std::endl;
	std::sort(uniqueColors.begin(), uniqueColors.end());
	uniqueColors.erase(std::unique(uniqueColors.begin(), uniqueColors.end()), uniqueColors.end());
	pixelMatrix = 0;

	return uniqueColors.size();
}
