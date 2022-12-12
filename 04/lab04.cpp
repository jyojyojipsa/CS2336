// Kangmin Kim
// CS 2336
// Lab 04

#include <lab04.h>

IntegerSet::IntegerSet()                           // initializes the set to the empty
{
	uint e = 0;
	
	allocateStorage(); // allocate the torage for the bitVector
	// loop through the universe (0,1,2,...,(N-1)) setting
	// each bit to 0
	for(e = 0; e < N; ++e){
		deleteElement(e);
		
	}
}

IntegerSet::IntegerSet(const IntegerSet& otherSet) // copy constructor
{
	uint e = 0;
	allocateStorage();
	 // allocate the torage for the bitVector
	// loop through the universe (0,1,2,...,(N-1)) setting
	// each bit to 0
	for(e = 0; e < N; ++e){
		deleteElement(e);
		if(otherSet.isMember(e))
		insertElement(e);
	}
	
}

IntegerSet::~IntegerSet()                          // destructor
{
	delete [] bitVector;
}
bool IntegerSet::isMember(uint e) const            // returns true if e is a member of
{
	if(isValid(e)){
		uint myWord = bitVector[word(e)]; // 비트 벡터 배열
	int myN = bit(e); // 비트 벡터 특정 배열에 속해있는 원소 (오른쪽에서 몇번째 있는건지) 
	
	return getBit(myWord,myN); // (배열 위치에 원소 가져오기)
	}
	else
		return false;
	
	
}	//   the set and false otherwise
uint IntegerSet::cardinality() const               // cardinality of a set (입력받은지 몇개 들어와있는지 체크)
{
	int count = 0;
	for(uint e = 0; e < N ; e++){ // 0 부터 N 까지 
		if(isMember(e)) // i 값은 비트 검사하기(멤버인지) //멤버
		count++;
	}
	return count;
}

void IntegerSet::insertElement(uint e)             // if e is valid and not a member of
{
	if(isValid(e) && !isMember(e)){
		uint myWord = bitVector[word(e)]; // 비트벡터에 0아니면 1을 선언하고 마이워드로 지정
		int myN = bit(e); // 나머지, N번째로 지정
		uint myV = 1; // V는 참인지 거짓인지
		
		myWord = setBit(myWord, myN, myV); // myWord 0 0 0 0 0 0 0 0  N번째에 V를 0으로 할꺼냐 1로 할꺼냐
		bitVector[word(e)] = myWord;
	}
}	//   the set, insert e into set

void IntegerSet::deleteElement(uint e)             // if e is valid and a member of
{
	if(isValid(e) && isMember(e)){
		uint myWord = bitVector[word(e)];
		int myN = bit(e);
		uint myV = 0;
		
		myWord = setBit(myWord, myN, myV);
		bitVector[word(e)] = myWord;
	}
}
                                          //   the set, delete e from set
IntegerSet IntegerSet::complement() const         // complement of a Set  //나머지
{
	
	IntegerSet myComplement; // myComplement에다가 insertElement넣고 return 하라
	uint e;
	for(e = 0; e < N; ++e){
		if (!(isMember(e))) // myComplement = object
		myComplement.insertElement(e);
		else if(isMember(e))
			myComplement.deleteElement(e);
	}

	
	
	return myComplement;// complement of a Set
}


ostream& IntegerSet::print(ostream& os) const{

	uint e = 0, cnt = 0;
	if (cardinality() == 0){
		os << static_cast<char>(216) << endl;
	}
	else{
		
		os << '{';
		for(e = 0; e < N; ++e){
			if(isMember(e) && (cnt != 0))
				os << ",";
			if(isMember(e)){
				os << e;
				cnt++;
			}
			
		}
		os << '}' << endl;
	}
	return os;
}

bool IntegerSet::isValid(uint e) const {
return (0 <= e) && (e < N);       // 0 <= e < N // 들어온 숫자가 0보다 크고 2보다 작은지 40을 설정했으니까 N넘지말아

}