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
			if(count[i]==0)
				continue;
			//count[i]=1;
			//cout<<"l "<<level<<endl;
			result[level]=sNew[i];
			count[i]--;
			printAnagrams(sNew,result,count,level+1,n);
			count[i]++;
			//count[i]=0;
		}
	}
}
//calculates count[]
void permute(char *s)
{
	int i,j;
	char *result=new char[strlen(s)];

	//for repeated characters,make a map to remove duplicacy

	map<char,int>myMap;
	map<char,int>::iterator it;
	for(i=0;i<strlen(s);i++)
	{
		it=myMap.find(s[i]);
		if(it!=myMap.end()) //element present,so increment count
			it->second++;
		else //not present?then insert it
			myMap.insert(pair<char,int>(s[i],1));
	}
	int count[myMap.size()];
	char sNew[myMap.size()];
	i=0;
	for(it=myMap.begin();it!=myMap.end();it++)
	{
		//cout<<it->first<<"  "<<it->second<<endl;
		sNew[i]=it->first;
		count[i]=it->second;
		//cout<<count[i]<<endl;
		i++;
	}
	sNew[i]='\0';
	printAnagrams(sNew,result,count,0,strlen(s));
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