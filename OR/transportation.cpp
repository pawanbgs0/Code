#include<iostream>
using namespace std;

int cost,i,j,row,col,matrix[10][10];
int r=0,c=0,p;
int supply[10],demand[10];
int value[10][10],rpos,cpos,rpre,cpre;
void firstiteration();

int main()
{
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            value[i][j]=0;
        }
    }
    cout<<"Enter the size of the matrix(rows)="<<endl;
    cin>>row;
    cout<<"Enter the size of the matrix(column)="<<endl;
    cin>>col;
    cout<<"Enter the cost matrix="<<endl;
    for(r=0;r<row;r++)
    {
        for(c=0;c<col;c++)
        {
            cin>>matrix[r][c];
        }
    }
  cout<<"Enter the supply="<<endl;
  for(r=0;r<row;r++)
  {
        cin>>supply[r];
  }
  cout<<"Enter the Demand="<<endl;
  for(c=0;c<col;c++)
  {
        cin>>demand[c];
  }
  firstiteration();
 
 }
 void firstiteration()
 {
    c=0;r=0;cost=0;
    do{
        if(demand[c]!=0)
        {
            if(demand[c]<supply[r])
            {
                value[r][c]=demand[c];
                supply[r]-=demand[c];
                demand[c]=0;
                if(c==col-1)
                    c=0;
                else
                    c++;
            }
            else
            {
                if(demand[c]==supply[r])
                {
                    value[r][c]=supply[r];
                    demand[c]=0;
                    supply[r]=0;
                    if(c==col-1)
                        c=0;
                    else
                        c++;
                    if(r==row-1)
                        r=0;
                    else
                        r++;
                }
                else
                {
                    value[r][c]=supply[r];
                    demand[c]-=supply[r];
                    if(r==row-1)
                        r=0;
                    else
                        r++;
                }
            }
        }
        else
        {
            if(c==col-1)
                c=0;
            else
                c++;
        }
    }
        while(demand[col-1]!=0);
        printf("\n");
        for(r=0;r<row;r++)
        {
            for(c=0;c<col;c++)
            {
                printf("\n Value[%d][%d]=%d",r+1,c+1,value[r][c]);
            }
        }


         printf("\n The Transportation Problem \n");
      for(r=0;r<row;r++)
         {
            for(c=0;c<col;c++)
            {
                printf("\t%d",matrix[r][c]);
                //cost+=matrix[r][c]*value[r][c];
            }
         printf("\n");
        }





         printf("\n The Initial Matrix \n");
      for(r=0;r<row;r++)
         {
            for(c=0;c<col;c++)
            {
                printf("\t%d",value[r][c]);
                //cost+=matrix[r][c]*value[r][c];
            }
         printf("\n");
        }
        for(r=0;r<row;r++)
         {
            for(c=0;c<col;c++)
            {
                cost+=matrix[r][c]*value[r][c];
            }
        }
      cout<<cost;
 }