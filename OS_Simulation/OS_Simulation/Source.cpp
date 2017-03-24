#include <iostream>
#include <map>
#include <thread>
#include "Core.h"
#include "Process.h"
using namespace std;

/// will be used towards number of threads and processess
int const SIZE = 5;
/// fileID will determine which text file (set of processes) to read in from the text file
map<int, Process>readInFromTextFile(int fileID);
/// this function will run in a background thread and whenever simSystem 
/// has less then a certian amount of processes it will pull from the map object (processes) and place that process into the simSystem
/// once the map object is empty the thread will be...	(terminated?, used for different purpose?, do something?, do nothing?)
void putInSystem(map<int, Process> processes);
/// this will excecute all of the processes 
void run();
/// initialize the cores and threads and then start the cores
void start(map<int,Process> processes);
/// create five random text files 
void createTextFiles();


queue<Process> simSystem;


int main()
{
	// create textFiles
	createTextFiles();
	//  read in form text file & place in map 
	map<int,Process> processes = readInFromTextFile(1);
	
	start(processes);

	return 0;
}
void createTextFiles()
{
	// do this wednesday
}
map<int, Process> readInFromTextFile(int fileID)
{
	map<int, Process> p;
	// do this wednesday
	return p;
}
void start(map<int,Process> processes) 
{
	// create cores 
	Core coreArray[SIZE];
	// assign first core to handle adding processes to the system
	coreArray[0].run(putInSystem,processes);
	// assign the other cores to actualy exceute the processes
	for(int i = 1; i < SIZE; i++)
	{
		coreArray[i].run(run);
	}


}
void putInSystem(map<int, Process> processes)
{
	// if number of proccess in the simSystem queue are belopw a certian number add a process from the processes map to the queue
	// do something where the arrivial time is a little more random. like create a random number between 1 and 5
	// and if the random number is 1 then add process to queue but if it is anything else wait a second and try again that way the arrival time is more random
}
void run() 
{
	// ignore this until we all meet tomorrow
}



