#include "worker_capslock.h"

//konstruktor bezparametrowy
worker_capslock::worker_capslock() :
	worker() {

}

//destruktor nie-wirtualny
worker_capslock::~worker_capslock() {

}

//konstruktor kopiujacy
worker_capslock::worker_capslock(const worker_capslock &secondWorker) :
	worker(secondWorker) {

}

//operator przypisania
const worker_capslock &worker_capslock::operator=(const worker_capslock &secondWorker) {
	if (this != &secondWorker) {
		worker::operator=(secondWorker);
	}
	return *this;
}

//metoda sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
void worker_capslock::processInformation(const std::string &info, morse &morseLine) {
	worker::processInformation(info, morseLine);
	std::stringstream stream(info);
	int counter = 0;
	while (true) {
		int integerInString;
		stream >> integerInString;
		if (!stream) {		
			break;
		}
		infoArray[counter++] = integerInString;
	}
	if (counter == 1) {
		morseLine.setInfo(infoArray[0]);
	}
	else if (counter == 2) {
		morseLine.setInfo(infoArray[0], infoArray[1]);
	}
	else if (counter == 3) {
		morseLine.setInfo(infoArray[0], infoArray[1], infoArray[2]);
	}
	else if (counter == 4) {
			morseLine.setInfo(infoArray[0], infoArray[1], infoArray[2], infoArray[3]);
	}
}