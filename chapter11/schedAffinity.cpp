#include <iostream>
#include <sched.h>
#include <unistd.h>
#include <string.h>

void current_affinity();

int main ()
{
   std::cout << "Before sched_setaffinity => ";
   current_affinity();

   cpu_set_t cpuset;
   CPU_ZERO(&cpuset);
   int cpu_id = 3;
   CPU_SET(cpu_id, &cpuset);

   int set_result = sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpuset);
   if (set_result != 0) 
   {
      std::cerr << "Error on sched_setaffinity" << std::endl;
      std::cout << errno << "-" << strerror(errno) << std::endl;
   }

   std::cout << "After sched_setaffinity => ";
   current_affinity();
   return 0;
}

// Helper function
void current_affinity()
{
   cpu_set_t mask;
   if (sched_getaffinity(0, sizeof(cpu_set_t), &mask) == -1) 
   {
      std::cerr << "error on sched_getaffinity";
      return;
   } 
   else 
   {
      long nproc = sysconf(_SC_NPROCESSORS_ONLN);
      for (int i = 0; i < nproc; i++) 
      {
         std::cout << CPU_ISSET(i, &mask);
      }
      std::cout << std::endl;
   }
}
