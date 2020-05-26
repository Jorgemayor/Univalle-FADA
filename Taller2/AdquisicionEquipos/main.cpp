#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<vector<int>> computers;
	int n, p, u;
	int cost = 0, aporte = 1;

	cin >> n >> p >> u;
	int cases[n+1][p+1][2];
	
	for(int i=0; i<n; i++) {
		int currentCost, currentAporte;
		cin >> currentCost >> currentAporte;
		computers.push_back({currentCost, currentAporte});
	}

	int acumulateAportes[n+1];
	acumulateAportes[n-1] = 0;
	for(int i=n-2; i>=0; i--)
		acumulateAportes[i] = acumulateAportes[i+1] + computers[i+1][aporte];

	for(int i=0; i<=n; i++)
		for(int j=0; j<=p; j++) {

			if(i == 0 or j == 0) {
				cases[i][j][cost] = 0;
				cases[i][j][aporte] = 0;
				continue;
			}
			
			vector<int> computer = computers[i-1];
			int currentCost = computer[cost], currentAporte = computer[aporte];
			//cout << "cuCost: " << currentCost << " cuAporte: " << currentAporte << endl;
			int minCostWithCurrent, minCostWithoutCurrent = cases[i-1][j][cost];
			int aporteWithCurrent, aporteWithoutCurrent = cases[i-1][j][aporte];

			if(j >= currentCost) {

				aporteWithCurrent = currentAporte + cases[i-1][j - currentCost][aporte];
				minCostWithCurrent = currentCost + cases[i-1][j - currentCost][cost];

				if(aporteWithoutCurrent + acumulateAportes[i-1] >= u) {
				
					if(minCostWithCurrent > minCostWithoutCurrent) {

						cases[i][j][aporte] = aporteWithoutCurrent;
						cases[i][j][cost] = minCostWithoutCurrent;

					} else if(minCostWithoutCurrent > minCostWithCurrent) {

						cases[i][j][aporte] = aporteWithCurrent;
						cases[i][j][cost] = minCostWithCurrent;
						
					} else if(aporteWithoutCurrent > aporteWithCurrent) {

						cases[i][j][aporte] = aporteWithoutCurrent;
						cases[i][j][cost] = minCostWithoutCurrent;

					} else {

						cases[i][j][aporte] = aporteWithCurrent;
						cases[i][j][cost] = minCostWithCurrent;
					}
				} else {
				
					cases[i][j][aporte] = aporteWithCurrent;
					cases[i][j][cost] = minCostWithCurrent; 
				}
			} else {

				cases[i][j][aporte] = aporteWithoutCurrent;
				cases[i][j][cost] = minCostWithoutCurrent;
			}
			//cout << "[" << i << "," << j << "]" << " max " << cases[i][j][aporte] << endl;
		}
	
	cout << endl << endl;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=p; j++) {

			cout << "[" << cases[i][j][aporte] << "," << cases[i][j][cost] << "]";
			if(j != p) cout << " ";
		}
		cout << endl;
	}
/*
	int resCost = cases[n][p][cost], resAporte = cases[n][p][aporte];
	int w = p; 
	for(int i = n; i > 0 && resAporte > 0; i--) {
	
		//cout << "It: " << i << "res" << resCost << endl;
		if (resAporte == cases[i - 1][w][aporte])  
			continue;         
		else { 
  
            // This item is included. 
            //printf("\n\n%d ", computers[i - 1][cost]);
              
            // Since this weight is included its  
            // value is deducted 
            resAporte = resAporte - computers[i - 1][aporte]; 
            w = w - computers[i - 1][cost];
        } 
    } */

	cout << "\n\nap: " << cases[n][p][aporte] << " cost: " << cases[n][p][cost] << endl;
	return 0;
}
