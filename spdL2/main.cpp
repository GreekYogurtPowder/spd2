#include <iostream>
#include "instancja.h"
#include "RandomNumberGenerator.h"
using namespace std;


int main()
{
	instancja inst = instancja();
	inst.wypiszTabele();
	//inst.calculate();
	long* tab = inst.Schrage();
	
	cout << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout <<tab[i] << " ";
	}

	return 0;
}