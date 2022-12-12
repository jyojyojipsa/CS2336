// Kangmin Kim
// CS 2336
// Lab 40

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

bool isOpeningBracket(char i)
{
    if (i == '(' || i == '{' || i == '[')
    {
        return true;
    }
    return false;
}

bool isClosingBracket(char i)
{
    if (i == ')' || i == '}' || i == ']')
    {
        return true;
    }

    return false;
}

bool isMatched(char i, char j)
{
    if (i == '(' && j == ')')
    {
        return true;
    }
    else if (i == '{' && j == '}')
    {
        return true;
    }
    else if (i == '[' && j == ']')
    {
        return true;
    }

    return false;
}

bool isNestedCorrectly(string str)
{
	stack<char> stack;

    for (uint i = 0; i < str.length(); i++)
    {
        if (isOpeningBracket(str[i]))
        {
            stack.push(str[i]);
        }
        else if (isClosingBracket(str[i]))
        {
            if (stack.empty())
            {
                return false;
            }

            if (isMatched(stack.top(), str[i]))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return stack.empty();
}