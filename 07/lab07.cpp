// Kangmin Kim
// CS 2336
// Lab 07

#include <lab07.h>
// overloaded input operator initializes Rational rat from input stream in
 istream& operator>>(istream& in, Rational& rat){
	int num, denom;
  
   in >> num >> denom;
   rat.setNumerator(num);
   rat.setDenominator(denom);
  
   return in;
}
// overloaded output operator prints Rational rat to output stream out
 ostream& operator<<(ostream& out, const Rational& rat){
	out << rat.getNumerator() << '/' << rat.getDenominator();

   return out;
}

Rational& Rational::operator=(const Rational& rhs)       // *this = rhs;
{
	if (this != &rhs){ // check for self-assignment
	this->setNumerator(rhs.getNumerator());
	this->setDenominator(rhs.getDenominator());
	}
	return *this;
}
Rational  Rational::operator+(const Rational& addend) const// returns *this + addend{
{	Rational sum; // declare a local object
	int myLCM = lcm(this->getDenominator(), addend.getDenominator());
	
	// manipulate the local object
	sum.setNumerator(myLCM * this->getNumerator() / this->getDenominator()+
					 myLCM * addend.getNumerator() / addend.getDenominator());
	sum.setDenominator(myLCM);
	sum.reduce();
	
	
	return sum; // return the local object
}
Rational  Rational::operator-() const                     // returns -(*this)
{
	return Rational(this->getNumerator() * -1, this->getDenominator());
}

Rational  Rational::operator-(const Rational& subtrahend) const// returns *this - subtrahend
{
	//return this->add(subtrahend.additiveInverse()); // from Lab 03
	
	//return this->operator+(subtrahend.operator-()); // okay
	return *this + -subtrahend;
	
}
Rational  Rational::operator*(const Rational& multiplicand) const// returns *this * multiplicand
{
	Rational Multi(this->getNumerator()*multiplicand.getNumerator(),this->getDenominator()*multiplicand.getDenominator());
	Multi.reduce();
	
	return Multi;
}
Rational  Rational::operator/(const Rational& divisor) const// returns *this / divisor
{
	//return this->multiply(divisor.multiplicativeInverse());
	return *this * divisor.multiplicativeInverse();
}
bool Rational::operator==(const Rational& rhs) const     // *this == rhs
{
	 Rational sum; // declare a local object
	int myLCM = lcm(this->getDenominator(), rhs.getDenominator());
	
	// manipulate the local object
	int left = myLCM * this->getNumerator() / this->getDenominator();
	int right = myLCM * rhs.getNumerator() / rhs.getDenominator();

	return left == right; // ==
}
bool Rational::operator!=(const Rational& rhs) const     // *this != rhs
{
	return !(*this == rhs);
}
bool Rational::operator< (const Rational& rhs) const     // *this <  rhs
{
	
	 Rational sum; // declare a local object
	int myLCM = lcm(this->getDenominator(), rhs.getDenominator());
	
	// manipulate the local object
	int left = myLCM * this->getNumerator() / this->getDenominator();
	int right = myLCM * rhs.getNumerator() / rhs.getDenominator();

	return left < right; // ==
}
bool Rational::operator<=(const Rational& rhs) const     // *this <= rhs
{
	return (*this < rhs) || (*this == rhs);
}
bool Rational::operator> (const Rational& rhs) const     // *this >  rhs 
{
	return !((*this < rhs) || (*this == rhs));
}
bool Rational::operator>=(const Rational& rhs) const     // *this >= rhs
{
	return !(*this < rhs);
}