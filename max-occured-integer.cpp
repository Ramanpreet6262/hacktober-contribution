#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of arrays";
    cin>>n;
    int L[n], R[n];

    for(int i=0; i<n; i++)
    {
        cin>>L[i];
        cin>>R[i];
    }

    int max = -1;
    for(int i=0; i<n; i++)
    {
        if(R[i]>max)
        {
            max = R[i];
        }
    }
    
    int size = max + 1;
    // int size = max + 2;
    int arr[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        arr[L[i]]++;
        arr[R[i]+1]--;
    }
    
    int prev = 0;
    int maxx = 0;

    for(int i=0; i<size; i++)
    {
        if(prev + arr[i] > maxx)
        {
            maxx = prev + arr[i];
        }    
        prev = prev + arr[i];
    }
    cout<<maxx;
}
