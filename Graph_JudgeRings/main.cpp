#include <iostream>
#define num 7
using namespace std;
int visited[num];
int map[num][num];
int Start,End;
int Min;
int minRoad[10];

int temp;
int tempLen;
int tempRoad[10];


void print(){
    int i;
    for(i=0;i<=Min;i++){
        cout<<minRoad[i]<<"->";
    }
    cout<<endl;
}


void initVisited(){
    int i;
    for(i=0;i<num;i++){
        visited[i]=0;
    }
}

void visit(int i,int k){
    int j,m;
    for(j=0;j<num;j++){
        if(visited[i]==1) continue;
        if(map[k][j]==0) continue;
        visited[j]=1;
        tempRoad[i]=j;
        if(j==End){
            Min=i;
            for(m=0;m<=Min;m++){
                minRoad[m]=tempRoad[m];
            }
            print();
        }else{
            visit(i+1,j);
        }
        visited[j]=0;
        tempLen=tempLen-map[k][j];
    }
}





int main(){
    int i,j;
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            cin>>map[i][j];
        }
    }

    for(i=0;i<num;i++){
        Start=i;
        End=i;
        initVisited();
        tempRoad[0]=Start;
        visit(1,Start);
    }




    return 0;
}

