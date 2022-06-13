#include <bits/stdc++.h>
 
int modularExponentiation(int x, int n, int m) {
	//Use the following property of modulus operator
    //(a x b) % m = ((a % m) x (b % m)) % m
    if(n == 0) return 1;
    if(n == 1) return (x%m);
    
    long long val = modularExponentiation(x,n/2,m) % m;
    
    if(n % 2 == 0)
        return ((long long)(val*val) % (long long)m);
    else
        return ((long long)(((val*val)%m)*x) % (long long)m);
}