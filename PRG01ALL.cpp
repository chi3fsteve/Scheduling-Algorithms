#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

vector<int> ERT(vector<int> jobReadyTime) {
	vector<int> idx(jobReadyTime.size());
	iota(idx.begin(), idx.end(), 0);
	stable_sort(idx.begin(), idx.end(),
		[&jobReadyTime](size_t i1, size_t i2) {return jobReadyTime[i1] < jobReadyTime[i2]; });

	return idx;
}

vector<int> EDD(vector<int> jobDueDate) {
	vector<int> idx(jobDueDate.size());
	iota(idx.begin(), idx.end(), 0);
	stable_sort(idx.begin(), idx.end(),
		[&jobDueDate](size_t i1, size_t i2) {return jobDueDate[i1] < jobDueDate[i2]; });

	return idx;
}

vector<int> SPT(vector<double> jobProcessing) {
	vector<int> idx(jobProcessing.size());
	iota(idx.begin(), idx.end(), 0);
	stable_sort(idx.begin(), idx.end(),
		[&jobProcessing](size_t i1, size_t i2) {return jobProcessing[i1] < jobProcessing[i2]; });

	return idx;
}

vector<int> WSPT(vector<double> jobProcessing, vector<double>jobWeight) {
	vector<double> ratio;
	for (size_t i = 0; i < jobProcessing.size(); i++)
	{
		ratio.push_back(jobProcessing[i] / jobWeight[i]);
	}
	vector<int> idx(ratio.size());
	iota(idx.begin(), idx.end(), 0);
	stable_sort(idx.begin(), idx.end(),
		[&ratio](size_t i1, size_t i2) {return ratio[i1] < ratio[i2]; });
	
	return idx;
}

int main() {
	vector<int> jobReadyTime = { 5, 6, 1, 8, 2, 10 };
	vector<int> jobDueDates = { 18, 16, 4, 20, 3, 30 };
	vector<double> jobProcessing = { 3, 4, 1, 7, 9, 6};
	vector<double> jobWeight = { 1, 1, 3, 2, 2, 3};
	
	vector<int> orderERT = ERT(jobReadyTime);
	vector<int> orderEDD = EDD(jobDueDates);
	vector<int> orderSPT = SPT(jobProcessing);
	vector<int> orderWSPT = WSPT(jobProcessing, jobWeight);

	cout << "Job ready times:\n";
	for (size_t i = 0; i < jobReadyTime.size(); i++)
	{
		cout << jobReadyTime[i] << " ";
	}
	cout << "\nIndices of jobs ordered based on Earliest Ready Time:\n";
	for (size_t i = 0; i < orderERT.size(); i++)
	{
		cout << orderERT[i] << " ";
	}

	cout << "\nJob due dates:\n";
	for (size_t i = 0; i < jobDueDates.size(); i++)
	{
		cout << jobReadyTime[i] << " ";
	}
	cout << "\nIndices of jobs ordered based on Earliest Due Date:\n";
	for (size_t i = 0; i < orderEDD.size(); i++)
	{
		cout << orderEDD[i] << " ";
	}

	cout << "\nJob processing times:\n";
	for (size_t i = 0; i < jobProcessing.size(); i++)
	{
		cout << jobProcessing[i] << " ";
	}
	cout << "\nIndices of jobs ordered based on Shortest Processing Time:\n";
	for (size_t i = 0; i < orderSPT.size(); i++)
	{
		cout << orderSPT[i] << " ";
	}

	cout << "\nRatio of job processing times to job weights:\n";
	for (size_t i = 0; i < jobProcessing.size(); i++)
	{
		cout << jobProcessing[i]/jobWeight[i] << " ";
	}
	cout << "\nIndices of jobs ordered based on Weighted Shortest Processing Time:\n";
	for (size_t i = 0; i < orderWSPT.size(); i++)
	{
		cout << orderWSPT[i] << " ";
	}
}