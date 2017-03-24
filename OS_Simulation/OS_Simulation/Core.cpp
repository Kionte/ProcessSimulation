#include "Core.h"


// Ctor
Core::Core(queue<Process>* rq, int q)
{
	busy = false; 
	ready = rq; 
	quantum = 0;
	throughput = 0;
	totalWait = 0;
	totalResponse = 0;
	totalTurnaround = 0;
	quantum = q; 
	wasted = 0; 
}

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

bool  Core::getBusy()
{
	return busy; 
}

int Core::getWasted()
{
	return wasted; 
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


// algs
void Core::FCFS(int clock, int* totalProcessTime)
{
	if (busy == false)
	{
		if (!ready->empty())
		{
			runningP = ready->front();
			ready->pop();
			runningP.startTime = clock;
			runningP.response = runningP.startTime - runningP.arrival_t;
			runningP.wait = runningP.startTime - runningP.arrival_t; 
			busy = true;
		}
	}

		if (runningP.startTime + runningP.tProcessTime <= clock && runningP.complete == false)
		{
			runningP.exit = clock;
			runningP.turnAround = runningP.exit - runningP.arrival_t;
			

			throughput++;
			totalWait += runningP.wait;
			totalResponse += runningP.response;
			totalTurnaround += runningP.turnAround;
			runningP.complete = true; 
			busy = false;
		}
		if (runningP.complete == true)
		{
			wasted++;
		}
}
void Core::RR(int clock, int * totalProcessTime) 
{
	if (busy == false)
	{
		if (!ready->empty())
		{
			runningP = ready->front(); 
			ready->pop();
			runningP.startTime = clock; 
			if (runningP.firstTime == true)
			{
				runningP.response = runningP.startTime - runningP.arrival_t; 
				runningP.qProcessTime = runningP.tProcessTime; 
				runningP.firstTime = false;
				*totalProcessTime += runningP.tProcessTime;
			}
			busy = true; 

		}
	}

	if (*totalProcessTime == 0)
	{
		runningP.complete = true;
		busy = false;
	}
	if (runningP.startTime + runningP.qProcessTime <= clock && runningP.complete == false)
	{
		runningP.exit = clock;
		runningP.turnAround = runningP.exit - runningP.arrival_t;
		runningP.wait = runningP.exit - runningP.arrival_t - runningP.tProcessTime;

		throughput++;
		totalWait += runningP.wait;
		totalResponse += runningP.response;
		totalTurnaround += runningP.turnAround;
		runningP.complete = true;
		busy = false;
		*totalProcessTime -= runningP.tProcessTime;
	}
	else if(clock - runningP.startTime >= quantum && runningP.complete == false)
	{
		runningP.qProcessTime -= quantum;
		busy = false;
		ready->push(runningP);
	}
	if (runningP.complete == true)
	{
		wasted++; 
	}

}
void Core::MLFB(queue<Process>* ready) 
{

}
