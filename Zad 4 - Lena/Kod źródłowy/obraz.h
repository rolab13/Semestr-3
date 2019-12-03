////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 4 - Lenna
//
// Klasa obraz pelniaca role klasy bazowej dla klas pochodnych (tutaj -> ppm)
//
// Autor - Mateusz Krzeszewski
//
// 24.11.2018 - utworzenie klasy
//
// UWAGI - 
// 1. Moj pomysl na opracowanie klas odbiega nieco od zaproponowanej koncepcji z zajec - 
//    a) klasa color (pixel) nie dziedziczy po klasie obraz, jest to osobna klasa.
//    b) klasa obraz pelni funkcje klasy "matki" dla roznych rozszerzen obrazow - tutaj tylko ppm.
//
////////////////////////////////////////////////////////////////
#ifndef OBRAZ_H
#define OBRAZ_H

//naglowek color.h do wirtualnej metody returnMatrix
#include "color.h"

class obraz {
protected:

	std::string fileName;
	color **pixelMatrix;
	int xIndex;
	int yIndex;
public:

	//konstruktor bezparametrowy
	obraz();

	//konstruktor parametrowy
	obraz(const std::string &fileName, color** pixelMatrix, int xIndex, int yIndex);

	//konstruktor kopiujacy
	obraz(const obraz &secondObr);

	//destruktor wirtualny
	virtual ~obraz();

	//wirtualna metoda read sluzaca do odczytywania obrazu z pliku
	virtual void read(const std::string &fileName) = 0;

	//wirtualna metoda write sluzaca do zapisywania aktualnego obrazu zawartego w obiekcie do pliku
	virtual void write(const std::string &fileName) = 0;

	//wirtualna metoda returnMatrix zwracajaca macierz zawierajaca informacje o kolorach
	virtual color** returnMatrix() = 0;

	///////////////////////////
	//
	//gettery

	//wirtualna metoda zwracajaca ilosc pixeli - 1 w szerokosci
	virtual int getXIndex() = 0;

	//wirtualna metoda zwracajaca ilosc pixeli -1 w wysokosci
	virtual int getYIndex() = 0;
	
};

#endif
