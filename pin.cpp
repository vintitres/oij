//pin

#include<iostream>

using namespace std;

long long int pow(long long int n, int p) {
long long int r = 1;
for (int i = 0; i < p; ++i) r *= n;
return r;
}

long long int f(int n, long long int k) {
if (n == 1) return k - 1;
long long int nn = pow(2LL, n);
if (k<=nn) {
return f(n-1,k);
}
return f(n-1,k-nn) + pow(3LL, n - 1) * 2;
}


int main() {
int n,q;
cin>>n>>q;
for (int i =0 ; i < q; ++i){
long long int k;
cin >>k;
if (k > pow(2LL, n+1)){ cout << (char)78 <<(char)73<<(char)69 << endl; continue;}
cout <<f(n,k)<<endl;
}
}
