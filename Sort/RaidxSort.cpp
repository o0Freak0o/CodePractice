#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<vector>

using namespace std;

//存放数字的数组
vector<int> arr;
//数组大小
int RadixSize;
//待输入的数字
int num;
//最大位数存储器
int Digit = 0;
//获取指定数字a的d位置上的值
int GetDigitNum(int a, int d);
//获取数组中数字的位数的最大值
int GetMaxBitx(vector<int> a);
//比较器
bool Compare(int a, int b);
//基数排序优化解法
vector<int> RadixSort(vector<int> a, int B, int E, int Digit);

//主函数
int main(){
    cout << "Please enter the num of the array" << endl;
    cin >> RadixSize;
    for (int i = 0; i < RadixSize; i++){
        cin >> num;
        arr.push_back(num);
    }
    Digit = GetMaxBitx(arr);
    arr = RadixSort(arr, 0, arr.size(), Digit);
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i]<<" ";
    return 0;
}

int GetDigitNum(int a, int d){
    return ((a / ((int)pow(10, d - 1))) % 10);
}

bool Compare(int a, int b){
    return a > b;
}

int GetMaxBitx(vector<int> a){
    sort(a.begin(), a.end(), Compare);
    int Biggest = a[0];
    while(Biggest % 10 != 0){
        Biggest /= 10;
        Digit++;
    }
    return Digit;
}

vector<int> RadixSort(vector<int> a, int B, int E, int Digit){
    vector<int> Help;
    for (int i = 0; i < E; i++)
        Help.push_back(0);
    int CurrentDigit = 1;
    while (CurrentDigit <= Digit)
    {
        int count[10] = {0};
        for (int i = 0; i < E; i++){
            int C_Num = GetDigitNum(a[i], CurrentDigit);
            count[C_Num]++;
        }
        for (int i = 0; i < 9; i++)
            count[i + 1] = count[i] + count[i + 1];
        for (int i = a.size() - 1; i >= B; i--){
            int C_Num = GetDigitNum(a[i], CurrentDigit);
            Help[count[C_Num]-1] = a[i];
            count[C_Num]--;
        }
        swap(a, Help);
        CurrentDigit++;
    }
    for (int i = 0; i < arr.size(); i++)
        cout << a[i]<<" ";
    return a;
}