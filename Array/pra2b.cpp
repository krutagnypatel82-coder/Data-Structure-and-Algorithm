#include <iostream>
using namespace std;

int sum(int a, int b){
    return a + b;
}

// Call by Reference using Pointer
void swapPointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Call by Reference using Variable
void swapReferenVar(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 4, y = 5;
    cout << "x = " << x << " y = " << y << endl;

    cout << sum(x, y) << endl;

    //swapPointer(&x, &y);
    swapReferenVar(x, y);
    cout << "x = " << x << " y = " << y << endl;

    return 0;
}