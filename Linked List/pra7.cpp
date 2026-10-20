#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*tail = 0;

int getlength()
{
    if(tail == 0) return 0;
    int count = 1;
    for(struct node *temp = tail->next; temp != tail; temp = temp->next) count++;
    return count;
}

void display()
{
    if(tail == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    struct node *temp = tail->next;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != tail->next);
    cout << endl;
}

void insertBeg()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    cout << "Enter data :- ";
    cin >> newnode->data;

    if(tail == 0) tail = newnode->next = newnode;
    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertEnd()
{
    insertBeg();
    tail = tail->next;
}

void insertatPos()
{
    struct node *newnode, *temp;
    int Pos, i = 1;

    cout << "Enter Position :- ";
    cin >> Pos;

    if(Pos < 1 || Pos > getlength()) cout << "Invalid Position...." << endl;
    else if(Pos == 1) insertBeg();
    else{
        newnode = (struct node*)malloc(sizeof(struct node));
        cout << "Enter data :- ";
        cin >> newnode->data;

        for(temp = tail->next; i < Pos - 1; i++) temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delfromBeg()
{
    if(tail == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    struct node *temp = tail->next;
    if(temp == tail) tail = 0;
    else tail->next = temp->next;
    free(temp);
}

void delfromEnd()
{
    if(tail == 0 || tail->next == tail) delfromBeg();
    else{
        struct node *previous = tail->next;
        while(previous->next != tail) previous = previous->next;
        previous->next = tail->next;
        free(tail);
        tail = previous;
    }
}

void delfromPos()
{
    struct node *current, *nextnode;
    int Pos, i = 1, l = getlength();

    cout << "Enter Position :- ";
    cin >> Pos;

    if(Pos < 1 || Pos > l) cout << "Invalid Position...." << endl;
    else if(Pos == 1) delfromBeg();
    else if(Pos == l) delfromEnd();
    else{
        for(current = tail->next; i < Pos - 1; i++) current = current->next;
        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n"
             << "4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n"
             << "7. Display\n8. Length\n0. Exit\nEnter choice :- ";
        cin >> choice;

        switch(choice)
        {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: insertatPos(); break;
            case 4: delfromBeg(); break;
            case 5: delfromEnd(); break;
            case 6: delfromPos(); break;
            case 7: display(); break;
            case 8: cout << "Length: " << getlength() << endl; break;
        }
    } while(choice != 0);
    return 0;
}