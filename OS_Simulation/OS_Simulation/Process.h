#ifndef PROCESS_H_
#define PROCESS_H_



struct Process {
	Process() {}
	Process(int PID, int priority, int arrivalTime, int cpuBurst, int ioBurst,
		int turnAround, int wait, int response, int contextSwitch, int startTime, int tProcessTime) :
	PID(PID), priority(priority), arrivalTime(arrivalTime), cpuBurst(cpuBurst), ioBurst(ioBurst),
		turnAround(turnAround), wait(wait), response(response), contextSwitch(contextSwitch), 
		startTime(startTime), tProcessTime(tProcessTime) {
		this->complete = false;
		this->firstTime = true; 
		this->taken = false; 
	}



	int PID;			//set at creation
	int priority;		//set at creation
	int arrivalTime;		//set when entered into system (populateQueue)
	int ioBurst;		//set at creation
	int cpuBurst;		//set at creation
	int turnAround;		//set on exit (exit time - arriaval time)
	int wait;			//set on exit (exit - arrival - tProcessTime)
	int response;		//set on arrival to core (startTime - arrivalTime)
	int contextSwitch;	//set on creation
	int startTime;		//set on arrival to core (clock)
	int tProcessTime;	//set on creation cpuBurst + ioBurst + contextSwitch
	int exit;			//set on exit (clock)
	bool complete;		//set on creation (false)
	bool firstTime;     //used to identify if process has ran through a core before
	int doneWhen;
	int timeLeft;
	int newStart;
	bool taken; 

};
#endif // !PROCESS_H_
