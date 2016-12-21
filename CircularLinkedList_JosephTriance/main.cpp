#include <iostream>
#include "CircularLinkedList.h"
using namespace std;
int main() {
    int n,m;
    int i=0;
    cout<<"please enter a number n to create an n-tuple link-list"<<endl;
    cin>>n;
    cout<<"please enter a number m to create a spelling number"<<endl;
    cin>>m;
    CircularLinkedList cll(n);
    do{
        cll.Delete(m-1,cll.present);
    }while(cll.length>1);
    return 0;
}