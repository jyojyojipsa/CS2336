// Kangmin Kim
// CS 2336
// Lab 20

#include <iostream>
using namespace std;

template<typename T>
void mySwap(T& first, T& second){
	T temp;
	temp = first;
	first = second;
	second = temp;
}

template<typename T>
void bubbleSort(T *array, int n){
	  int j;
	  bool did_swap = false;
	  
	  

    for (j = 0; j < n - 1; ++j)
      if(array[j] > array[j + 1])
	  {
		  mySwap(array[j], array[j + 1]);
		  did_swap = true;
	  }
	if(did_swap)
		return bubbleSort(array, n - 1);
} 
