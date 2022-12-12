// Kangmin Kim
// CS 2336
// Lab 12

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void insertComma(unsigned long num, ostream& os){

	if(num < 1000) // base case when the reursion stops
	{
		os << num;
	}
	else
	{
		insertComma(num / 1000, os);
		char ch = os.fill(); // obtain the current fill char 
		os << "," << setfill('0') << setw(3) << num % 1000;
		os.fill(ch); // restore the fill char to its original setting
	}

}
