// Write a program to find the greater no. using inline func.?
/* code starts */
#include<iostream>
using std::cin; //input for user
using std::cout;

//greater function start
inline int greater(int a,int b)
{
	if(a>b)
		return a;		// returns a if a is greater else b
	return b;
}

int main()
{
	int a,b,c;
	cin>>a>>b;  
	c=greater(a,b);		
	cout<<c;
	
	return 0;
}
/* code ends */
