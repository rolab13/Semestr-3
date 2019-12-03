#include "morse.h"

//konstruktor bezparametrowy
morse::morse()
	: frequency(666)
	, pauseTime(100)
	, dotTime(200)
	, dashTime(600)
	, charPause(200)
	, spacePause(800) {
}

//konstruktor z parametrami
morse::morse(int frequency_, int pauseTime_, int dotTime_, int dashTime_, int charPause_, int spacePause_)
	: frequency(frequency_)
	, pauseTime(pauseTime_)
	, dotTime(dotTime_)
	, dashTime(dashTime_)
	, charPause(charPause_)
	, spacePause(spacePause_) {
	if (dotTime > dashTime) {
		std::cerr << "Blad! Czas trwania sygnalu krotkiego nie moze byc dluzszy od czasu sygnalu dlugiego" << std::endl;
		std::cout << "zamieniam wartosci sygnalow miejscami" << std::endl;
		int temp = dotTime;
		dotTime = dashTime;
		dashTime = temp;
	}
	else if (dotTime == dashTime) {
		std::cerr << "Blad! Czas trwania sygnalu krotkiego musi byc krotszy od czasu sygnalu dlugiego" << std::endl;
		std::cout << "ustawiam dlugi sygnal rowny trzykrotnosci krotszego" << std::endl;
		dashTime *= 3;
	}
}

//destruktor
morse:: ~morse() {

}

//konstruktor kopiujacy
morse::morse(const morse &copyMorse) {
	this->frequency = copyMorse.frequency;
	this->pauseTime = copyMorse.pauseTime;
	this->dotTime = copyMorse.dotTime;
	this->dashTime = copyMorse.dashTime;
	this->charPause = copyMorse.charPause;
	this->spacePause = copyMorse.spacePause;
}

//przeciazony operator przypisania
morse morse::operator=(const morse& secondMorse) {
	this->frequency = secondMorse.frequency;
	this->pauseTime = secondMorse.pauseTime;
	this->dotTime = secondMorse.dotTime;
	this->dashTime = secondMorse.dashTime;
	this->charPause = secondMorse.charPause;
	return *this;
}

//przeciazony operator przesuniecia bitowego, sluzy jako strumien wypikujacy informacje w kodzie morsa
morse morse::operator<<(const std::string &sentence) {
	morse tempMorse(*this);
	std::string tempString;
	tempString = sentenceToMorse(sentence);

		for (size_t i = 0; i < tempString.length(); i++) {
			//std::cout << tempString[i];
			if (tempString[i] == '\n') {
				Sleep(tempMorse.spacePause);
			}
			else if (tempString[i] == ' ') {
				Sleep(tempMorse.charPause);
			}
			else {
				if (tempString[i] == '.') {
					tempMorse.beepDot();
				}
				else {
					tempMorse.beepDash();
				}
				Sleep(tempMorse.pauseTime);
			}
		}
	return *this;
}

//przeciazone operatory przesuniecia bitowego; zamieniaja wartosci argumentow na string i wywoluja przeciazony operator << dla stringow
morse morse::operator<< (bool &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}

morse morse::operator<< (short &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}
morse morse::operator<< (unsigned short &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}
morse morse::operator<< (const int &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}
morse morse::operator<< (const unsigned int &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}
morse morse::operator<< (const long &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}
morse morse::operator<< (const long long &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}
morse morse::operator<< (const unsigned long &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}

morse morse::operator<< (const unsigned long long &number) {
	std::string stringNumber = std::to_string(number);
	morse::operator<<(stringNumber);
	return *this;
}

//przeciazone operatory przesuniecia bitowego dla liczb zmiennoprzecinkowych - obsluguja do 15 miejsc po przecinku dla double'i i do 6 dla float'a
morse morse::operator<<(const long double &number) {
	std::ostringstream tempStringNumber;
	tempStringNumber << std::fixed;
	tempStringNumber << std::setprecision(15);
	tempStringNumber << number;
	std::string stringNumber = tempStringNumber.str();

	stringNumber = removeUselessZeroes(stringNumber);

	morse::operator<<(stringNumber);
	return *this;
}

morse morse::operator<<(const float &number) {
	std::ostringstream tempStringNumber;
	tempStringNumber << std::fixed;
	tempStringNumber << std::setprecision(6);
	tempStringNumber << number;
	std::string stringNumber = tempStringNumber.str();

	stringNumber = removeUselessZeroes(stringNumber);

	morse::operator<<(stringNumber);
	return *this;
}

morse morse::operator<<(const double &number) {
	morse::operator<<(long double (number));
	return *this;
}

//przeciazony operator przesuniecia bitowego dla specjalnie stworzonej klasy OBEJSCIEPAUZY zeby mozna bylo uzywac pause w main.cpp
morse morse::operator<< (OBEJSCIEPAUZY &pause) {
	Sleep(3000);
	return *this;
}

//settery
//ustawia wartosc czestotliwosci
void morse::setFrequency(int value) {
	frequency = value;
}

//ustawia wartosc pauzy miedzy piknieciami
void morse::setPause(int value) {
	pauseTime = value;
}

//ustawia wartosc czasu trwania pikniecia sygnalu krotkiego
void morse::setDotTime(int value) {
	if (dashTime <= value) {
		std::cerr << "Blad! Czas trwania sygnalu krotkiego musi byc krotszy od czasu sygnalu dlugiego! " << std::endl;
	}
	else {
		dotTime = value;
	}
}

//ustawia wartosc czasu trwania pikniecia sygnalu dlugiego
void morse::setDashTime(int value) {
	if (dotTime >= value) {
		std::cerr << "Blad! Czas trwania sygnalu dlugiego musi byc dluzszy od czasu sygnalu krotkiego! " << std::endl;
	}
	else {
		dashTime = value;
	}
}

//ustawia wartosc pauzy miedzy znakami w kodzie morsa
void morse::setCharPause(int value) {
	charPause = value;
}

//ustawia wartosc pauzy miedzy slowami (wartosc dla spacji)
void morse::setSpacePause(int value) {
	spacePause = value;
}

//gettery
//pobiera wartosc czestotliwosci
int morse::getFrequency() {
	return this->frequency;
}

//pobiera wartosc pauzy miedzy piknieciami
int morse::getPause() {
	return this->pauseTime;
}

//pobiera wartosc czasu trwania pikniecia sygnalu krotkiego
int morse::getDotTime() {
	return this->dotTime;
}

//pobiera wartosc czasu trwania pikniecia sygnalu dlugiego
int morse::getDashTime() {
	return this->dashTime;
}

//pobiera wartosc pauzy miedzy znakami w kodzie morsa
int morse::getCharPause() {
	return this->charPause;
}

//pobiera wartosc pauzy miedzy slowami (wartosc dla spacji)
int morse::getSpacePause() {
	return this->spacePause;
}

//metoda wypikujaca sygnal krotki	
void morse::beepDot() {
	Beep(this->frequency, this->dotTime);
}

//metoda wypikujaca sygnal dlugi	
void morse::beepDash() {
	Beep(this->frequency, this->dashTime);
}


