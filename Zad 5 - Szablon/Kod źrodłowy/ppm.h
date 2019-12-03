////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 4 - Lenna
//
// Klasa ppm sluzaca jako reprezentacja obrazku formatu ppm w formacie tablicy 2d 
//
// Autor - Mateusz Krzeszewski
//
// 24.11.2018 - utworzenie klasy
//
// UWAGI --
// 1. Podczas odczytywania danych z pliku uzywamy wektora - zaznaczam,
//    ze rownie dobrze moglibysmy uzyc dynamicznej tablicy o ((xIndex+1)*(yIndex+1))*3 elementach
//    lub uzyc statycznej tablicy 3 elementowej i program dzialalby rownie dobrze
////////////////////////////////////////////////////////////////
#ifndef PPM_H
#define PPM_H
#include "obraz.h"
#include <fstream>
#include <vector>

class ppm : public obraz {
	public:

		//konstruktor bezparametrowy
		ppm();

		//konstruktor przyjmujacy za parametr nazwe pliku ktory bedziemy odczytywac
		ppm(const std::string &fileName);

		//konstruktor parametrowy
		ppm(const std::string &fileName, color** pixelMatrix, int xIndex, int yIndex);

		//konstruktor kopiujacy
		ppm(const ppm &secondPpm);

		//destruktor wirtualny dziedziczacy po obraz
		virtual ~ppm();

		//metoda read sluzaca do odczytwania pliku o podanej w parametrze nazwie/sciezce
		void read(const std::string &fileName);

		//metoda write sluzaca do odczytwania pliku o podanej w parametrze nazwie/sciezce
		void write(const std::string &fileName);

		//metoda sluzaca do odczytania ilosci kolorow w osi x
		int getXIndex() const;

		//metoda sluzaca do odczytania ilosci kolorow w osi y
		int getYIndex() const;

		//metoda zwracajaca obraz w postaci macierzy zawierajacej kolory
		color** returnMatrix() const;
};

#endif