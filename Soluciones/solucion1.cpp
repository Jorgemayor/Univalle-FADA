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
	for(int i = 0; i<=n-1; i+=1){
			archivo >> name >> grandeza;
		animals[i] = make_pair(name, grandeza);
	}
	return animals;
}

void someKindOfSort () {
	

}

int main() {
	
	string testcase = "prueba1";
	pair<string, int>* animals = getInput(testcase);
	return 0;
}
