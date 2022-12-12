// Kangmin Kim
// CS 2336
// Lab 26

#include <vector>
#include <cmath>

using namespace std;

int meanUsingIndexing(const vector<int>& v){
	vector<int>::size_type i, end = v.size();
	double total = 0;
	double avg = 0;
	int cnt = 0;
	for(i = 0; i < end; ++i)
	{
		total += v[i]; // total += v.at(i);
		cnt++;
	}
		avg = total / cnt;
	return round(avg);
}

int meanUsingIterators(const vector<int>& v){
	vector<int>::const_iterator itr, end = v.cend();
	double total = 0;
	double avg = 0;
	int cnt = 0;
	for (itr = v.cbegin(); itr < end; ++itr){
		
			total += *itr;
			cnt++;
		}
		avg = total / cnt;

		return round(avg);
	
}

int meanUsingPointers(const vector<int>& v){
	vector<int>::const_pointer ptr, end = v.data() + v.size();
	double total = 0;
	double avg = 0;
	int cnt = 0;
	for (ptr = v.data(); ptr < end; ++ptr){
		total += *ptr;
		cnt++;
	}
	
		avg = total / cnt;

	return round(avg);
}
