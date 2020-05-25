#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	vector<vector<int>> professors;
	int k, c, numberOfMen, numberOfWomen;
	char sexo;

	int gender = 0, experience = 1, salary = 2;

	cin >> k >> c;
	while(cin >> sexo) {
	
		int currentGender, currentExperience, currentSalary;
		cin >> currentExperience >> currentSalary;

		if(sexo == 'H' || sexo == 'h') {
			currentGender = 1;
			numberOfMen++;
		}
		else if(sexo == 'M' || sexo == 'm') {
			currentGender = 0;
			numberOfWomen++;
		}
		else {
			cout << "Not correct gender" << endl;
			return 1;
		}
		professors.push_back({currentGender, currentExperience, currentSalary});
	}

	int n = professors.size();

	int cases[n+1][c+1];

	for(int i=0; i<=n; i++)
		cases[i][0] = 0;

	for(int i=0; i<=c; i++)
		cases[0][i] = 0;

	for(int i=1; i<=k; i++)
		for(int j=1; j<=c; j++) {
		
			int maxExpWithCurrent, maxExpWithoutCurrent = cases[i-1][j];
			vector<int> professor = professors[i-1];
			int expectedSalary = professor[salary];

			if(j >= expectedSalary)
				maxExpWithCurrent = professor[experience] + cases[i-1][j - expectedSalary];

			cases[i][j] = max(maxExpWithCurrent, maxExpWithoutCurrent);
			cout << "[" << i << "," << j << "]" << " max " << cases[i][j] << endl;
		}



	cout << cases[n][c] << endl;
	return 0;
}
