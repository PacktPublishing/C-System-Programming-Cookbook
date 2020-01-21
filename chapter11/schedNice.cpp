#include <string.h>
#include <iostream>
#include <unistd.h>

int main ()
{
   std::cout << "Starting ..." << std::endl;

   if (nice (5) == -1)
      std::cout << "nice failed = " << strerror(errno) << std::endl;
   else
      std::cout << "nice value succesfully set = " << std::endl;

   while (1) ;
   std::cout << "End ..." << std::endl;
   return 0;
}
