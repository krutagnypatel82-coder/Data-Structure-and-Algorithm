#include <iostream>
using namespace std;

#define N 5
class Queue{
    public:
    int queue[N];
    int front = -1;
    int rear = -1;

    void enqueuer(){
        int x;
        cout << "Enter element : ";
        cin >> x;
    if(rear == N - 1){
        cout << "Overflow" << endl;
    }else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x; 
    }else{
        rear++;
        queue[rear] = x;
    }
}

    void dequeuer(){
        if(front == -1 && rear == -1){
            cout << "Underflow !" << endl;
        }else if(front == rear){
            cout << queue[front] << endl;
            front = rear = -1;
        }else{
            cout << queue[front] << endl;
            front++;
        }
    }

    void display(){
        if(front == -1 && rear == -1){
            cout << "Underflow !" << endl;
        }else{
            for(int i = front; i < rear+1; i++){
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Queue q;

    int ch;
    do{
    cout << "Enter choice : 1.Enqueuer, 2.Dequeuer, 3.Display :- ";
    cin >> ch;

    switch(ch){
        case 1:
            q.enqueuer();
            break;
        case 2:
            q.dequeuer();
            break;
        case 3:
            q.display();
            break;
        case 0:
            cout << "Exiting......" << endl;
            break;
        default:
            cout << "Invalid choice !" << endl;
            break;
    }
    }while(ch != 0);
    return 0;
}