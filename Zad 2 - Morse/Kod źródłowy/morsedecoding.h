////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 2 - kod morsa.
//
// Funkcja zamieniajaca ciagi znakow na kod morsa w postaci ciagu znakow (+ dodano klase OBEJSCIEPAUZY dla obslugie pause w main)
//
// Autor - Mateusz Krzeszewski
//
// 03.11.2018 - utworzenie funkcji.
//
// UPDATES:
//
// 06.11.2018 - dodano OBEJSCIE pauzy /MK
//
////////////////////////////////////////////////////////////////
#ifndef MORSEDECODING_H
#define MORSEDECODING_H
#include <string>
#include <iostream>

//klasa OBEJSCIEPAUZY sluzaca tylko i wylacznie do przeciazenia operatora << w morse na ta klase aby mozna bylo uzyc pause w main
//nie potrzebujemy operatora przypisania/konstruktora kopiujacego bowiem jedynym zadaniem tej klasy jest stworzyc obiekt pause
class OBEJSCIEPAUZY {
	public:
		OBEJSCIEPAUZY();
		~OBEJSCIEPAUZY();
};

//wrzucenie deklaracji pause do main
extern OBEJSCIEPAUZY pause;

//funkcja sluzaca do zamiany pojedynczego znaku na ciag znakow w postaci kropek i myslnikow
std::string characterToMorse(const char &character);

//funkcja sluzaca do zamiany ciagu znakow na ciag znakow w postaci kodu morsa
std::string sentenceToMorse(const std::string sentence);

//funkcja usuwajaca nieznaczace zera z liczb zmiennoprzecinkowych 
std::string removeUselessZeroes(std::string stringNumber);
#endif