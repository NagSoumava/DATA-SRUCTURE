/* lexicographical order and distinct permutations */

#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

void printAnagrams(char *sNew,char *result,int count[],int level,int n)//n=original length of inputted string
{
	//cout<<"l= "<<strlen(result)<<endl;
	if(level==n)
	{
		result[level]='\0';
		cout<<result<<endl;
		return;
	}
	else
	{
		for(int i=0;i<strlen(sNew);i++)
		{
			if(count[i]==1)
				continue;
			else
			{
				count[i]=1;
				result[level]=sNew[i];
				printAnagrams(sNew,result,count,level+1,n);
				count[i]=0;	
			}
			
		}
	}
}
//calculates count[]
void permute(char *s)
{
	int i,j;
	char *result=new char[strlen(s)];
	int *count=new int[strlen(s)];
	for(i=0;i<strlen(s);i++)
		count[i]=0;
	//for repeated characters,make a map to remove duplicacy

	printAnagrams(s,result,count,0,strlen(s));
}	

//driver program
int main()
{
	char word[50];
	cout<<"Enter your string:";
	cin>>word;
	sort(word,word+strlen(word)); //to sort the anagrams lexicographically
	permute(word);
	return 0;
}