#include <sched.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
   std::cout << "Starting ..." << std::endl;

   int policy = sched_getscheduler(getpid());
   switch(policy) 
   {
      case SCHED_OTHER: std::cout << "current process' policy = SCHED_OTHER" << std::endl ; break;
      case SCHED_RR:   std::cout << "current process' policy = SCHED_RR" << std::endl;  break;
      case SCHED_FIFO:  std::cout << "current process' policy = SCHED_FIFO" << std::endl; break;
      default:   std::cout << "Unknown... " << std::endl;
   }

   int fifoMin = sched_get_priority_min(SCHED_FIFO);
   int fifoMax = sched_get_priority_max(SCHED_FIFO);
   std::cout << "MIN Priority for SCHED_FIFO = " << fifoMin << std::endl;
   std::cout << "MAX Priority for SCHED_FIFO = " << fifoMax << std::endl;

   struct sched_param sched;
   sched.sched_priority = (fifoMax - fifoMin) / 2;
   if (sched_setscheduler(getpid(), SCHED_FIFO, &sched) < 0)
      std::cout << "sched_setscheduler failed = " << strerror(errno) << std::endl;
   else
      std::cout << "sched_setscheduler has set this process priority to = " << sched.sched_priority << std::endl;

   policy = sched_getscheduler(getpid());
   std::cout << "=> " << policy << std::endl;

   std::cout << "End ..." << std::endl;
   return 0;
}
