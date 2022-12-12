// Kangmin Kim
// CS 2336
// Lab 09

#include <lab09.h>

  Rational&  Rational::operator++()                         // preincrement
  {
	  uint num = this->getNumerator();
	  uint denom = this->getDenominator();
	  
	  this->setNumerator(num + denom);
	  this->reduce();
	  // add "1" to this
	  // If *this = 2/3, then *this becomes 5/3
	  return *this;
  }
  Rational  Rational::operator++(int)                       // postincrement
  {
	  Rational copy = *this;
	  
	  // call the preincrement operato to increment *this
	  //++this; // increment the address this
	  ++*this; // ok
	  //*++this; // increment the address this by 1 and then dereference
	  //*this++; // core dump; calling the postincrement (itself)
	  /*this->operator++();*/ // ok
	  
	  
	  return copy;
  }
  Rational&  Rational::operator--()                         // predecrement
   {
	   
	   this->setNumerator(getNumerator()- getDenominator());
	   this->reduce();
	  // subtract "1" to this
	  // If *this = 2/3, then *this becomes -1/3
	  return *this;
  }
  Rational  Rational::operator--(int)                       // postdecrement
  {
	 Rational copy = *this;
	 
	 --*this;
	 
	 
	 
	 return copy;
  }