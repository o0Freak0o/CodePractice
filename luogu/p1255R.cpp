#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>

using namespace std;

//核心思想，利用二维数组存储结果
//第一维代表楼梯层数
//第二维代表结果
//兼顾解决高精问题
//需要注意的是，结果是高位在后，因此输出的时候是Length_--
int upstairs[5010][5010];
//结果长度，初值为1
int RLength_ = 1;
//用户输入的楼梯的层数
int ULength_;
//累加函数
void SIterator(int Num);

//主函数
int main(){
    upstairs[1][1] = 1;
    upstairs[2][1] = 2;
    cout << "Please enter the num of the stairs:" << endl;
    cin >> ULength_;
    SIterator(ULength_);
    cout << "Total methods have ";
    for (int i = RLength_; i >= 1; i--)
        cout << upstairs[ULength_][i];
    return 0;
}

void SIterator(int Num){
    for (int i = 3; i <= Num; i++){
        for (int j = 1; j <= RLength_; j++)
            upstairs[i][j] = upstairs[i - 1][j] + upstairs[i - 2][j];
        for (int j = 1; j <= RLength_; j++){
            if(upstairs[i][j] >= 10){
                upstairs[i][j + 1] = upstairs[i][j] / 10 + upstairs[i][j + 1];
                upstairs[i][j] %= 10;
            }
            if(upstairs[i][RLength_+1])
                RLength_++;
        }
    }
}