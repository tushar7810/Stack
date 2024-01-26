#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c){
    return (!isalpha(c) && !isdigit(c));
}
int getPriority(char c){
    if(c == '-' || c == '+') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    else return 0;
}
string infixToPostfix(string infix){
    infix = '(' + infix + ')';
    int l = infix.size();
    stack <char> st;
    string output;
    for(int i =0;i<l;i++){
        char c = infix[i];
        if(isalpha(c) || isalpha(c))
            output += c;
        else if(c == '(')
            st.push('(');
        else if(c == ')'){
            while(st.top() != '('){
                output += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }else{
            while(getPriority(c) < getPriority(st.top())){
                output += st.top();
                st.pop();
            }
            st.push(c);
        }   
    }
    while(!st.empty()){
        output += st.top();
        st.pop();
    }
    return output;
}
string infixToPrefix(string infix){
    int l = infix.size();
    reverse(infix.begin(),infix.end());
    for(int i=0;i<l;i++){
        if(infix[i] == '('){
            infix[i] = ')';
            i++;
        }else if(infix[i] == ')'){
            infix[i] = '(';
            i++;
        }
    }
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(),prefix.end());
    return prefix;
}
int main(){
    string s = "a+b*(c^d-e)^(f+g*h)-i" ; //("(p+q)*(c-d)");
    cout<<"Infix Expression : "<< s <<endl;
    cout<<"Prefix Expression : "<< infixToPrefix(s) <<endl;
    // Prefix Expression is : -+a*b^-^cde+f*ghi
    return 0;
}
