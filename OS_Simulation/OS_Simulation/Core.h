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

	Process runningP;
	int quantum;
	int throughput;
	int totalWait;
	int totalResponse;
	int totalTurnaround;

public:
	Core();
	// getters
	int getQuantum();
	Process getRunningP();
	int getThroughput();
	int getTotalWait();
	int getTotalResponse();
	int getTotalTurnAround();

	// setters
	void setQuantum(int quantum);
	void setRunningP(Process runningP);
	void setThroughput(int throughput);
	void settotalWait(int totalWait);
	void setTotalResponse(int totalResponse);
	void setTotalTurnAround(int totalTurnAround);

};

#endif // !CORE_H

