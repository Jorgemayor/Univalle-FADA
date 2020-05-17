#include <iostream>
#include <string.h>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

int n, m, k;

int getInput() {

    ifstream archivo("../Pruebas/prueba1.txt");
    string nombre;
    int peso;
    archivo >>n >> m >> k;
    cout << "Datos iniciales:" << n << m << k <<  endl;
    pair<string,int> animales[n];
    for(int i = 0;i <= n-1;i+=1){
        archivo >>nombre >> peso;
        animales[i] = make_pair(nombre, peso);
        cout<<"animal: " << animales[i].first << " grandeza: " << animales[i].second << endl;
    }
    return 1;
}

int main() {
    
    getInput();
    return 0;
}
