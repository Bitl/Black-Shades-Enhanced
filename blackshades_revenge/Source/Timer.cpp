/**> HEADER FILES <**/
#ifdef WIN32
#include "Support.h"
#endif

#include <string.h>
#include "Timer.h"				


/********************> Timer <*****/
void TimerInit(timer* theTimer)
{
	UnsignedWide			ms;								

	Microseconds(&ms);									
	 
	memset(theTimer, 0, sizeof(timer));						

	theTimer->mm_timer_start	= ms.lo;						
	theTimer->mm_timer_elapsed	= theTimer->mm_timer_start;			
}

float TimerGetTime(timer* theTimer)
{
	UnsignedWide			ms;
	
	Microseconds(&ms);
	
	
	return( (float) (ms.lo - theTimer->mm_timer_start) * 1000.0f);
}
