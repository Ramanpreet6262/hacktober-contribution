#include <bits/stdc++.h>
using namespace std;
long long factorial (int N);
int main()
{
    int T,N;
    cin>>T;  //input number of testcases
    while(T--)
    {
        cin>>N; //input n
        cout<<factorial(N)<<endl;
    }
    return 0;
}

long long factorial (int N)
{
    long long fact = 1;
    for(int i = 1; i <= N; i++)
    {
        fact = fact * i;
    }
    return fact;
}
