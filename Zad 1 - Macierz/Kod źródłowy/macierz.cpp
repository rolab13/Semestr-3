#include "macierz.h"

//Konstruktor bezparametrowy, tworzy tablic� dynamiczn� przyjmuj�ca za warto�ci tablice dynamiczne (koniec ko�c�w mamy macierz 2x2) o warto�ciach 0.0 w ka�dym indexie. 
macierz::macierz(){
	this->howManyLines = 2;
	this->howManyColumns = 2;
	matrix = new double * [2];
	for(int i=0;i<2;i++){
		matrix[i] = new double [2];
		for(int j=0;j<2;j++){
			matrix[i][j] = 0.0;
		}
	}
}

//Konstruktor przyjmuj�cy za parametry ilo�� wierszy i kolumn.
macierz::macierz(int howManyLines, int howManyColumns){
	this->howManyLines = howManyLines;
	this->howManyColumns = howManyColumns;
	matrix = new double * [howManyLines];
	for(int i=0;i<howManyLines;i++){
		matrix[i] = new double [howManyColumns];
		for(int j=0;j<howManyColumns;j++){
			matrix[i][j] = 0.0;
		}
	}
}

//Destruktor, przy usuwaniu obiektu usuwa tablice dynamiczne.
macierz::~macierz(){
	for(int i=0;i<howManyLines;i++){
		delete []matrix[i];
	}
	delete []matrix;
}
//Konstruktor kopiuj�cy, tworzy now� macierz 2x2 przy czym po kolei przypisuje do niej warto�ci z podanej w parametrze macierzy.
macierz::macierz(const macierz &copyMatrix){
	this->howManyColumns = copyMatrix.howManyColumns;
	this->howManyLines = copyMatrix.howManyLines;
	matrix = new double * [howManyLines];
	for(int i=0;i<howManyLines;i++){
		matrix[i] = new double [howManyColumns];
		for(int j=0;j<howManyColumns;j++){
			matrix[i][j] = copyMatrix.returnValue(i,j);
		}
	}
}

//Metoda wy�wietlaj�ca macierz w programie.
void macierz::view(){
	for(int i=0;i<howManyLines;i++){
		std::cout<<"(";
		for(int j=0;j<howManyColumns;j++){
			std::cout<<matrix[i][j];
			if(j<(howManyColumns-1))
			std::cout<<",";
		}
		std::cout<<")"<<std::endl;
	}
}

//Metoda ustawiaj�ca konkretn� warto�� w danej kolumnie w danym wierszu.
void macierz::set(int linIndex, int colIndex, double value){
	if(linIndex>=howManyLines){
		std::cerr<<"Blad! Podana liczba wierszy jest wieksza niz faktyczna liczba wierszy w macierzy."<<std::endl;
	}
	else if(colIndex>=howManyColumns){
		std::cerr<<"Blad! Podana liczba kolumn jest wieksza niz faktyczna liczba kolumn w macierzy."<<std::endl;
	}
	else{
		matrix[linIndex][colIndex]=value;
	}
}

//Metoda za pomoc� kt�rej mo�emy pobra� warto�� z danego wiersza/kolumny.
double macierz::returnValue(int linIndex, int colIndex) const{
	return matrix[linIndex][colIndex];
}

//Przeci��ony operator przypisania, przypisuje warto�ci z drugiej macierzy do pierwszej.
void macierz::operator=(const macierz& secondMatrix){
	if( (this->howManyColumns==secondMatrix.howManyColumns) && (this->howManyLines==secondMatrix.howManyLines) ){
		for(int i=0;i<this->howManyLines;i++){
			for(int j=0;j<this->howManyColumns;j++){
				this->set(i,j,secondMatrix.returnValue(i,j));
			}
		}
	}
	else{
		std::cerr<<"Nie mozesz przypisac macierzy do macierzy o innych rozmiarach!"<<std::endl;
	}
}

//Przeci��ony operator por�wnania, zwraca warto�� "true", je�eli warto�ci w konkretnych indexach s� sobie r�wne.
bool macierz::operator==(const macierz& secondMatrix){
	if( (this->howManyColumns==secondMatrix.howManyColumns) && (this->howManyLines==secondMatrix.howManyLines) ){
		bool isEqual=true;
		for(int i=0;i<this->howManyLines;i++){
			for(int j=0;j<this->howManyColumns;j++){
				if(this->returnValue(i,j) != secondMatrix.returnValue(i,j)){
					isEqual=false;
				}
			}
			if(isEqual==false){
				break; //Je�eli w dowolnym indexie warto�ci obu macierzy r�ni� si� od siebie p�tla por�wnuj�ca ko�czy si� natychmiastowo, odci��amy procesor.
			}
		}	
		return isEqual;
	}
	else{
		return false;
	}
}

//Przeci��ony operator mno�enia, mno�enie macierzowe.
macierz macierz::operator*(const macierz& secondMatrix) {
	if(this->howManyColumns==secondMatrix.howManyLines){
	    macierz tempMatrix(this->howManyLines,secondMatrix.howManyColumns);
		double temp = 0.0;
	    for(int i=0;i<this->howManyLines;i++){
	       	for(int j=0;j<secondMatrix.howManyColumns;j++){
	       		temp = 0.0;
	       		for(int d=0;d<this->howManyLines;d++){
	       			temp += this->returnValue(i,d) * secondMatrix.returnValue(d,j);
				}
				tempMatrix.set(i,j,temp);
			}
		}
	    return tempMatrix;
	}
	else{
		std::cerr<<"Blad! Nie mozesz pomnozyc macierzy, ktore maja rozna ilosc kolumn / wierszy."<<std::endl;
		macierz tempMatrix(0,0);
		return tempMatrix;
	}
}

//Przeci��ony operator dodawania, dodajemy warto�ci w identycznych indexach macierzy.
macierz macierz::operator+(const macierz& secondMatrix){
	if( (this->howManyColumns==secondMatrix.howManyColumns) && (this->howManyLines==secondMatrix.howManyLines) ){
		macierz tempMatrix;
		double temp;
		for(int i=0;i<this->howManyLines;i++){
			for(int j=0;j<this->howManyColumns;j++){
				temp = 0.0;
				temp = this->returnValue(i,j) + secondMatrix.returnValue(i,j);
				tempMatrix.set(i,j,temp);	
			}
		}	
		return tempMatrix;
	}
	else{
		std::cerr<<"Nie mozesz dodawac do siebie macierzy o roznych rozmiarach!"<<std::endl;
		macierz tempMatrix(0,0);
		return tempMatrix;
	}
}

//Przeci��ony operator odejmowania, odejmujemy warto�ci w identycznych indexach macierzy.
macierz macierz::operator-(const macierz& secondMatrix){
	if( (this->howManyColumns==secondMatrix.howManyColumns) && (this->howManyLines==secondMatrix.howManyLines) ){
		macierz tempMatrix;
		double temp;
		for(int i=0;i<this->howManyLines;i++){
			for(int j=0;j<this->howManyColumns;j++){
				temp = 0.0;
				temp = this->returnValue(i,j) - secondMatrix.returnValue(i,j);
				tempMatrix.set(i,j,temp);	
			}
		}	
		return tempMatrix;
	}
	else{
		std::cerr<<"Nie mozesz odejmowac od siebie macierzy o roznych rozmiarach!"<<std::endl;
		macierz tempMatrix(0,0);
		return tempMatrix;
	}
}



	

