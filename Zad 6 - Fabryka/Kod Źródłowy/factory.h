////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 6 - fabryka
//
// Klasa factory sluzaca do przekazywania informacji w postaci kodu morsa
// do wyboru:
// beep - wypikiwanie za pomoca funkcji Beep z biblioteki <windows.h>
// capslock - wypikiwanie za pomoca lampki capslocka
// console - wypikiwanie na ekran konsoli
// disk - zapisywanie na dysk w postaci kodu morsa
//
// Autor - Mateusz Krzeszewski
//
// UPDATES:
//
// 24.12.2018 - utworzenie klasy factory
// 29.12.2018 - "zatrudnienie" 4 pracownikow (utworzenie tablicy dynamicznej workerOffice przejmujacej obsluge setExternalInfo) / MK
//
////////////////////////////////////////////////////////////////
#ifndef FACTORY_H
#define FACTORY_H
#include "morse_console.h"
#include "morse_beep.h"
#include "morse_capslock.h"
#include "morse_disk.h"
#include "worker_beep.h"
#include "worker_capslock.h"
#include "worker_console.h"
#include "worker_disk.h"

class factory {
	protected:
		morse *primaryMorse;
		worker *workerOffice[4];
		int currentState;
	public:
		//statyczne zmienne sluzace do wyboru sposobu przekazywania morsa
		static const int beep = 0;
		static const int capslock = 1;
		static const int console = 2;
		static const int disk = 3;

		//konstruktor bezparametrowy
		factory();

		//destruktor nie-wirtualny
		~factory();

		//konstruktor kopiujacy
		factory(const factory &secondFactory);

		//operator przypisania
		const factory &operator=(const factory &secondFactory);

		//metoda ustawiajaca parametry dla "linii produkcyjnej" morsa
		void setExternalInfo(const std::string &info);

		//metoda ustawiajaca sposob przekazywania morsa
		void setOutput(const int &value);

		//metoda usuwajaca zbedne 0 (wykorzystywana dla liczb zmiennoprzecinkowych)
		std::string removeUselessZeroes(const std::string &stringNumber);

		//metoda convert zamieniajaca dowolny typ danych (obslugiwany przez std::to_string) na kod morsa
		template <typename T>
		void convert(const T &value) {
			
			std::string tempString = std::to_string(value);
			//jezeli nasze wartosci to liczby zmiennoprzecinkowe to usuwamy nieznaczace zera
			if (std::is_same<T, float>::value || std::is_same<T, double>::value) {
				tempString = removeUselessZeroes(tempString);
			}
			primaryMorse->returnMorse(tempString);
			
		}

		//metoda convert dla ciagow znakow
		void convert(const char value[]) {
			std::string tempString = value;
			primaryMorse->returnMorse(tempString);
		}
};
#endif