#ifndef SIMULATEOR_H_
#define SIMULATEOR_H_

#include <ctime>
#include <fstream>
#include <queue>
#include <string>
#include <map>

#include "Process.h"

using std::endl;
using std::queue;
using std::map;

class Simulator
{
private:
	int clock; // current time
	queue<Process* > user;

public:


	Simulator() {

	}
	//Process *process = NULL;

	void createUser() {
		srand((unsigned int)time(NULL));
		//std::fstream process_file("processes");
		for (int i = 0; i < 100; i++) // generates 100 random processes
		{
			int PID = i, priority = rand() % (5) + 1, arrival_t = 0,
				cpuBurst = rand() % (10) + 1, ioBurst = rand() % (11) + 5, ifIO = rand() % 2;
			if (ifIO == 0) ioBurst = 1; // randomly decide if process is io-bound/heavy or not
			Process *process = NULL;
			process = new Process(PID, priority, arrival_t, cpuBurst, ioBurst, 0,0,0,0);
			user.push(process);
		}
	}

	void run_simulation()
	{
		map <int, Process> global;
		// run the simulation
		for (int clock = 0; !user.empty(); ++clock)
		{
			// for each time interval ...
			if (!user.empty() & global.size() < 16) {
				int entry = rand() % 2;
				if (entry == 1) {
					Process *process = user.front();
					process->arrival_t = clock;
					global.insert_or_assign(process->arrival_t, process);
					user.pop();
				}
			}


		}
	}



};

#endif