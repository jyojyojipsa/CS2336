#ifndef LAB04_H
#define LAB04_H

#include <iostream>
#include <bits.h>

using namespace std;

const uint N = 40;

class IntegerSet
{
 public:
  IntegerSet::IntegerSet();                           // initializes the set to the empty
                                          //   set
  IntegerSet::IntegerSet(const IntegerSet& otherSet); // copy constructor
  IntegerSet::~IntegerSet();                          // destructor
  bool IntegerSet::isMember(uint e) const;            // returns true if e is a member of
                                          //   the set and false otherwise
  uint IntegerSet::cardinality() const;               // cardinality of a set
  void IntegerSet::insertElement(uint e);             // if e is valid and not a member of
                                          //   the set, insert e into set
  void IntegerSet::deleteElement(uint e);             // if e is valid and a member of
                                          //   the set, delete e from set
  IntegerSet::IntegerSet complement() const;          // complement of a Set

  ostream& IntegerSet::print(ostream& os) const;
 private:
  uint *bitVector;                        // Pointer to dynamically
                                          //   allocated memory
  bool IntegerSet::isValid(uint e) const;             // 0 <= e < N
  uint word(uint n) const;                // Determine index within
                                          //   bitVector where n is located
  uint bit(uint n) const;                 // Determine position within
                                          //   bitVector[word(n)]
                                          //   for element n
  void allocateStorage();                 // Calculate # of elements
                                          //   in bitVector to represent
                                          //   elements 0..(N-1) & then
                                          //   allocate storage
};

#endif
