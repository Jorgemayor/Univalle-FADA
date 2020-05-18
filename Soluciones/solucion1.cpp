#include <iostream>
#include <string.h>
#include <map>
#include <tuple>
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
 * @return animals map --> Maps that relates all
 * animals with their awesomeness.
 */
map<string, int> getAnimals(ifstream & file) {
	
	string name;
	int awesomeness;
	map<string, int> animals;
	for(int i=0; i<n; i++){
		file >> name >> awesomeness;
		animals[name] = awesomeness;
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
void getShow(ifstream & file) {

	string firstAnimal, secondAnimal, thirdAnimal;
	auto show = new tuple<string, string, string>[60][60];
	show[0][0] = make_tuple("rhazek", "nico", "jorge");
	cout << "El más gay, " << get<0>(show[0][0]) << endl;
	//return 0;
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
	map<string, int> animals = getAnimals(file);
	getShow(file);
	cout << "test " << animals["Mariposa"] << endl;
	return 0;
}
