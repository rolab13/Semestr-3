#include "morse.h"

//konstruktor bezparametrowy
morse::morse() {

}

//destruktor wirtualny
morse::~morse() {

}

//konstruktor kopiujacy
morse::morse(const morse &secondMorse) {

}

//metoda zamieniajaca pojedynczy znak w ciag znakow skladajacych sie z kropek i myslnikow
std::string morse::charToMorse(const char &character) {
	char b = character;
	int a = b;


	//obsluga liter
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
		if (a < 97) {
			a += 32;
		}
		switch (a) {
		case 'a':
			return ".-";
		case 'b':
			return "-...";
		case 'c':
			return "-.-.";
		case 'd':
			return "-..";
		case 'e':
			return ".";
		case 'f':
			return "..-.";
		case 'g':
			return "--.";
		case 'h':
			return "....";
		case 'i':
			return "..";
		case 'j':
			return ".---";
		case 'k':
			return "-.-";
		case 'l':
			return ".-..";
		case 'm':
			return "--";
		case 'n':
			return "-.";
		case 'o':
			return "---";
		case 'p':
			return ".--.";
		case 'q':
			return "--.-";
		case 'r':
			return ".-.";
		case 's':
			return "...";
		case 't':
			return "-";
		case 'u':
			return "..-";
		case 'v':
			return "...-";
		case 'w':
			return ".--";
		case 'x':
			return "-..-";
		case 'y':
			return "-.--";
		case 'z':
			return "--..";
		}
	}
	//obsluga spacji
	else if (a == ' ') {
		return " ";
	}
	//obsluga kropki
	else if (a == '.') {
		return ".-.-.-";
	}
	//obsluga przecinka
	else if (a == ',') {
		return "--..--";
	}
	//obsluga myslnika (dla liczb ujemnych)
	else if (a == '-') {
		return "-....-";
	}
	//obsluga cyfr
	else if (a >= 48 && a <= 59) {
		std::string digitInMorse = "-----";
		a -= 48;
		for (int i = 0; i < a; i++) {
			digitInMorse.pop_back();
			if (i < 5) {
				digitInMorse = "." + digitInMorse;
			}
			else {
				digitInMorse = "-" + digitInMorse;
			}
		}
		return digitInMorse;
	}
	return "--------------";
}

//metoda zamieniajca stringi w ciagi znakow skladajace sie z kropek i myslnikow
std::string morse::sentenceToMorse(const std::string &sentence) {
	std::string sentenceInMorse = "";
	for (size_t i = 0; i < sentence.length(); i++) {
		sentenceInMorse += charToMorse(sentence[i]);
		sentenceInMorse += " ";
	}
	return sentenceInMorse;
}

///////////////////
//puste definicje metod setInfo
void morse::setInfo(const std::string &infoString) {}
void morse::setInfo(const int &value) {}
void morse::setInfo(const int &value1, const int &value2) {}
void morse::setInfo(const int &value1, const int &value2, const int &value3) {}
void morse::setInfo(const int &value1, const int &value2, const int &value3, const int &value4) {}
void morse::setInfo(const int &value1, const int &value2, const int &value3, const int &value4, const int &value5) {}
