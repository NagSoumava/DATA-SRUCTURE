#include<iostream>
#include<cstring>
#define ROW 5
#define COL 6
using namespace std;


//(x,y)=used in the matrix and level=current index of the pattern matched
int findPatternUtil(char matrix[ROW][COL],int used[ROW][COL],char *P,int x,int y,int level)
{
	if(level==strlen(P)) //pattern matched
	{
		return 1;
	}
	if(x==ROW||y==COL)
		return 0;
	if(used[x][y]==1) //used cell,so skip this
		return 0;


	//considering the the 1st row elements for which 8-point Bresenham cannot be applied
	//as they donot have 8 neighbours
	if(matrix[x][y]!=P[level] && level==0)
	{
		if(x<(ROW-1))
			return findPatternUtil(matrix,used,P,x+1,y,0);
		else if(y<(COL-2))
			return findPatternUtil(matrix,used,P,0,y+1,0);
		else
			return 0; //false
	}


	else if(matrix[x][y]==P[level]) //match found,check its 8 neighbours
	{
		used[x][y]=1; //mark this cell as used
		int res;
		res=((x>0)?findPatternUtil(matrix,used,P,x-1,y,level+1):0)||
			(res=(x<(ROW-1))?findPatternUtil(matrix,used,P,x+1,y,level+1):0)||
			(res=(y>0)?findPatternUtil(matrix,used,P,x,y-1,level+1):0)||
			(res=(y<(COL-2))?findPatternUtil(matrix,used,P,x,y+1,level+1):0)||
			(res=(x>0&&y>0)?findPatternUtil(matrix,used,P,x-1,y-1,level+1):0)||
			(res=(x>0&&y<(COL-2))?findPatternUtil(matrix,used,P,x-1,y+1,level+1):0)||
			(res=(x<(ROW-1)&&y>0)?findPatternUtil(matrix,used,P,x+1,y-1,level+1):0)||
			(res=(x<(ROW-1)&&y<(COL-2))?findPatternUtil(matrix,used,P,x+1,y+1,level+1):0);
		used[x][y]=0; //mark this cell as unused
		return res;
	}
	else 
		return 0;
}



int findPattern(char matrix[ROW][COL],char *P)
{
	int used[ROW][COL]={{0,},}; //initialising by zeroes
	return findPatternUtil(matrix,used,P,0,0,0);
}


//driver program
int main()
{
	int isPresent;
	char pattern[ROW*COL];
	char matrix[ROW][COL]={"ACPRC",
							"XSOPC",
							"VOVNI",
							"WGFMN",
							"QATIT"};
	cout<<"Enter pattern:";
	cin>>pattern;						
	isPresent=findPattern(matrix,pattern);
	if(isPresent)
		cout<<"Pattern is present\n";
	else
		cout<<"Pattern is not present\n";
	return 0;
}