#include <iostream>
#include <map>
#include <thread>
#include "Core.h"
#include "Process.h"
#include "GlobalQueue.h"
using namespace std;

/// will be used towards number of threads and processess
int const SIZE = 5;


// randomly created
queue<Process> user;

// queue that the processes will be pulling from
queue<Process> ready;

void createUser() {
	srand((unsigned int)time(NULL));
	//std::fstream process_file("processes");
	for (int i = 0; i < 100; i++) // generates 100 random processes
	{
		int PID = i, priority = rand() % (5) + 1, arrival_t = 0,
			cpuBurst = rand() % (10) + 1, ioBurst = rand() % (11) + 5, ifIO = rand() % 2, contextSwitch = rand() % 3;
		if (ifIO == 0) ioBurst = 1; // randomly decide if process is io-bound/heavy or not
		Process *process = NULL;
		process = new Process(PID, priority, arrival_t, cpuBurst, ioBurst, 0, 0, 0, contextSwitch, 0);
		user.push(*process);
	}
}

void computeAvg(vector<Core> cores, int clock, int wasted);

bool check(vector<Core> cores);

int main()
{
	
	createUser();
	cout << "Please enter the desired number of cores for the simulation (*4 or 8).\n\n";
	int num;
	cin >> num;
	while (num != 4 && num != 8 && cin.fail())
	{
		cout << "Invalid input\n";
		cin.clear();
		cout << "Please enter your desired number of cores for the simulation (*4 or 8).\n\n";
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> num;
	}
	cout << "\nPlease enter the desired quantum for the simulation (max 20).\n\n";
	int q;
	cin >> q;
	while ((q > 20 || q < 1 || cin.fail()))
	{
		cout << "Invalid input\n";
		cin.clear();
		cout << "Please enter the desired quantum for the simulation (max 20).\n\n";
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> q;
	}
	cout << "\nPlease enter the desired run time for the simulation (Range: 100-1000000).\n\n";
	int run;
	cin >> run;
	while ((run < 100 || run > 1000000 || cin.fail()))
	{
		cout << "Invalid input\n";
		cin.clear();
		cout << "Please enter the desired quantum for the simulation (Range: 100-1000000).\n\n";
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> run;
	}

	vector<Core> cores;

	for (int i = 0; i < num; i++)
	{
		Core* temp = NULL;
		temp = new Core(&ready, q);
		cores.push_back(*temp);
	}
	int wasted = 0; 
	int clock = 0; 
	int totalProcessTime = 0;
	// use this to change the alg
	int alg = 0;
	do
	{
			// for each time interval ...
			if ((!user.empty() && (ready.size() < 5))) {
				int entry = rand() % 2;
				if (entry == 1) {
					Process process = user.front();
					process.arrival_t = clock;
					ready.push(process);
					user.pop();
				}
			}
			for (auto &c : cores)
			{
				c.FCFS(clock, &totalProcessTime);
			}
			for (auto &c : cores)
			{
				if (c.getRunningP().complete && ready.empty())
				{
					wasted++;
					break;
				}
			}
				clock++;
				
	} while (check(cores) || !user.empty() || !ready.empty() && clock < run);


	//double utilization = ((double)clock - (double)c1.getWasted()) / (double)clock;
	//int totalThroughput = c1.getThroughput() + c2.getThroughput() + c3.getThroughput(); 
	
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

bool check(vector<Core> cores) 
{
	for (auto &c : cores)
	{
		if (c.getBusy())
		{
			return true;
		}	
	}
	return false;
}
