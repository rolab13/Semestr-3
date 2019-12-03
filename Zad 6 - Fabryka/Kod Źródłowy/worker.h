////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa worker sluzaca jako klasa matka dla klas worker_beep/worker_capslock/worker_console/worker_disk
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 29.12.2018 - utworzenie klasy worker
//
////////////////////////////////////////////////////////////////
#ifndef WORKER_H
#define WORKER_H

#include "morse.h"
#include <sstream>

class worker {
	protected:
		int *infoArray;
		std::string info;
	public:
		//konstruktor bezparametrowy
		worker();

		//destruktor wirtualny
		virtual ~worker();

		//konstruktor kopiujacy
		worker(const worker &secondWorker);

		//operator przypisania
		const worker &operator=(const worker &secondWorker);

		//metoda wirtualna sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
		virtual void processInformation(const std::string &info, morse &morseLine);

		//metoda wirtualna sluzaca do zaaplikowania starych parametrow dla nowej linii
		virtual void changeStartingParameters(morse &morseLine);
};
#endif