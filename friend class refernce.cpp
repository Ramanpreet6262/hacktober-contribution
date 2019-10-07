/* code starts */
#include<iostream>
#include<string.h>
using namespace std;

//decleration of class inc
class inc;
class id
{
	int salary;
	char dept[50];
	public:
		void getdata(){
			cout<<"Enter salary and department";
			cin>>salary>>dept;			
		}
		friend class inc;
};

class inc
{
	public:
		void in(id &i1)
		{
			if(strcmp(i1.dept,"cse")==0)
				i1.salary+=1000;		// add salary 1000 if dept is cse
			
			else if(strcmp(i1.dept,"ece")==0)
				i1.salary+=2000;		// add salary 2000 if dept is ece
			else if(strcmp(i1.dept,"mech")==0)
				i1.salary+=750;			// add salary 750 if dept is mech	
		}
		void display(id &i1)
		{
			cout<<"The department is "<<i1.dept<<endl;		
			cout<<i1.salary;
		}
};

int main()
{
	id i1;
	inc c1;
	i1.getdata();
	c1.in(i1);
	c1.display(i1);
	
	return 0;
}
/* code ends*/
