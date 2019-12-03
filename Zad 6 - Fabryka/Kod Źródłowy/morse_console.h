////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa morse_console dziedziczaca po klasie morse sluzaca do wypikiwania kodu na ekran konsoli
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 24.12.2018 - utworzenie klasy morse_console
//
////////////////////////////////////////////////////////////////
#ifndef MORSE_CONSOLE_H
#define MORSE_CONSOLE_H
#include "morse.h"

class morse_console : public morse {
	protected:
		int pauseTime;
	public:
		//konstruktor bezparametrowy
		morse_console();

		//destruktor nie-wirtualny
		~morse_console();

		//konstruktor kopiujacy
		morse_console(const morse_console &secondMorse);

		//operator przypisania
		const morse_console &operator=(const morse_console &secondMorse);

		//metoda wyswietlajaca kod morsa na ekranie konsoli
		void returnMorse(const std::string &morseMessage);

		//setter przerwy pomiedzy wyswietlaniem pojedynczego znaku
		void setPauseTime(const int &value);

		//metoda dziedziczona setInfo ustawiajaca czas przerwy za pomoca settera setPauseTime
		void setInfo(const int &value);
};
#endif