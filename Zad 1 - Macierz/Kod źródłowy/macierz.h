#ifndef MACIERZ_H_INCLUDED
#define MACIERZ_H_INCLUDED
#include <iostream>
class macierz{
	protected:
		double **matrix;
		int howManyLines;
		int howManyColumns;
	public:
		macierz(); //Konstruktor bezparametrowy, tworzy tablic� dynamiczn� przyjmuj�ca za warto�ci tablice dynamiczne (koniec ko�c�w mamy macierz 2x2) o warto�ciach 0.0 w ka�dym indexie. 
		
		macierz(int howManyLines, int howManyColumns); //Konstruktor przyjmuj�cy za parametry ilo�� wierszy i kolumn.
		
		~macierz(); //Destruktor, przy usuwaniu obiektu usuwa tablice dynamiczne.
		
		macierz(const macierz &copyMatrix); //Konstruktor kopiuj�cy, tworzy now� macierz po czym po kolei przypisuje do niej warto�ci z podanej w parametrze macierzy.
		
		void view(); //Metoda wy�wietlaj�ca macierz w programie.
		
		void set(int linIndex, int colIndex, double value); //Metoda ustawiaj�ca konkretn� warto�� w danej kolumnie w danym wierszu.
		
		double returnValue(int linIndex, int colIndex) const; //Metoda za pomoc� kt�rej mo�emy pobra� warto�� z danego wiersza/kolumny.
		
		void operator=(const macierz& secondMatrix); //Przeci��ony operator przypisania, przypisuje warto�ci z drugiej macierzy do pierwszej.
		
		bool operator==(const macierz& secondMatrix); //Przeci��ony operator por�wnania, zwraca warto�� "true", je�eli warto�ci w konkretnych indexach s� sobie r�wne.
		
		macierz operator*(const macierz& secondMatrix); //Przeci��ony operator mno�enia, mno�enie macierzowe.
		
		macierz operator+(const macierz& secondMatrix); //Przeci��ony operator dodawania, dodajemy warto�ci w identycznych indexach macierzy.
		
		macierz operator-(const macierz& secondMatrix); //Przeci��ony operator odejmowania, odejmujemy warto�ci w identycznych indexach macierzy.	
};
#endif
