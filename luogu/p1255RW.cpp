#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>

//递归解法，检测点会超时
//同时没有考虑到高精度问题
//因此这里仅作为反面教材23333
using namespace std;

//楼梯数
int upstairs;
//方法数量计数器
int Numcount = 0;
//步数
int method[2] = {1, 2};
//搜索函数
void search(int c);

//主函数
int main(){
    cout << "Please enter the stairs:" << endl;
    cin >> upstairs;
    search(0);
    cout << Numcount;
    return 0;
}

void search(int c){
    if (c == upstairs){
        Numcount++;
        return;
    }
    if(c > upstairs)
        return;
    for (int i = 0; i < 2; i++){
        c += method[i];
        search(c);
        c -= method[i];
    }
}