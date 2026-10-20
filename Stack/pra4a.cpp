#include <iostream>
using namespace std;

class Stack{
    public:
    char stack[50];
    int top = -1;

    void push(char x)
    {
        top++;
        stack[top] = x;
    }

    char pop()
    {
        char x = stack[top];
        top--;
        return x;
    }

    int priority(char x)
    {
        if (x == '^')
            return 3;
        if (x == '*' || x == '/' || x == '%')
            return 2;
        if (x == '+' || x == '-')
            return 1;
        return 0;
    }
};

int main(){

    Stack s;

    char infix[50], postfix[50];
    int i = 0, j = 0;
    char x;

    cout << "Enter infix expression: ";
    cin >> infix;

    while (infix[i] != '\0')
    {
        x = infix[i];

        if ((x >= 'A' && x <= 'Z') ||
            (x >= 'a' && x <= 'z') ||
            (x >= '0' && x <= '9'))
        {
            postfix[j] = x;
            j++;
        }
        else if (x == '(')
        {
            s.push(x);
        }
        else if (x == ')')
        {
            while (s.stack[s.top] != '(')
            {
                postfix[j] = s.pop();
                j++;
            }
            s.pop();
        }
        else
        {
            while (s.top != -1 && s.priority(s.stack[s.top]) >= s.priority(x))
            {
                postfix[j] = s.pop();
                j++;
            }
            s.push(x);
        }

        i++;
    }

    while (s.top != -1)
    {
        postfix[j] = s.pop();
        j++;
    }

    postfix[j] = '\0';

    cout << "Postfix expression: " << postfix;

    return 0;
}