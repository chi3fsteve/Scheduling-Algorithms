#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<math.h>

using namespace std;

int main() {
	int Cmax;
	vector<int> jobs = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> jobsProcessing = { 5, 3, 7, 9, 2, 6, 2, 3 };
	int numberOfMachines = 3;
	double maxElement = max_element(begin(jobsProcessing), end(jobsProcessing))[0];
	double sumOfElements = accumulate(jobsProcessing.begin(), jobsProcessing.end(), 0);
	double sumPerMachine = ceil(sumOfElements / numberOfMachines);
	if (sumPerMachine > maxElement)
	{
		Cmax = sumPerMachine;
	}
	else
	{
		Cmax = maxElement;
	}
	vector<vector<int>> schedule(numberOfMachines);
	vector<int> processingPerMachine(numberOfMachines);
	int counter = 0;
	int acc = 0;
	for (int i = 0; i < jobsProcessing.size(); i++) {
		if (acc + jobsProcessing[i] < Cmax)
		{
			acc = acc + jobsProcessing[i];
			schedule[counter].push_back(jobs[i]);
			processingPerMachine[counter] = acc;
		}
		else if (acc + jobsProcessing[i] == Cmax)
		{
			schedule[counter].push_back(jobs[i]);
			processingPerMachine[counter] = Cmax;
			counter++;
			acc = 0;
		}
		else if (acc + jobsProcessing[i] > Cmax)
		{
			schedule[counter].push_back(jobs[i]);
			processingPerMachine[counter] = Cmax;
			counter++;
			schedule[counter].push_back(jobs[i]);
			acc = acc + jobsProcessing[i] - Cmax;
			processingPerMachine[counter] = acc;
		}
	}
	cout << "Schedule:\n";
	for (int i = 0; i < schedule.size(); i++)
	{
		cout << "Machine" << i + 1 << " ";
		for (int j = 0; j < schedule[i].size(); j++)
		{
			cout << "J" << schedule[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "Processing per machine:\n";
	for (int i = 0; i < processingPerMachine.size(); i++)
	{
		cout << "Machine" << i + 1 << ": ";
		cout << processingPerMachine[i];
		cout << "\n";
	}
}