////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 5 - Szablony 
//
// Klasa z szablonem obslugujaca zliczanie ilosci znakow/slow/liczb/kolorow.
//
// Autor - Mateusz Krzeszewski
//
// 11.12.2018 - utworzenie klasy
//
// UPDATES
//
// 12.12.2018 - zmiana sposobu obslugi plikow - teraz pliki ladowane sa do stringow w mainie, nie w metodzie addData /MK
// 16.12.2018 - dodanie roznych sposob obslugi kolorow przy robieniu wykresow / MK
//
////////////////////////////////////////////////////////////////
#ifndef FREQCOUNTER_H
#define FREQCOUNTER_H
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "ppm.h"

//szablon z klasa licznika czestotliwosci
template <class T>

class freqcounter{
	protected:
		std::map<T, int> counterMap;
		int howMany;
		int maxValue;
	public:

		//konstruktor bezparametrowy
		freqcounter() :
			counterMap({}),
			howMany(0),
			maxValue(0){	
		}

		//konstruktor parametrowy przyjmujacy istniejaca juz mapę
		freqcounter(const std::map<T,int> &secondMap) :
			counterMap(secondMap),
			howMany(0),
			maxValue(0) {
				for (typename std::map<T, int>::iterator it = counterMap.begin(); it != counterMap.end(); ++it) {
				if (it->second > maxValue) {
					maxValue = it->second;
				}
				howMany++;
			}
		}

		//konstruktor kopiujacy
		freqcounter(const freqcounter &secondCounter):
			counterMap(secondCounter.counterMap),
			howMany(secondCounter.howMany),
			maxValue(secondCounter.maxValue) {
		}

		//operator przypisania
		freqcounter operator=(const freqcounter &secondCounter) {
				this->counterMap = secondCounter.counterMap;
				this->howMany = secondCounter.howMany;
				this->maxValue = secondCounter.maxValue;
				return *this;
		}

		//destruktor NIE wirtualny, z tej klasy nie bedziemy dziedziczyc
		~freqcounter(){
		}

		//metoda pozwalajaca dodac klucz do mapy przyjmujaca za argument wartosc pierwszego typu naszej mapy
		void addData(const T &value) {
			if (counterMap.find(value) == counterMap.end()) {
				counterMap[value] = 1;
				howMany++;
			}
			else {
				counterMap[value]++;
			}
				
			if (counterMap[value] > maxValue) {
				maxValue = counterMap[value];
			}
		}

		//metoda stricte pomocnicza, sluzaca do wyswietlania mapy w konsoli
		void showFreq() {
			for (typename std::map<T, int>::iterator it = counterMap.begin(); it != counterMap.end(); ++it) {
				std::cout << it->first << " " << it->second << std::endl;
			}
		}

		//metoda zwracajaca najczesciej wystepujaca wartosc z mapy
		T mostFrequent(){
			for (typename std::map<T, int>::iterator it = counterMap.begin(); it != counterMap.end(); ++it) {
				if (it->second == maxValue) {
					return it->first;
				}
			}
			return 0;
		}

		//metoda tworzaca plik tekstowy z zawartoscia mapy przyjmujaca za parametr nazwe pliku
		void createText(const std::string &fileName) {
			std::fstream outputFile(fileName, std::ofstream::out);
			for (typename std::map<T, int>::iterator it = counterMap.begin(); it != counterMap.end(); ++it) {
				outputFile << "[" << it->first << "] [" << it->second << "]\n";
			}

			outputFile.close();
		}

		//metoda tworzaca wykres do naszej mapy - domyslnie slupki przyjmuja kolor czerwony, dla obrazow przyjmuja kolor poszczegolnego pixela
		//UWAGA - dla bardzo duzych obiektow (np. obraz 70000x200) tworzenie wykresow moze zajac DUZO czasu
		void createImage(const std::string &fileName) {
			obraz* outputOb;
			color** resultImage = new color*[howMany * 2];

			for (int i = 0; i < howMany * 2; i++) {
				resultImage[i] = new color[maxValue];
				for (int j = 0; j < maxValue; j++) {
					resultImage[i][j] = color(255, 255, 255);
				}
			}

			int i = 0;
			for (typename std::map<T, int>::iterator it = counterMap.begin(); it != counterMap.end(); ++it) {
					for (int j = 0; j < it->second; j++) {\
						if (std::is_same<T, color>::value) {
							resultImage[i][j] = it->first;
						}
						else if (std::is_same<T, int>::value) {
							resultImage[i][j] = color(it->first);
						}
						else {
							resultImage[i][j] = color(255, 0, 0);
						}
					}
					i += 2;
			}
			outputOb = new ppm(fileName, resultImage, howMany * 2, maxValue);
			outputOb->write(fileName);
		}

		//metoda czyszczaca nasz licznik czestotliwosci
		void clearMap() {
			counterMap.clear();
			howMany = 0;
			maxValue = 0;
		}

		//metoda zwracajaca maksymalna ilosc w mapie
		int getMaxValue() const{
			return maxValue;
		}

		//metoda zwracajaca ilosc kluczy w mapie
		int getHowMany() const{
			return howMany;
		}

		//metoda kasujaca dany klucz z mapy
		void erase(T value) {
			counterMap.erase(value);
		}
};

//przeciazony operator porownania mniejszosci dla kolorow, stworzony specjalnie dla mapy
bool operator < (const color& leftColor, const color& rightColor) {
	return (leftColor.getRGBValue() < rightColor.getRGBValue());
}

//przeciazony operator przesuniecia bitowego dla strumienia, potrzebne do wypisywania kolorow na ekran/pliku w formie heksadecymalnej
std::ostream & operator << (std::ostream &out, const color &ourColor)
{
	out << "#" << std::hex << ourColor.getRGBValue() << std::dec;
	return out;
}

#endif