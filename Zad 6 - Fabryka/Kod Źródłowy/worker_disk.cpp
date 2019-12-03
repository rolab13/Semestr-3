#include "worker_disk.h"

//konstruktor bezparametrowy
worker_disk::worker_disk() :
	worker() {

}

//destruktor nie-wirtualny
worker_disk::~worker_disk() {

}

//konstruktor kopiujacy
worker_disk::worker_disk(const worker_disk &secondWorker) :
	worker(secondWorker) {

}

//operator przypisania
const worker_disk &worker_disk::operator=(const worker_disk &secondWorker) {
	if (this != &secondWorker) {
		worker::operator=(secondWorker);
	}
	return *this;
}

//metoda sluzaca do przeprocesowania informacji z setExternalInfo z fabryki
void worker_disk::processInformation(const std::string &info, morse &morseLine) {
	this->info = info;
	morseLine.setInfo(info);
}