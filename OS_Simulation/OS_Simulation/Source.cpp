#include <iostream>
#include <map>
#include <thread>
#include "Core.h"
#include "Process.h"
using namespace std;

/// fileID will determine which text file (set of processes) to read in from the text file
map<int, Process>readInFromTextFile(int fileID);
/// this function will run in a background thread and whenever simSystem 
/// has less then a certian amount of processes it will pull from the map object (processes) and place that process into the simSystem
/// once the map object is empty the thread will be...	(terminated?, used for different purpose?, do something?, do nothing?)
void putInSystem(map<int, Process> processes);


queue<queue<Process>> simSystem;

int main()
{
	//  read in form text file & place in map 
	map<int, Process> processes = readInFromTextFile(1);
	// create cores 
		// im cant remeber if we are doing one core per algorithm (3) or if we were doing something else?

	// create threads
		// one thread will run "putInSystem". the other threads will run "core.algorithm()"

	// start threads



	return 0;
}

void putInSystem(map<int, Process> processes)
{
	// while system size is less then n add process from processes to system
}
map<int, Process> readInFromTextFile(int fileID)
{
	map<int, Process> p;

	return p;
}
