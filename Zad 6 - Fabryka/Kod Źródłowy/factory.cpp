#include "factory.h"

//konstruktor bezparametrowy
factory::factory() :
	primaryMorse(new morse_console),
	currentState(factory::console),
	workerOffice(){
	workerOffice[0] = new worker_beep;
	workerOffice[1] = new worker_capslock;
	workerOffice[2] = new worker_console;
	workerOffice[3] = new worker_disk;
}

//destruktor nie-wirtualny
factory::~factory() {
	delete primaryMorse;
	for (int i = 0; i < 4; i++) {
		delete workerOffice[i];
	}
}

//konstruktor kopiujacy
factory::factory(const factory &secondFactory) :
	primaryMorse(secondFactory.primaryMorse),
	currentState(secondFactory.currentState),
	workerOffice() {
	for (int i = 0; i < 4; i++) {
		workerOffice[i] = secondFactory.workerOffice[i];
	}
}

//operator przypisania
const factory &factory::operator=(const factory &secondFactory) {
	if (this != &secondFactory) {
		this->primaryMorse = secondFactory.primaryMorse;
		this->currentState = secondFactory.currentState;
		for (int i = 0; i < 4; i++) {
			workerOffice[i] = secondFactory.workerOffice[i];
		}
	}
	return *this;
}

//metoda ustawiajaca parametry dla "linii produkcyjnej" morsa
void factory::setExternalInfo(const std::string &info) {
	for (int i = 0; i < 4; i++) {
		workerOffice[i]->processInformation(info, *primaryMorse);
	}
}

//metoda ustawiajaca sposob przekazywania morsa
void factory::setOutput(const int &value) {
	if (currentState != value) {
		delete primaryMorse;
		if (value == 0) {
			primaryMorse = new morse_beep;
			currentState = 0;
		}
		else if (value == 1) {
			primaryMorse = new morse_capslock;
			currentState = 1;
		}
		else if (value == 2) {
			primaryMorse = new morse_console;
			currentState = 2;
		}
		else if (value == 3) {
			primaryMorse = new morse_disk;
			currentState = 3;
		}
		else {
			primaryMorse = new morse_console;
			currentState = 2;
		}
		workerOffice[value]->changeStartingParameters(*primaryMorse);
	}
}

//metoda usuwajaca zbedne 0 (wykorzystywana dla liczb zmiennoprzecinkowych)
std::string factory::removeUselessZeroes(const std::string &stringNumber) {
	bool areAnyZeroesLeft = true;
	std::string tempString = stringNumber;
	while (areAnyZeroesLeft) {
		if (tempString[tempString.length() - 1] == '0') {
			tempString.pop_back();
		}
		else {
			areAnyZeroesLeft = false;
		}
	}
	return tempString;
}
