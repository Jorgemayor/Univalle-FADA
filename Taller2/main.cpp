
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n ;
int U ;
vector<int> C;
vector<int> B;
vector<int> acumUtility;
vector<int> pickedEquips;


int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }


int chooseEquip(int P)
{



    if (n == 0 || P == 0)
        return 0;


    if (C[n - 1] > P)
    {
        n--;
        return chooseEquip(P);}


    else {
        n--;
        if(B[n] + chooseEquip(P - C[n]) > chooseEquip(P))
        {
            pickedEquips.at(n) = 1;
        }
        return max(B[n] + chooseEquip(P - C[n]), chooseEquip(P));

    }
}






int main()
{
     n = 5;
     U = 11;
     C = {1,3,4,6,9};
     B = {2,4,3,4,6};
    acumUtility.assign(n, 0);
    pickedEquips.assign(n, 0);


    int aux = accumulate(B.begin(), B.end(), 0);
    for(int i = 0; i < n; i++ ){
        acumUtility.at(i) = aux;
        aux -= B[i];}

    for(int i = 0; i < n; i++ ){
        cout<<pickedEquips[i]<<" ";}



    cout<<endl<<chooseEquip(9);

    return 0;
}



