#ifndef PROCESS_H
#define PROCESS_H




struct Process
{
	int id;
	int priority;
	int ioBurst;
	int cpuBurst;
	int turnAround;
	int wait;
	int response;
	int contextSwitchTime;

	Process() {}
	Process(int id, int priority, int ioBurst, int cpuBurst, int turnAround, int wait, int response, int contextSwitchTime) 
	{
		this->id = id;
		this->priority = priority;
		this->ioBurst = ioBurst;
		this->cpuBurst = cpuBurst;
		this->turnAround = turnAround;
		this->wait = wait;
		this->response = response;
		this->contextSwitchTime = contextSwitchTime;
	}

};

#endif // !PROCESS_H
