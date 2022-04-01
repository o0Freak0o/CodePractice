#include<bits/stdc++.h>
using namespace std;

bool is_leap(int year){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return true;
    else
    return false;
}

int main(){
    int year;
    scanf("%d",&year);
    if(is_leap(year))
    cout<<"1";
    else
    cout<<"0";
    return 0;
}