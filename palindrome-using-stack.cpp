#include <bits/stdc++.h>
#define size 100
using namespace std;
class Stack{
    private:
    string value;
    char arr[size];
    int top;
    public:
    Stack(){
        top = -1;
    }
    void push(string x){
        value = x;
        if(top >= size - 1){
            cout<<"Stack is full"<<endl;
            return;
        }
        for(char i:value){
            arr[++top] = i;
        }
    }
    void pal(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        int a=top+1;
        char arr1[a];
        for(int i=a-1;i>=0;i--){
            arr1[a-1-i] = arr[i];
        }
        for(int i=0;i<a;i++){
            if(arr[i] != arr1[i]){
                cout<<"Not a palindrome"<<endl;
                return;
            }
        }
        cout<<"Palindrome"<<endl;
    }
};
int main(){
    Stack s;
    string x;
    getline(cin,x);
    s.push(x);
    s.pal();
    return 0;
}