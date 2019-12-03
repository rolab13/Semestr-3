////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa worker_beep sluzaca do obslugi fabryki dla linii morse_beep
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 29.12.2018 - utworzenie klasy worker_beep
//
////////////////////////////////////////////////////////////////
#ifndef WORKER_BEEP_H
#define WORKER_BEEP_H
#include "worker.h"
#include "morse_beep.h"

class worker_beep : public worker {
	public:
		//konstruktor bezparametrowy
		worker_beep();

		//destruktor nie-wirtualny
		~worker_beep();

		//konstruktor kopiujacy
		worker_beep(const worker_beep &secondWorker);

		//operator przypisania
		const worker_beep &operator=(const worker_beep &secondWorker);

		//metoda sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
		void processInformation(const std::string &info, morse &morseLine);
};
#endif