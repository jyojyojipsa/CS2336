// Kangmin Kim
// CS 2336
// Lab 15
#include <iostream>
#include <bits.h>

using namespace std;

// printBinary is a recursive function that writes the binary
// representation of num to output stream os
void printQuaternary(int num, ostream& os){
	if(num == 0)
	{
		return;
	}
	else
	{
		unsigned int unum = static_cast<unsigned int>(num);
		printQuaternary(unum >> 2, os);  // 16 bits = 4; from cs 24  28
		os << getBits(unum,0,2); // right shift 하고 0이나 1 했을때 랜덤이라 1이 들어오면 좆된다.
								//2칸가면 4로 나누고 나머지를 아웃풋
								//몫은 또 나누고
	}
}
