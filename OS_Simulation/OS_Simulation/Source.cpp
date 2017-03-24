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

int main()
{
	Process P1(1, 1, 3, 4, 2); 
	Process P2(2, 1, 5, 3, 2); 
	Process P3(3, 1, 4, 6, 2); 
	Process P4(1, 1, 3, 4, 2);
	Process P5(2, 1, 5, 3, 2);
	Process P6(3, 1, 4, 6, 2);
	Process P7(1, 1, 3, 4, 2);
	Process P8(2, 1, 5, 3, 2);
	Process P9(3, 1, 4, 6, 2);

	P1.arrival_t = 0; 
	P2.arrival_t = 0; 
	P3.arrival_t = 0; 
	P4.arrival_t = 0;
	P5.arrival_t = 0;
	P6.arrival_t = 0;
	P7.arrival_t = 0;
	P8.arrival_t = 0;
	P9.arrival_t = 0;

	user.push(P1); 
	user.push(P2); 
	user.push(P3); 
	user.push(P4);
	user.push(P5);
	user.push(P6);
	user.push(P7);
	user.push(P8);
	user.push(P9);

	Core c1(&user, 3); 
	Core c2(&user, 3); 
	Core c3(&user, 3); 


	int clock = 0; 
	int totalProcessTime = 0;
	// use this to change the alg
	int alg = 0;
	do
	{
		switch (alg)
		{
		case 0:
			c1.FCFS(clock, &totalProcessTime);
			c2.FCFS(clock, &totalProcessTime);
			c3.FCFS(clock, &totalProcessTime);
			clock++;
			break;
		case 1:
			c1.RR(clock, &totalProcessTime);
			c2.RR(clock, &totalProcessTime);
			c3.RR(clock, &totalProcessTime);
			clock++;
			break;
			
		default:
			break;
		}
	
	} while (c1.getBusy() == true || c2.getBusy() == true || c3.getBusy() == true || !user.empty()); 
	double utilization = ((double)clock - (double)c1.getWasted()) / (double)clock;
	int totalThroughput = c1.getThroughput() + c2.getThroughput() + c3.getThroughput(); 
	cout << utilization  << endl;
	cout << c3.getWasted() << endl;
	cout << c2.getWasted() << endl;
	cout << c3.getWasted() << endl;
	
	return 0;
}

