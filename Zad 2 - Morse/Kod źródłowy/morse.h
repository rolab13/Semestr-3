////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 2 - kod morsa.
//
// Klasa morse sluzaca do "wypikiwania" znakow w kodzie morsa.
//
// Autor - Mateusz Krzeszewski
//
// 02.11.2018 - utworzenie klasy morse
//
// UPDATES:
//
// 06.11.2018 - dodano przeciazenie operatorow dla wielu zmiennych w tym dla klasy OBEJSCIEPAUZY (wiecej info w morsedecoding.h) / MK
//
// UWAGA:
// Jezeli chcesz wyswietlac kod morsa na ekranie - odkomentuj 65 linijke w morse.cpp
//
////////////////////////////////////////////////////////////////

#ifndef MORSE_H
#define MORSE_H

#include <windows.h>
#include <sstream>
#include <iomanip>
#include "morsedecoding.h"

class morse{
	protected:
		int frequency;
		int pauseTime;
		int dotTime;
		int dashTime;
		int charPause;
		int spacePause;

	public:	
		//konstruktor bezparametrowy
		morse();

		//konstruktor z parametrami
		morse(int frequency_, int pauseTime_, int dotTime_, int dashTime_, int charPause_, int spacePause_);

		//destruktor wirtualny - dla klasy w takiej postaci zbedny; stworzony z mysla o dziedziczeniu
		virtual ~morse();

		//konstruktor kopiujacy
		morse(const morse &copyMorse);

		//przeciazony operator przypisania
		morse operator= (const morse &secondMorse);

		//przeciazony operator przesuniecia bitowego, sluzy jako strumien wyswietlajacy/pikajacy zdania w kodzie morsa.
		morse operator<< (const std::string &sentence);

		//przeciazone operatory przesuniecia bitowego; zamieniaja wartosci argumentow na string i wywoluja podstawowy przeciazony operator.
		morse operator<< (bool &number);
		morse operator<< (short &number);
		morse operator<< (unsigned short &number);
		morse operator<< (const int &number);
		morse operator<< (const unsigned int &number);
		morse operator<< (const long &number);
		morse operator<< (const long long &number);
		morse operator<< (const unsigned long &number);
		morse operator<< (const unsigned long long &number);
		
		//przeciazone operatory przesuniecia bitowego dla liczb zmiennoprzecinkowych - obsluguja do 12 miejsc po przecinku
		morse operator<< (const long double &number);
		morse operator<< (const float &number);
		morse operator<< (const double &number);

		//przeciazony operator przesuniecia bitowego dla specjalnie stworzonej klasy OBEJSCIEPAUZY zeby mozna bylo uzywac pause w main.cpp
		morse operator<< (OBEJSCIEPAUZY &pause);

		//settery
		//ustawia wartosc czestotliwosci
		void setFrequency(int value);
		//ustawia wartosc pauzy miedzy piknieciami
		void setPause(int value);
		//ustawia wartosc czasu trwania pikniecia sygnalu krotkiego
		void setDotTime(int value);
		//ustawia wartosc czasu trwania pikniecia sygnalu dlugiego
		void setDashTime(int value);
		//ustawia wartosc pauzy miedzy znakami w kodzie morsa
		void setCharPause(int value);
		//ustawia wartosc pauzy miedzy slowami (wartosc dla spacji)
		void setSpacePause(int value);

		//gettery
		//pobiera wartosc czestotliwosci
		int getFrequency();
		//pobiera wartosc pauzy miedzy piknieciami
		int getPause();
		//pobiera wartosc czasu trwania pikniecia sygnalu krotkiego
		int getDotTime();
		//pobiera wartosc czasu trwania pikniecia sygnalu dlugiego
		int getDashTime();
		//pobiera wartosc pauzy miedzy znakami w kodzie morsa
		int getCharPause();
		//pobiera wartosc pauzy miedzy slowami (wartosc dla spacji)
		int getSpacePause();

		//metoda wypikujaca sygnal krotki	
		void beepDot();
		//metoda wypikujaca sygnal dlugi
		void beepDash();	
};
#endif
