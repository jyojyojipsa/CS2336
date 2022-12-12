// Kangmin Kim
// CS 2336
// Lab 28


template<typename T>
bool Frequency<T>::operator==(const T rhs) const
{
   if( this->value == rhs)
return true;
else return false;
   //this에 있는놈이랑 rhs랑 같은지 비교하는거
} 
template<typename T>
bool Frequency<T>::operator< (const Frequency<T> rhs) const
{
   if(this->frequency < rhs.frequency)
	   
   return true;
   else return false;
	   
   //this에  있는놈이 rhs보다 작은지 비교하는 함수
}

template<typename T>
vector<Frequency<T> > distribution(const vector<T>& v)
{
   vector<Frequency<T>> myDist;
   typename vector<T>::const_pointer vPtr, vEnd = v.data() + v.size();
   typename vector<Frequency<T>>::iterator myDistItr;
  
   // iterate through the elements of vEnd
   for (vPtr = v.data(); vPtr < vEnd; vPtr++)
   {
       myDistItr= find(myDist.begin(), myDist.end(),*vPtr);
       if(myDistItr ==myDist.end())
       { //then we didn't find it, so add a new Frequency to myVector
           myDist.emplace_back(Frequency<T>(*vPtr));
       }
       else //we found *vPtr, so increment the appropriate frequency
       {
           myDistItr->increment();//(*findItr).increment();
       }
   }
   return myDist;
  
}

template<typename T>
ostream& operator<<(ostream& out, const vector<Frequency<T>>& v)
{
	typename vector<T>::size_type i, end = v.size();
   for (i = 0; i < end; ++i)
      out << v[i].getValue() << " -> " << v[i].getFrequency() << "\n";
  
  return out;
}
