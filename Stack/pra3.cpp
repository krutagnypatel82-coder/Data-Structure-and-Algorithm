#include <iostream>
using namespace std;

#define N 5
class Stack{
    public:
    int stack[N];
    int top = -1;

    void Push(){
        int x;
        cout << "Enter data : ";
        cin >> x;
        if(top == N-1){
            cout << "Overflow" << endl;
        }else{
            top++;
            stack[top] = x;
            cout << "Element Inserted Successfully" << endl;
        }
    }

    void Pop(){
        int item;
        if(top == -1){
            cout << "Underflow" << endl;
        }else{
            item = stack[top];
            top--;
        }
        cout << item << endl;
    }

    void Peek(){
        if(top == -1){
            cout << "Underflow" << endl;
        }else{
            cout << stack[top] << endl;
        }
    }

    void display(){
        for(int i = top; i >= 0; i--){
            cout << stack[i] << endl;
        }
    }
};

int main(){
    Stack s;
    int ch;
    do{
        cout << "Enter Choice: 1.Push, 2.Pop, 3.Peek, 4.Display:- ";
        cin >> ch;
        switch(ch){
            case 1:
                s.Push();
                break;
            case 2:
                s.Pop();
                break;
            case 3:
                s.Peek();
                break;
            case 4:
                s.display();
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }while(ch != 0);
    return 0;
}