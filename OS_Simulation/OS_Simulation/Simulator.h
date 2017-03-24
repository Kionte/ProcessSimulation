//#ifndef SIMULATOR_H_
//#define SIMULATOR_H_
//
//#include <ctime>
//#include <fstream>
//#include <iostream>
//#include <queue>
//#include <string>
//#include <map>
//
//#include "Process.h"
//
//using std::endl;
//using std::cout;
//using std::cin;
//using std::queue;
//using std::map;
//
//class Simulator
//{
//private:
//	int clock; // current time
//	queue<Process* > user;
//
//public:
//
//	Simulator() {
//
//	}
//
//	void createUser() {
//		srand((unsigned int)time(NULL));
//		//std::fstream process_file("processes");
//		for (int i = 0; i < 100; i++) // generates 100 random processes
//		{
//			int PID = i, priority = rand() % (5) + 1, arrival_t = 0,
//				cpuBurst = rand() % (10) + 1, ioBurst = rand() % (11) + 5, ifIO = rand() % 2, contextSwitch = rand() % 3 + 1;
//			if (ifIO == 0) ioBurst = 1; // randomly decide if process is io-bound/heavy or not
//			Process *process = NULL;
//			process = new Process(PID, priority, arrival_t, cpuBurst, ioBurst, 0, 0, 0, contextSwitch, 0);
//			user.push(process);
//		}
//	}
//
//	void enter_data() {
//		cout << "Please enter the desired number of cores for the simulation (*4 or 8).\n\n";
//		int cores;
//		cin >> cores;
//		while ((cores != 4 || cores != 8 || cin.fail()))
//		{
//			cout << "Invalid input\n";
//			cin.clear();
//			cout << "Please enter your desired arrival rate for the simulation (patients/hour *max = 60*): ";
//			cin.ignore(std::numeric_limits<int>::max(), '\n');
//			cin >> cores;
//		}
//	}
//
//	void run_simulation()
//	{
//		map <int, Process> global;
//		// run the simulation
//		for (int clock = 0; !user.empty(); ++clock)
//		{
//			// for each time interval ...
//			if ((!user.empty() & global.size()) < 16) {
//				int entry = rand() % 2;
//				if (entry == 1) {
//					Process *process = user.front();
//					process->arrival_t = clock;
//					global.insert_or_assign(process->arrival_t, process);
//					user.pop();
//				}
//			}
//
//
//		}
//	}
//
//
//
//};
//
//#endif