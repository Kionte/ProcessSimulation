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
	Process(int id, int priority, int ioBurst, int cpuBurst, int turnAround, int wait, int response, int contextSwitchTime) {}
};

