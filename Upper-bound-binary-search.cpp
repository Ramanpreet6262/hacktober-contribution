#include<iostream>
using namespace std;

int upper_bound(int a[], int l, int r, int no)
{
    while(l<r)
    {
        int mid = (l + r) / 2;

        if(a[mid] > no)
        {
            r = mid;
        }
        
        else 
        {
            l = mid + 1;
        }
    }
    return l;
}

int main() 
{
    int n, no;
    cout<<"Enter no. of elements"<< endl;
    cin>>n;
    cout<<"Enter the no. of which upper bound is to be found"<< endl;
    cin>>no;
    int arr[n];
    cout<<"Enter no's"<< endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int result = upper_bound(arr, 0, n-1, no);

    cout<<"Upper bound is present at "<<result<<" index"<<endl;
    return 0;
}
