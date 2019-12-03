#include "morsedecoding.h"

//pusta definicja konstruktora
OBEJSCIEPAUZY::OBEJSCIEPAUZY() {
}

//pusta definicja destruktora
OBEJSCIEPAUZY::~OBEJSCIEPAUZY() {
}

//definicja objektu pause ktory ma sluzyc jako "manipulator" dla klasy morse 
OBEJSCIEPAUZY pause;

//funkcja sluzaca do zamiany pojedynczego znaku na ciag znakow w postaci kropek i myslnikow
std::string characterToMorse(const char& character) {
	
	char b = character;
	int a = b;

	//obsluga liter
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
		if (a < 97) {
			a+=32;
		}
		/*
		cala instrukcja switch skopiowana z https://www.geeksforgeeks.org/morse-code-implementation/
		*/
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
	//w przypadku pozostalych znakow - nie przewiduje potrzeby kodowania ich / nie istnieja w kodzie morsa
	else {
		std::cerr << "Blad! Nie mozesz uzyc kodu morsa do znaku " << character << "." << std::endl;
	}
	return "--------------";
}

//funkcja sluzaca do zamiany ciagu znakow na ciag znakow w postaci kodu morsa
std::string sentenceToMorse(const std::string sentence) {
	std::string tempString = "";
	for (size_t i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ') {
			tempString.pop_back();
			tempString += "\n";
		}
		else {
		tempString += characterToMorse(sentence[i]);
		tempString += " ";
		}
	}
	return tempString;
}

//funkcja usuwajaca nieznaczace zera z liczb zmiennoprzecinkowych 
std::string removeUselessZeroes(std::string stringNumber){
	bool areAnyZeroesLeft = true;
	while (areAnyZeroesLeft) {
		if (stringNumber[stringNumber.length() - 1] == '0') {
			stringNumber.pop_back();
		}
		else {
			areAnyZeroesLeft = false;
		}
	}
	return stringNumber;
}