////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 5 - Szablony 
//
// Program sluzacy do zliczania ilosci pojedynczych znakow/slow/liczb/kolorow
//
// Autor - Mateusz Krzeszewski
//
// 11.12.2018 - utworzenie programu
//
// UPDATES
//
// 12.12.2018 - zmiana sposobu obslugi plikow - teraz pliki ladowane sa do stringow w mainie, nie w metodzie addData /MK
// 13.12.2018 - dodano obsluge TRY-THROW-CATCH - jezeli ktorys z plikow odczytywanych zaladuje sie niepoprawnie - program przestaje dzialac.
//
////////////////////////////////////////////////////////////////
#include "freqcounter.h"

//niezbedna biblioteka aby pobierac ziarno dla generowania liczb pseudolosowych
#include <time.h>

int main(void) {
	
	//ustawienie ziarna dla generatora liczb losowych
	srand((unsigned int)time(NULL));
	
	freqcounter<int> fq_rand;
	freqcounter<char> fq_charEN;
	freqcounter<char> fq_charIT;
	freqcounter<char> fq_charPL;
	freqcounter<std::string> fq_stringEN;
	freqcounter<std::string> fq_stringIT;
	freqcounter<std::string> fq_stringPL;
	freqcounter<color> fq_ppm;

	////////////////////////////////////
	//stringi w ktorych bedziemy przechowywac pliki
	//
	std::string bibliaEN="";
	std::string bibliaPL="";
	std::string bibliaIT="";

	std::ifstream inFile("biblia-en.txt");
	if (inFile) {
		inFile.seekg(0, std::ios::end);
		std::streamoff len = inFile.tellg();
		inFile.seekg(0);
		std::string contents(long(len) + 1, '\0');
		inFile.read(&contents[0], len);
		bibliaEN = contents;
	}
	inFile.close();

	////////////////////////////////////
	//ladujemy 3 pliki bibli do stringow
	//
	inFile.open("biblia-pl_ksiega_rdzaju_3.txt");
	if (inFile) {
		inFile.seekg(0, std::ios::end);
		std::streamoff len = inFile.tellg();
		inFile.seekg(0);
		std::string contents(long(len) + 1, '\0');
		inFile.read(&contents[0], len);
		bibliaPL = contents;
	}
	inFile.close();
	
	inFile.open("biblia-it.txt");
	if (inFile) {
		inFile.seekg(0, std::ios::end);
		std::streamoff len = inFile.tellg();
		inFile.seekg(0);
		std::string contents(long(len) + 1, '\0');
		inFile.read(&contents[0], len);
		bibliaIT = contents;
	}
	inFile.close();

	try {
		if (bibliaEN == "") {
			throw "BLAD! Nie laduje Ci danych do bibliaEN!";
		}
		if (bibliaIT == "") {
			throw "BLAD! Nie laduje Ci danych do bibliaIT!";
		}
		if (bibliaPL == "") {
			throw "BLAD! Nie laduje Ci danych do bibliaPL!";
		}
	}
	catch (const char* error) {
		std::cerr << error << std::endl;
		std::cout << "Program konczy dzialanie!" << std::endl;
		system("pause");
		return 666;
	}


	////////////////////////////////////
	//zczytujemy char'y ze stringow
	//
	for (size_t i = 0; i < bibliaEN.length(); i++) {
		fq_charEN.addData(bibliaEN[i]);
	}

	//usuwamy znaki nowej linii - nie widze sensu umieszczania ich w pliku (ich ilosc jest zmienna w zaleznosci od tego jak biblia zostala zapisana w formacie txt)
	fq_charEN.erase('\n');
	fq_charEN.createText("biblia-en-result-chars.txt");

	for (size_t i = 0; i < bibliaIT.length(); i++) {
		fq_charIT.addData(bibliaIT[i]);
	}

	//usuwamy znaki nowej linii po czym zapisujemy wyniki do pliku txt
	fq_charIT.erase('\n');
	fq_charIT.createText("biblia-it-result-chars.txt");

	for (size_t i = 0; i < bibliaPL.length(); i++) {
		fq_charPL.addData(bibliaPL[i]);
	}

	//usuwamy znaki nowej linii po czym zapisujemy wyniki do pliku txt
	fq_charPL.erase('\n');
	fq_charPL.createText("biblia-pl-result-chars.txt");


	////////////////////////////////////
	//zczytujemy slowa z biblii
	//
	std::string temp = "";
	for (size_t i = 0; i < bibliaEN.length(); i++) {
		if ((bibliaEN[i] == ' ' || bibliaEN[i] == '\n') && temp != "") {
			fq_stringEN.addData(temp);
			temp = "";
		}
		else {
			if (bibliaEN[i] != '\n') {
				temp += bibliaEN[i];
			}
		}
	}

	//tworzymy liste w txt dla naszych slow z biblii
	fq_stringEN.createText("biblia-en-result-string.txt");


	temp = "";
	for (size_t i = 0; i < bibliaIT.length(); i++) {
		if ((bibliaIT[i] == ' ' || bibliaIT[i] == '\n') && temp != "") {
			fq_stringIT.addData(temp);
			temp = "";
		}
		else {
			if (bibliaIT[i] != '\n') {
				temp += bibliaIT[i];
			}
		}
	}

	//tworzymy liste w txt dla naszych slow z biblii
	fq_stringIT.createText("biblia-it-result-string.txt");


	temp = "";

	for (size_t i = 0; i < bibliaPL.length(); i++) {
		if ((bibliaPL[i] == ' ' || bibliaPL[i] == '\n') && temp != "") {
			fq_stringPL.addData(temp);
			temp = "";
		}
		else {
			if (bibliaPL[i] != '\n') {
				temp += bibliaPL[i];
			}
		}
	}

	//tworzymy liste w txt dla naszych slow z biblii
	fq_stringPL.createText("biblia-pl-result-string.txt");


	////////////////////////////////////
	//generujemy 1000000 liczb losowych i wpisujemy je do mapy
	//
	for (int i = 0; i < 1000000; i++) {
		fq_rand.addData(rand() % 1000);
	}


	//tworzymy wykres wraz z lista w txt dla naszych losowych danych
	fq_rand.createText("random-result-list.txt");
	fq_rand.createImage("random-result-image.ppm");


	////////////////////////////////////
	//zczytujemy ile jest jakich kolorow w danym obrazku - za przyklad uzywam lenny z zadania 4.
	//
	obraz *ob = new ppm("lenna.ppm");

	//pomocnicza tablia 2D o wartosciach kolorow z naszego obrazka
	color **myImage = new color*[ob->getXIndex()];
	for (int i = 0; i < ob->getXIndex(); i++) {
		myImage[i] = new color[ob->getYIndex()];
	}
	myImage = ob->returnMatrix();

	//zczytujemy z pomocniczej tablicy wartosci kolorow do naszego licznika
	for (int i = 0; i < ob->getXIndex(); i++) {
		for (int j = 0; j < ob->getYIndex(); j++) {
			fq_ppm.addData(myImage[i][j]);
		}
	}

	//tworzymy wykres wraz z lista w txt dla naszego obrazu
	fq_ppm.createText("obraz-result-list.txt");
	fq_ppm.createImage("obraz-result-image.ppm");

	//czyscimy pomocnicza tablice
	for (int i = 0; i < ob->getXIndex(); i++) {
		delete[] myImage[i];
	}
	delete[] myImage;

	system("pause");
	return 0;
}
