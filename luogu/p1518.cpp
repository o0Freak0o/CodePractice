#include<bits/stdc++.h>
using namespace std;

int Forest[12][12] = {0};
//x y Head
//0 = North 1 = East 2 = Sourth 3 = West
int Farmer[3];
int Cow[3];
int count_ = 0;
//方向存储数组
int direc[4][4]={{-1,0},{0,1},{1,0},{0,-1}};
//mark 160000 status
int mark[11][11][4][11][11][4] = {0};
int mark2[160005] = {0};

//六维数组解法
int move1();
//hash函数解法
int move2();

int main(){
    char c;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j<= 10; j++){
            cin>>c;
            if(c != '*'){
                Forest[i][j] = 1;
                if(c == 'F'){
                    Farmer[0] = i;
                    Farmer[1] = j;
                    Farmer[2] = 0;
                }
                if(c == 'C'){
                    Cow[0] = i;
                    Cow[1] = j;
                    Cow[2] = 0;
                }
            }
        }
    }
    int res = move1();
    //int res = move2();
    printf("%d",res);
    return 0;
}

int move1(){
    bool isExit = false;
    mark[Farmer[0]][Farmer[1]][Farmer[2]][Cow[0]][Cow[1]][Cow[2]] += 1;
    while (!isExit)
    {
        if(Forest[Farmer[0]+direc[Farmer[2]][0]][Farmer[1]+direc[Farmer[2]][1]] == 0){
            Farmer[2] = (Farmer[2]+1)%4;
        }else{
            Farmer[0] = Farmer[0]+direc[Farmer[2]][0];
            Farmer[1] = Farmer[1]+direc[Farmer[2]][1];
        }
        if(Forest[Cow[0]+direc[Cow[2]][0]][Cow[1]+direc[Cow[2]][1]] == 0){
            Cow[2] = (Cow[2]+1)%4;
        }else{
            Cow[0] = Cow[0]+direc[Cow[2]][0];
            Cow[1] = Cow[1]+direc[Cow[2]][1];
        }
        if(mark[Farmer[0]][Farmer[1]][Farmer[2]][Cow[0]][Cow[1]][Cow[2]] == 1){
            return 0;
            // break;
            isExit = 1;
        }
        count_++;
        mark[Farmer[0]][Farmer[1]][Farmer[2]][Cow[0]][Cow[1]][Cow[2]] += 1;
        if(Cow[0] == Farmer[0] && Cow[1] == Farmer[1]){
            return count_;
            break;
        }
        
    } 
}

int move2(){
    bool isExit = false;
    //hash函数
    mark2[Farmer[0]+Farmer[1]*10+Cow[0]*100+Cow[1]*1000+Farmer[2]*10000+Cow[2]*40000] = 1;
    while (!isExit)
    {
        if(Forest[Farmer[0]+direc[Farmer[2]][0]][Farmer[1]+direc[Farmer[2]][1]] == 0){
            Farmer[2] = (Farmer[2]+1)%4;
        }else{
            Farmer[0] = Farmer[0]+direc[Farmer[2]][0];
            Farmer[1] = Farmer[1]+direc[Farmer[2]][1];
        }
        if(Forest[Cow[0]+direc[Cow[2]][0]][Cow[1]+direc[Cow[2]][1]] == 0){
            Cow[2] = (Cow[2]+1)%4;
        }else{
            Cow[0] = Cow[0]+direc[Cow[2]][0];
            Cow[1] = Cow[1]+direc[Cow[2]][1];
        }
        if(mark2[Farmer[0]+Farmer[1]*10+Cow[0]*100+Cow[1]*1000+Farmer[2]*10000+Cow[2]*40000] == 1){
            return 0;
            // break;
            isExit = 1;
        }
        count_++;
        mark2[Farmer[0]+Farmer[1]*10+Cow[0]*100+Cow[1]*1000+Farmer[2]*10000+Cow[2]*40000] += 1;
        if(Cow[0] == Farmer[0] && Cow[1] == Farmer[1]){
            return count_;
            break;
        }
    } 
}