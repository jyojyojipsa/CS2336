// Kangmin Kim
// CS 2336
// Lab 34

template<typename T>
void miniVector<T>::insert(int i, const T& item)
{
	if (empty() && i != 0)
	{
		throw underflowError("miniVector insert(): vector empty");
	}
	if (i < 0 || i > vSize)
	{
		throw indexRangeError("miniVector insert(): index range error", i, vSize);
	}
	
	push_back(item);
	// Loop to move the existing elements to create an open
	for(int x = vSize - 1; x > i; --x)
	{
		vArr[x] = vArr[x - 1];
	}
	// spot at index i
	vArr[i] = item;

		
}
// insert item at index i in the vector.
// Precondition vector is not empty and 0 <= i <= vSize.
// Postcondition the vector size increases by 1.
 
template<typename T>
void miniVector<T>::erase(int i)
{
	if (empty())
	{
		throw underflowError("miniVector erase(): vector empty");
	}
	if (i < 0 || i >= vSize)
	{
		throw indexRangeError("miniVector erase(): index range error", i, vSize);
	}
	
	
	for(int x = i; x < vSize - 1; x++)
	{
		vArr[x] = vArr[x + 1];
	}
	
	
	pop_back();
}

// erase the item at index i in the vector.
// Precondition vector is not empty and 0 <= i < vSize.
// Postcondition the vector size decreases by 1.
