#include<iostream>
#include<cstring>
using namespace std;

void printkLengthWords(char *word,char *op,int k,int level)
{
	if(k==0)
	{
		op[level]='\0';
		cout<<op<<endl;
		return;
	}
	for(int i=0;i<strlen(word);i++)
	{
		op[level]=word[i];
		printkLengthWords(word,op,k-1,level+1);
	}
}

int main()
{
	char word[50],op[50];
	int k;
	cout<<"Enter word: ";
	cin>>word;
	cout<<"Enter value of k: ";
	cin>>k;
	printkLengthWords(word,op,k,0);
	return 0;
}