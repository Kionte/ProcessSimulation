#include <iostream>
#include <map>
#include <thread>
#include "Core.h"
#include "Process.h"
using namespace std;

map<int, Process>readInFromTextFile(int fileID);

queue<queue<Process>> system;
int main()
{

	//  read in form text file & place in map 
	map<int, Process> processes = readInFromTextFile(1);
	// create cores 

	// create threads

	// run
}


map<int, Process> readInFromTextFile(int fileID)
{
	map<int, Process> p;

	return p;
}