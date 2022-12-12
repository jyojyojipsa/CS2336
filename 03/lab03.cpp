 // CS 2336
 //	Lab 03
 // Kangmin Kim
 
 #include <lab03.h>
 #include <cmath> // for abs
 
  
 
Rational Rational::add(const Rational& addend) const {
	Rational sum; // declare a local object
	int myLCM = lcm(this->getDenominator(), addend.getDenominator());
	
	// manipulate the local object
	sum.setNumerator(myLCM * this->getNumerator() / this->getDenominator()+
					 myLCM * addend.getNumerator() / addend.getDenominator());
	sum.setDenominator(myLCM);
	sum.reduce();
	
	
	return sum; // return the local object
}
Rational Rational::additiveInverse() const {
	
	
	return Rational(this->getNumerator() * -1, this->getDenominator());
}
Rational Rational::subtract(const Rational& subtrahend) const{
	return this->add(subtrahend.additiveInverse());
	
	
}
Rational Rational::multiply(const Rational& multiplicand) const {
	Rational Multi(this->getNumerator()*multiplicand.getNumerator(),this->getDenominator()*multiplicand.getDenominator());
	Multi.reduce();
	
	return Multi;
}
Rational Rational::multiplicativeInverse() const{
	Rational mInv;
	mInv.setNumerator(this->getDenominator());
	mInv.setDenominator(this->getNumerator());
	return mInv;
}
Rational Rational::divide(const Rational& divisor) const {
	
	return this->multiply(divisor.multiplicativeInverse());
	
	
	
	
}
ostream& Rational::print(ostream& os) const  {
	os << this->getNumerator() << '/' << this->getDenominator();
	
	return os;
	
}
istream& Rational::read(istream& is) {
	int num, denom;
	
	if(is >> num >> denom){
		this->setNumerator(num);
		this->setDenominator(denom);
	}
	else{
		this->setNumerator(num);
		this->setDenominator(denom);
	}
	
	return is;
}
/*
r.subtract(s).
*/
int Rational::lcm(int m, int n) const
{
	if(m == 0 || n == 0)
		return 0;
	else
		return abs(m * n / gcd(m,n));
}