#include <sched.h>
#include <iostream>
#include <string.h>

int main ()
{
   std::cout << "Starting ..." << std::endl;

   struct sched_param sched;
   sched.sched_priority = 8;
   if (sched_setscheduler(0, SCHED_RR, &sched) < 0)
      std::cout << "sched_setscheduler failed = " << strerror(errno) 
                << std::endl;
   else
      std::cout << "sched_setscheduler has set this process priority to = " 
                << sched.sched_priority << std::endl;

   struct timespec tp;
   int retCode = sched_rr_get_interval(0, &tp);
   if (retCode == -1)
   {
      std::cout << "sched_rr_get_interval failed = " << strerror(errno) << std::endl;
      return 1;
   }

   std::cout << "timespec sec = " << tp.tv_sec << " nanosec = " << tp.tv_nsec << std::endl;
   std::cout << "End ..." << std::endl;
   return 0;
}
