#include <iostream>
#include "Bucket.h"
#include <cmath>
using namespace std;

void array_cpy(int *dest,int *src,int n){
    int i;
    for(i=0;i<n;i++){
        dest[i]=src[i];
    }
}

int getLoc(int num,int k){                      //get the digit at the location k of number num
    int tempnum=num;
    int ele;
    int i;
    for(i=0;i<k;i++){
        ele=tempnum%10;
        tempnum=tempnum/10;
    }
    return ele;
}

void selection_sort(int *a,int n){
    int min;
    int i,j,k;
    int temp;
    for(i=0;i<n-1;i++){
        min=a[i];                          //assert that the minimum is placed at the first of the list
        k=i;                               //to store the index of the actual smallest element
        for(j=i+1;j<n;j++){
            if(a[j]<min){                  //find the smallest element
                min=a[j];
                k=j;                       //replace the index
            }
        }
        temp=a[i];                         //place the smallest element to the first of the list
        a[i]=min;
        a[k]=temp;
    }
}

void bubble_sort(int *a,int n){
    int i,j;
    int temp;
    for(i=n;i>1;i--){                      //sort the first i elements into sequential order
        for(j=0;j<i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}

void rank_sort(int *a,int n){
    int rank[10];
    int i,j;
    int temp;
    for(i=0;i<10;i++){
        rank[i]=0;
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[i]<=a[j])rank[j]++;                  //emulate a single-cyclic competition among list members
            else rank[i]++;                           //who wins, who gets one points
        }
    }
    for(i=0;i<10;i++){
        while(rank[i]!=i){                            //the points one gets equal to the rank he deserves
            int t=rank[i];
            temp=a[i];
            a[i]=a[t];
            a[t]=temp;
            temp=rank[i];
            rank[i]=rank[t];
            rank[t]=temp;
        }
    }
}

void insertion_sort(int *a,int n){
    int i,j;
    int x;
    for(i=0;i<n;i++){
        x=a[i];                                       //assumes that the first i-1 elements are in order
        for(j=i-1;j>=0&&x<a[j];j--){                  //insert the number a[i] into the first i-1 elements
            a[j+1]=a[j];                              //and make sure that the list after the insertion in good order
        }
        a[j+1]=x;
    }
}

void radix_sort(int *a,int n){
    int max=0;
    int i,j,m;
    int node;
    for(i=0;i<n;i++){
        if(a[i]>max) max=a[i];
    }
    int k=log10(max)+1;
    Bucket buckets[10];                                        //create 10 buckets to hold the numbers
    for(i=1;i<=k;i++){
        for(j=0;j<10;j++){
            buckets[getLoc(a[j],i)].add(a[j]);                 //put the numbers into the buckets respectively
        }
        node=0;
        for(j=0;j<10;j++){
            for(m=0;m<buckets[j].len;m++){                     //get the numbers from the buckets and rearrange
                a[node]=buckets[j].list[m];
                node++;
            }
            buckets[j].clear();                                //clear the buckets before the next round's sort
        }
    }
}

























int main() {
    int i;
    int a[]= {1,4,2,8,5,7,10,4,3,9};
    int c[]={288,371,260,531,287,235,56,299,18,23};
    int b[10];
    //----------------------------selection sort-----------------------------//
    /*
    cout<<"testing selection sort:"<<endl;
    array_cpy(b,a,10);
    selection_sort(b,10);
    for(i=0;i<10;i++){
        cout<<"  "<<b[i];
    }
    cout<<endl;
    //*/
    //----------------------------bubble sort--------------------------------//
    /*
    cout<<"testing bubble sort:"<<endl;
    array_cpy(b,a,10);
    bubble_sort(b,10);
    for(i=0;i<10;i++){
        cout<<"  "<<b[i];
    }
    cout<<endl;
    //*/
    //----------------------------rank sort--------------------------------//
    /*
    cout<<"testing rank sort:"<<endl;
    array_cpy(b,a,10);
    rank_sort(b,10);
    for(i=0;i<10;i++){
        cout<<"  "<<b[i];
    }
    cout<<endl;
    //*/
    //----------------------------insertion sort--------------------------------//
    /*
    cout<<"testing insertion sort:"<<endl;
    array_cpy(b,a,10);
    insertion_sort(b,10);
    for(i=0;i<10;i++){
        cout<<"  "<<b[i];
    }
    cout<<endl;
    //*/
    //----------------------------radix sort--------------------------------//
    ///*
    cout<<"testing radix sort:"<<endl;
    array_cpy(b,a,10);
    radix_sort(c,10);
    for(i=0;i<10;i++){
        cout<<"  "<<c[i];
    }
    cout<<endl;
    //*/
    return 0;
}