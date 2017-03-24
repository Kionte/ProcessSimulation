#ifndef PROCESS_H_
#define PROCESS_H_


struct Process {
	Process() {}
	Process(int PID, int priority, int cpuBurst, int ioBurst,
		int contextSwitch) {
		this->PID = PID; 
		this->priority = priority; 
		this->cpuBurst = cpuBurst; 
		this->ioBurst = ioBurst; 
		this->contextSwitch = contextSwitch; 
		this->complete = false;
		this->tProcessTime = this->cpuBurst + this->ioBurst + this->contextSwitch; 
		this->firstTime = true; 
	}
	int PID;			//set at creation
	int priority;		//set at creation
	int arrival_t;		//set when entered into system (populateQueue)
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
	bool firstTime; 
	int qProcessTime; 

};
#endif // !PROCESS_H_
