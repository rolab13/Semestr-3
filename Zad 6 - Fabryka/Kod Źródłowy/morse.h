////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa morse sluzaca jako matka dla klas morse_beep/morse_console/morse_disk/mors_capslock
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 24.12.2018 - remake klasy morse (z programu z zadania 3) na potrzeby fabryki
//
// UWAGI:
//
// 1. Klasa morse jest abstrakcyjna, nie powinnismy tworzyc dla niej obiektu - stad brak operator przypisania.
//
////////////////////////////////////////////////////////////////

#ifndef MORSE_H
#define MORSE_H

#include <string>
#include <windows.h>
#include <iostream>

class morse{
	public:
		//konstruktor bezparametrowy
		morse();

		//destuktor wirtualny
		virtual ~morse();

		//konstruktor kopiujacy
		morse(const morse &secondMorse);

		//metoda zamieniajaca pojedynczy znak w ciag znakow skladajacych sie z kropek i myslnikow
		std::string charToMorse(const char &character);

		//metoda zamieniajca stringi w ciagi znakow skladajace sie z kropek i myslnikow
		std::string sentenceToMorse(const std::string &sentence);

		//metoda abstrakcyjna wywolujaca morsa w sposob dla pochodnych
		virtual void returnMorse(const std::string &sentence) = 0;

		///////////////////
		//wirtualne metody setInfo przeciazone dla roznych parametrow

		virtual void setInfo(const std::string &infoString);
		virtual void setInfo(const int &value);
		virtual void setInfo(const int &value1, const int &value2);
		virtual void setInfo(const int &value1, const int &value2, const int &value3);
		virtual void setInfo(const int &value1, const int &value2, const int &value3, const int &value4);
		virtual void setInfo(const int &value1, const int &value2, const int &value3, const int &value4, const int &value5);
};
#endif