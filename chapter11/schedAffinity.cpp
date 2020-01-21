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
   int cpu_id = 1;
   CPU_SET(cpu_id, &cpuset);
   cpu_id = 3;
   CPU_SET(cpu_id, &cpuset);

   // sched_setaffinity: This function installs the cpusetsize bytes long affinity mask pointed to
   // by cpuset for the process or thread with the ID pid. If successful the function returns zero and the scheduler 
   // will in future take the affinity information into account.
   int set_result = sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpuset);
   if (set_result != 0) 
   {
      std::cerr << "Error on sched_setaffinity" << std::endl;
      std::cout << errno << "-" << strerror(errno) << std::endl;
   }

   // Check what is the actual affinity mask that was assigned to the thread.
   // sched_getaffinity: This functions stores the CPU affinity mask for the process or thread with the ID pid in 
   // the cpusetsize bytes long bitmap pointed to by cpuset. If successful, the function always initializes all bits
   // in the cpu_set_t object and returns zero.
   // int get_affinity = sched_getaffinity(pid, sizeof(cpu_set_t), &cpuset);
   // if (get_affinity != 0) 
   // {
   //    std::cout << "Error on sched_getaffinity" << std::endl;
   // }
 
   // CPU_ISSET: This macro returns a nonzero value (true) if cpu is a member of the CPU set set, and zero (false) otherwise.
   // if (CPU_ISSET(cpu_id, &cpuset)) 
   // {
   //    std::cout << "Successfully set thread " << pid << " to affinity to CPU: " << cpu_id << std::endl;
   // } else 
   // {
   //    std::cerr << "Failed set thread to affinity to CPU " << std::endl;
   // }

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
