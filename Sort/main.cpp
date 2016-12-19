#include <iostream>
using namespace std;

void array_cpy(int *dest,int *src,int n){
    int i;
    for(i=0;i<n;i++){
        dest[i]=src[i];
    }
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
    for(i=n;i>1;i--){
        for(j=0;j<i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}





























int main() {
    int i;
    int a[]= {1,4,2,8,5,7,10,4,3,9};
    int b[10];
    //----------------------------selection sort-----------------------------//
    ///*
    cout<<"testing selection sort:"<<endl;
    array_cpy(b,a,10);
    selection_sort(b,10);
    for(i=0;i<10;i++){
        cout<<"  "<<b[i];
    }
    cout<<endl;
    //*/
    //----------------------------bubble sort--------------------------------//
    ///*
    cout<<"testing bubble sort:"<<endl;
    array_cpy(b,a,10);
    bubble_sort(b,10);
    for(i=0;i<10;i++){
        cout<<"  "<<b[i];
    }
    cout<<endl;
    //*/
    //----------------------------bubble sort--------------------------------//
    ///*
    cout<<"testing bubble sort:"<<endl;
    array_cpy(b,a,10);
    bubble_sort(b,10);
    for(i=0;i<10;i++){
        cout<<"  "<<b[i];
    }
    cout<<endl;
    //*/
    return 0;
}