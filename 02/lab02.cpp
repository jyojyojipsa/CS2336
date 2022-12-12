// Kangmin Kim
// CS 2336
// Lab 02

#include <lab02.h>
#include <cmath> // for abs

using namespace std;


Rational::Rational() : Rational(0,1)	// default constructor
{ }

Rational::Rational(int num, int denom){       // additional constructor
	setNumerator(num);
	setDenominator(denom);
}

void Rational::setNumerator(int num){
		data.first = num;
}// set numerator to num

void Rational::setDenominator(int denom){
		data.second = (denom !=0) ? denom : 1; // true -> denom, false -> 1
}// set denominator to denom

int Rational::getNumerator() const{
	return data.first;
}	// return numerator

int Rational::getDenominator() const{
	return data.second;
}	         // return denominator

void Rational::reduce(){                       // Reduce to lowest terms and normalize
	int myGCD = gcd(getNumerator(),getDenominator());
	
	if (getDenominator() < 0)
		myGCD = -myGCD;
	
	setNumerator(getNumerator() / myGCD);
	setDenominator(getDenominator() / myGCD);
}
  
int Rational::gcd(int m, int n) const{         // returns the gcd of m and n
	if(m==0)
		return abs(n); // absolute value n
	else if (n==0)
		return abs(m);
	else // use Euclid's algorithm
	{
		m = abs(m);
		n = abs(n);
		int rem = m % n;
		
		while (rem != 0){
			m = n;
			n = rem;
			rem = m%n;
		}
	}
		
		return n;
}
