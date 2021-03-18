#ifndef INSTANCJA_H
#define INSTANCJA_H
#include "zadanie.h"

class instancja
{
public:
	zadanie* tablica;
	long rozmiar;

	instancja();
	void wypiszTabele();
	int calculate();
	int Schrage();
protected:
};

#endif