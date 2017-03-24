#include "Core.h"


// Ctor
Core::Core() {}

// getters

int Core::getQuantum()
{
	return quantum;
}
Process Core::getRunningP()
{
	return runningP;
}
int Core::getThroughput()
{
	return throughput;
}
int Core::getTotalWait()
{
	return totalWait;
}
int Core::getTotalResponse()
{
	return totalResponse;
}
int Core::getTotalTurnAround()
{
	return totalTurnaround;
}



// setters

void Core::setQuantum(int quantum)
{
	this->quantum = quantum;
}
void Core::setRunningP(Process runningP)
{
	this->runningP;
}
void Core::setThroughput(int throughput)
{
	this->throughput = throughput;
}
void Core::settotalWait(int totalWait)
{
	this->totalWait = totalWait;
}
void Core::setTotalResponse(int totalResponse)
{
	this->totalResponse = totalResponse;
}
void Core::setTotalTurnAround(int totalTurnAround)
{
	this->totalTurnaround = totalTurnAround;
}


// special
