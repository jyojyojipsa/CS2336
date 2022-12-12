// Kangmin Kim
// CS 2336
// Lab 19
#include <iostream>
#include <string>


// isPalindrome is a recursive function that returns true if string s
// is a palindrome and false otherwise
using namespace std;
// toupper , tolower 
bool isPalindrome(string s)
{
	
	
	
	if (s.length() == 0)
    return true;
	else if(toupper(*(s.begin())) == toupper(*((s.end()-1))))
		return isPalindrome(s.substr(1,s.length()-2));
	else 
		return false;
	
}
