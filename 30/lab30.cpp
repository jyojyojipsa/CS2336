// Kangmin Kim
// CS 2336
// Lab 30

#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <IntegerSet.h>

using namespace std;

void sieveOfEratosthenes(IntegerSet& prime)
{
	   for(uint i = 2; i * i < prime.size(); i++){
		  if(prime.isMember(i) == 1)
			for(uint j = i*2; j <= prime.size(); j+=i)
				prime.reset(j);
	   }
}
ostream& operator<<(ostream& out, const IntegerSet& set)
{
      
	  for(uint i = 2; i <= set.size();i++){
			if(set.isMember(i))
				out << i << '\n';
	  }

	  
	  return out;
}
