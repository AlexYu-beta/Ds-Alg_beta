//
// Created by alex on 12/23/16.
//
#include <iostream>
using namespace std;

#ifndef POSTFIXEVALUATION_STACK_H
#define POSTFIXEVALUATION_STACK_H
class Stack{
public:
    int length;
    int top;
    int *list;

    Stack(int n):length(n){
        list=new int[n];
        top=-1;
    }

    ~Stack(){
        delete list;
    }

    void push(int num){
        if(top>=length) cout<<"stack overflow!!"<<endl;
        else{
            top++;
            list[top]=num;
        }
    }

    int pop(){
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
#endif //POSTFIXEVALUATION_STACK_H
