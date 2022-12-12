// Kangmin Kim
// CS 2336
// Lab 06

#include <lab06.h>

 IntegerSet IntegerSet::Union(const IntegerSet& otherSet) const
 {
	 IntegerSet mySet; // declare a local object
	 
	 for(uint e = 0; e < N; ++e)
	 {
		 if(isMember(e)||otherSet.isMember(e))
			 mySet.insertElement(e);
	 }
	 
	 return mySet; // return the local object
 }
 IntegerSet IntegerSet::intersection(const IntegerSet& otherSet) const
 {
	 IntegerSet mySet; // declare a local object
	 
	 for(uint e = 0; e < N; ++e)
	 {
		 if(isMember(e)&&otherSet.isMember(e))
			 mySet.insertElement(e);
	 }
	 return mySet; // return the local object
 }
 IntegerSet IntegerSet::difference(const IntegerSet& otherSet) const
 {
	 IntegerSet mySet; // declare a local object
	 
	 for(uint e = 0; e < N; ++e)
	 {
		 if(isMember(e)&&!(otherSet.isMember(e)))
			 mySet.insertElement(e);
	 }
	 return mySet; // return the local object
 }
 IntegerSet IntegerSet::symmetricDifference(const IntegerSet& otherSet) const
 {
	 IntegerSet mySet; // declare a local object
	 
	 for(uint e = 0; e < N; ++e)
	 {
		 if((isMember(e)||otherSet.isMember(e))&&!(isMember(e)&&otherSet.isMember(e)))
			 mySet.insertElement(e);
	 }
	 
	 return mySet; // return the local object
 }