////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 4 - Lenna
//
// Klasa color sluzaca jako reprezentacja jednego koloru w RGB.
//
// Autor - Mateusz Krzeszewski
//
// 24.11.2018 - utworzenie klasy
//
////////////////////////////////////////////////////////////////
#ifndef COLOR_H
#define COLOR_H

//ponizsze biblioteki uzywane sa we wszystkich pozostalych plikach, zalaczam je wiec tutaj
#include <string>
#include <iostream>

class color {
	protected:

		unsigned short redValue;
		unsigned short greenValue;
		unsigned short blueValue;
		unsigned long rgbValue;
	public:

		//konstruktor bezparametrowy
		color();

		//konstruktor parametrowy przyjmujacy za parametry poszczegolne wartosci RGB
		color(short redValue, short greenValue, short blueValue);

		//konstruktor parametrowy przyjmujacy za parametr pelna wartosc koloru w RGB
		color(long RGBValue);

		//destruktor niewirtualny, nie przewiduje dziedziczenia z pojedynczego pixela(koloru)
		~color();

		//konstruktor kopiujacy
		color(const color &secondColor);

		/*metoda wyswietlajaca wartosci koloru (sluzy tylko dla sprawdzenia)
		void readColor();
		*/

		//////////////////
		//operatory

		//operator przypisania
		color operator=(const color &secondColor);

		//operator porownania zwracajacy wartosc true jezeli kazda skladowa RGB jest rowna w obu obiektach
		bool operator==(const color &secondColor);

		//operator porownania zwracajacy wartosc false jezeli kazda skladowa RGB jest rowna w obu obiektach
		bool operator!=(const color &secondColor);

		//////////////////
		//gettery

		//metoda zwracajaca wartosc koloru czerwonego 
		short getRedValue();

		//metoda zwracajaca wartosc koloru zielonego
		short getGreenValue();

		//metoda zwracajaca wartosc koloru niebieskiego 
		short getBlueValue();

		//metoda zwracajaca wartosc koloru w postaci (R)*256*256 + (G)*256 + (B)
		long getRGBValue();
};

#endif