#ifndef TOWNSTHREAD_IS_INCLUDED
#define TOWNSTHREAD_IS_INCLUDED
/* { */


#include <thread>
#include <mutex>

#include "towns.h"
#include "outside_world.h"

class TownsThread
{
private:
	FMTowns *townsPtr;
	int runMode;

public:
	bool unitTestDone;
	int returnCode;
	mutable std::mutex vmLock,signalLock;

	enum
	{
		RUNMODE_PAUSE,
		RUNMODE_FREE,
		RUNMODE_DEBUGGER,
		RUNMODE_ONE_INSTRUCTION, // Always with debugger.
		RUNMODE_EXIT,
	};

	TownsThread();

	void Start(FMTowns *townsPtr,Outside_World *outside_world);

	/*! Returns the current run mode.
	    The thread that calls this function must take vmLock before calling.
	*/
	int GetRunMode(void) const;

	/*! Sets the current run mode.
	    The thread that calls this function must take vmLock before calling. 
	*/
	void SetRunMode(int runModevoid);

	void PrintStatus(const FMTowns &towns) const;

	/*! Returns true if (EDX=="TSUG" && EAX=="ARU!") (success) || (EDX=="FAIL" && EAX=="FAIL"))
	    It also sets returnCode 0 (success) or 1 (fail).
	*/
	bool UnitTestDone(const FMTowns &towns);
};

class TownsUIThread
{
public:
	void Run(TownsThread *vmThread,FMTowns *towns,const class TownsARGV *argv,Outside_World *outside_world);
private:
	virtual void Main(TownsThread &vmThread,FMTowns &towns,const class TownsARGV &argv,Outside_World &outside_world)=0;
};

/* } */
#endif
