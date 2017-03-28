#include "Core.h"


// Ctor
Core::Core(queue<Process>* rq, int q)
{
	busy = false; 
	ready = rq; 
	totalWait = 0;
	totalResponse = 0;
	totalTurnaround = 0;
	quantum = q; 
	totalContextSwitch = 0; 
	throughput = 0;
	wasted = 0; 
	readyWhen = 0;
}


// getters
int Core::getTotalTurnAround() {
	return totalTurnaround; 
}
int Core::getQuantum() {
	return quantum;
}
Process Core::getRunningP() {
	return runningP;
}



int Core::getTotalWait(){
	return totalWait;
}
int Core::getTotalResponse(){
	return totalResponse;
}


bool Core::getBusy(){
	return busy; 
}

int Core::getWasted(){
	return wasted; 
}

int Core::getConSwitch(){
	return totalContextSwitch; 
}

int Core::getThroughput(){
	return throughput; 
}

int Core::getReadyWhen() {
	return readyWhen;
}

// setters
void Core::setQuantum(int quantum){
	this->quantum = quantum;
}
void Core::setRunningP(Process *runningP){
	this->runningP;
}
void Core::settotalWait(int *totalWait){
	this->totalWait = *totalWait;
}
void Core::setTotalResponse(int totalResponse){
	this->totalResponse = totalResponse;
}
void Core::setTotalTurnAround(int totalTurnAround){
	this->totalTurnaround = totalTurnAround;
}
void Core::setTotalThroughput(int *throughput) {
	this->throughput = *throughput;
}





// algorithms
void Core::FCFS(int clock, int* totalProcessTime){
	if (busy == false && !ready->empty()) { // if current core is free & the global queue is not empty, execute process
			runningP = ready->front();
			ready->pop();
			runningP.startTime = clock;
			runningP.response = runningP.startTime - runningP.arrivalTime;
			runningP.wait = runningP.response; // Response time & wiat time are the same in FCFS 
			busy = true;
	} else if (busy == false && !ready->empty()) {
		wasted++; }
		if ((runningP.startTime + runningP.tProcessTime) == clock){
			runningP.exit = clock;
			runningP.turnAround = (runningP.exit - runningP.arrivalTime);
			++throughput;
			totalContextSwitch += runningP.contextSwitch; 
			totalWait += runningP.wait;
			totalResponse += runningP.response;
			totalTurnaround += runningP.turnAround;
			runningP.complete = true; 
			busy = false;
		}

}

void Core::RR(int clock, int* totalProcessTime) {	
	if (busy == false && !ready->empty()) {
			//start:
			runningP = ready->front();
			ready->pop();
			if (runningP.firstTime == true) {
				runningP.startTime = clock; // sets original start time
				runningP.response = runningP.startTime - runningP.arrivalTime;
				runningP.doneWhen = runningP.startTime + runningP.tProcessTime;
				//runningP.timeLeft = runningP.tProcessTime - quantum;
				runningP.firstTime = false;
				*totalProcessTime += runningP.tProcessTime;
			}
			busy = true;
			runningP.newStart = clock;
			readyWhen = runningP.newStart + quantum;
			//runningP.doneWhen = runningP.newStart + quantum;

			if (runningP.firstTime == false) {
				runningP.timeLeft -= quantum;
			}
		}

		if (busy == false && ready->empty()) {
			wasted++;
		}

		if (runningP.timeLeft < 0) { runningP.timeLeft = 0; }

		if (runningP.doneWhen == clock) {
			runningP.exit = clock;
			runningP.turnAround = (runningP.exit - runningP.arrivalTime);
			runningP.wait = runningP.response + runningP.exit - runningP.arrivalTime - runningP.tProcessTime;
			throughput++;
			totalContextSwitch += runningP.contextSwitch;
			totalWait += runningP.wait;
			totalResponse += runningP.response;
			totalTurnaround += runningP.turnAround;
			runningP.complete = true;
			busy = false;
			*totalProcessTime -= runningP.tProcessTime;
		}
		else if (readyWhen == clock) {
			ready->push(runningP); // push back to global queue
			if (!ready->empty()) {
				runningP = ready->front();
				ready->pop();
			}
			busy = false;
			//goto start;
		}
		//--runningP.doneWhen;

}


void Core::MLFB(queue<Process>* ready) 
{

}
