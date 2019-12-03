#include "morse_beep.h"

//konstruktor bezparametrowy
morse_beep::morse_beep() :
	morse(),
	beepFrequency(666),
	dotBeepTime(200),
	dashBeepTime(600),
	pauseBetweenBeep(200),
	pauseBetweenChar(400){

}

//destruktor nie-wirtualny
morse_beep::~morse_beep(){

}

//konstruktor kopiujacy
morse_beep::morse_beep(const morse_beep &secondMorse) :
	morse(secondMorse),
	beepFrequency(secondMorse.beepFrequency),
	dotBeepTime(secondMorse.dotBeepTime),
	dashBeepTime(secondMorse.dashBeepTime),
	pauseBetweenBeep(secondMorse.pauseBetweenBeep),
	pauseBetweenChar(secondMorse.pauseBetweenChar) {

}

//operator przypisania
const morse_beep &morse_beep::operator=(const morse_beep &secondMorse) {
	if (this != &secondMorse) {
		this->beepFrequency = secondMorse.beepFrequency;
		this->dotBeepTime = secondMorse.dotBeepTime;
		this->dashBeepTime = secondMorse.dashBeepTime;
		this->pauseBetweenBeep = secondMorse.pauseBetweenBeep;
		this->pauseBetweenChar = secondMorse.pauseBetweenChar;
	}
	return *this;
}

//metoda wypikujaca kod morsa za pomoca dzwiekow
void morse_beep::returnMorse(const std::string &morseMessage) {
	std::string tempString = morse::sentenceToMorse(morseMessage);

	for (size_t i = 0; i < tempString.length(); i++) {
		if (tempString[i] == '\n') {
			Sleep(pauseBetweenChar);
		}
		else if (tempString[i] == ' ') {
			Sleep(pauseBetweenChar);
		}
		else {
			if (tempString[i] == '.') {
				beepDot();
			}
			else {
				beepDash();
			}
			Sleep(pauseBetweenBeep);
		}
	}
}

//metoda wypikujaca sygnal krotki	
void morse_beep::beepDot() {
	Beep(this->beepFrequency, this->dotBeepTime);
}

//metoda wypikujaca sygnal dlugi	
void morse_beep::beepDash() {
	Beep(this->beepFrequency, this->dashBeepTime);
}

///////////////////
//settery

//setter czestotliwosci sygnalu
void morse_beep::setBeepFrequency(const int &value) {
	this->beepFrequency = value;
}

//setter czasu pikniecia kropki
void morse_beep::setDotBeepTime(const int &value) {
	this->dotBeepTime = value;
}

//setter czasu pikniecia dash-a
void morse_beep::setDashBeepTime(const int &value) {
	this->dashBeepTime = value;
}

//setter czasu pauzy miedzy piknieciami
void morse_beep::setPauseBetweenBeep(const int &value) {
	this->pauseBetweenBeep = value;
}

//setter czasu pauzy miedzy znakami
void morse_beep::setPauseBetweenChar(const int &value) {
	this->pauseBetweenChar = value;
}

///////////////////
//metoda setInfo przeciazona dla roznych kombinacji parametrow

//setInfo dla czterech wartosci - ustawia kolejno czestotliwosc
void morse_beep::setInfo(const int &value) {
	setBeepFrequency(value);
}

//setInfo dla czterech wartosci - ustawia kolejno czestotliwosc, czas pikniecia kropki
void morse_beep::setInfo(const int &value1, const int &value2) {
	setInfo(value1);
	setDotBeepTime(value2);
}

//setInfo dla czterech wartosci - ustawia kolejno czestotliwosc, czas pikniecia kropki, czas pikniecia dash-a
void morse_beep::setInfo(const int &value1, const int &value2, const int &value3) {
	setInfo(value1, value2);
	setDashBeepTime(value3);
}

//setInfo dla czterech wartosci - ustawia kolejno czestotliwosc, czas pikniecia kropki, czas pikniecia dash-a, czas pauzy miedzy piknieciami
void morse_beep::setInfo(const int &value1, const int &value2, const int &value3, const int &value4) {
	setInfo(value1, value2, value3);
	setPauseBetweenBeep(value4);
}

//setInfo dla czterech wartosci - ustawia kolejno czestotliwosc, czas pikniecia kropki, czas pikniecia dash-a, czas pauzy miedzy piknieciami, czas pauzy miedzy znakami
void morse_beep::setInfo(const int &value1, const int &value2, const int &value3, const int &value4, const int &value5) {
	setInfo(value1, value2, value3, value4);
	setPauseBetweenChar(value5);
}
