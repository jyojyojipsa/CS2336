// Kangmin Kim
// CS 2336
// Lab 25


template<typename U>
ostream& operator<<(ostream& output, const Accumulator<U>& obj)
{
        
        output << obj.getTotal();
		return output;
}

template<typename T>
Accumulator<T>::Accumulator(const T& value  /*= T()*/ )    //constructor
{
        this->total = value;
}

// access and update functions
template<typename T>
T Accumulator<T>::getTotal() const                         // return total
{
        return this->total;
}

template<typename T>
void Accumulator<T>::addValue(const T& value)              // add (+) value to total
{
        this->total += value;
}

