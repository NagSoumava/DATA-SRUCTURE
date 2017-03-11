#include<iostream>
#include<cstring>
using namespace std;


void printInterleavedString(char *s1,char *s2,char *op,int m,int n,int index)
{
	if(m==0&&n==0)
	{
		op[index]='\0';
		cout<<op<<endl;
		return;
	}
	if(m>0) //keep 1st character of string1 constant
	{
		op[index]=*s1;
		printInterleavedString(s1+1,s2,op,m-1,n,index+1);
	}
	if(n>0)
	{
		op[index]=*s2;
		printInterleavedString(s1,s2+1,op,m,n-1,index+1);
	}
}

void interleavedString(char *s1,char *s2)
{
	char *op=new char[strlen(s1)+strlen(s2)];
	printInterleavedString(s1,s2,op,strlen(s1),strlen(s2),0); //0 is the starting index of the output string
}

//driver program
int main()
{
	char s1[50],s2[50];
	cout<<"Enter first string: ";
	cin>>s1;
	cout<<"Enter second string:";
	cin>>s2;
	interleavedString(s1,s2);
	return 0;
}