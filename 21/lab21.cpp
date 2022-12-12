// Kangmin Kim
// CS 2336
// Lab 21

// function template prototype
template<typename T>
const T *linearSearch(const T *array, int n, T itemToFind)
{
	const T *ptr = array;
	
	if( n == 0 )
		return nullptr;
	else if(*ptr == itemToFind)
			return ptr;
	else return linearSearch(array + 1, n - 1, itemToFind);
		
	/*for (ptr = array; ptr < array + n; ptr++){
		if(*ptr == itemToFind)
			return ptr;
	}*/
	
	//return nullptr;

}

