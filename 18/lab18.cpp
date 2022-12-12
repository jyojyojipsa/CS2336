// Kangmin Kim
// CS 2336
// Lab 18
#include <iostream>
#include <bits.h>

using namespace std;

// printBinary is a recursive function that writes the binary
// representation of num to output stream os
void printBase32(int num, ostream& os){
	if(num == 0)
	{
		return;
	}
	else
	{
		
		
		unsigned int unum = static_cast<unsigned int>(num);
		
		printBase32(unum >> 5, os);  // 16 bits = 4; from cs 24  28	
		if(getBits(unum,0,5) >= 0 && getBits(unum,0,5) < 10)
			os << getBits(unum,0,5);
		else if(getBits(unum,0,5) == 10)
			os << 'A';
		else if(getBits(unum,0,5) == 11)
			os << 'B';
		else if(getBits(unum,0,5) == 12)
			os << 'C';
		else if(getBits(unum,0,5) == 13)
			os << 'D';
		else if(getBits(unum,0,5) == 14)
			os << 'E';
		else if(getBits(unum,0,5) == 15)
			os << 'F';
		else if(getBits(unum,0,5) == 16)
			os << 'G';
		else if(getBits(unum,0,5) == 17)
			os << 'H';
		else if(getBits(unum,0,5) == 18)
			os << 'I';
		else if(getBits(unum,0,5) == 19)
			os << 'J';
		else if(getBits(unum,0,5) == 20)
			os << 'K';
		else if(getBits(unum,0,5) == 21)
			os << 'L';
		else if(getBits(unum,0,5) == 22)
			os << 'M';
		else if(getBits(unum,0,5) == 23)
			os << 'N';
		else if(getBits(unum,0,5) == 24)
			os << 'O';
		else if(getBits(unum,0,5) == 25)
			os << 'P';
		else if(getBits(unum,0,5) == 26)
			os << 'Q';
		else if(getBits(unum,0,5) == 27)
			os << 'R';
		else if(getBits(unum,0,5) == 28)
			os << 'S';
		else if(getBits(unum,0,5) == 29)
			os << 'T';
		else if(getBits(unum,0,5) == 30)
			os << 'U';
		else if(getBits(unum,0,5) == 31)
			os << 'V';
		
	}
}
