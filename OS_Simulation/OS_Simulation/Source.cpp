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
void run(int i);
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

}
map<int, Process> readInFromTextFile(int fileID)
{
	map<int, Process> p;
	return p;
}
void start(map<int,Process> processes) 
{
	// create cores 
	Core coreArray[SIZE];

	coreArray[0].run(putInSystem,processes);
	
}
void putInSystem(map<int, Process> processes)
{

}
void run(int i) 
{

}



