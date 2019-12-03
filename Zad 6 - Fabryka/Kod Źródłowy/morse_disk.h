////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa morse_disk dziedziczaca po klasie morse sluzaca do zapisywania kodu na dysku w postaci kropek i myslnikow
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 24.12.2018 - utworzenie klasy morse_disk
//
////////////////////////////////////////////////////////////////
#ifndef MORSE_DISK_H
#define MORSE_DISK_H
#include "morse.h"

class morse_disk : public morse {
	protected:
		std::string fileName;
	public:
		//konstruktor bezparametrowy
		morse_disk();

		//destruktor nie-wirtualny
		~morse_disk();

		//konstruktor kopiujacy
		morse_disk(const morse_disk &secondMorse);

		//operator przypisania
		const morse_disk &operator=(const morse_disk &secondMorse);

		//metoda zapisujaca kod morsa na dysku w pliku txt
		void returnMorse(const std::string &morseMessage);

		//setter nazwy pliku
		void setName(const std::string &fileName);

		//metoda dziedziczona setInfo ustawiajaca nazwe pliku za pomoca settera setName
		void setInfo(const std::string &infoString);
};
#endif