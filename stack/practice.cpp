#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isValid(string s)
{
    map<char, char> m = {
        {'{', '}'},
        {'(', ')'},
        {'[', ']'}};

    stack<char> mystack;

    char temp;

    for (int i = 0; i < s.length(); i++)
    {
        if (!mystack.empty())
        {

            if (m[temp] == s[i])
            {
                mystack.pop();
                temp ='\0';
            }
            else
            {
                 
                temp = mystack.top() ;
                if (m[temp] == s[i])
                {  
                    mystack.pop();
                    temp = '\0';
                  
                }
                else
                {
                    mystack.push(s[i]);
                    temp = s[i];
                }
            }
        }
        else
        {
            mystack.push(s[i]);
            temp = s[i];
        }
    }

    return mystack.empty();
}

int main()
{
    string s = "{{()}}";
    cout << "is vaild" << isValid(s) << endl;

    return 0;
}