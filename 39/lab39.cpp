// Kangmin Kim
// CS 2336
// Lab 39

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
	stack<char> a,b,c;
	//Lambda Expressions
	auto myUpper = [](unsigned char c) -> unsigned char {return toupper(c); };
	
	//auto keyword 
	//cout << "Debug before: " << s << endl;
	
	
	transform(s.begin(), s.end(), s.begin(), myUpper);
	

	
	//cout << "Debug after : " << s << endl;
	
	// 1. add the chars from s to both a & b (backward order)
	for(uint i = s.size(); i > 0; i--)
	{
		a.push(s[i]);
		b.push(s[i]);
	}
	// 2. sacrifice b into initialize c
	// push the top of b to c and then pop b
	for(uint i = s.size(); i > 0; i--)
	{
		c.push_back(s[i]);
	}
	// 3. b is now empty a contains s backwards
	//                   c contians s forwards
	// 4. now compare a and c. If equal, return true
		for(uint i = s.size(); i > 0; i--)
	{
		if(a == c)
			return true;
		else
			return false;
	}
	
	// else, return false.

	
	for(uint i = 0; i < s.length() / 2; ++i)
	{
		if(s[i] != s[s.length() - 1 - i])
		{
			return false;
		}
	}
	
	return true;
	
}

/*bool isPalindrome(string str)
{
int length = str.length();
for (int i = 0; i < length / 2;i++) {
if (tolower(str[i]) != tolower(str[length - 1 - i])) {
return false;
} // if
} // for loop
return true;
}
*/