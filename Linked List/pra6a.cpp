#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = 0;

int getlength()
{
    int count = 0;
    for(struct node *temp = head; temp != 0; temp = temp->next) count++;
    return count;
}

void display()
{
    if(head == 0) cout << "List is empty";
    for(struct node *temp = head; temp != 0; temp = temp->next) cout << temp->data << " ";
    cout << endl;
}

void insertEnd()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node)), *temp = head;
    cout << "Enter data you want to insert :- ";
    cin >> newnode->data;
    newnode->next = 0;

    if(head == 0) head = newnode;
    else{
        while(temp->next != 0) temp = temp->next;
        temp->next = newnode;
    }
}

void insertatPos()
{
    struct node *newnode, *temp = head;
    int Pos, i = 1;

    cout << "Enter the Position :- ";
    cin >> Pos;

    if(Pos < 1 || Pos > getlength() + 1)
    {
        cout << "Invalid Position...." << endl;
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    cout << "Enter data :- ";
    cin >> newnode->data;

    if(Pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }else{
        for(; i < Pos - 1; i++) temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void DeleteFrombeg()
{
    struct node *temp = head;
    if(head == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    head = head->next;
    free(temp);
}

void DeleteFromend()
{
    struct node *temp = head;
    if(head == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    if(head->next == 0)
    {
        free(head);
        head = 0;
        return;
    }
    while(temp->next->next != 0) temp = temp->next;
    free(temp->next);
    temp->next = 0;
}

void DeleteFromPos()
{
    struct node *temp = head, *nextnode;
    int Pos, i = 1;

    cout << "Enter a Position :- ";
    cin >> Pos;

    if(Pos < 1 || Pos > getlength())
    {
        cout << "Invalid Position...." << endl;
        return;
    }

    if(Pos == 1) DeleteFrombeg();
    else{
        for(; i < Pos - 1; i++) temp = temp->next;
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}

int main()

{
    int choice;
    do
    {
        cout << "\n1. Insert at End\n2. Insert at Position\n"
             << "3. Delete from Beginning\n4. Delete from End\n5. Delete from Position\n"
             << "6. Display\n7. Length\n0. Exit\nEnter choice :- ";
        cin >> choice;

        switch(choice)
        {
            case 1: insertEnd(); break;
            case 2: insertatPos(); break;
            case 3: DeleteFrombeg(); break;
            case 4: DeleteFromend(); break;
            case 5: DeleteFromPos(); break;
            case 6: display(); break;
            case 7: cout << "Length: " << getlength() << endl; break;
        }
    } while(choice != 0);
    return 0;
}