#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
//Checking whether kth bit of a number is set or not
void kthBit(int n, int k){
    if(n & (1<<(k-1))){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

//-----------------------------------------------------------------------
//Function to count number of set bits in number

//Brian Kerningam's Algorithm>>>>>>>>>>>>>>>>>
//takes O(number of set bits) time 
int countSetKB(int n){
    int count = 0;
    while(n>0){
        n = (n & (n-1)); //Important step
        count++;
    }
    return count;
}


//Lookup table method for 32 bits number>>>>>>>>>>>>>>>>>>>>>>>>>>>
//takes O(1) time 

int table[256]; 
//Calculating number of set bit for every number between 0 to 255 

void initialise(){
    table[0] = 0;
    for(int i = 1; i<256; i++){
        table[i] = (i&1) + table[i/2];
    }
}

int countSetLT(int n){
    initialise();
    int result = 0;
    //{Oxff =(11111111)b}
    result += table[n & 0xff]; //n & Oxff return last 8 bits of the number n 
    n = n>>8;
    result += table[n & 0xff];
    n = n>>8;
    result += table[n & 0xff];
    n = n>>8;
    result += table[n & 0xff];
    n = n>>8;
    return result;
}

//------------------------------------------------------------------
//Function to check whether a number is power of 2 or not
bool isPowerTwo(int n){
    return ((n != 0) && ((n & (n-1)) == 0));
}


//---------------------------------------------------------------------
//Function to find the number occuring odd number of times in an array

int onlyOddOccuring(int *numbers, int n){
    int res = 0;
    for(int i = 0; i< n; i++){
        res = res ^ numbers[i];
    }
    return res;
}


//----------------------------------------------------------------------
//Function to find two numbers occuring odd number of times in an array
void twoOddOccuring(int *numbers, int n){
    int res = 0;
    for(int i = 0; i< n; i++){
        res = res ^ numbers[i];
    }
    int first = res & (~(res - 1));
    int num1 = 0;
    int num2 = 0;
    for(int i = 0; i< n; i++){
        if((first & numbers[i]) == 0){
            num1 = num1 ^ numbers[i];
        }else{
            num2 = num2 ^ numbers[i];
        }   
    }
    cout<<num1<<" "<<num2<<endl;

}



int main(){

    cout<<boolalpha;
    kthBit(5,2);
    cout<<countSetKB(46)<<endl;
    cout<<countSetLT(46)<<endl;
    cout<<isPowerTwo(32)<<endl;
    int arr1[7] = {3,3,3,5,5,6,3};
    cout<<onlyOddOccuring(arr1, 7)<<endl;
    int arr2[8] = {3,3,3,5,5,6,3,5};
    twoOddOccuring(arr2,8);
    return 0;
}
