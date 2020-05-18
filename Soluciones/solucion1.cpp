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

	string animal;
	string show[m][k*(m-1)][3];

	for(int i=0; i<k*(m-1); i++){
		file>>animal;
		show[0][i][0] = animal;
		file>>animal;
		show[0][i][1] = animal;
		file>>animal;
		show[0][i][2] = animal;
	}

	for(int i=1; i<m; i++){

		for(int j=0; j<k; j++){
			file>>animal;
			show[i][j][0] = animal;
			file>>animal;
			show[i][j][1] = animal;
			file>>animal;
			show[i][j][2] = animal;
		}
	}

	
}

//Desde acá hasta la fución main

tuple<string, string, string> escena0 = make_tuple("Cabra", "Mariposa","Leon");
tuple<string, string, string> escena1 = make_tuple("Jirafa", "Mariposa","Tortuga");
tuple<string, string, string> escena2 = make_tuple("Cabra", "Tortuga","Jirafa");





int grandezaEscena(tuple<string, string, string> escena, map<string, int> animales){

    int result = 0;
    result = animales[get<0>(escena)] + animales[get<1>(escena)] + animales[get<2>(escena)];
    //apply([](auto&&... args) {((cout << args << '\n'), ...);}, escena);
    return result;

}



int grandezaParte( tuple<string, string, string> parte[], map<string, int> animales){

    int result = 0;
    //Parte de prueba
    for(int i=0; i<k; i++){

        result += grandezaEscena(parte[i], animales);
    }

    return 0;
}

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
