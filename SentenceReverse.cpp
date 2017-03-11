#include<iostream>
#include<cstring>
using namespace std;


void reverseWord(char *s,int start,int end)
{
	while(start<end)
	{
		char temp=s[start];
		s[start]=s[end];
		s[end]=temp;
		start++;
		end--;
	}
	//cout<<"out"<<endl;
}


//abcd abcd
void reverse(char *s)
{
	//cout<<s<<endl;
	int end,wordStart,wordEnd;
	end=strlen(s)-1;
	wordStart=wordEnd=0;
	while(wordEnd<=end)
	{
		if(s[wordEnd]!=' ')  //ignores leading spaces
		{
			while(s[wordEnd]!=' '&&wordEnd<=end)
			{
				wordEnd++;
				//cout<<s[start];
			}
			reverseWord(s,wordStart,wordEnd-1); //reverse the word
		}
			wordEnd++;
			wordStart=wordEnd;
	}
	reverseWord(s,0,end); //reverse the string of the reversed words which will indirectly reverse the inputted sentence
	cout<<"Reversed sentence: "<<s<<endl;
}

int main()
{
	char s[100];
	cout<<"Enter your sentence: ";
	cin.getline(s,100);
	//cout<<s<<endl;
	reverse(s);
	return 0;
}