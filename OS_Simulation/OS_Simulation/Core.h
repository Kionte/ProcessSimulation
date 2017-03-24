#ifndef CORE_H
#define CORE_H


#include<queue>
#include<thread>
#include<map>
#include"Process.h"
using namespace std;
class Core
{
private:

	queue<Process>* PrevQ;
	queue<Process>* NextQ;
	int quantum;
	Process runningP;
	int throughput;
	int totalWait;
	int totalResponse;
	int totalTurnaround;
	thread t;



public:
	Core();


	// getters
	queue<Process>* getPrevQ();
	queue<Process>* getNextQ();
	int getQuantum();
	Process getRunningP();
	int getThroughput();
	int getTotalWait();
	int getTotalResponse();
	int getTotalTurnAround();

	// setters
	void setPrevQ(queue<Process>* prevQ);
	void setNextQ(queue<Process>* nextQ);
	void setQuantum(int quantum);
	void setRunningP(Process runningP);
	void setThroughput(int throughput);
	void settotalWait(int totalWait);
	void setTotalResponse(int totalResponse);
	void setTotalTurnAround(int totalTurnAround);

	void algorithm();
	void run(void(*func));
	void run(void(*func)(map<int, Process>), map<int, Process> processes);

};

#endif // !CORE_H
