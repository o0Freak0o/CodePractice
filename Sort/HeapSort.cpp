#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>

//请注意，Heap结构远比HeapSort要重要！
//请注意，Heap结构远比HeapSort要重要！
//请注意，Heap结构远比HeapSort要重要！
//尽管有些语言有现成的Heap包（譬如java）
//但是其内部是黑盒，你并不能对其结构进行改变（譬如，我要删掉数组中的某个数，并且这个堆要给我自动重新调整为堆）。
//因此强烈建议手写推排

int Heap[10001];
int HeapSize;
//临时存储变量
int C_HeapSize;
void swap(int i, int j, int a[]);
void HeapInsert(int j, int a[]);
void Heapify(int i, int a[], int CurrentHeapSize);
void HeapSort(int HeapSize, int Heap[]);
using namespace std;

//主函数
int main(){
    cout << "Please enter the num of the array" << endl;
    cin >> HeapSize;
    cout << "Please enter the numbers of the array" << endl;
    for (int i = 0; i < HeapSize; i++){
        cin >> Heap[i];
    }
    cout << "Waiting..." << endl;
    HeapSort(HeapSize, Heap);
    cout << "The ordered sequence after HeapSort is as follows" << endl;
    for (int i = 1; i <= HeapSize; i++){
        cout << Heap[i] << " ";
    }
    cout << endl;
    cout << "HeapSort Complicated." << endl;
    return 0;
}
//数值交换函数
void swap(int i, int j, int a[]){
    int tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
}
//HeapInsert过程
void HeapInsert(int j, int a[]){
    while( a[j] > a[(j-1)/2]){
        swap(j, (j - 1) / 2, a);
        j = (j - 1) / 2;
    } 
}
//Heapify过程
void Heapify(int i, int a[], int CurrentHeapSize){
    while ( (i*2+1) < CurrentHeapSize )
    {
        int Larger = (i * 2 + 2 < HeapSize) && (Heap[i * 2 + 1] < Heap[i * 2 + 2]) ? i * 2 + 2 : i * 2 + 1;
        int Largest = Heap[Larger] < Heap[i] ? i : Larger;
        if (Largest == i)
            return;
        else{
            swap(i, Largest, a);
            i = Largest;
        }
    }
}
//HeapSort过程
//传递一个数组给该函数，HeapInsert有更优化的解法，
//此处不做拓展
void HeapSort(int HeapSize, int Heap[]){
    for (int i = 0; i < HeapSize; i++){
        HeapInsert(i, Heap);
    }
    C_HeapSize = HeapSize;
    while (C_HeapSize > 0)
    {
        swap(0, C_HeapSize, Heap);
        C_HeapSize -= 1;
        Heapify(0, Heap, C_HeapSize);
    }
}