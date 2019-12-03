#include "morse_capslock.h"

//konstruktor bezparametrowy
morse_capslock::morse_capslock() :
	morse(),
	dotBeepTime(200),
	dashBeepTime(500),
	pauseBetweenBeep(200),
	pauseBetweenChar(600) {
}

//destruktor nie-wirtualny
morse_capslock::~morse_capslock() {

}

//konstruktor kopiujacy
morse_capslock::morse_capslock(const morse_capslock &secondMorse) :
	morse(secondMorse),
	dotBeepTime(secondMorse.dotBeepTime),
	dashBeepTime(secondMorse.dashBeepTime),
	pauseBetweenBeep(secondMorse.pauseBetweenBeep),
	pauseBetweenChar(secondMorse.pauseBetweenChar) {

}

//operator przypisania
morse_capslock morse_capslock::operator=(const morse_capslock &secondMorse) {
	if (this != &secondMorse) {
		this->dotBeepTime = secondMorse.dotBeepTime;
		this->dashBeepTime = secondMorse.dashBeepTime;
		this->pauseBetweenBeep = secondMorse.pauseBetweenBeep;
		this->pauseBetweenChar = secondMorse.pauseBetweenChar;
	}
	return *this;
}

void morse_capslock::returnMorse(const std::string &morseMessage) {
	std::string tempString = morse::sentenceToMorse(morseMessage);
	for (size_t i = 0; i < tempString.length(); i++) {
		if (tempString[i] == '\n') {
			Sleep(pauseBetweenChar);
		}
		else if (tempString[i] == ' ') {
			Sleep(pauseBetweenChar);
		}
		else {
			if (tempString[i] == '.') {
				beep(dotBeepTime);
			}
			else {
				beep(dashBeepTime);
			}
			Sleep(pauseBetweenBeep);
		}
	}
}

//metoda zmieniajaca aktualny stan capslocka
void morse_capslock::capslockBlink() {
	INPUT in[2];
	in[0].type = INPUT_KEYBOARD;
	in[0].ki.wVk = VK_CAPITAL;
	in[0].ki.wScan = 0;
	in[0].ki.time = 0;
	in[0].ki.dwFlags = 0;
	in[0].ki.dwExtraInfo = 0;
	in[1] = in[0];
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(2, in, sizeof(INPUT));
}

//metoda zmieniajaca stan capslock'a na czas podany w parametrze
void morse_capslock::beep(const int &time) {
	capslockBlink();
	Sleep(time);
	capslockBlink();
}

//setter czasu trwania kropki
void morse_capslock::setDotBeepTime(const int &value) {
	this->dotBeepTime = value;
}

//setter czasu trwania dash-a
void morse_capslock::setDashBeepTime(const int &value) {
	this->dashBeepTime = value;
}

//setter czasu pauzy miedzy sygnalami
void morse_capslock::setPauseBetweenBeep(const int &value) {
	this->pauseBetweenBeep = value;
}

//setter czasu pauzy miedzy znakami
void morse_capslock::setPauseBetweenChar(const int &value) {
	this->pauseBetweenChar = value;
}

///////////////////
//metoda setInfo przeciazona dla roznych kombinacji parametrow

//setInfo dla czterech wartosci - kolejno czas pauzy miedzy znakami
void morse_capslock::setInfo(const int &value) {
	setPauseBetweenChar(value);
}

//setInfo dla czterech wartosci - kolejno czas pauzy miedzy znakami, czas trwania sygnalu krotkiego
void morse_capslock::setInfo(const int &value1, const int &value2) {
	setInfo(value1);
	setDotBeepTime(value2);
}

//setInfo dla czterech wartosci - kolejno czas pauzy miedzy znakami, czas trwania sygnalu krotkiego, czas trwania sygnalu dlugiego
void morse_capslock::setInfo(const int &value1, const int &value2, const int &value3) {
	setInfo(value1, value2);
	setDashBeepTime(value3);
}

//setInfo dla czterech wartosci - kolejno czas pauzy miedzy znakami, czas trwania sygnalu krotkiego, czas trwania sygnalu dlugiego, czas pauzy miedzy sygnalami
void morse_capslock::setInfo(const int &value1, const int &value2, const int &value3, const int &value4) {
	setInfo(value1, value2, value3);
	setPauseBetweenBeep(value4);
}
