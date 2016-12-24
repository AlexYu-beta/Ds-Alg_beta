//
// Created by alex on 12/24/16.
//

#ifndef EXPRESSIONTREE_MYSTACK_H
#define EXPRESSIONTREE_MYSTACK_H
#include <iostream>
using namespace std;
template<typename T>
class MyStack{
public:
    int length;
    int top;
    T *list;

    MyStack(int n):length(n){
        list=new T[n];
        top=-1;
    }

    ~MyStack(){
        delete list;
    }

    void push(T ele){
        if(top>=length) cout<<"stack overflow!!"<<endl;
        else{
            top++;
            list[top]=ele;
        }
    }

    T pop(){
        if(top<0){
            cout<<"stack downflow!!"<<endl;
            return 0;
        }
        else{
            top--;
            return list[top+1];
        }
    }
};
#endif //EXPRESSIONTREE_MYSTACK_H
