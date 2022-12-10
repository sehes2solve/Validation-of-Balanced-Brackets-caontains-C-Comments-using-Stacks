#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool ThePairBracketsAreEqual (char Thefirst, char TheSecond)
{
    if (Thefirst == '(' && TheSecond == ')')
        return true ;
    else if (Thefirst == '{' && TheSecond == '}')
        return true ;
    else if (Thefirst == '[' && TheSecond == ']')
        return true ;
    return false ;

}
bool valid (string expression)
{
    bool skip = false ;
    stack <char> balanced ;
    for (int i = 0 ; i < expression.length(); i++)
    {
        if (expression[i] != '*' && !skip)
        {
            if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
                balanced.push(expression[i]) ;
            else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
            {
                if (balanced.empty())
                    return false ;
                else if (ThePairBracketsAreEqual(balanced.top(),expression[i])== false)
                    return false ;
                balanced.pop() ;

            }
            else if (expression[i] == '/' && expression[i + 1] == '*' && (i + 1) < expression.length())
            {
                balanced.push (expression[i]) ;
                balanced.push (expression[i+1]);
                i++;
                skip = true ;
            }
        }
        else if (expression[i] == '*' && expression[i + 1] == '/' && (i + 1) < expression.length())
        {
            if (!balanced.empty())
            {
                if (balanced.top() == expression[i])
                {
                    balanced.pop();
                    balanced.pop();
                    i++;
                    skip = false;
                }
            }
            else
                return false ;
        }

    }
    if (balanced.empty())
        return true ;
    else
        return false ;
}
int main()
{

    string s ;
    cin >> s ;

    cout << valid (s) ;
    return 0;
}
