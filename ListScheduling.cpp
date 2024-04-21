//Algorithm LS (List Scheduling): assign the first available job to the first available machine
//LS is an online algorithm: deciding about scheduling a given job we know nothing on jobs following that job

//Another example of approximation algorithm for P2||Cmax is algorithm LPT
//Algorithm LPT(LargestProcessing Time) : order jobs nonincreasingly with respect to job processing Times and next apply algorithm LS

#include <algorithm>
#include <iostream>
#include<vector>
#include<numeric>

using namespace std;

vector<vector<int>> listScheduling(vector<int> jobProcessing, int numberOfMachines, int arrSize) {
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
	//Below insert your processing times:
	vector<int> jobs = { 5, 3, 7, 9, 2, 6, 2, 3 };
	int arrSize = jobs.size();
	//Below insert your number of machines:
	int numberOfMachines = 2;
	vector<vector<int>> scheduleLS;
	scheduleLS = listScheduling(jobs, numberOfMachines, arrSize);

	cout << "Below is the output of the LS algorithm for selected processing times and number of machines\n";

	for (int i = 0; i < scheduleLS.size(); i++)
	{
		cout << "Machine"<< i+1 << " ";
		for (int j = 0; j < scheduleLS[i].size(); j++)
		{
			cout << scheduleLS[i][j] << " ";
		}
		cout << "\n";
	}

	vector<int> sortJobs(arrSize);
	copy(jobs.begin(), jobs.begin() + arrSize, sortJobs.begin());
	sort(sortJobs.begin(), sortJobs.end(), greater<int>());

	vector<vector<int>> scheduleLPT;
	scheduleLPT = listScheduling(sortJobs, numberOfMachines, arrSize);
	cout << "\nBelow is the output of the LPT algorithm for selected processing times and number of machines\n";

	for (int i = 0; i < scheduleLPT.size(); i++)
	{
		cout << "Machine" << i + 1 << " ";
		for (int j = 0; j < scheduleLPT[i].size(); j++)
		{
			cout << scheduleLPT[i][j] << " ";
		}
		cout << "\n";
	}
}
