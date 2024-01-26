#include<bits/stdc++.h>
using namespace std;
int Evalpost(string exp){
    int a,b;
    char ch;
    stack<int> st; 
    for( int i = 0 ; i < exp.size() ; ++i ){
        ch = exp[i];
        if(isdigit(ch)) st.push(ch - '0');
        else {
            a = st.top(); 
            st.pop();
            b = st.top();
            st.pop();
            switch(ch){
                case '^':   st.push(pow(b,a));
                            break;
                case '/':   st.push(b/a);
                            break;
                case '*':   st.push(b*a);
                            break;
                case '+':   st.push(b+a);
                            break;
                case '-':   st.push(b-a);
                            break;
            }
        }
    }
    return st.top();
}
int main(){
    string exp = "231*+9-";
    cout<< Evalpost(exp); // Evaluatae value is -4
    return 0;
}
