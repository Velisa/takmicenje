#include <limits>
#include <iostream>
using namespace std;

int main() {
  std::cout
    << static_cast<int>(numeric_limits<char>::min()) << "\n"
 		<< static_cast<int>(numeric_limits<char>::max()) << "\n\n"
   	<< static_cast<int>(numeric_limits<unsigned char>::min()) << "\n"
   	<< static_cast<int>(numeric_limits<unsigned char>::max()) << "\n\n"
   	<< numeric_limits<short>::min() << "\n"
		<< numeric_limits<short>::max() << "\n\n"
		<< numeric_limits<unsigned short>::min() << "\n"
		<< numeric_limits<unsigned short>::max() << "\n\n"
		<< numeric_limits<int >::min() << "\n"
		<< numeric_limits<int >::max() << "\n\n"
		<< numeric_limits<unsigned int >::min() << "\n"
		<< numeric_limits<unsigned int >::max() << "\n\n"
		<< numeric_limits<long >::min() << "\n"
		<< numeric_limits<long >::max() << "\n\n"
		<< numeric_limits<unsigned long >::min() << "\n"
		<< numeric_limits<unsigned long >::max() << "\n\n"
		<< numeric_limits<long long >::min() << "\n"
		<< numeric_limits<long long >::max() << "\n\n"
		<< numeric_limits<unsigned long long >::min() << "\n"
		<< numeric_limits<unsigned long long >::max() << "\n\n";
}

