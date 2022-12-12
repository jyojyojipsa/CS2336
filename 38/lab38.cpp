// CS 2336
// Lab 38
// Kangmin Kim

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

void bucketSort(vector<uint>& v, uint numDigits)
{
		vector<vector<uint>> buckets;
		
		
		// resize the buckets vector to have 10 rows
		buckets.resize(10);
		uint b,d,i,j;
		uint n = v.size();
		
		
		
		
		// Loop numDigits times
		//   1) distribution psas
		for(d = 0; d < numDigits; d++)
		{
			for(i = 0; i < n; i++)
			{
				buckets[(v.at(i) / static_cast<uint>(pow(10,d))) % 10].push_back(v.at(i));
			}
			v.clear();
		
		
		
		//   2) gathering pass
		for(i = 0; i < 10; i++)
		{
			b = buckets[i].size();
			for(j = 0; j < b; j++)
			{
				v.push_back(buckets[i][j]);
			}
			buckets[i].clear();
		}
		
	}
}
