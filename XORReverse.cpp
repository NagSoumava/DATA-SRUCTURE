#include<iostream>
#include<cstring>
using namespace std;

void reverse(char *word)
{
	if(word==NULL||*word=='\0')
		return;
	int end=strlen(word)-1;
	for(int start=0;start<end;start++)
	{
		if(word[start]==' ')
			continue;
		else
		{
			word[start]^=word[end];
			word[end]^=word[start];
			word[start]^=word[end];
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