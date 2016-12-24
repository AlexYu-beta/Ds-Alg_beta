#include <iostream>
#include "MyTree.h"
#include "MyStack.h"

using namespace std;
static MyStack<MyTree<char>*> *stack=new MyStack<MyTree<char>*>(50);

int getLen(char *list){
    int count=0;
    char *p=list;
    while(*p++)count++;
    return count;
}

int main() {
    char *postFixSentence=new char[256];
    cin>>postFixSentence;
    int len=getLen(postFixSentence);
    int i;
    for(i=0;i<len;i++){
        if(((postFixSentence[i]<='9'&&postFixSentence[i]>='0'))){
            stack->push(new MyTree<char>(new TreeNode<char>(postFixSentence[i])));
        }else{
            MyTree<char> *b=stack->pop();
            MyTree<char> *a=stack->pop();
            a->combine(new TreeNode<char>(postFixSentence[i]),b);
            stack->push(a);
        }
    }

    stack->list[0]->InOrder();
    return 0;
}