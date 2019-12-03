#include "morse_disk.h"
#include <fstream>

//konstruktor bezparametrowy
morse_disk::morse_disk() :
	morse(),
	fileName("defaultMorse.txt") {
}

//destruktor nie-wirtualny
morse_disk::~morse_disk(){

}

//konstruktor kopiujacy
morse_disk::morse_disk(const morse_disk &secondMorse) :
	morse(secondMorse),
	fileName(secondMorse.fileName) {
}

//operator przypisania
const morse_disk &morse_disk::operator=(const morse_disk &secondMorse) {
	if (this != &secondMorse) {
		this->fileName = secondMorse.fileName;
	}
	return *this;
}

//metoda zapisujaca kod morsa na dysku w pliku txt
void morse_disk::returnMorse(const std::string &morseMessage) {
	std::fstream outputFile(fileName, std::ofstream::out);
	outputFile << morse::sentenceToMorse(morseMessage);
	outputFile.close();
}

//setter nazwy pliku
void morse_disk::setInfo(const std::string &infoString) {
	setName(infoString);
}

//metoda dziedziczona setInfo ustawiajaca nazwe pliku za pomoca settera setName
void morse_disk::setName(const std::string &fileName) {
	this->fileName = fileName + ".txt";

}

