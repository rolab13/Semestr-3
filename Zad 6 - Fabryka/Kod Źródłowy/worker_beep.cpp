#include "worker_beep.h"

//konstruktor bezparametrowy
worker_beep::worker_beep():
	worker(){

}

//destruktor nie-wirtualny
worker_beep::~worker_beep() {

}

//konstruktor kopiujacy
worker_beep::worker_beep(const worker_beep &secondWorker) :
	worker(secondWorker){

}

//operator przypisania
const worker_beep &worker_beep::operator=(const worker_beep &secondWorker) {
	if (this != &secondWorker) {
		worker::operator=(secondWorker);
	}
	return *this;
}

//metoda sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
void worker_beep::processInformation(const std::string &info, morse &morseLine) {
	worker::processInformation(info, morseLine);
	std::stringstream stream(info);
	int counter = 0;
	while (true) {
		int integerInString;
		stream >> integerInString;
		if (!stream || counter > 4) {
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
	else if (counter == 5) {
		morseLine.setInfo(infoArray[0], infoArray[1], infoArray[2], infoArray[3], infoArray[4]);
	}
}