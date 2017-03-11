#include<iostream>
#include<cstring>
#include<climits>
#define MAX 256
using namespace std;

void findMinWindow(char *t,char *p)
{
	int shouldFind[MAX]={0,}; //no of times an element must be found according to the pattern
	int hasFound[MAX]={0,}; // no of times an element is found till now
	int pSize,tSize,i,j,count,minWindowSize,windowSize,first,last;
	
	minWindowSize=INT_MAX;
	
	first=last=0;
	pSize=strlen(p);
	tSize=strlen(t);
	for(i=0;i<pSize;i++) //store the frequency of each element present in the pattern
		shouldFind[p[i]]+=1;
	j=count=0;
	//find the window size
	for(i=0;i<tSize;i++)
	{
		if(shouldFind[t[i]]==0) //element in the text is not present in the pattern
			continue;
		hasFound[t[i]]+=1; //update the no of times an element is found till now
		if(shouldFind[t[i]]>=hasFound[t[i]])
			count++;
		if(count==pSize)
		{
			//check for invalid elements in the window
			while(shouldFind[t[j]]==0||hasFound[t[j]]>shouldFind[t[j]])
			{
				if(hasFound[t[j]]>shouldFind[t[j]])
					hasFound[t[j]]--;
				j++; //shifting the window to skip the ina=valid elements
			}
			windowSize=i-j+1;
			if(minWindowSize>windowSize)
			{
				minWindowSize=windowSize;
				first=j; //starting of the window
				last=i;//end position of the window
			}
		}

	}
	cout<<endl<<"Start: "<<first+1<<" Finish: "<<last+1<<endl;
}


int main()
{
	char s[500],p[500];
	cout<<"Enter your string:"<<endl;
	cin.getline(s,500); // to include spaces
	cout<<"Enter your pattern:\n";
	cin>>p;
	findMinWindow(s,p);
	return 0;
}
