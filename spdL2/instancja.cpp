#include "instancja.h"

using namespace std;

instancja::instancja() {
	long ziarno;
	long suma = 0;

	cout << "Wprowadz ziarno losowania: ";
	cin >> ziarno;
	RandomNumberGenerator generator = RandomNumberGenerator(ziarno);

	cout << "Wprowadz rozmiar problemu: ";
	cin >> rozmiar;

	for (int i = 0; i < rozmiar; i++) {
		lista_zadan.push_back(zadanie());
		lista_zadan[i].j = i + 1;
		lista_zadan[i].p = generator.nextInt(1, 29);
		suma += lista_zadan[i].p;
	}

	for (int i = 0; i < rozmiar; i++) {
		lista_zadan[i].r = generator.nextInt(1, suma);
	}

	for (int i = 0; i < rozmiar; i++) {
		lista_zadan[i].q = generator.nextInt(1, 29); //29 lub suma
	}
}

void instancja::wypiszTabele() {
	cout << endl << "j: [";
	for (int i = 0; i < rozmiar; i++) {
		cout << lista_zadan[i].j;
		if (i == rozmiar - 1) { //jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "r: [";
	for (int i = 0; i < rozmiar; i++) {
		cout << lista_zadan[i].r;
		if (i == rozmiar - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}


	cout << endl << "p: [";
	for (int i = 0; i < rozmiar; i++) {
		cout << lista_zadan[i].p;
		if (i == rozmiar - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "q: [";
	for (int i = 0; i < rozmiar; i++) {
		cout << lista_zadan[i].q;
		if (i == rozmiar - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}
}

void instancja::wypiszPi(vector<long> pi) {
	cout << endl << "Pi: [";
	for (int i = 0; i < pi.size(); i++) {
		cout << pi[i];
		if (i == pi.size() - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}
}

void instancja::calculate() { //przeciazenie, aby moc policzyc przed wykonaniem schrege
	vector<long> pi;
	for (int i = 0; i < rozmiar; i++) {
		pi.push_back(lista_zadan[i].j);
	}
	calculate(pi);
}

void instancja::calculate(vector<long> pi) {

	vector <long> wektor_S; //wektor momentow rozpoczecia
	vector <long> wektor_C; //wektor momentow zakonczen
	vector <zadanie> wektor_zadan_pi; //wekor zadan posortowany wedlug kolejnosci pi
	long C_max = 0;

	for (int i = 0; i < rozmiar; i++) { //sortowanie listy zadan wedlug kolejnosci PI
		for (int j = 0; j < rozmiar; j++) {
			if (lista_zadan[j].j == pi[i]) {
				wektor_zadan_pi.push_back(lista_zadan[j]);
			}
		}
	}

	//wg pseudokodu
	wektor_S.push_back(wektor_zadan_pi[0].r); 
	wektor_C.push_back(wektor_S[0] + wektor_zadan_pi[0].p);
	C_max = wektor_C[0] + wektor_zadan_pi[0].q;

	for (int j = 1; j < rozmiar; j++) {
		wektor_S.push_back(max(wektor_zadan_pi[j].r, wektor_C[j - 1]));
		wektor_C.push_back(wektor_S[j] + wektor_zadan_pi[j].p);
		C_max = max(C_max, wektor_C[j] + wektor_zadan_pi[j].q);
	}

	cout << endl << "Cmax = " << C_max;

	cout << endl << "S: [";
	for (int i = 0; i < rozmiar; i++) {
		cout << wektor_S[i];
		if (i == rozmiar - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "C: [";
	for (int i = 0; i < rozmiar; i++) {
		cout << wektor_C[i];
		if (i == rozmiar - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "Cq: [";
	for (int i = 0; i < rozmiar; i++) {
		cout << wektor_C[i] + wektor_zadan_pi[i].q;
		if (i == rozmiar - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}
}

static bool min_r(const zadanie& zad1, const zadanie& zad2) {
	return zad1.r < zad2.r;
}

static bool max_q(const zadanie& zad1, const zadanie& zad2) {
	return zad1.q > zad2.q;
}

vector<long> instancja::Schrage() {

	//int k = 1; //nr zadania w permutacji 
	vector<long> pi; //permutacje
	vector<zadanie> wektor_G; //wektor zadan gotowych do realizacji
	vector<zadanie> wektor_N; //wektor zadan nieuszeregowanych

	for (int i = 0; i < rozmiar; i++) {
		wektor_N.push_back(lista_zadan[i]);
	}

	sort(wektor_N.begin(), wektor_N.end(), min_r);

	long t = wektor_N[0].r; //chwila czasowa

	while (!wektor_G.empty() || !wektor_N.empty()) {

		while (!wektor_N.empty() && wektor_N[0].r <= t) {

			wektor_G.push_back(wektor_N[0]);
			wektor_N.erase(wektor_N.begin());
		}

		if (!wektor_G.empty()) {
			sort(wektor_G.begin(), wektor_G.end(), max_q);
			pi.push_back(wektor_G[0].j);
			t += wektor_G[0].p;
			wektor_G.erase(wektor_G.begin());
		}
		else
			t = wektor_N[0].r;
	}

	return pi;
}

