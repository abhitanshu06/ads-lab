#include <bits/stdc++.h>
using namespace std;

int priority(char op){
    if(op=='^'){
        return 3;
    }
    if(op=='*'||op=='/'||op=='%'){
        return 2;
    }
    if(op=='+'||op=='-'){
        return 1;
    }
    return 0;
}

bool isoperand(char ch){
    return(ch>='A' && ch<='Z' ||ch>='a' &&ch<='z'||ch>='0'&&ch<='9');
}

string pos(string infix){
    stack<char> st;
    string postfix="";
    for(char ch:infix){
        if(isoperand(ch)){
            postfix+=ch;
        }
        else if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.empty() && st.top()!='('){
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && st.top()!='(' && (priority(st.top())>=priority(ch) || (priority(st.top()) == priority(ch)&&ch!='^'))){
                postfix+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }

    return postfix;
    
}

int main(){
    string infix;
    cin>>infix;
    cout<<pos(infix);
    return 0;
}