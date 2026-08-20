#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &c : infix) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    stack<char> st;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() &&
                   st.top() != '(' &&
                   precedence(st.top()) > precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix;
    cin >> infix;
    cout << infixToPrefix(infix) << endl;
    return 0;
}