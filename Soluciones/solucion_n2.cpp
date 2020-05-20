#include <iostream>
#include <string.h>
#include <iomanip>
#include <map>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

int n, m, k;
vector<vector<vector<string>>> show;
map<vector<string>, vector<string>> sortedScenes;
map<vector<string>, int> scenesAwesomeness;
unordered_map<string, int> animals;

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
 * Gets the average awesomeness of the show.
 * 
 * @return average float --> Value of the average awesomeness of
 * the show.
 */
float getShowAverageAwesomeness(){


    int sum = 0;

    for(int i=0; i<show[0].size();i++){

        sum += getSceneAwesomeness(show[0][i]);
    }

    float average = sum / ((m - 1.0) * k);
    return average;
}



/**
 * Sorts the animals of each scene of each part of the show.
 * 
 */
void sortAnimals() {

    vector<vector<string>> part;
    vector<string> scene;

    for(int i=0; i<m; i++) {

        part = show[i];
        for(int j=0; j<part.size(); j++) {

            vector<string> sortedScene = sortedScenes[part[j]];
            if(i and sortedScene.size()) {
                show[i][j] = sortedScene;
                continue;
            }

            scene = part[j];
            int awesomenessFirstAnimal = animals[scene[0]];
            int awesomenessSecondAnimal = animals[scene[1]];
            int awesomenessThirdAnimal = animals[scene[2]];

            if(awesomenessFirstAnimal < awesomenessSecondAnimal) {

                if(awesomenessSecondAnimal < awesomenessThirdAnimal) {

                    sortedScenes[scene] = scene;

                } else if(awesomenessFirstAnimal < awesomenessThirdAnimal) {

                    swap(show[i][j][1], show[i][j][2]);
                    sortedScenes[scene] = show[i][j];
                } else {

                    swap(show[i][j][1], show[i][j][2]);
                    swap(show[i][j][0], show[i][j][1]);
                    sortedScenes[scene] = show[i][j];
                }
            } else if(awesomenessFirstAnimal < awesomenessThirdAnimal) {

                swap(show[i][j][0], show[i][j][1]);
                sortedScenes[scene] = show[i][j];

            } else if(awesomenessSecondAnimal < awesomenessThirdAnimal) {

                swap(show[i][j][0], show[i][j][2]);
                swap(show[i][j][0], show[i][j][1]);
                sortedScenes[scene] = show[i][j];

            } else {

                swap(show[i][j][0], show[i][j][2]);
                sortedScenes[scene] = show[i][j];
            }

            scenesAwesomeness[show[i][j]] = awesomenessFirstAnimal + awesomenessSecondAnimal + awesomenessThirdAnimal;
        }
    }
}

/**
 * Sorts the scenes of each part of the show.
 *
 */
void sortScenes() {


    vector<string> scene;
    vector<vector<string>> part;


    for (int f = 0;f < m; f++) {


        part = show[f];


        for (int i = 0; i < part.size(); i++)
        {

            // Last i elements are already in place
            for (int j = 0; j < part.size() - i -1   ; j++)
                if ((getSceneAwesomeness(part[j])) > (getSceneAwesomeness(part[j+1]))){

                    part[j].swap(part[j+1]);}
        }
        show[f]=part;

    }
}




/**
 * Sorts the parts of the show.
 *
 */
void sortParts() {

    //vector<vector<vector<string>>> showCopy;
    int partAwesomeness[m];
    for (int i = 0; i < m; i++) {

        partAwesomeness[i] = getPartAwesomeness(show[i]);


    }


       //showCopy = show;
       for (int i = 0; i < show.size(); i++) {

           // Last i elements are already in place
           for (int j = 1; j < show.size() - i - 1; j++) {
               if (partAwesomeness[j] > partAwesomeness[j + 1]) {

                   show[j].swap(show[j + 1]);
                   int temp = partAwesomeness[j];
                   partAwesomeness[j+1]=temp;
                   partAwesomeness[j]=partAwesomeness[j+1];
               }
           }

       }
       //show = showCopy;


}




/**
 * Main function
 *
 */
int main() {

    string testCase = "prueba2";
    ifstream file ("../Pruebas/" + testCase + ".txt");
    file >> n >> m >> k;
    setAnimals(file);
    setShow(file);
    cout << "sort animals" << endl;
    sortAnimals();
    cout << "sort scenes" << endl;
    sortScenes();
    cout << "sort parts" << endl;
    sortParts();

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



    cout << "El promedio de grandeza de todo el espectaculo fue de " << fixed << setprecision(2) << getShowAverageAwesomeness() << endl;
    return 0;
}