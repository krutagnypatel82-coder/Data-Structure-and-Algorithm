#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Stack {
    public:
    double stack[50];
    int top = -1;

    void push(double x)
    {
        top++;
        stack[top] = x;
    }

    double pop()
    {
        double x = stack[top];
        top--;
        return x;
    }
};

int main(){

    Stack s;
    char postfix[50];
    int i = 0;
    double op1, op2, result;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    while (postfix[i] != '\0')
    {
        char x = postfix[i];

        // If the character is a digit (single-digit operand),
        // push its numeric value onto the stack
        if (x >= '0' && x <= '9')
        {
            s.push(x - '0');   // convert char digit to int
        }
        else
        {
            // It's an operator: pop two operands
            op2 = s.pop();   // second operand popped first
            op1 = s.pop();   // first operand popped second

            switch (x)
            {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '%':
                    result = (int)op1 % (int)op2;
                    break;
                case '^':
                    result = pow(op1, op2);
                    break;
                default:
                    cout << "Invalid operator: " << x << endl;
                    return 1;
            }

            s.push(result);
        }

        i++;
    }

    cout << "Result = " << s.pop() << endl;

    return 0;
}