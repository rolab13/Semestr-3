////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa worker_disk sluzaca do obslugi fabryki dla linii morse_disk
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 29.12.2018 - utworzenie klasy worker_disk
//
////////////////////////////////////////////////////////////////
#ifndef WORKER_DISK_H
#define WORKER_DISK_H
#include "worker.h"

class worker_disk : public worker {
	public:
		//konstruktor bezparametrowy
		worker_disk();

		//destruktor nie-wirtualny
		~worker_disk();

		//konstruktor kopiujacy
		worker_disk(const worker_disk &secondWorker);

		//operator przypisania
		const worker_disk &operator=(const worker_disk &secondWorker);

		//metoda sluzaca do przeprocesowania informacji z setExternalInfo z fabryki - tutaj ustawia nazwe pliku do ktorego bedziemy zapisywac
		void processInformation(const std::string &info, morse &morseLine);
};
#endif