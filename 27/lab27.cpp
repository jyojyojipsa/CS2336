// Kangmin Kim
// CS 2336
// Lab 27

#include <algorithm>
#include <vector>

template<typename T>
pair<T, int> modeUsingIndexing(const vector<T>& v)
{
   vector<T> copy(v); //O(N)
   pair<T, int> myMode;
   typename vector<T>::size_type i, end = copy.size();
   sort(copy.begin(), copy.end());//O(n log n)
   int count = 1;
   myMode.first = copy[0];
   myMode.second = 1;
   //Gives the first mode if there are multiple modes
   for (i = 1; i < end; i++) // o(N)
   {
	   if(copy[i-1] == copy[i])
		   count++;
	   else if(count > myMode.second){
		   myMode.second = count;
		   myMode.first = copy[i-1];
		   count = 1;
	   }
	   else{
		   count = 1;
	   }
   }
   
   if(count > myMode.second){
		   myMode.second = count;
		   myMode.first = copy[i - 1];
		   count = 1;
   }
   
	return myMode;
}

template<typename T>
pair<T, int> modeUsingIterators(const vector<T>& v){
	
	pair<T, int> myMode;
	vector<T> copy(v);
	typename vector<T>::iterator itr, end = copy.end();
	
	sort(copy.begin(), copy.end()); // 
	int count = 1;
	myMode.first = *(copy.begin());
	myMode.second = 1;
	
	for (itr = copy.begin() + 1; itr < end; ++itr){
		if (*itr == *(itr -1)) count++;
       else if (count > myMode.second) {
           myMode.second = count;
           myMode.first = *(itr-1);
           count = 1;
		}
		else
			count = 1;
	}
	if (count > myMode.second) {
           myMode.second = count;
           myMode.first = *(itr - 1);
           count = 1;
		}
	return myMode;
}

template<typename T>
pair<T, int> modeUsingPointers(const vector<T>& v){
	
	pair<T, int> myMode;
	vector<T> copy(v);
	typename vector<T>::pointer ptr, end = copy.data() + copy.size();
	
	sort(copy.begin(), copy.end()); 
	
	myMode.first = *(copy.data());
	myMode.second = 1;
	int count = 1;
	for(ptr = copy.data() + 1; ptr < end; ++ptr){
		 if (*ptr == *(ptr - 1)) 
			 count++;
       else if (count > myMode.second){
           myMode.second = count;
           myMode.first = *(ptr - 1);
           count = 1;
			}
		else 
			count = 1;
	}
	if (count > myMode.second) {
           myMode.second = count;
           myMode.first = *(ptr-1);
           count = 1;
	}
	
	return myMode;
	
}
