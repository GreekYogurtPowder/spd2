#include "instancja.h"
#include "zadanie.h"
#include "RandomNumberGenerator.h"
#include <iostream>
#include <algorithm>

using namespace std;

instancja::instancja() {
	long ziarno;
	long suma = 0;

	cout << "Wprowadz ziarno losowania: ";
	cin >> ziarno;
	RandomNumberGenerator generator = RandomNumberGenerator(ziarno);

	cout << "Wprowadz rozmiar problemu: ";
	cin >> rozmiar;

	long* tablica_j = new long[rozmiar];
	long* tablica_r = new long[rozmiar];
	long* tablica_p = new long[rozmiar];
	long* tablica_q = new long[rozmiar];

	for (int i = 0; i < rozmiar; i++) {
		tablica_j[i] = i + 1;
		tablica_p[i] = generator.nextInt(1, 29);
		suma += tablica_p[i];
	}

	for (int i = 0; i < rozmiar; i++) {
		tablica_r[i] = generator.nextInt(1, suma);
	}

	for (int i = 0; i < rozmiar; i++) {
		tablica_q[i] = generator.nextInt(1, 29);
	}

	tablica = new zadanie[rozmiar];

	for (int i = 0; i < rozmiar; i++) {
		tablica[i] = zadanie(i + 1, tablica_r[i], tablica_p[i], tablica_q[i]);
	}
}

void instancja::wypiszTabele() {
	cout << endl << "nr: ";
	for (int i = 0; i < rozmiar; i++) {
		cout << tablica[i].j << " ";
	}

	cout << endl << "r:  ";
	for (int i = 0; i < rozmiar; i++) {
		cout << tablica[i].r << " ";
	}


	cout << endl << "p:  ";
	for (int i = 0; i < rozmiar; i++) {
		cout << tablica[i].p << " ";
	}

	cout << endl << "q:  ";
	for (int i = 0; i < rozmiar; i++) {
		cout << tablica[i].q << " ";
	}
}

int instancja::calculate() {

	long* tablica_S = new long[rozmiar]; //tablica momentow rozpoczecia
	long* tablica_C = new long[rozmiar]; //tablica momentow zakonczen
	long C_max;

	tablica_S[0] = tablica[0].r;
	tablica_C[0] = tablica_S[0] + tablica[0].p;
	C_max = tablica_C[0] + tablica[0].q;

	for (int j = 1; j < rozmiar; j++) {

		tablica_S[j] = max(tablica[j].r, tablica_C[j - 1]);
		tablica_C[j] = tablica_S[j] + tablica[j].p;
		C_max = max(C_max, tablica_C[j] + tablica[j].q);
	}

	return C_max;

}

int instancja::Schrage() {

	int k = 1; //nr zadania w permutacji 


	zadanie* tablica_G = new zadanie[rozmiar]; //tablica zadan gotowych do realizacji
	zadanie* tablica_N = new zadanie[rozmiar]; //tablica zadan nieuszeregowanych


	for (int j = 0; j < rozmiar; j++) {

		tablica_N[j] = zadanie(tablica[j].j, tablica[j].r, tablica[j].p, tablica[j].q);
	}

	long t = tablica[0].r; //chwila czasowa

	for (int j = 1; j < rozmiar; j++) {

		if (t > tablica[j].r)
			t = tablica[j].r;

	}



	return 0;



}