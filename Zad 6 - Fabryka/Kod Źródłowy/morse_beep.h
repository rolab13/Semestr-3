////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa morse_beep dziedziczaca po klasie morse sluzaca do wypikiwania kodu morsa dzwiekami
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 24.12.2018 - utworzenie klasy morse_beep
//
////////////////////////////////////////////////////////////////
#ifndef MORSE_BEEP_H
#define MORSE_BEEP_H
#include "morse.h"

class morse_beep : public morse {
protected:
	int beepFrequency;
	int dotBeepTime;
	int dashBeepTime;
	int pauseBetweenBeep;
	int pauseBetweenChar;
public:
	//konstruktor bezparametrowy
	morse_beep();

	//destruktor nie-wirtualny
	~morse_beep();

	//konstruktor kopiujacy
	morse_beep(const morse_beep &secondMorse);

	//operator przypisania
	const morse_beep &operator=(const morse_beep &secondMorse);

	//metoda wypikujaca kod morsa za pomoca dzwiekow
	void returnMorse(const std::string &morseMessage);

	//metoda wypikujaca pojedynczy sygnal kropki
	void beepDot();

	//metoda wypikujaca pojedynczy sygnal dash-a
	void beepDash();

	////////////////////
	//settery
	
	//setter czestotliwosci sygnalu
	void setBeepFrequency(const int &value);

	//setter czasu pikniecia kropki
	void setDotBeepTime(const int &value);

	//setter czasu pikniecia dash-a
	void setDashBeepTime(const int &value);

	//setter czasu pauzy miedzy piknieciami
	void setPauseBetweenBeep(const int &value);

	//setter czasu pauzy miedzy znakami
	void setPauseBetweenChar(const int &value);

	///////////////////
	//metoda setInfo przeciazona dla roznych kombinacji parametrow

	//setInfo dla jednej wartosci - ustawia kolejno czestotliwosc
	void setInfo(const int &value);

	//setInfo dla dwoch wartosci - ustawia kolejno czestotliwosc, czas pikniecia kropki
	void setInfo(const int &value1, const int &value2);

	//setInfo dla trzech wartosci - ustawia kolejno czestotliwosc, czas pikniecia kropki, czas pikniecia dash-a
	void setInfo(const int &value1, const int &value2, const int &value3);

	//setInfo dla czterech wartosci - ustawia kolejno czestotliwosc, czas pikniecia kropki, czas pikniecia dash-a, czas pauzy miedzy piknieciami
	void setInfo(const int &value1, const int &value2, const int &value3, const int &value4);

	//setInfo dla czterech wartosci - ustawia kolejno czestotliwosc, czas pikniecia kropki, czas pikniecia dash-a, czas pauzy miedzy piknieciami, czas pauzy miedzy znakami
	void setInfo(const int &value1, const int &value2, const int &value3, const int &value4, const int &value5);
};
#endif