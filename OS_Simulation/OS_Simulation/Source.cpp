#include <iostream>
#include <map>


#include "Core.h"
#include "Process.h"
#include "GlobalQueue.h"
using namespace std;

// randomly created representation of user
queue<Process> user;

// queue that the processes will be pulling from
queue<Process> ready;

void createUser() {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) // generates 100 random processes
	{
		int PID = i, priority = rand() % (5) + 1, arrivalTime = 0, cpuBurst = rand() % (10) + 1, 
			ioBurst = rand() % (11) + 5, ifIO = rand() % 2, contextSwitch = rand() % 3 + 1,
			tProcessTime = cpuBurst + ioBurst + contextSwitch;
		if (ifIO == 0) ioBurst = 1; // randomly decide if process is io-bound/heavy or not
		Process *process = NULL;
		process = new Process(PID, priority, arrivalTime, cpuBurst, ioBurst, 0, 0, 0, contextSwitch, 0, tProcessTime);
		user.push(*process);
	}

}


void computeAvg(vector<Core> cores, int clock, int wasted);

bool check(vector<Core> cores);

int main(){
	vector<Core> cores;
	int wasted = 0; // total time wasted waiting
	int clock = 0; // global clock variable
	int totalProcessTime = 0;
	int quantum = 0;
	bool quantum_set = false;


	createUser();
	cout << "Please enter the desired number of cores for the simulation (*4 or 8).\n\n";
	int num_cores;
	cin >> num_cores;
	while ((num_cores != 4 && num_cores != 8) || cin.fail()){
		cout << "Invalid input\n";
		cin.clear();
		cout << "Please enter your desired number of cores for the simulation (*4 or 8).\n\n";
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> num_cores;
	}
	cout << "\nPlease enter the desired run time for the simulation (*Range: 100-1000000).\n\n";
	int run;
	cin >> run;
	while (!(run >= 100 && run <= 1000000) || cin.fail()){
		cout << "Invalid input\n";
		cin.clear();
		cout << "Please enter the desired run time for the simulation (*Range: 100-1000000).\n\n";
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> run;
	}

	cout << "\nPlease enter the desired algorithm for the simulation.\n\n";
	int alg;
	cout << "First Come First Serve = 1\n";
	cout << "Round Robin = 2\n";
	cout << "Shortest Process Next = 3\n";
	cin >> alg;

	while (!(alg >= 1 && alg <= 4) || cin.fail())
	{
		cout << "Invalid input\n";
		cin.clear();
		cout << "Please enter the desired algorithm for the simulation.\n\n";
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> alg;
	}
	for (int i = 0; i < num_cores; i++) // creats "num_cores" cores to work with
	{
		Core* temp = NULL;
		temp = new Core(&ready, quantum);
		cores.push_back(*temp);
	}


	while (clock < run)
	{

		for (int i = 0; i < 15; i++)
		{
			if ((!user.empty() && (ready.size() < 20))) {
				int entry = 1;
				if (entry == 1) {
					Process process = user.front();
					process.arrivalTime = clock;
					ready.push(process);
					user.pop();
				}
			}
		}
		switch (alg) {
		case 1:
			for (auto &c : cores) {
				c.FCFS(clock, &totalProcessTime);
			} break;
		case 2:
			if (quantum_set == false) {
				cout << "\nPlease enter the desired quantum for the simulation (max 20).\n\n";
				cin >> quantum;
				while (!(quantum >= 1 && quantum <= 20) || cin.fail()) {
					cout << "Invalid input\n";
					cin.clear();
					cout << "Please enter the desired quantum for the simulation (max 20).\n\n";
					cin.ignore(std::numeric_limits<int>::max(), '\n');
					cin >> quantum;
				}
				quantum_set = true;
				for (auto &c : cores) {
					c.setQuantum(quantum);
				}

			}

			for (auto &c : cores) {
				c.RR(clock, &totalProcessTime);
			} break;

			//case 3:
			//	for (auto &c : cores) {
			//		c.SPN(clock, &totalProcessTime);
			//	} break;
			//case 4:
			//	for (auto &c : cores) {
			//		c.MLFB(clock, &totalProcessTime);
			//	} break;


		}
		clock++;
		
	}
	
	system("CLS"); // clears screen
	computeAvg(cores, clock, wasted);

	return 0;
}



void computeAvg(vector<Core> cores, int clock, int wasted)
{
	// stat you want find
	double avgWait = 0;
	double avgResponse = 0;
	double avgTurnaround = 0; 
	double avgConSwitch = 0; 
	double wastedTime = 0; 
	double utilization = 0; 
	int throughput = 0; 
	// go through cores and get total for stat
	for (auto &c : cores)
	{
		avgWait += c.getTotalWait();
		avgResponse += c.getTotalResponse(); 
		avgTurnaround += c.getTotalTurnAround(); 
		avgConSwitch += c.getConSwitch(); 
		throughput += c.getThroughput(); 
	}

	// calculate avg of stat
	utilization = (((double)clock - (double)wasted) / (double)clock) * 100; 
	avgWait = (double)avgWait / (double)throughput;
	avgResponse = (double)avgResponse / (double)throughput; 
	avgTurnaround = (double)avgTurnaround / (double)throughput; 
	avgConSwitch = (double)avgConSwitch / (double)throughput; 
	// output stat
	cout << "Throughput: " << throughput << endl; 
	cout << "Avg. Wait: " << avgWait << endl;
	cout << "Avg. Response: " << avgResponse << endl; 
	cout << "Avg. Turnaround: " << avgTurnaround << endl;
	cout << "Avg. Context Switch Time: " << avgConSwitch << endl; 
	cout << "CPU Utilization Percentage: %" << utilization << endl; 

}

//bool check(vector<Core> cores) {
//	for (auto &c : cores){
//		if (c.getBusy()){
//			return true;}
//		else { return false; }
//	}
//
//}
