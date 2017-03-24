#include <iostream>
#include <map>
#include <thread>
#include "Core.h"
#include "Process.h"
using namespace std;

/// will be used towards number of threads and processess
int const SIZE = 5;


// randomly created
queue<Process> user;

// queue that the processes will be pulling from
queue<Process> ready;



// processes with io burst will be stored  here until finiished with io
queue<Process> waiting;
int main()
{
	return 0;
}

