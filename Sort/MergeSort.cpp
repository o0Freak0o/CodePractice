#include<bits/stdc++.h>
using namespace std;
int r[10001];
// void MergeSort(int a[],int s,int t){
//     if(s == t) return;
//     int mid = (s+t)/2;//����ȡ��
//     MergeSort(a,s,mid);
//     MergeSort(a,mid+1,t);
//     int i = s,j=mid+1,k=s;//�ϲ�����
//     while (i<=mid && j<=t)
//     {
//         if(a[i]<=a[j]){
//             r[k]=a[i];k++;i++;
//         }else{
//             r[k]=a[j];k++;j++;
//         }
//     }
//     while(i<=mid){
//         r[k]=a[i];
//         k++;
//         i++;
//     }
//     while(j<=t){
//         r[k]=a[j];
//         k++;
//         j++;
//     }
//     for(i = s;i<=t;i++){
//         a[i]=r[i];
//     }
// }

//int�����ݴ������
int arr[100001];
//��������
int Help_arr[100001];
//�����С
int num;
//����Ԫ��
int element;
void MergeSort(int arr[], int Left, int Right);

int main(){
    cout<<"Please enter the num of the array"<<endl;
    cin>>num;
    cout<<"Please enter the elements in the array (Integer)"<<endl;
    for (int i = 0; i < num; i++){
        cin>>arr[i];
    }
    MergeSort(arr, 0, num-1);
    for (int i = 0; i < num; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
void MergeSort(int arr[], int Left, int Right){
    //�ݹ���ڣ��������±����
    if (Left == Right)
        return;
    //ȡ�м�ֵ
    int Media = Left + ((Right - Left) >> 1);
    MergeSort(arr, Left, Media);
    MergeSort(arr, Media+1, Right);
    int i = Left;
    int l = Left;
    int k = Media+1;
    int j = Right;
    while (i <= Media && k <= Right )
    {
        if(arr[i] < arr[k])
            Help_arr[l++] = arr[i++];
        else
            Help_arr[l++] = arr[k++];
    }
    while (i <= Media)
        Help_arr[l++] = arr[i++];
    while (k <= Right)
        Help_arr[l++] = arr[k++];
    for(int i = Left; i <= Right; i++)
        arr[i] = Help_arr[i];

}