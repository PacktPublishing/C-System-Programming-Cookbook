#include <string.h>
#include <iostream>
#include <sched.h>

int main ()
{
   std::cout << "Starting ..." << std::endl;

   for( ;; ) 
   {
      int counter = 0;
      for(int i = 0 ; i < 10000 ; ++i)
         counter += i;

      if (sched_yield() == -1)
      {
         std::cout << "sched_yield failed = " << strerror(errno) << std::endl;
         return 1;
      }
   }

   // we should never get here ... 
   std::cout << "End ..." << std::endl;
   return 0;
}
