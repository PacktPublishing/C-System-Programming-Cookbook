#include <iostream>
#include <limits>

int main ()
{
   // integral types section
   std::cout << "char " << int(std::numeric_limits<char>::min())
             << "-" << int(std::numeric_limits<char>::max())
             << " size (Byte) =" << sizeof (char) << std::endl;
   std::cout << "wchar_t " << std::numeric_limits<wchar_t>::min()
             << "-" <<  std::numeric_limits<wchar_t>::max()
             << " size (Byte) ="
             << sizeof (wchar_t) << std::endl;
   std::cout << "int " << std::numeric_limits<int>::min() << "-"
             << std::numeric_limits<int>::max() << " size (Byte) ="
             << sizeof (int) << std::endl;
   std::cout << "bool " << std::numeric_limits<bool>::min() << "-"
             << std::numeric_limits<bool>::max() << " size (Byte) ="
             << sizeof (bool) << std::endl;

// floating point types
   std::cout << "float " << std::numeric_limits<float>::min() << "-"
             << std::numeric_limits<float>::max() << " size (Byte) ="
             << sizeof (float) << std::endl;
   std::cout << "double " << std::numeric_limits<double>::min() << "-"
             << std::numeric_limits<double>::max() << " size (Byte) ="
             << sizeof (double) << std::endl;

   return 0;
}

