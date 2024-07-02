#include<iostream>
using namespace std;
#define max 7
int stack[max];
int top =-1;

void push(){
    int val;
    cout<<"Enter the data : ";
    cin >> val;
    if(top >= max-1){
        cout<<"Stack Overflow";
    }else{
        stack[++top] = val;
    }
}

int pop(){
    if( top < 0){
        cout<<"Stack Underflow"<<endl;
    }else{
        int a = stack[top];
        top--;
        return a;
    }
}

void display(){
    if(top >=0){
        for(int i= top ; i>=0;i--){
            cout<< stack[i]<<endl;
        }
    }

}

int main(){
    int ch;
    do{
        cout<<"Enter your choice : ";
        cin>>ch;
        switch (ch){
            case 1 : push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            default : exit(0);
        }
    }while(1);

    return 0;
}


// To run this code type 'g++ Stack.cpp'
//  and for compile './a.out'

//then  enter 1,2 or 3 as your wish to push,pop and display respectively
