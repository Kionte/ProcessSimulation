#ifndef GLOBAL_QUEUE_H_
#define GLOBAL_QUEUE_H_


#include <ctime>
#include <fstream>
#include <queue>
#include <string>
#include <map>





#include "process.h"
#include "Simulator.h"

using std::map;
using std::queue;

class GlobalQueue {
private:
	map <int, Process* > global;
	queue<Process* > user;

public:
	GlobalQueue() {}

	void createUser() {
		srand((unsigned int)time(NULL));
		//std::fstream process_file("processes");
		for (int i = 0; i < 100; i++) // generates 100 random processes
		{
			int PID = i, priority = rand() % (5) + 1, arrival_t = 0, cpuBurst = rand() % (10) + 1, 
				ioBurst = rand() % (11) + 5, ifIO = rand() % 2, contextSwitch = rand() % 3,
				tProcessTime = (cpuBurst + ioBurst + contextSwitch);
			if (ifIO == 0) ioBurst = 1; // randomly decide if process is io-bound/heavy or not
			Process *process = NULL;
			process = new Process(PID, priority, arrival_t, cpuBurst, ioBurst, 0, 0, 0, contextSwitch, 0, tProcessTime);
			user.push(process);
		}
	}
	void update(int clock) {
		for (int clock = 0; !user.empty(); ++clock)
		{
			// for each time interval ...
			if ((!user.empty() & global.size()) < 16) {
				int entry = rand() % 2;
				if (entry == 1) {
					Process *process = user.front();
					process->arrivalTime = clock;
					global.insert_or_assign(process->arrivalTime, process);
					user.pop();
				}
			}
		}
	}

	friend class Simulator;
};




#endif