#include "ppm.h"

//konstruktor bezparametrowy
ppm::ppm()
	: obraz(){
	this->fileName += ".ppm";
}

//konstruktor przyjmujacy za parametr nazwe pliku ktory bedziemy odczytywac
ppm::ppm(const std::string &fileName)
	: obraz(fileName, 0, 0, 0) {
	read(this->fileName);
}

//konstruktor kopiujacy
ppm::ppm(const ppm &secondPpm)
	: obraz(secondPpm.fileName, secondPpm.pixelMatrix, secondPpm.xIndex, secondPpm.yIndex) {
		for (int i = 0; i < xIndex; i++) {
			pixelMatrix[i] = new color[yIndex];
		}
		pixelMatrix = secondPpm.pixelMatrix;
}

//destruktor niewirtualny, nie przewiduje dziedziczenia z klasy dedykowanej dla danego pliku
ppm::~ppm() {

}

//metoda read sluzaca do odczytwania pliku o podanej w parametrze nazwie/sciezce
void ppm::read(const std::string &fileName){

	std::ifstream file(fileName, std::ofstream::in);

	if (file.is_open()) {
		int number;
		int xIncr = 0;
		int yIncr = 0;
		std::string temp;
		int colorsTab[3];
		int colorsCounter = 0;

		//pomijamy smieciowe informacje
		for (int i = 0; i < 5; i++) {
			file >> temp;
		}

		//zczytujemy rozdz. obrazka
		file >> this->xIndex;
		file >> this->yIndex;

		//tworzymy tablice 2d (macierz) o wymiarach analogicznych do rozdzielczosci obrazka
		pixelMatrix = new color*[xIndex];
		for (int i = 0; i < xIndex; i++) {
			
		}

		//pomijamy maksymalna liczbe dla kazdej z barw, przyjmujemy domyslna wartosc 255
		file >> temp;

		//zaladowanie macierzy wartosciami kolorow z pliku
		while (file >> number)
		{
			colorsTab[colorsCounter] = number;
			colorsCounter++;
			if (colorsCounter > 2){
				colorsCounter = 0;
				pixelMatrix[xIncr][yIncr++] = color(colorsTab[0], colorsTab[1], colorsTab[2]);
				if (yIncr == yIndex) {
					xIncr++;
					yIncr = 0;
				}
			}
		}
		file.close();
	}
	else {
		std::cerr << "Blad podczas otwierania pliku " << fileName << std::endl;
	}
}

//metoda write sluzaca do odczytwania pliku o podanej w parametrze nazwie/sciezce
void ppm::write(const std::string &fileName) {

	std::fstream file(fileName, std::ofstream::out);

	if (file.is_open()) {
		int counter = 0;

		file << "P3\n" << "# Created by MateuszKrzeszewski\n"
			 << xIndex << " " << yIndex << "\n"
			 << 255 << "\n";
		
		for (int i = 0; i < xIndex; i++) {
			for (int j = 0; j < yIndex; j++) {
				counter++;
				file << pixelMatrix[i][j].getRedValue() << " "
					<< pixelMatrix[i][j].getGreenValue() << " "
					<< pixelMatrix[i][j].getBlueValue() << " ";
				if (counter % 16 == 0) {
					counter = 0;
					file << "\n";
				}
			}
		}
		file.close();
	}
	else {
		std::cerr << "Blad podczas zapisywania " << fileName << std::endl;
	}
}

//metoda sluzaca do odczytania ilosci kolorow w osi x
int ppm::getXIndex() {
	return xIndex;
}

//metoda sluzaca do odczytania ilosci kolorow w osi y
int ppm::getYIndex() {
	return yIndex;
}

//metoda zwracajaca obraz w postaci macierzy zawierajacej kolory
color** ppm::returnMatrix() {
	return pixelMatrix;
}