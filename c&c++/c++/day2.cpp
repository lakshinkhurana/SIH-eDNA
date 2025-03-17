#include<iostream>
using namespace std;

//Learning Recursion
int fibonacci(int n){
    if(n<=1){
        return n;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int factorial(int n){
    if(n<0){
        cout<<"Wrong Input!"<<endl;
        return 0;
    }
    if(n==0){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int sumOfDigits(int num){
    if(num<=0){
        return 0;
    }else{
        return num%10+sumOfDigits(num/10);
    }
}
int main(){
    int n;
    cout<<"Number of Elements required in Series  ";
    cin>>n;
    //Printing Series
    for(int i=0;i<n;i++){
        cout<<fibonacci(i)<<" ";
    }
    cout<<endl;
    cout<<factorial(7)<<endl;
    cout<<sumOfDigits(1233)<<endl;
    return 0;
}