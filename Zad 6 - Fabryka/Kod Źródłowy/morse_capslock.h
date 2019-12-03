////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa morse_capslock dziedziczaca po klasie morse sluzaca do wypikiwania kodu morsa lampka capslock'a
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 24.12.2018 - utworzenie klasy morse_capslock
//
////////////////////////////////////////////////////////////////
#ifndef MORSE_CAPSLOCK_H
#define MORSE_CAPSLOCK_H
#include "morse.h"

class morse_capslock : public morse {
	protected:
		int dotBeepTime;
		int dashBeepTime;
		int pauseBetweenBeep;
		int pauseBetweenChar;
	public:
		//konstruktor bezparametrowy
		morse_capslock();

		//destruktor nie-wirtualny
		~morse_capslock();

		//konstruktor kopiujacy
		morse_capslock(const morse_capslock &secondMorse);

		//operator przypisania
		morse_capslock operator=(const morse_capslock &secondMorse);

		//metoda wypikujaca kod morsa na lampce capslock'a na klawiaturze
		void returnMorse(const std::string &morseMessage);

		//metoda zmieniajaca aktualny stan capslocka
		void capslockBlink();

		//metoda zmieniajaca stan capslock'a na czas podany w parametrze
		void beep(const int &time);

		///////////////////
		//settery

		//setter czasu trwania kropki
		void setDotBeepTime(const int &value);

		void setDashBeepTime(const int &value);

		//setter czasu pauzy miedzy sygnalami
		void setPauseBetweenBeep(const int &value);

		//setter czasu pauzy miedzy znakami
		void setPauseBetweenChar(const int &value);

		///////////////////
		//metoda setInfo przeciazona dla roznych kombinacji parametrow

		//setInfo dla czterech wartosci - kolejno czas pauzy miedzy znakami
		void setInfo(const int &value);

		//setInfo dla czterech wartosci - kolejno czas pauzy miedzy znakami, czas trwania sygnalu krotkiego
		void setInfo(const int &value1, const int &value2);

		//setInfo dla czterech wartosci - kolejno czas pauzy miedzy znakami, czas trwania sygnalu krotkiego, czas trwania sygnalu dlugiego
		void setInfo(const int &value1, const int &value2, const int &value3);

		//setInfo dla czterech wartosci - kolejno czas pauzy miedzy znakami, czas trwania sygnalu krotkiego, czas trwania sygnalu dlugiego, czas pauzy miedzy sygnalami
		void setInfo(const int &value1, const int &value2, const int &value3, const int &value4);
};
#endif