////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa worker_console sluzaca do obslugi fabryki dla linii morse_disk
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 29.12.2018 - utworzenie klasy worker_console
//
////////////////////////////////////////////////////////////////
#ifndef WORKER_CONSOLE_H
#define WORKER_CONSOLE_H
#include "worker.h"

class worker_console : public worker {
	public:
		//konstruktor bezparametrowy
		worker_console();

		//destruktor nie-wirtualny
		~worker_console();

		//konstruktor kopiujacy
		worker_console(const worker_console &secondWorker);

		//operator przypisania
		const worker_console &operator=(const worker_console &secondWorker);

		//metoda sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
		void processInformation(const std::string &info, morse &morseLine);
};
#endif