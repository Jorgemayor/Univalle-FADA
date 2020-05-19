#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

int n, m, k;
map<string, int> animals;
vector<vector<vector<string>>> show;

/**
 * Reads the input related to the animals from an
 * specific test case in the directory Pruebas.
 * 
 * @param file ifstream --> Test case file.
 */
void setAnimals(ifstream & file) {
	
	string name;
	int awesomeness;
	for(int i=0; i<n; i++){
		file >> name >> awesomeness;
		animals[name] = awesomeness;
	}
}

/**
 * Reads the input related to the show from an
 * specific test case in the directory Pruebas.
 *
 * @param file ifstream --> Test case file.
 */
void setShow(ifstream & file){
	
	vector<vector<string>> part;
	vector<string> scene;
	string animal;

	for(int i=0; i<k*(m-1); i++){
		scene.clear();

		file>>animal;
		scene.push_back(animal);
		file>>animal;
		scene.push_back(animal);
		file>>animal;
		scene.push_back(animal);

		part.push_back(scene);
	}

	show.push_back(part);
	
	for(int i=1; i<m; i++){
		part.clear();
		
		for(int j=0; j<k; j++){
			scene.clear();
			
			file>>animal;
			scene.push_back(animal);
			file>>animal;
			scene.push_back(animal);
			file>>animal;
			scene.push_back(animal);

			part.push_back(scene);
		}
		show.push_back(part);
	}
}

//Desde acá hasta la fución main

tuple<string, string, string> escena0 = make_tuple("Cabra", "Mariposa","Leon");
tuple<string, string, string> escena1 = make_tuple("Jirafa", "Mariposa","Tortuga");
tuple<string, string, string> escena2 = make_tuple("Cabra", "Tortuga","Jirafa");





int grandezaEscena(tuple<string, string, string> escena){

    int result = 0;
    result = animals[get<0>(escena)] + animals[get<1>(escena)] + animals[get<2>(escena)];
    //apply([](auto&&... args) {((cout << args << '\n'), ...);}, escena);
    return result;

}



int grandezaParte( tuple<string, string, string> parte[]){

    int result = 0;
    //Parte de prueba
    for(int i=0; i<k; i++){

        result += grandezaEscena(parte[i]);
    }

    return result;
}

/**
 * Main function
 *
 */
int main() {
	
	string testCase = "prueba3";
	ifstream file ("../Pruebas/" + testCase + ".txt");
	file >> n >> m >> k;
	setAnimals(file);
	setShow(file);
	

	//Pruebas
	
	cout << "test animals " << animals["Mariposa"] << endl;

	cout << endl << "test show" << endl;

	cout << endl << "Apertura" << endl;

	for(int i=0; i<k*(m-1); i++) {
		for(int j=0; j<3; j++)
			cout << show[0][i][j] << " ";
		cout << endl;
	}

	cout << endl;

	for(int i=1; i<m; i++) {
		cout << "Parte " << i << endl;
		for(int j=0; j<k; j++) {
			for(int l=0; l<3; l++)
				cout << show[i][j][l] << " ";
			cout << endl;
		}

		cout << endl;
	}

	return 0;
}
