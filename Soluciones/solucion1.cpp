#include <iostream>
#include <string.h>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

int n, m, k;

/**
 * Reads the input related to the animals from an
 * specific test case in the directory Pruebas.
 * 
 * @param file ifstream --> Test case file.
 * @return animals pointer --> Pointer to animals' array, declared locally.
 */
pair<string, int>* getAnimals(ifstream & file) {
	
	string name;
	int awesomeness;
	auto animals = new pair<string, int>[n];
	for(int i=0; i<n; i++){
			file >> name >> awesomeness;
		animals[i] = make_pair(name, awesomeness);
	}
	return animals;
}

/**
 * Reads the input related to the show from an
 * specific test case in the directory Pruebas.
 *
 * @param file ifstream --> Test case file.
 * @return show pointer --> Pointer to show's matrix, declared locally.
 */
tuple<string, string, string>* getShow(ifstream & file) {

	string firstAnimal, secondAnimal, thirdAnimal;
	auto show = new tuple<string, string, string>[m][k*(m-1)];
	show[0] = make_tuple("rhazek", "nico", "jorge");

	return tuple;
	
}


/**
 * Sorts the given animals due to their awesomeness
 * 
 * @param animals pointer --> Pointer of the given
 * array of animals to sort
 */
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
	
	string testCase = "prueba3";
	ifstream file ("../Pruebas/" + testCase + ".txt");
	file >> n >> m >> k;
	pair<string, int>* animals = getAnimals(file);
	tuple<string, string, string>* show = getShow(file);
	someKindOfSort(animals);
	for(int i=0; i<n; i++) {
		cout << "a: " << animals[i].first << " g: " << animals[i].second << endl;
	}
	return 0;
}
