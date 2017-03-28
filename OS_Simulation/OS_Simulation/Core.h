#ifndef CORE_H_
#define CORE_H_


#include<queue>
#include<thread>
#include<map>
#include"Process.h"

using namespace std;
class Core
{
protected:



	Process runningP;
	queue<Process>* ready;
	int quantum;
	int totalWait;
	int totalResponse;
	int totalTurnaround;
	int totalContextSwitch; 
	int wasted; 
	bool busy; 
	int throughput;
	int readyWhen;

public:
	Core(queue<Process>* rq, int q);
	// getters
	int getQuantum();
	Process getRunningP();
	int getTotalWait();
	int getTotalResponse();
	int getTotalTurnAround();
	int getWasted(); 
	bool getBusy(); 
	int getConSwitch(); 
	int getThroughput(); 
	int getReadyWhen();
	// setters
	void setQuantum(int quantum);
	void setRunningP(Process *runningP);
	void settotalWait(int *totalWait);
	void setTotalResponse(int totalResponse);
	void setTotalTurnAround(int totalTurnAround);
	void setTotalThroughput(int *throughput);


	// algs
	void FCFS(int clock, int* totalProcessTime);
	void RR(int clock, int* totalProcessTime);
	void MLFB(queue<Process>* ready);
};

#endif // !CORE_H

