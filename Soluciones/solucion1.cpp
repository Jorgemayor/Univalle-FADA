#include <iostream>
#include <string.h>
#include <utility>
using namespace std;

int n, m, k;

int getInput() {

    n = 1;
    k = 0;
    m = 0;
    pair<string,int> animales[n];
    animales[0] = make_pair("cabra", 1); 	
    cout<<"animal: " << animales[0].first << " grandeza: " << animales[0].second << endl;
    
    return 1;
}

int main() {
    
    getInput();
    return 0;
}
