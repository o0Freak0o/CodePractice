#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * @brief 
 * 二叉树结构体(常规版)
 * @param *right 右指针
 * @param *left 左指针
 * @param data 数据域
 */
typedef struct Nodes{
    Node *left;
    Node *right;
    int data;
} Node;

void PrintProcess(int i, int N, bool down){
    if(i > N)
        return;
    PrintProcess(i+1,N,true);
    // cout<<down?:"凹":"凸";
    if (down == true)
        cout<<"凹";
    else
        cout<<"凸";
}

int main(){
    return 0;
}