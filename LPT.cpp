//Algorithm LS (List Scheduling): assign the first available job to the first available machine
//LS is an online algorithm: deciding about scheduling a given job we know nothing on jobs following that job

#include <algorithm>
#include <iostream>
#include <iterator>
#include<vector>
#include<numeric>

using namespace std;

vector<vector<int>> listScheduling(int jobProcessing[], int numberOfMachines, int arrSize) {
	vector<vector<int>> schedule(numberOfMachines);
	vector<int> timePerMachine(numberOfMachines);
	int minElementIndex;
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < numberOfMachines; j++) {
			timePerMachine[j] = accumulate(schedule[j].begin(), schedule[j].end(), 0);
		}
		minElementIndex = min_element(timePerMachine.begin(), timePerMachine.end()) - timePerMachine.begin();
		schedule[minElementIndex].push_back(jobProcessing[i]);
	}
	return schedule;
}

int main() {
	int jobs[] = { 5, 3, 7, 9, 2, 6, 2 };
	int arrSize = sizeof(jobs) / sizeof(jobs[0]);
	int n_machines = 2;
	vector<vector<int>> schedule;
	schedule = listScheduling(jobs, n_machines, arrSize);
	for (int i = 0; i < schedule.size(); i++)
	{
		for (int j = 0; j < schedule[i].size(); j++)
		{
			cout << schedule[i][j];
		}
		cout << "\n";
	}
}