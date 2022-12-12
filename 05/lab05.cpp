// CS 2336
// Kangmin Kim
// Lab 05

#include <lab05.h>

/*
	Equality operators: == and !=
	Relational operaors: <, <=, >=, >
	
	It's only necessary to write the code for ONE of te equality
	operators and ONE of the relational operators. It's traditional
	to write the code for == and <.
	
	Write != as !(==)
	Write <= as (<) || (==)
	Write >= as !(<) 
	Write > as !(<=) = !((<) || (==)) = !(<) && !(==) // Demorgan's Law
*/

 bool Rational::isEqualTo(const Rational& other) const    // *this == other
 {
	 Rational sum; // declare a local object
	int myLCM = lcm(this->getDenominator(), other.getDenominator());
	
	// manipulate the local object
	int lhs = myLCM * this->getNumerator() / this->getDenominator();
	int rhs = myLCM * other.getNumerator() / other.getDenominator();

	return lhs == rhs; // ==
 }
 bool Rational::isNotEqualTo(const Rational& other) const // *this != other
 {
	 return !(this->isEqualTo(other));
	 
 }
 bool Rational::isLessThan(const Rational& other) const   // *this < other
 {
	  Rational sum; // declare a local object
	int myLCM = lcm(this->getDenominator(), other.getDenominator());
	
	// manipulate the local object
	int lhs = myLCM * this->getNumerator() / this->getDenominator();
	int rhs = myLCM * other.getNumerator() / other.getDenominator();

	return lhs < rhs;
	
 }
 bool Rational::isLessThanOrEqualTo(const Rational& other) const // *this <= other
 {
	 return (this->isLessThan(other) || this->isEqualTo(other));
 }
 bool Rational::isGreaterThan(const Rational& other) const // *this > other
 {
	 return (!(this->isEqualTo(other)) && !(this->isLessThan(other)));
 }
 bool Rational::isGreaterThanOrEqualTo(const Rational& other) const // *this >= other
 {
	 return !(this->isLessThan(other));
 }