#include <iostream>
#include "instancja.h"
#include "RandomNumberGenerator.h"
using namespace std;


int main()
{
	instancja inst = instancja();
	inst.wypiszTabele();
	inst.calculate();

    return 0;
}
