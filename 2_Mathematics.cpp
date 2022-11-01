#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

//-----------------------------------------------------------------------
//Function to count number of digits
int numberOfDigits(int n){

    return ceil(log10(n));
}


//-----------------------------------------------------------------------
//Function to check if a number is palindrome or not
bool isPalindrome(int n){
    int temp = n;
    int rev = 0;
    while(temp != 0){
        rev = ((rev * 10) + (temp % 10));
        temp = temp / 10;
    }
    return (rev == n);
}



//------------------------------------------------------------------------
//Function to find the factorial of a number
long long fact(int n){
    long long factorial = 1;
    for(int i = 2; i <= n; i++){
        factorial *= i;
    }
    return factorial;
} 



//------------------------------------------------------------------------
//Function to calculate number of trailing zeros in factorial of a number
int trailingZero(int n){
    int zeros = 0;
    int i = 5;
    while(true){
        int temp = n/i;
        if(temp != 0){
            zeros += temp;
            i*= 5;
        }else{
            break;
        }
    }
    return zeros;
}


//-----------------------------------------------------------------------
//Function to find GCD of two numbers
int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}



//-----------------------------------------------------------------------
//Function to find LCM of two numbers
int lcm(int a, int b){
    int value = (a * b)/ gcd(a, b); 
    return value;
}



//-----------------------------------------------------------------------
//Function to check if a number is prime or not 
bool isPrime(int n){
    if(n == 1){
        return false;
    }if(n == 2 || n == 3){
        return true;
    }if(n % 2 == 0 || n % 3 == 0){
        return false;
    }else{
        for(int i = 5; i*i <= n; i += 6){
            if(n % i == 0 || n % (i+2) == 0){
                return false;
            }
        }
        return true;
    }
}



//-----------------------------------------------------------------------
//Function for finding prime factors of a number
void primeFactor(int n){
    if(n == 1){
        return ;
    }
    while(n % 2 == 0){
        cout<<2<<" ";
        n = n/2;
    }
    
    while(n % 3 == 0){
        cout<<3<<" ";
        n = n/3;
    }
    
    for(int i = 5; i*i <= n; i += 6){
        while(n % i == 0){
            cout<<i<<" ";
            n = n/i;
        }
        while(n % (i+2) == 0){
            cout<<i+2<<" ";
            n = n/(i+2);
        }
    }
    if(n>3){
        cout<<n<<" ";
    }
    cout<<endl;
}



//----------------------------------------------------------------------
//Function to find all divisors of a number
void divisors(int n){
    int i = 2;
    for(; i*i < n; i++){
        if(n % i == 0){
            cout<<i<<" ";
        }
    }
    for(; i >= 1; i--){
        if(n % i == 0){
            cout<<n/i<<" ";
        }
    }
    cout<<endl;
}



//---------------------------------------------------------------------------------------
//Sieve of Eratosthenes - Function to find prime numbers less than equal to a number
void sieveOfEratothenes(int n){
    vector<bool> sieve(n+1, true);

}





int main(){
    cout<<boolalpha;
    cout<<numberOfDigits(23123)<<endl;
    cout<<isPalindrome(23132)<<endl;
    cout<<fact(15)<<endl;
    cout<<trailingZero(15)<<endl;
    cout<<gcd(12, 13)<<endl;
    cout<<lcm(12,13)<<endl;
    cout<<isPrime(15)<<endl;
    primeFactor(70);
    divisors(70);
    
    return 0;
}
