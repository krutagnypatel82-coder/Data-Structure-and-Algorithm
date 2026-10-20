#include <iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1, rear = -1;

void enqueuer()
{
    int x;
    cout << "Insert an element :- ";
    cin >> x;
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }else if((rear+1)%N == front){
        cout << "Queue is Full" << endl;
    }else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeuer()
{
    if(front == -1 && rear == -1)
    {
        cout << "Queue is empty" << endl;
    }else if(front == rear){
        cout << queue[front] << endl;
        front = rear = -1;
    }else{
        cout << queue[front] << endl;
        front = (front + 1)%N;
    }
}


void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        cout << "Queue is empty." << endl;
    }else{
        cout << "Queue is :-";
        while(i!=rear)
        {
            cout << queue[i] << " ";
            i = (i+1)%N;
        }
        cout << queue[rear] << endl;
    }
}

int main(){

    int x, n;
    do{
    cout << "Enter Choices ( Exit : 0 ) :-" << endl;
    cout << "1.Enqueuer, 2.Dequeuer, 3.Display:- ";
    cin >> n;

    switch(n){
        case 1:
            enqueuer();
            break;
        case 2:
            dequeuer();
            break;
        case 3:
            display();
            break;
        default:
            cout << "Invalid Choice.........." << endl;
    }
    }while(n != 0);

    return 0;
}