#include <iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

using namespace std;

unsigned t0, t1;





int Len[4] = { 10000,15000,20000,25000 };
int Dimension[7] = { 4 ,6,8,10,12,18,20 };

// int Len[4] = { 200,300,400,500};
// int Dimension[7] = { 2,3,4,5,6,7,8};


void printVec(vector<vector<int>>& a) {
	int lenSubVector = a[0].size();

	for (vector<vector<int>>::iterator it = a.begin(); it != a.end(); ++it) {
		for (int j = 0; j < lenSubVector; j++)
			cout << (*it)[j] << " ";
		cout << endl;
	}
}



void distanciaEuclidiana(vector<int> *a, vector<int> *b) {
	double distancia=0;

	vector<int>::iterator itb = b->begin();
	for (vector<int>::iterator ita = a->begin(); ita != a->end(); ++ita,++itb) {
		distancia += pow((*itb) - (*ita), 2);
	}

	distancia = sqrt(distancia);
	//cout << distancia;
}


void distanciaEuclidiana(vector<vector<int>>* a) {
	for (vector<vector<int>>::iterator it1 = a->begin(); it1 != a->end(); ++it1) 
		for (vector<vector<int>>::iterator it2 = a->begin(); it2 != a->end(); ++it2) 
			distanciaEuclidiana(&(*it1),&(*it2));
}



void rellenar(vector<vector<int>> *a,int b) {
	int numero;
	srand(time(NULL));


	for (vector<vector<int>>::iterator it = a->begin(); it != a->end(); ++it){
		
		(*it).resize(b);
		for (int j = 0; j < b; j++)
		{
			numero = 1 + rand() % (101 - 1);
			(*it)[j] = numero;
		}
		
	}
	
}




void tiemposMultidimensional() {
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			vector<vector<int>> Vec(Len[i]);
			rellenar(&Vec,Dimension[j]);

			t0 = clock();
			distanciaEuclidiana(&Vec);
			t1 = clock();

			cout << (double(t1 - t0) / CLOCKS_PER_SEC)<<endl;
		}

	}

}

int main()
{
	tiemposMultidimensional();
    return 0;
}
