// Kangmin Kim
// CS 2336
// Lab 41


#include <iostream>
#include<bits/stdc++.h>

using namespace std;
  
//Function to return precedence of operators
int prec(char c)
{
if(c == '*' || c == '/')
return 2;
else if(c == '+' || c == '-')
return 1;
else
return -1;
}
  

//to postfix expression
int infix2Postfix(string s, ostream& out)
{
std::stack<char> st;

int l = s.length();

for(int i = 0; i < l; i++)
{
// if the character is a white space continue reading the next character from the string
if(s[i] == ' ')
continue;

// If the character is an ‘(‘, push it to the stack.
else if(s[i] == '(')
  
st.push(s[i]);
// If the scanned character is an operand, add it to output string.
else if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
out<<s[i] << ' ';
  
//If an operator is scanned
else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
{
while(!st.empty() && prec(s[i]) <= prec(st.top()) && st.top() != '(')
{
char c = st.top();
st.pop();
out<<c << ' ';
}
st.push(s[i]);
}
  

  
// If the scanned character is an ‘)’, pop and to output string from the stack
// until an ‘(‘ is encountered.
else if(s[i] == ')')
{
while(!st.empty() && st.top() != '(')
{
char c = st.top();
st.pop();
out<<c << ' ';
}
if(!st.empty() && st.top() == '(')
{
char c = st.top();
st.pop();
}
else
{   
out<<"\nError in expression: unbalanced right paranthesis\n";
return 0;
}
}
  

}
//Pop all the remaining elements from the stack
while(!st.empty())
{
char c = st.top();
st.pop();
if(c != '(')
out<< c << ' ';
else
out<<"\nError in expression: unbalanced paranthesis\n";
}
  
return 1;
}

