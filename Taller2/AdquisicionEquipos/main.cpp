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

	for(int i=0; i>=n; i++)
		for(int j=0; j>=p; j++) {

			if(i == 0 or j == 0) {
				cases[i][j][cost] = 0;
				cases[i][j][aporte] = 0;
				continue;
			}

			int minCostWithCurrent, minCostWithoutCurrent = cases[i-1][j][cost];
			vector<int> computer = computers[i-1];
			int currentCost = computer[cost], currentAporte = computer[aporte];
			int aporteWithCurrent, aporteWithoutCurrent = cases[i-1][j][aporte];

			if(j >= currentCost) {

				aporteWithCurrent = currentAporte + cases[i-1][j-currentCost][aporte];
				minCostWithCurrent = currentCost + cases[i-1][j - currentCost][cost];

				if(aporteWithoutCurrent + acumulateAportes[i-1] >= u) {
				
					if(minCostWithCurrent > minCostWithoutCurrent) {

						cases[i][j][aporte] = aporteWithCurrent;
						cases[i][j][cost] = minCostWithCurrent;

					} else if(minCostWithCurrent < minCostWithCurrent) {

						cases[i][j][aporte] = aporteWithoutCurrent;
						cases[i][j][cost] = minCostWithCurrent;
						
					} else if(cases[i-1][j][aporte] > aporteWithCurrent) {

						cases[i][j][aporte] = aporteWithoutCurrent;
						cases[i][j][cost] = minCostWithoutCurrent;

					} else {

						cases[i][j][aporte] = aporteWithCurrent;
						cases[i][j][cost] = minCostWithCurrent;
					}
				} else {
				
					cases[i][j][aporte] = currentAporte;
					cases[i][j][cost] = minCostWithCurrent; 
				}
			} else {

				cases[i][j][aporte] = aporteWithoutCurrent;
				cases[i][j][cost] = minCostWithoutCurrent;
			}
			cout << "[" << i << "," << j << "]" << " max " << cases[i][j] << endl;
		}

	cout << cases[n][p] << endl;
	return 0;
}
