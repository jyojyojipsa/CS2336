#include<iostream>
#include<cstdlib>
#include<cctype>
#include<string>
#include<stack>
#include<queue>

using namespace std;

void rmPuncSpaces(string& str){

int i;

string wsPunct;

string::size_type idx;

for(i=0;i<128;i++)
if(isspace(i)||ispunct(i))
wsPunct += i;

while((idx=str.find_first_of(wsPunct)) != string::npos)
if(idx==0)
str = str.substr(idx+1);
else if(idx==str.length()-1)
str = str.substr(0,idx);
else
str = str.substr(0,idx) + str.substr(idx+1);

}


bool isPalindrome(string str){

// the input str is a string of characters after
// removing spaces and punctuations by rmPuncSpaces function

stack<char> strStack; // declare a stack of characters
queue<char> strQueue; // declare a queue of characters

// using a loop to push characters one by one to the stack and queue
for(int i=0;i<str.length();i++){
strStack.push(str[i]);
strQueue.push(str[i]);
}

// poping the characters from stack and queue
// stack pop -> last in first out
// queue pop -> first in first out
// meaning, for a palindrome string, stack top and queue front are supposed to be equal,
// otherwise the string is not a palindrome
while (!strStack.empty() && !strQueue.empty()) {
if(strStack.top()!= strQueue.front())
return false; // string is not a palindrome
strStack.pop(); // point to next element from top (last in)
strQueue.pop(); // point to next element from front (first in)
}
return true; // string is a palindrome
}