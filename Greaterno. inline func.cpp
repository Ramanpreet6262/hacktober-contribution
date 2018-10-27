// Write a program to find the greater no. using inline func.?

#include<iostream>
using std::cin;
using std::cout;

inline int greater(int ,int );

int greater(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	
	else
	{
		return b;
	}
}

int main()
{
	int a,b,c;
	cin>>a>>b;
	c=greater(a,b);
	cout<<c;
	
	return 0;
}
