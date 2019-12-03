#ifndef MACIERZ_H_INCLUDED
#define MACIERZ_H_INCLUDED
#include <iostream>
class macierz{
	protected:
		double **matrix;
		int howManyLines;
		int howManyColumns;
	public:
		macierz(); //Konstruktor bezparametrowy, tworzy tablicê dynamiczn¹ przyjmuj¹ca za wartoœci tablice dynamiczne (koniec koñców mamy macierz 2x2) o wartoœciach 0.0 w ka¿dym indexie. 
		
		macierz(int howManyLines, int howManyColumns); //Konstruktor przyjmuj¹cy za parametry iloœæ wierszy i kolumn.
		
		~macierz(); //Destruktor, przy usuwaniu obiektu usuwa tablice dynamiczne.
		
		macierz(const macierz &copyMatrix); //Konstruktor kopiuj¹cy, tworzy now¹ macierz po czym po kolei przypisuje do niej wartoœci z podanej w parametrze macierzy.
		
		void view(); //Metoda wyœwietlaj¹ca macierz w programie.
		
		void set(int linIndex, int colIndex, double value); //Metoda ustawiaj¹ca konkretn¹ wartoœæ w danej kolumnie w danym wierszu.
		
		double returnValue(int linIndex, int colIndex) const; //Metoda za pomoc¹ której mo¿emy pobraæ wartoœæ z danego wiersza/kolumny.
		
		void operator=(const macierz& secondMatrix); //Przeci¹¿ony operator przypisania, przypisuje wartoœci z drugiej macierzy do pierwszej.
		
		bool operator==(const macierz& secondMatrix); //Przeci¹¿ony operator porównania, zwraca wartoœæ "true", je¿eli wartoœci w konkretnych indexach s¹ sobie równe.
		
		macierz operator*(const macierz& secondMatrix); //Przeci¹¿ony operator mno¿enia, mno¿enie macierzowe.
		
		macierz operator+(const macierz& secondMatrix); //Przeci¹¿ony operator dodawania, dodajemy wartoœci w identycznych indexach macierzy.
		
		macierz operator-(const macierz& secondMatrix); //Przeci¹¿ony operator odejmowania, odejmujemy wartoœci w identycznych indexach macierzy.	
};
#endif
