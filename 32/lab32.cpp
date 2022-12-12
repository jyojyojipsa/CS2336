// Kangmin Kim
// CS 2336
// Lab 32


template <typename T>
void exchangeSort(vector<T>& v){
	typename vector<T>::size_type i;
	typename vector<T>::size_type j;
	typename vector<T>::size_type temp;
	for(i = 0; i < v.size();i++)
	{
		for(j = i + 1; j < v.size(); j++)
		{
			if (v[i] > v[j])
			{
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
	return;
}