#include <iostream>
#include "Stack.h"
using namespace std;
static Stack *stack;

int getLen(char *list){
    int count=0;
    char *p=list;
    while(*p++)count++;
    return count;
}

int main() {
    char *postFixSentence=new char[256];                                   //this time, i try to hold the input
    int len;                                                               //sentence in the form of char*
    int i;                                                                 //the maxSize(256) must be indicated
    int numA,numB,numC;
    cin>>postFixSentence;
    len=getLen(postFixSentence);
    stack=new Stack(30);
    for(i=0;i<len;i++){
        if(((postFixSentence[i]<='9'&&postFixSentence[i]>='0'))){
            stack->push(postFixSentence[i]-'0');
        }else{
            numA=stack->pop();
            numB=stack->pop();
            switch(postFixSentence[i]){
                case '+':numC=numA+numB;break;
                case '-':numC=numA-numB;break;
                case '*':numC=numA*numB;break;
                case '/':numC=numA/numB;break;
                default:break;
            }
            stack->push(numC);
        }
    }
    cout<<stack->list[stack->top]<<endl;                        //the answer is stored in the top of the stack

    return 0;
}