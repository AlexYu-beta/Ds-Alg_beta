//
// Created by alex on 12/21/16.
//
#include <iostream>
using namespace std;
#ifndef CIRCULARLINKEDLIST_JOSEPHTRIANCE_CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_JOSEPHTRIANCE_CIRCULARLINKEDLIST_H
struct nodeJ{
    int num;
    nodeJ *next;
};

class CircularLinkedList{
public:
    CircularLinkedList(int);
    void Delete(int,nodeJ *);

    int length;
    nodeJ *head;
    nodeJ *present;
};

CircularLinkedList::CircularLinkedList(int n){
    this->length=n;
    this->head =new nodeJ;
    nodeJ *ptrtemp;
    ptrtemp=head;
    this->present=head;
    for(int i=0;i<n;i++){
        ptrtemp->num=i;
        if(i==n-1){
            ptrtemp->next=head;
        }
        else {
            ptrtemp->next = new nodeJ;
            ptrtemp = ptrtemp->next;
        }
    }
}


void CircularLinkedList::Delete(int n,nodeJ *ptrtemp) {
//locate
    ptrtemp=this->present;
    for(int i=n;i>1;i--){
        ptrtemp=ptrtemp->next;
    }
//select
    int numa=0;
    numa=ptrtemp->next->num;
    cout<<numa+1<<endl;
    ptrtemp->next=ptrtemp->next->next;
    this->length--;
    this->present=ptrtemp->next;
}
#endif //CIRCULARLINKEDLIST_JOSEPHTRIANCE_CIRCULARLINKEDLIST_H
