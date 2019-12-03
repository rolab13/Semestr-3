////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa worker_capslock sluzaca do obslugi fabryki dla linii morse_capslock
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 29.12.2018 - utworzenie klasy worker_capslock
//
////////////////////////////////////////////////////////////////
#ifndef WORKER_CAPSLOCK_H
#define WORKER_CAPSLOCK_H
#include "worker.h"
#include "morse_beep.h"

class worker_capslock : public worker {
	public:
		//konstruktor bezparametrowy
		worker_capslock();

		//destruktor nie-wirtualny
		~worker_capslock();

		//konstruktor kopiujacy
		worker_capslock(const worker_capslock &secondWorker);

		//operator przypisania
		const worker_capslock &operator=(const worker_capslock &secondWorker);

		//metoda sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
		void processInformation(const std::string &info, morse &morseLine);
};
#endif