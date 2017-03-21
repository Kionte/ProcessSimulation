#include<queue>
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

public:

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
};