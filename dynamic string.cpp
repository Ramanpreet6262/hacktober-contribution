#include<iostream>
#include<stdio.h>
using namespace std;

class str
{
	char *name;
	int len;
	public:
		str(char *s)
		{
			len = strlen(s);
			name = new char[len+1];
			strcpy(name,s);
			
		}
	
}
