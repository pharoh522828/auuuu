#include<iostream>
using namespace std;

int h=0;
int h2=0;

    
    int soln[4][4]={
        {0,1,0,0},
        {0,0,0,1},
        {1,0,0,0},
        {0,0,1,0}
    };
    
    int output1[4][4]={0};

void print(int board[4][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    
    
    
    //copy paste values
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
           output1[i][j]=board[i][j];
        }
        cout<<endl;
    }
    
}

bool isValid(int board[4][4],int row,int col){
    
    for(int i=0;i<col;i++)
    {
        if(board[row][i]==1)
        {
            return false;
        }
    }
    
    
    for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    
    
    for(int i=row+1, j=col-1;i<4 && j>=0 ;i++,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    
    return true;
}


void placeQueen(int board[4][4],int col)
{
    if(col==4)
    {
        
        

        
    
        print(board);
        
        
        
    }
    
    for(int i=0;i<4;i++)
    {
        if(isValid(board,i,col))
        {
            board[i][col]=1;
            
            placeQueen(board,col+1);
            board[i][col]=0;
            
        }
    }
}

int main(){
    int board[4][4]={0};
    cout<<"Initailly"<<endl;

    
    cout<<"Heuristic=No of misplaced queens"<<endl;
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[i][j]!=soln[i][j])
            {
                h=h+1;
            }
        }
    }
    cout<<"Initial heuristic="<<h<<endl;
    
    print(board);
    placeQueen(board,0);
    
    
    cout<<"----CALCULATING HEURISTIC FOR FRST SOLN"<<endl;
        for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(soln[i][j]!=output1[i][j])
            {
                h2=h2+1;
            }
        }
    }

    
    cout<<"HEURISTIC FOR SECOND SOLN----->"<<h2<<endl;
    cout<<"DONE"<<endl;
    
}
