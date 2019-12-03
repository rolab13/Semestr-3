#include "worker.h"

//konstruktor bezparametrowy
worker::worker():
	infoArray(),
	info(""){
}


//destruktor wirtualny
worker::~worker() {
	delete infoArray;
}

//konstruktor kopiujacy
worker::worker(const worker &secondWorker) :
	infoArray(0),
	info(secondWorker.info) {

	int howManyIndexes = 1;
	for (size_t i = 0; i < secondWorker.info.length(); i++) {
		if (info[i] == ' ') {
			howManyIndexes++;
		}
	}
	if (howManyIndexes > 1) {
		infoArray = new int[howManyIndexes];
		for (int i = 0; i < howManyIndexes; i++) {
			infoArray[i] = secondWorker.infoArray[i];
		}
	}
}

//operator przypisania
const worker &worker::operator=(const worker &secondWorker) {
	if (this != &secondWorker) {
		this->info = secondWorker.info;
		int howManyIndexes = 1;
		for (size_t i = 0; i < secondWorker.info.length(); i++) {
			if (info[i] == ' ') {
				howManyIndexes++;
			}
		}
		if (howManyIndexes > 1) {
			infoArray = new int[howManyIndexes];
			for (int i = 0; i < howManyIndexes; i++) {
				infoArray[i] = secondWorker.infoArray[i];
			}
		}
	}
	return *this;
}

//metoda wirtualna sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
void worker::processInformation(const std::string &info, morse &morseLine) {
	this->info = info;
	int howManyInformation = 1;
	for (size_t i = 0; i < info.length(); i++) {
		if (info[i] == ' ') {
			howManyInformation++;
		}
		if (howManyInformation == 5) {
			break;
		}
	}
	infoArray = new int[howManyInformation];
}

//metoda wirtualna sluzaca do zaaplikowania starych parametrow dla nowej linii
void worker::changeStartingParameters(morse &morseLine) {
	processInformation(info, morseLine);
}