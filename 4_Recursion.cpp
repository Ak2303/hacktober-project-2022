#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

//--------------------------------------------------------------------------------------------
//Given a rope of length L and it can cut into a, b or c length of piece, Find the max pieces
//Time complexity == O(3^n) better solution with DP
int ropeCut(int L, int a, int b, int c){
    if(L == 0){
        return 0;
    }
    if(L < 0){
        return -1;
    }

    int res = max(max(ropeCut(L - a, a, b, c), ropeCut(L - b, a, b, c)), ropeCut(L - c, a, b, c));

    if(res == -1){
        return -1;
    }else{
        return res + 1;
    }
}


//---------------------------------------------------------------------------------------
//Function to print Subsets of a given string
void stringSubset(string s, string curr = "", int i = 0){
    if(s.length() == i){
        cout<<curr<<" ";
        return;
    }

    stringSubset(s, curr, i+1);
    stringSubset(s, curr + s[i], i+1); 
} 


//---------------------------------------------------------------------------------------
//Tower of Hanio 
void towerOfHanio(int n, char A, char B, char C){

    if(n == 1){
        cout<<"Move 1 from "<<A<<" to "<<C<<endl;
        return;
    }

    towerOfHanio(n-1, A, C, B);
    cout<<"Move "<<n<<" from "<<A<<" to "<<C<<endl;
    towerOfHanio(n-1, B, A, C);

}


//-----------------------------------------------------------------------------------------
//Josephus problem
int josephus(int n, int k){

    if( n == 1){
        return 0;
    }

    return (josephus(n-1, k) + k) % n;
}


//-----------------------------------------------------------------------------------------
int subsetSum(int arr[], int n, int sum){
    if(n == 0){
        return ((sum == 0)? 1: 0);
    }

    return (subsetSum(arr, n-1, sum) + subsetSum(arr, n -1, sum - arr[n - 1]));
}


//-----------------------------------------------------------------------------------------
//Function to print all permutations of a string
void stringPerm(string s, int i = 0){
    if(i == s.length() - 1){
        cout<<s<<" ";
        return;
    }

    for(int j = i; j < s.length(); j++){
        swap(s[i], s[j]);
        stringPerm(s, i+1);
        swap(s[i], s[j]);
    }
}

int main(){
    cout<<ropeCut(8, 4, 2, 5)<<endl;
    stringSubset("ABC");
    cout<<endl;
    towerOfHanio(3, 'A', 'B', 'C');
    cout<<josephus(5,3)<<endl;
    int arr[5] = {3,2,5,7,1};
    cout<<subsetSum(arr, 5, 8)<<endl;
    stringPerm("ABC");
    cout<<endl; 

    return 0;
}