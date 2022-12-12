// Kangmin Kim
// CS 2336
// Lab 31

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string ID = "Kangmin Kim - CS 2336 - Lab 31\n\n";

int main()
{
	string inputLine;
	vector<string> filenames;
	
	uint data = 60;
	uint l = 0;

	uint r = 0;
	
	cout << ID;
	
	
	// output the horizontal line
	cout << setfill('-') << setw(60) << '-' << setfill(' ') << endl;
	
	
	// input an unknown # of lines, each containing a filenames 

	
	while (getline(cin, inputLine))
	{
		filenames.push_back(inputLine);
		if(l < inputLine.size())
		{
			l = inputLine.size();
		}	
	}
	uint f = filenames.size();
	// Sort
	sort(filenames.begin(), filenames.end());
	
	uint c = (data - l) / (l + 2) + 1;
	
	if( f % c != 0)
	r = (f / c) + 1;
	else
		r = f / c;
	
	if( f % r != 0)	
	c = (f / r) + 1;
	else
		c = f / r;
	
	 for (uint i = 0; i < r; i++)
	 {
		 for (uint j = 0 ; r * j + i < filenames.size(); j++)
		 {
			 if(j < c - 1)
				 cout << left << setw (l + 2) << filenames[r * j + i];
				 
			 else
				 cout << left << setw(l) << filenames[r * j + i];
			
		 }
		 cout << endl;
	 }
	
	
	return 0;
}
	