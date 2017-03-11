#include<iostream>
#include<cstring>
using namespace std;

void reverse(char *word)
{
	if(word==NULL||*word=='\0')
		return;
	int end=strlen(word)-1;
	char temp;
	for(int start=0;start<end;start++)
	{
		if(word[start]==' ')
			continue;
		else
		{
			temp=word[start];
			word[start]=word[end];
			word[end]=temp;
			end--;
		}
	}
}


int main()
{
	char word[100],*w;
	cout<<"Enter word:\n";
	cin>>word;
	reverse(word);
	cout<<"Reversed word: "<<word<<endl;
	return 0;
}