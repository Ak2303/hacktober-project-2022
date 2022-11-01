//******ORDER*******
// const < log(log n) < log n < n^1/3 < n^1/2 < n < n^2 < n^3 < 2^n < n!

int getsum(int arr[], int n){

    int sum = 0;

    if(n % 2 != 0)
        return 0;

    else{
        for(int i =0; i< n; i++){
            sum += arr[i];
        }
        return sum;
    }
}
//-------------------------------------------------------------
//Time complexity for getSum function>>>>>>


//Best case : constant 
//Average: taking even and odd equally likely, linear + constant / 2  = linear
//worst case: linear

//---------------------------------------------------------------
//Asymptotic Notations>>>>>>>

/*Big O: Represent exact bound or upper bound 
    f(n) = O(g(n))
    if f(n) <= c*g(n), n>no
*/

/*Theta: Represent exact bound
    f(n) = theta(g(n))
    if 0 <= c1*g(n) <= f(n) <= c2*g(n), n>no
*/

/*Omega: Represent lower bound
    f(n) = Omega(g(n))
    if f(n) >= c*g(n), n>no
*/

//f(n) = 2n+3
//f(n) = O(n), O(n^2), O(n^3)...
//f(n) = Omega(n), Omega(n^1/2), Omega(n^1/3)
//f(n) = theta(n)

//if f(n) = O(g(n)) => g(n) = omega(f(n))

//if f(n) = theta(g(n)) => f(n) = O(g(n)) and f(n) = omega(g(n))

//-------------------------------------------------------
//Analysis of loops>>>>>>>>>>>>>>>>

/*Theta(n)
for(int i=0; i<n; i+=c){
    //theta(1) work
}
*/

/*Theta(log n)
for(int i=0; i<n; i*=c){
    //theta(1) work
}
*/

/*Theta(log(log n))
for(int i=0; i<n; i = pow(i,c)){
    //theta(1) work
}
*/

//------------------------------------------------------------
//Analysis of recursion>>>>>>>>>>>>>>

int fun(int n){
    if(n <= 1){
        return;
    }
    //print(n)
    fun(n/2);
    fun(n/2);
}

//Base case
//T(1) = theta(1)
//Recurrence relation
//T(n) = 2*T(n/2) + theta(1)

//T(n) = 2*(2*T(n/4) + theta(1)) + theta(1)
//T(n) = 2*(2*(2*....T(1)+ theta(1)....)+theta(1)) + theta(1)
//Sum this up...

//OR
//Make recursion tree
/*
                        theta(1)                        theta(1)
                        /      \                        
                    theta(1)    theta(1)                2theta(1) 
                    /    \       /     \
            theta(1) theta(1) theta(1)  theta(1)        4theta(1)
            ......
            ....
            ...
            theta(1).........................theta(1)   2^(log n) * theta(1) 
Sum this up..
*/

//Upper Bounds in recursion>>>>>>>

/* 
T(n) = T(n/2) + T(n/4) + cn
                            cn                      cn
                        /      \                        
                      cn/2      cn/4                3cn/4 
                    /    \       /  \
                 cn/4   cn/8  cn/8  cn/16           9cn/16
            ......
            ....
            ...

Here one branch will get exhausted early than the others and hence the tree is not complete.
so we cant find the exact bound for this recurrence relation but we can find the upper bound
by assuming it to be a complete tree.

T(n) = O(cn + 3cn/4 + 9cn/16+ ...)
T(n) = O(cn/1-3/4) .................... Assuming the series to be infite
T(n) = O(n)
*/

//-------------------------------------------------------------
//Space Complexity>>>>>>>>

int fib(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int a = 0;
    int b = 1;
    for(int i = 2; i< n; i++){
        int c = a+b;
        a = b;
        b = c; 
    } 
    return b;
}

//Space complexity = theta(1)
//Auxiliary space = theta(1)

