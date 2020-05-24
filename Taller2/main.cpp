
#include <iostream>
using namespace std;




int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

int equips[] = {};

int chooseEquip(int n, int P, int U, int C[], int B[])
{



    if (n == 0 || P == 0)
        return 0;


    if (C[n - 1] > P)
        return chooseEquip(n - 1 , P, U, C, B);


    else
        return max(
                B[n - 1] + chooseEquip(n - 1, P - C[n - 1], U, C, B),
                chooseEquip(n - 1 , P, U, C, B));
                equips[n]= 1;


}






int main()
{

    int n = 5;
    int P = 22;
    int U = 11;
    int C[] = {1, 3, 4, 6, 9};
    int B[] = {2, 4, 3, 4, 6};
    int equips[5] ={};

    cout<<chooseEquip(n ,P, U, C, B)<<endl;
    cout<<equips;
    return 0;
}



