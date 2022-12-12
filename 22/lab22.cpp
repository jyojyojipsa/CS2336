// Kangmin Kim
// CS 2336
// Lab 22
#include <iostream>
#include <string>

using namespace std;

// function template prototype
template<typename T>
const T *binarySearch(const T *first, const T *last, T itemToFind)
{
	const T *middle = first + (last - first) / 2;
	
	if( first > last )
		return nullptr;
	else if( *middle == itemToFind )
		return middle;
	else if( itemToFind < *middle )
		return binarySearch(first, middle - 1, itemToFind);
	else
		return binarySearch(middle + 1, last, itemToFind);
}
	/*while (first <= last)
	{
		middle = first + (last - first) / 2;
		
		
		if (itemToFind == *middle)
			return middle;
		else if (itemToFind < *middle)
			last = middle - 1;
		else
			first = middle + 1;
	}*/
	
	//return nullptr;

