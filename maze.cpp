#include<iostream>
#include <memory>
#include <queue>
using namespace std;

int maze[][5]={{1,1,1,0,0},
               {0,1,0,0,0},
			   {1,1,1,0,0},
			   {0,1,1,1,1}
              };

int m[][5]= {{0,0,0,0,0},
             {0,0,0,0,0},
			 {0,0,0,0,0},
			 {0,0,0,0,0}
            };

typedef struct position{
	int x;
	int y;
} pos;

std::queue<pos> q;

 int row=4;
 int col=5;
 
int ifsafe(int x,int y)
{
	if(x>=0 && x<row && y>=0 && y<col && maze[x][y]==1)
		return 1;
	return 0;

}

void findpath(int row,int col){	
	pos startpoint;
	startpoint.x=0;
	startpoint.y=0;
	q.push(startpoint);	
	
	while(!q.empty())
	{
		int i=q.front().x;
		int j=q.front().y;
		q.pop();
		bool path=false;
		if(maze[i][j]==1)
		{
			
			maze[i][j]= 0;			
			pos p;	
			if(ifsafe(i+1,j))		
			{			
				p.x=i+1;
				p.y=j;
				q.push(p);
                path=true;
			}
			if(ifsafe(i,j+1))		
			{			
				p.x=i;
				p.y=j+1;
				q.push(p);
				path=true;
			}
			if(ifsafe(i,j-1))		
			{			
				p.x=i;
				p.y=j-1;
				q.push(p);
				path=true;
			}

			if(path){
				m[i][j]= 1 ;			
				path=false;
			}

		}

	}
		
		
}


int main(){
	findpath(3,4);


	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			cout<<m[i][j]<<" "; 
		}
		cout<<endl;
	}
cout<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			cout<<maze[i][j]<<" "; 
		}
		cout<<endl;
	}

}


