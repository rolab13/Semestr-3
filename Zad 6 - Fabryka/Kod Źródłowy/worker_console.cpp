#include "worker_console.h"

//konstruktor bezparametrowy
worker_console::worker_console() :
	worker() {

}

//destruktor nie-wirtualny
worker_console::~worker_console() {

}

//konstruktor kopiujacy
worker_console::worker_console(const worker_console &secondWorker) :
	worker(secondWorker){

}

//operator przypisania
const worker_console &worker_console::operator=(const worker_console &secondWorker) {
	if (this != &secondWorker) {
		worker::operator=(secondWorker);
	}
	return *this;
}

//metoda sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
void worker_console::processInformation(const std::string &info, morse &morseLine) {
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
	if (counter > 0) {
		morseLine.setInfo(infoArray[0]);
	}
}