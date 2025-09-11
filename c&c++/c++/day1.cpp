#include<iostream>
using namespace std;

/*Swapping Function*/
void swap(int &l,int &m){
    int temp=l;
    l=m;
    m=temp;
}

/*Bubble Sort Function*/
void bubbleSort(int array[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(array[j+1]<array[j]){
                swap(array[j+1],array[j]);
            }
        }
    }
    for(int i = 0; i<n ; i++){
        cout<<array[i]<<" ";
    }
}

/*Selection Sort Algorithm*/
void selectionSort(int array[],int n){
    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){
            if(array[i]>array[j]){
                swap(array[i],array[j]);
            }
        }
    }
    for(int i = 0; i<n ; i++){
        cout<<array[i]<<" ";
    }
}
/*Insertion Sort Algorithm*/
void insertionSort(int array[],int n){
    for(int i=1;i<n;i++){
        int currentValue=array[i];
        j=i-1;

        while(j>=0 && array[j]>currentValue){
            array[j+1]=array[j];
            j=j-1
        }
        array[j+1]=key;
    }

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    int arr[]={3,5,9,11,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    cout<<endl;
    selectionSort(arr,n);
    cout<<endl;
    insertionSort(arr,n);
    return 0;
}