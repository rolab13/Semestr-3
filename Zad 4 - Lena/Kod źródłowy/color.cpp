#include "color.h"

//konstruktor bezparametrowy
color::color()
	: redValue(0)
	, greenValue(0)
	, blueValue(0)
	, rgbValue(0){
}

//konstruktor parametrowy przyjmujacy za parametry poszczegolne wartosci RGB
color::color(short redValue, short greenValue, short blueValue)
	: redValue(redValue)
	, greenValue(greenValue)
	, blueValue(blueValue)
	, rgbValue((redValue * 256 * 256) + (greenValue * 256) + blueValue) {
}

//konstruktor parametrowy przyjmujacy za parametr pelna wartosc koloru w RGB
color::color(long RGBValue)
	: redValue(unsigned short(RGBValue / 256 / 256))
	, greenValue(unsigned short(RGBValue / 256 - (redValue * 256)))
	, blueValue(unsigned short (RGBValue - (greenValue * 256) - (redValue * 256 * 256)))
	, rgbValue(RGBValue){
}

//destruktor niewirtualny, nie przewiduje dziedziczenia z pojedynczego pixela(koloru)
color::~color() {

}

//konstruktor kopiujacy
color::color(const color &secondColor)
	: redValue(secondColor.redValue)
	, greenValue(secondColor.greenValue)
	, blueValue(secondColor.blueValue)
	, rgbValue(secondColor.rgbValue) {
}

/*metoda wyswietlajaca wartosci koloru (sluzy tylko dla sprawdzenia)
void color::readColor() {
	std::cout << "Red : " << redValue
			  << "\nGreen : " << greenValue
			  << "\nBlue : " << blueValue << std::endl;
}
*/

//operator przypisania
color color::operator=(const color &secondColor) {
	if (*this == secondColor) {
		return *this;
	}
	else {
		this->redValue = secondColor.redValue;
		this->greenValue = secondColor.greenValue;
		this->blueValue = secondColor.blueValue;
		this->rgbValue = secondColor.rgbValue;

		return *this;
	}
}

//operator porownania zwracajacy wartosc true jezeli kazda skladowa RGB jest rowna w obu obiektach
bool color::operator==(const color &secondColor) {
	if (this->redValue == secondColor.redValue
		&& this->greenValue == secondColor.greenValue
		&& this->blueValue == secondColor.blueValue) {
		return true;
	}
	else {
		return false;
	}
}

//operator porownania zwracajacy wartosc false jezeli kazda skladowa RGB jest rowna w obu obiektach
bool color::operator!=(const color &secondColor) {
	if (this->redValue == secondColor.redValue
		&& this->greenValue == secondColor.greenValue
		&& this->blueValue == secondColor.blueValue) {
		return false;
	}
	else {
		return true;
	}
}

//metoda zwracajaca wartosc koloru czerwonego 
short color::getRedValue() {
	return redValue;
}

//metoda zwracajaca wartosc koloru zielonego
short color::getGreenValue() {
	return greenValue;
}

//metoda zwracajaca wartosc koloru niebieskiego 
short color::getBlueValue() {
	return blueValue;
}

//metoda zwracajaca wartosc koloru w postaci (R)*256*256 + (G)*256 + (B)
long color::getRGBValue() {
	return rgbValue;
}