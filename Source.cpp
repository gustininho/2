#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include "singleton.h"


using namespace std;

int i =INT_MAX;
void ivedimas (int B[],int &n);
int kiek_gyventoju (int B[], int n);
void isvedimas (int  B[],int n, ofstream & rez);

int main () {

	Singleton::Instance()->writeToLogFile();
	system("pause");

	ofstream f2 ("Rezultatai.txt");
	int B[20];
	int n;

	ivedimas(B,n);
	isvedimas(B,n, f2);
	
	f2 << "-----------------" << endl;
	f2 << "Gyventoju kiekis " << kiek_gyventoju(B,n) <<endl;

	return 0;
}

void ivedimas (int B[],int &n){
	ifstream f1 ("Namas.txt");
	f1 >> n;
	for (int i=1;i<=n;i++){
		f1 >> B[i];
	}
}

int kiek_gyventoju (int B[], int n){
	int suma=0;
	for (int i=1;i<=n;i++){
		suma = B[i] + suma;
	}
	return suma;
}

void isvedimas (int  B[],int n, ofstream & rez){
		for (int i=1;i<=n;i++){
			rez << " " << "Buto numeris: "<< i << "  " << setw(3) << "Gyventoju skaicius: "<< B[i] << endl;
		}
}