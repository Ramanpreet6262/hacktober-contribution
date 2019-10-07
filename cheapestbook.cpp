#include<iostream>
using namespace std;

class book
{
	int price;
	char title[50];
	
	public:
		void getdata()
		{
			cin>>price>>title;
		}
		friend int cheapest(book a[], int n);			// declaring a friend function
};

int main()
{
	int i,n,cprice;
	cin>>n;				// scannning size of array
	book a[n];
	for(i=0;i<n;i++)
	{
		a[i].getdata();		// scanning data
	}
	cprice=cheapest(a,n)		//cprice returns integer from cheapest function
	
	return 0;
	
}


int cheapest(book a[], int n)		// returns cheapest book
{
	int l=a[0].price;
	int i;
	for(i=0;i<n;i++)
		{
			if(a[i].price<l)
			{
				l=a[i].price;
			}
		}
		return l;
}
