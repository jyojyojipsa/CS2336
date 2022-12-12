// Kangmin Kim
// CS 2336
// Lab 11

#include <lab11.h>

  bool IntegerSet::operator==(const IntegerSet& rhs) const // Test for equality
  {
	  for(uint e = 0; e < N ; e++){
		  if(this->isMember(e) != rhs.isMember(e))
		return false;
	  }	  
	  return true; // this 와 rhs 가 같은 원소인지 같은지 체크하고
  }
  
  bool IntegerSet::operator<=(const IntegerSet& rhs) const // Subset
  {
	  uint count = 0;
	  for(uint e = 0; e < N; e++){
		  if((this->isMember(e) == true) && (rhs.isMember(e) == true)) {
			count++;
		  }
	  }
	  if(count == this->cardinality())
		  return true;
	  else return false;
  }
  bool IntegerSet::operator< (const IntegerSet& rhs) const // Proper Subset
  {
	   uint count = 0;
	  for(uint e = 0; e < N; e++){
		  if((this->isMember(e) == true) && (rhs.isMember(e) == true)) {
			count++;
		  }
	  }
	  if((count == this->cardinality()) && (this->cardinality() > 0))
		  return true;
	  else return false;
  }
  