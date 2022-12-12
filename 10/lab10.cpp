// Kangmin Kim
// CS 2336
// Lab 10

#include <lab10.h>

IntegerSet IntegerSet::operator+(const IntegerSet& rhs) const // union
 {
	 IntegerSet mySet; // declare a local object
	 
	 for(uint e = 0; e < N; ++e)
	 {
		 if((this->isMember(e))||(rhs.isMember(e))){
			 uint myWord = mySet.bitVector[word(e)]; // 비트벡터에 0아니면 1을 선언하고 마이워드로 지정
		int myN = bit(e); // 나머지, N번째로 지정
		uint myV = 1; // V는 참인지 거짓인지
		
		myWord = setBit(myWord, myN, myV); // myWord 0 0 0 0 0 0 0 0  N번째에 V를 0으로 할꺼냐 1로 할꺼냐
		mySet.bitVector[word(e)] = myWord;
		}
	 }
	 return mySet; // return the local object
 } // this랑 rhs 비교해서 조건에 해당하면 마이셋 집어넣기
IntegerSet IntegerSet::operator*(const IntegerSet& rhs) const // intersection
{
	IntegerSet mySet; // declare a local object
	 
	 for(uint e = 0; e < N; ++e)
	 {
		 if((this->isMember(e))&&(rhs.isMember(e))){
			 uint myWord = mySet.bitVector[word(e)]; // 비트벡터에 0아니면 1을 선언하고 마이워드로 지정
		int myN = bit(e); // 나머지, N번째로 지정
		uint myV = 1; // V는 참인지 거짓인지
		
		myWord = setBit(myWord, myN, myV); // myWord 0 0 0 0 0 0 0 0  N번째에 V를 0으로 할꺼냐 1로 할꺼냐
		mySet.bitVector[word(e)] = myWord;
		 }
	 }
	 
	 return mySet; // return the local object
}
IntegerSet IntegerSet::operator-(const IntegerSet& rhs) const // difference
 {
	 IntegerSet mySet; // declare a local object
	 
	 for(uint e = 0; e < N; ++e)
	 {
		 if(((this->isMember(e))!=(rhs.isMember(e))) && this->isMember(e)){
			 uint myWord = mySet.bitVector[word(e)]; // 비트벡터에 0아니면 1을 선언하고 마이워드로 지정
		int myN = bit(e); // 나머지, N번째로 지정
		uint myV = 1; // V는 참인지 거짓인지
		
		myWord = setBit(myWord, myN, myV); // myWord 0 0 0 0 0 0 0 0  N번째에 V를 0으로 할꺼냐 1로 할꺼냐
		mySet.bitVector[word(e)] = myWord;
		 }
	 }
	 
	 return mySet; // return the local object
 }
IntegerSet IntegerSet::operator/(const IntegerSet& rhs) const // symmetric diff
{
	IntegerSet mySet; // declare a local object
	 
	 for(uint e = 0; e < N; ++e)
	 {
		 if((this->isMember(e))!=(rhs.isMember(e))){
			 uint myWord = mySet.bitVector[word(e)]; // 비트벡터에 0아니면 1을 선언하고 마이워드로 지정
		int myN = bit(e); // 나머지, N번째로 지정
		uint myV = 1; // V는 참인지 거짓인지
		
		myWord = setBit(myWord, myN, myV); // myWord 0 0 0 0 0 0 0 0  N번째에 V를 0으로 할꺼냐 1로 할꺼냐
		mySet.bitVector[word(e)] = myWord;
		}
	 }
	 
	 return mySet; // return the local object
}