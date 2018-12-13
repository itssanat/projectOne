#include<stdio.h>
#define M 5 // for rows 
#define N 6 // for colomn 
int stack[100][2];
int top = -1;
int last = -1;
int solveMazeUtil(int maze[N][N], int x, int y, int u,int v,int px,int py);

void printSolution()
{
    int i;
    for (i = 0; i <= top; i++)
        printf("(%d,%d)-->",stack[i][0],stack[i][1]);
    printf("\n");
}

int isSafe(int maze[M][N], int x, int y)
{
   if(x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1)
       return 1;
   return 0;
}

void solveMaze(int maze[M][N],int s,int t,int u,int v)
{
    printf("in solvemaze\n"); ////
    if(solveMazeUtil(maze, s, t, u,v,-2,-2) == 0)
        printf("Solution doesn't exist");
    else{
        printf("there exist a path...\n");
        printSolution();
    }
}

int solveMazeUtil(int maze[N][N], int x, int y,int u,int v,int px,int py)
{
    if(x == u && y == v)
    {
        top++;
        stack[top][0] = x;
        stack[top][1] = y;
        return 1;
    }
    if(isSafe(maze, x, y) == 1)
    {
        top++;
        stack[top][0] = x;
        stack[top][1] = y;
        if ((px!=x+1 || py!=y) && solveMazeUtil(maze, x+1, y,u,v,x,y) == 1){ 
            return 1;
        }
        if ((px!=x-1 || py!=y) && solveMazeUtil(maze, x-1, y,u,v,x,y) == 1){ 
            return 1;
        }
        if ((px!=x || py!= y+1) && solveMazeUtil(maze, x, y+1, u,v,x,y) == 1){ 
            return 1;
        }
        if ((px!=x || py!=y-1) && solveMazeUtil(maze, x, y-1, u,v,x,y) == 1){ 
            return 1;
        }
        top--;
        return 0;
    }   
    return 0;
}

int main()
{
    int maze[M][N]  =  { 
        {1,1,0,0,0,1},
        {1,1,1,1,1,1},
        {1,1,0,0,0,1},
        {0,0,0,0,1,1},
        {1,1,1,1,1,0}
    };
    solveMaze(maze,1,2,3,4);
    return 0;
}