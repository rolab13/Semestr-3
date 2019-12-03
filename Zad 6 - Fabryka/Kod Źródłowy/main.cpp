#include "factory.h"

int main(void) {

	factory f;
	f.setExternalInfo("100");
	f.setOutput(factory::console);
	f.convert(1);
	f.convert(1.0);
	f.convert(1.0f);
	f.convert("Ala ma kota");
	f.convert('A');
	f.setOutput(factory::disk);
	f.setOutput(factory::console);

	f.setExternalInfo("mojmorsik");
	f.setOutput(factory::disk);
	f.convert("Pan da 4 pkt");

	f.setExternalInfo("200 200 400 1000");
	f.setOutput(factory::capslock);
	f.convert(123);

	f.setOutput(factory::beep);
	f.setExternalInfo("300 200 400 400 1000");
	f.convert(123);
	
	system("pause");
	return 0;
}
