#include <iostream>
#include <string.h>
#include <map>
#include <vector>
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

/**
 * Gets the awesomeness of on scene
 * 
 * @param scene vector<string> --> vector representing
 * a part's scene.
 * @return result int --> Value of the awesomeness of
 * the scene.
 */
int getSceneAwesomeness(vector<string> scene){

	int result = animals[scene[0]] + animals[scene[1]] + animals[scene[2]];

	return result;
}


/**
 * Gets the awesomeness of a part
 * 
 * @param part vector<vector<string>> --> vector
 * representing a show's part.
 * @return result int --> Value of the awesomeness of
 * the part.
 */
int getPartAwesomeness(vector<vector<string>> part){

	int result = 0;
    
	for(int i=0; i<part.size(); i++)
		result += getSceneAwesomeness(part[i]);
	
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
