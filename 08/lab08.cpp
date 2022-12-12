// Kangmin Kim
// CS 2336
// Lab 08

#include <lab08.h>

ostream& operator<<(ostream& out, const IntegerSet& set){
	uint e = 0, cnt = 0;
	if (set.cardinality() == 0){
		out << static_cast<char>(216) << endl;
	}
	else{
		
		out << '{';
		for(e = 0; e < N; ++e){
			if(set.isMember(e) && (cnt != 0))
				out << ",";
			if(set.isMember(e)){
				out << e;
				cnt++;
			}
			
		}
		out << '}' << endl;
	}
	return out;
}

  IntegerSet IntegerSet::operator+(uint e) const     // if e is valid and not a member of
  {
	  IntegerSet temp(*this); // create a local object that's a copy
							  // of the calling object using the copy
							  // constructor
							  
	  	if((isValid(e) && !isMember(e))){
		uint myWord = temp.bitVector[word(e)]; // ????? 0??? 1? ???? ????? ??
		int myN = bit(e); // ???, N??? ??
		uint myV = 1; // V? ??? ????
		
		myWord = setBit(myWord, myN, myV); // myWord 0 0 0 0 0 0 0 0  N??? V? 0?? ??? 1? ???
		temp.bitVector[word(e)] = myWord;
		}	
		return temp;
	
  }
                                        //   the set, insert e into set
  IntegerSet IntegerSet::operator-(uint e) const     // if e is valid and a member of
  {
	  	IntegerSet temp(*this); // *this = left hand side
		if(isValid(e) && isMember(e)){
		uint myWord = temp.bitVector[word(e)]; // ????? 0??? 1? ???? ????? ??
		int myN = bit(e); // ???, N??? ??
		uint myV = 0; // V? ??? ????
		
		myWord = setBit(myWord, myN, myV); // myWord 0 0 0 0 0 0 0 0  N??? V? 0?? ??? 1? ???
		temp.bitVector[word(e)] = myWord;
		
	}
	return temp;
  }                                       //   the set, delete e from set
  IntegerSet IntegerSet::operator-() const           // complement of a Set
  {
	  IntegerSet myComplement; // myComplement??? insertElement?? return ??
	uint e;
	for(e = 0; e < N; ++e){
		if (!(isMember(e))) // myComplement = object
		{
			uint myWord = myComplement.bitVector[word(e)]; // 비트벡터에 0아니면 1을 선언하고 마이워드로 지정
		int myN = bit(e); // 나머지, N번째로 지정
		uint myV = 1; // V는 참인지 거짓인지
		
		myWord = setBit(myWord, myN, myV); // myWord 0 0 0 0 0 0 0 0  N번째에 V를 0으로 할꺼냐 1로 할꺼냐
		myComplement.bitVector[word(e)] = myWord;
		}
		else if(isMember(e))
			{
				uint myWord = myComplement.bitVector[word(e)];
		int myN = bit(e);
		uint myV = 0;
		
		myWord = setBit(myWord, myN, myV);
		myComplement.bitVector[word(e)] = myWord;
			}
	}
 
	
	
	return myComplement;// complement of a Set
  }
  IntegerSet& IntegerSet::operator=(const IntegerSet& rhs) // *this = rhs;
  {
	  if (this != &rhs) // avoid self-assignment
	  {
		  for (uint e = 0; e < N; ++e)
		  {
			  uint myWord = rhs.bitVector[word(e)]; // 비트벡터에 0아니면 1을 선언하고 마이워드로 지정
			int myN = bit(e); // 나머지, N번째로 지정
			uint myV; // V는 참인지 거짓인지
			  if(rhs.isMember(e))
			  {
				  //*this = *this + e;
				  myV = 1;
				  myWord = setBit(myWord, myN, myV);
				  
			  }
			  else // e is not a member
			  {
				  //*this = *this - e;
				  //this->operator=(this->operator-((e)));	
				  myV = 0;
				  myWord = setBit(myWord, myN, myV);
			  }
			  this->bitVector[this->word(e)] = myWord;
			  
		  }
	  }
	  
	  return *this;
  }