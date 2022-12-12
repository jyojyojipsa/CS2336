// Kangmin Kim
// CS 2336
// Lab 29

#include <algorithm>


template<typename T>
bool nextPermutation(vector<T>& v)
{
	uint length = v.size() - 1;
	for(uint i = length; i > 0 ;--i){ // search i - 1    1 3 2 5 
		if(v[i-1] < v[i])  // 1 3 2 5
						//       i-1i
			for(uint j = length; j > i-1; --j){ // search j
				if(v[i-1] < v[j]){ //   1 3 2 5
				swap(v[i-1],v[j]); //   1 3 5 2
				reverse(v.begin()+i,v.end()); // 1 3 5 2
				return true;
				}
			}
	}
	reverse(v.begin(),v.end()); // 4 3 2 1 to 1 2 3 4
	return false;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for(uint i = 0; i < v.size(); i++)
		os << v[i];
	return os;
}