#include "morse_console.h"
#include <iostream>

//konstruktor bezparametrowy
morse_console::morse_console() :
	morse(),
	pauseTime(100){
}

//destruktor nie-wirtualny
morse_console::~morse_console() {

}

//konstruktor kopiujacy
morse_console::morse_console(const morse_console &secondMorse):
	morse(secondMorse),
	pauseTime(secondMorse.pauseTime) {

}

//operator przypisania
const morse_console &morse_console::operator=(const morse_console &secondMorse) {
	if (this != &secondMorse) {
		this->pauseTime = secondMorse.pauseTime;
	}
	return *this;
}

//metoda wyswietlajaca kod morsa na ekranie konsoli-
void morse_console::returnMorse(const std::string &morseMessage) {
	std::string tempString = morse::sentenceToMorse(morseMessage);
	for (size_t i = 0; i < tempString.length(); i++) {
		std::cout << tempString[i];
		Sleep(pauseTime);
	}
	std::cout << std::endl;
}

//setter przerwy pomiedzy wyswietlaniem pojedynczego znaku
void morse_console::setPauseTime(const int &value) {
	this->pauseTime = value;
}

//metoda dziedziczona setInfo ustawiajaca czas przerwy za pomoca settera setPauseTime
void morse_console::setInfo(const int &value) {
	setPauseTime(value);
}
