#include<bits/stdc++.h>
using namespace std;

//int�����ݴ������
int arr[100001];
//�����С
int num;
//����Ԫ��
int element;
//���ŵݹ����
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
    //�ݹ���ڣ��������±����
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