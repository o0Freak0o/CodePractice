#include<bits/stdc++.h>
using namespace std;

//int型数据存放数组
int arr[100001];
//数组大小
int num;
//数组元素
int element;
//快排递归过程
void QuickSort(int arr[], int Left, int Right);

int main(){
    memset(arr,0,sizeof(arr));
    cout<<"Please enter the num of the array"<<endl;
    cin>>num;
    cout<<"Please enter the elements in the array (Integer)"<<endl;
    for (int i = 0; i < num; i++){
        cin>>arr[i];
    }
    QuickSort(arr, 0, num-1);
    for (int i = 0; i < num; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void QuickSort(int arr[], int Left, int Right){
    int tmp_Left = Left;
    int tmp_Right = Right;
    int media = arr[Left];
    //递归出口，即左右下标相等
    if (Left == Right)
        return ;
    while (tmp_Left < tmp_Right){
        while (tmp_Left < tmp_Right && media <= arr[tmp_Right])
            tmp_Right--;
        arr[tmp_Left] = arr[tmp_Right];
        while (tmp_Left < tmp_Right && media >= arr[tmp_Left])
            tmp_Left++;
        arr[tmp_Right] = arr[tmp_Left];
    }
    arr[tmp_Left] = media;
    QuickSort(arr, Left, tmp_Left - 1);
    QuickSort(arr, tmp_Left + 1, Right);
}

// void qsort(int a[],int left,int right){
//     if(left>=right)
//     return;
//     int i = left;
//     int j = right;
//     int key = a[left];
//     while(i<j){
//         while(i<j&&key<=a[j]) j--;
//         a[i] = a[j];
//         while(i<j&&key>=a[i]) i++;
//         a[j] = a[i];
//     }
//     a[i] = key;
//     qsort(a,left,i-1);
//     qsort(a,i+1,right);
// }
// int a[101];
// int main(){
//     memset(a,0,sizeof(a));
//     int n,i;
//     cin>>n;
//     for(i=0;i<n;i++){
//         cin>>a[i];
//     }
//     qsort(a,0,n-1);
//     for(i=0;i<n;i++) cout<<a[i]<<" ";
//     return 0;
// }