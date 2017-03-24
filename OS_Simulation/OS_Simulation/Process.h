#ifndef PROCESS_H_
#define PROCESS_H_


struct Process {
	Process() {}
	Process(int PID, int priority, int arrival_t, int cpuBurst, int ioBurst,
		int turnAround, int wait, int response, int contextSwitch) :
		PID(PID), priority(priority), arrival_t(arrival_t), cpuBurst(cpuBurst),
		ioBurst(ioBurst), turnAround(turnAround), wait(wait), response(response), contextSwitch(contextSwitch) {}
	int PID;
	int priority;
	int arrival_t;
	int ioBurst;
	int cpuBurst;
	int turnAround;
	int wait;
	int response;
	int contextSwitch;

};
#endif // !PROCESS_H_
