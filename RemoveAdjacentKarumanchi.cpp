#include<iostream>
#include<cstring>
using namespace std;


void removeUtil(char *word,int j,int i,int length)
{
	cout<<"i="<<i<<" j="<<j<<endl;
	if(i>length)
	{
		cout<<"hello "<<word<<endl;
		return;
	}
	while(word[j]==word[i] && j>=0) //cancel identical pairs
	{
			j--;
			i++;
			cout<<"while i="<<i<<" j="<<j<<endl;
	}
	word[++j]=word[i]; //update the word after cancelling
	cout<<word<<endl;
	removeUtil(word,j,i+1,length);
}


void remove(char *word)
{
	int length=strlen(word);
	removeUtil(word,0,1,length);// 0=first letter,1=2nd letter,the 1st two letters will be compared first
}
int main()
{
	char word[100];
	cout<<"Enter your string: ";
	cin>>word;
	remove(word);
	return 0;
}
// qpaaaaadaaaaadprq