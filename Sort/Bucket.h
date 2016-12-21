//
// Created by alex on 12/21/16.
//
#include <iostream>
using namespace std;
#ifndef SORT_BUCKET_H
#define SORT_BUCKET_H
class Bucket{
public:
    int len;
    int *list;
    Bucket(){
        list=new int[10];
        len=0;
    }
    void add(int number);
    void clear();
};

void Bucket::add(int number) {
    list[len]=number;
    len++;
}

void Bucket::clear() {
    delete list;
    list=new int[10];
    len=0;
}

#endif //SORT_BUCKET_H
