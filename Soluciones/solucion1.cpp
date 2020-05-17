#include <iostream>
#include <string.h>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

int n, m, k;

pair<string, int>* getInput(string testcase) {
	
	ifstream archivo("../Pruebas/"+testcase+".txt");
	string name;
	int grandeza;
	archivo >> n >> m >> k;
	pair<string,int>* animals = new pair<string, int>[n];
	for(int i = 0; i<n; i++){
			archivo >> name >> grandeza;
		animals[i] = make_pair(name, grandeza);
	}
	return animals;
}

void someKindOfSort (pair<string, int>* animals) {
	
	pair<string, int> sortedArray[n];
	for(int i=0; i<n; i++)
		sortedArray[animals[i].second - 1] = animals[i];
	for(int i=0; i<n; i++)
		animals[i] = sortedArray[i];
}

int main() {
	
	string testcase = "prueba3";
	pair<string, int>* animals = getInput(testcase);
	someKindOfSort(animals);
/*	for(int i=0; i<n; i++) {
		cout << "a: " << animals[i].first << " g: " << animals[i].second << endl;
	}*/
	return 0;
}
