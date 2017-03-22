#include <iostream>
#include <map>
#include <thread>
#include "Core.h"
#include "Process.h"
using namespace std;

int const SIZE = 5;
/// fileID will determine which text file (set of processes) to read in from the text file
map<int, Process>readInFromTextFile(int fileID);
/// this function will run in a background thread and whenever simSystem 
/// has less then a certian amount of processes it will pull from the map object (processes) and place that process into the simSystem
/// once the map object is empty the thread will be...	(terminated?, used for different purpose?, do something?, do nothing?)
void putInSystem(map<int, Process> processes);
/// this will excecute all of the processes 
void run(int i);
/// initialize the cores and threads and then start the cores
void start();
/// create five random text files 
void createTextFiles();
/// delete text files?
/// not sure if we need this but maybe run this at the end of the program?
/// or right after reading all of the text files in? 
/// or just put this code in the createTextFile() function
void deleteTextFiles();
queue<queue<Process>> simSystem;


int main()
{
	// create textFiles
	createTextFiles();
	//  read in form text file & place in map 
	map<int, Process> processes = readInFromTextFile(1);
	start();

	return 0;
}
void createTextFiles()
{

}
map<int, Process> readInFromTextFile(int fileID)
{
	map<int, Process> p;
	return p;
}
void start() 
{
	// create cores 
	Core coreArray[SIZE];
	// create threads
	// one thread will run "putInSystem". the other threads will run "core.algorithm()"
	thread threadArray[SIZE];

	threadArray[0] = thread(0, putInSystem);
	for (int i = 1; i < SIZE; i++)
	{
		threadArray[i] = thread(run, i);
	}
	// start threads
	for (auto &t : threadArray)
	{
		t.join();
	}
}
void putInSystem(map<int, Process> processes)
{
	// while system size is less then n add process from processes to system
}
void run(int i) 
{

}
void deleteTextFiles() 
{

}


