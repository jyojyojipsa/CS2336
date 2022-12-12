// CS 2336
// Lab 33
// Kangmin Kim

template <typename T>

void shellSort(vector<T>& v)

{
	typename vector<T>::size_type i;
	typename vector<T>::size_type j;
	typename vector<T>::size_type end = v.size();
    uint k;


    // calculate k using the for loop
    for (k = 1; k <= v.size() / 9; k = 3 * k + 1)
    { }
    
    // implement the Shell sort
    while (k > 1)
    {
        for (i = 0; i < k; i++)
        {
            vector<T> sublist;
            // step 1: build sublist_i
            // obtain from v: i, i + k, i + 2k, ...
			for (j = i; j < end; j+=k)
			{
                sublist.emplace_back(v[j]);
			}
            // step 2: call insertionSort(sublist);
            insertionSort(sublist); // sort when it's not sorted
			
			uint a = 0;
            // step 3: take the elements from the sorted sublist and place them back at the appropriate places in v
			for (j = i; j < end; j+=k)
			{
				v[j] = sublist[a];
				a++;
			}
        }
        k /= 3;
    }
    // call insertionSort one more time on va_arg
    insertionSort(v);
}
