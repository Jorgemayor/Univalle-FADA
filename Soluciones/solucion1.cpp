#include <iostream>
#include <string.h>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

int n, m, k;

/**
 * Gets the input from the specific testCase.
 * All the inputs must be in Pruebas directory.
 * 
 * @param testCase string --> Name of testCase file
 * @return animals pointer --> Pointer to animals array, declared locally.
 */
pair<string, int>* getInput(const string& testCase) {
	
	ifstream archivo("../Pruebas/" + testCase + ".txt");
	string name;
	int grandeza;
	archivo >> n >> m >> k;
	auto animals = new pair<string, int>[n];
	for(int i=0; i<n; i++){
			archivo >> name >> grandeza;
		animals[i] = make_pair(name, grandeza);
	}
	return animals;
}

void someKindOfSort(pair<string, int>* animals) {
	
	pair<string, int> sortedArray[n];
	for(int i=0; i<n; i++)
		sortedArray[animals[i].second - 1] = animals[i];
	for(int i=0; i<n; i++)
		animals[i] = sortedArray[i];
}

//Desde acá hasta la fución main



/**
 * Main function
 *
 */
int main() {
	
	string testcase = "prueba3";
	pair<string, int>* animals = getInput(testcase);
	someKindOfSort(animals);
	for(int i=0; i<n; i++) {
		cout << "a: " << animals[i].first << " g: " << animals[i].second << endl;
	}
	return 0;
}
