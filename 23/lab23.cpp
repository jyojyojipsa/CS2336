// Kangmin Kim
// CS 2336
// Lab 23

template<typename T>
int numDistinct(const T *array, int n)
{
	int myNumDistinct = 0;
	const T *outer = array, *inner, *const end = array + n;
	
	if(outer == end)
		return 0;
	else if( outer < end )
		myNumDistinct += numDistinct(array + 1, n - 1);
	// 
	// for (outer = array; outer < end; ++outer)
	// {
		for (inner = outer + 1; inner < end && *outer != *inner; ++inner)
		{
			//empty body
		}
	if (inner == end)
		{
		myNumDistinct++;
		}
	//	}
	return myNumDistinct;
}

/*


----------------------------------------------------

a  b  c  a  b (end)
a------->a exit
b------->b exit
c--------->(end) myNumDistinct++
a--------->(end)
b--------->(end)

----------------------------------------------------








*/