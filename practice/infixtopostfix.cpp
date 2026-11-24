#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char ch : infix)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            s.push(ch);
        }

        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            s.pop(); // remove '('
        }
        else
        {
            while (!s.empty() &&
                   precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix);

    return 0;
}