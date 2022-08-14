#include <bits/stdc++.h>

#define MAX 10
 
using namespace std;
enum boolean{FALSE,TRUE};
 
class vam{
    int data[MAX][MAX];
    int req[MAX];
    int cpcty[MAX];
    int allocation[MAX][MAX];
    int row,col,n_allo;
    public:
        vam(){
            for(int i=0;i<MAX;i++){
                cpcty[i]=0;
                req[i]=0;
                for(int j=0;j<MAX;j++){
                    data[i][j]=0;
                    allocation[i][j]=0;
                }
            }
            row=col=n_allo=0;
        }
        void setColumn(int no){col=no;};
        void setRow(int no){row=no;}
        void getData();
        void getCapacity();
        void getRequiredValue();
        void makeAllocation();
        boolean checkValue(int [],int);
        int getMinVal(int [],int);
        int getTotalMinVal(int [],int,int);
        int getMinValsPos(int,int [],int);
        void display();
        int getPanalty(int [],int);
};
int vam::getPanalty(int array[],int no){
    int i,j,temp;
    for(i=0;i<no;i++)
        for(j=i+1;j<no;j++)
            if(array[i]>array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
    return array[1]-array[0];
}
int vam::getMinVal(int array[],int no){
    int min=array[0];
    for(int i=0;i<no;i++)
        if(array[i]<min)
            min=array[i];
    return min;
}
int vam::getMinValsPos(int value,int temp_data[],int no){
    int k=0;
    for(int i=0;i<no;i++)
        if(temp_data[i]==value)
            return i;
    return -1;
}
int vam::getTotalMinVal(int array[],int n,int value){
    int no=0;
    for(int i=0;i<n;i++)
        if(array[i]==value)
                no++;
    return no;
}
boolean vam::checkValue(int arr[],int no){
    for(int i=0;i<no;i++)
        if(arr[i]!=0)
            return FALSE;
    return TRUE;
}
void arrayCopy(int start,int end,int array1[],int start1,int array2[]){
    for(int i=start,j=start1;i<end;i++,j++)
        array2[j]=array1[i];
}
int getTotal(int array[],int no){
    int sum=0;
    for(int i=0;i<no;i++)
        sum+=array[i];
    return sum;
}
void copy2DArray(int startRow,int startCol,int endRow,int endCol,int array[][MAX],int start1Row,int start1Col,int ans[][MAX]){
    for(int i=startRow,k=start1Row;i<endRow;i++,k++)
        for(int j=startCol,l=start1Col;j<endCol;j++,l++)
            ans[k][l]=array[i][j];
}
int getMaxVal(int array[MAX],int no){
    int max=0;
    for(int i=0;i<no;i++)
        if(array[i]>max)
            max=array[i];
    return max;
}
int getMaxValPos(int array[MAX],int no,int value){
    for(int i=0;i<no;i++)
        if(value==array[i])
            return i;
    return -1;
}
void vam::makeAllocation(){
    int i=0,j=0,min,total_min;
    int temp_req[MAX]={0};
    int temp_cpcty[MAX]={0};
    int temp_data[MAX][MAX]={0};
    int position[MAX]={0};
    int dataPos[MAX]={0};
    int sum_of_cap,sum_of_req;
    sum_of_cap=getTotal(cpcty,row);
    sum_of_req=getTotal(req,col);
    if(sum_of_cap!=sum_of_req){
        if(sum_of_cap>sum_of_req){
            for(j=0;j<row;j++)
                data[j][col]=0;
            req[col]=sum_of_cap-sum_of_req;
            col++;
        }
        else{
            for(j=0;j<col;j++)
                data[row][j]=0;
            cpcty[row]=sum_of_req-sum_of_cap;
            row++;
        }
    }
    i=j=0;
    arrayCopy(0,row,cpcty,0,temp_cpcty);
    arrayCopy(0,col,req,0,temp_req);
    copy2DArray(0,0,row,col,data,0,0,temp_data);
    int rowPanalty[MAX]={0};
    int colPanalty[MAX]={0};
    int panaltyData[MAX]={0},n=0;
    while(!checkValue(temp_cpcty,row) || !checkValue(temp_req,col)){
 
        for(i=0;i<row;i++){
            arrayCopy(0,col,temp_data[i],0,panaltyData);
            if(temp_cpcty[i]!=0)
                rowPanalty[i]=getPanalty(panaltyData,col);
            else
                rowPanalty[i]=0;
        }
        for(i=0;i<col;i++){
            for(j=0;j<row;j++)
                panaltyData[j]=temp_data[j][i];
            if(req[i]!=0)
                colPanalty[i]=getPanalty(panaltyData,row);
            else
                colPanalty[i]=0;
        }
        int maxRowPanalty=getMaxVal(rowPanalty,row);
        int maxColPanalty=getMaxVal(colPanalty,col);
        int maxPanRow[MAX]={0};
        int maxPanCol[MAX]={0};
        if(maxRowPanalty>maxColPanalty){
            i=getMaxValPos(rowPanalty,row,maxRowPanalty);
            for(j=0;j<col;j++)
                maxPanRow[j]=temp_data[i][j];
            min=getMinVal(maxPanRow,col);
            j=getMinValsPos(min,maxPanRow,col);
        }
        else{
            j=getMaxValPos(colPanalty,col,maxColPanalty);
            for(i=0;i<row;i++)
                maxPanCol[i]=temp_data[i][j];
            min=getMinVal(maxPanCol,row);
            i=getMinValsPos(min,maxPanCol,row);
        }
 
        if(temp_cpcty[i]>temp_req[j]){
            allocation[i][j]=temp_req[j];
            for(int k=0;k<row;k++)
                temp_data[k][j]=9999;
            temp_cpcty[i]-=temp_req[j];
            temp_req[j]=0;
        }
        else if(temp_cpcty[i]<temp_req[j]){
            allocation[i][j]=temp_cpcty[i];
            for(int k=0;k<col;k++)
                temp_data[i][k]=9999;
            temp_req[j]-=temp_cpcty[i];
            temp_cpcty[i]=0;
        }
        else{
            int k;
            allocation[i][j]=temp_cpcty[i];
            for(k=0;k<row;k++)
                temp_data[k][j]=9999;
            for(k=0;k<col;k++)
                temp_data[i][k]=9999;
            temp_req[j]=temp_cpcty[i]=0;
        }
        n++;
    }
    n_allo=n;
}
void vam::getCapacity(){
    cout<<"enter capacity for each source : \n";
    for(int i=0;i<row;i++){
        cout<<"s"<<i+1<<" : ";
        cin>>cpcty[i];
    }
}
void vam::getRequiredValue(){
    cout<<"enter required unit value for each destination : \n";
    for(int i=0;i<col;i++){
        cout<<"d"<<i+1<<" : ";
        cin>>req[i];
 
    }
}
void vam::display(){
    int i;
    cout<<"\ngiven data :\n";
    cout<<setw(9);
    for(i=0;i<col;i++)
        cout<<"D"<<i+1<<setw(4);
    cout<<setw(5)<<"cap"<<endl<<setw(0);
    for(i=0;i<row;i++){
        cout<<setw(3)<<"S"<<i+1;
        for(int j=0;j<col;j++)
            cout<<setw(5)<<data[i][j];
        cout<<setw(5)<<cpcty[i]<<endl;
    }
    cout<<setw(4)<<"req";
    for(i=0;i<col;i++)
        cout<<setw(5)<<req[i];
 
    cout<<"\n\n after allocation :\n";
    for(i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(allocation[i][j]!=0)
                cout<<setw(5)<<data[i][j]<<"*"<<setw(2)<<allocation[i][j];
            else
                cout<<setw(8)<<data[i][j];
        }
        cout<<endl;
    }
    int k=0,sum=0;
    for(i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(allocation[i][j]!=0){
                cout<<"("<<data[i][j]<<" * "<<allocation[i][j]<<")";
                if(k<n_allo-1){
                    cout<<"+";
                    k++;
                }
                sum+=data[i][j]*allocation[i][j];
            }
        }
    }
    cout<<"\nanswer : "<<sum;
    if((row+col-1)==n_allo){
        cout<<"\nhere "<<row<<"+"<<col<<"-1 ="<<n_allo<<" no. of allocations";
        cout<<"\n so this problem is non-degenarated solution";
    }
    else{
        cout<<"\nhere "<<row<<"+"<<col<<"-1 !="<<n_allo<<"no of allocations";
        cout<<"\n so this problem is degenarated solution";
    }
}
void vam::getData(){
    cout<<"enter source to destination data:"<<endl;
    for(int i=0;i<row;i++){
        cout<<"enter "<<i<<"th row : ";
        for(int j=0;j<col;j++){
            cin>>data[i][j];
        }
    }
}
 main()
{
    vam v;
    int r,c;
    cout<<"enter no of Rows : ";
    cin>>r;
    cout<<"enter no of columns : ";
    cin>>c;
 
    v.setColumn(c);
    v.setRow(r);
    v.getData();
    v.getCapacity();
    v.getRequiredValue();
    
    v.makeAllocation();
    v.display();
   
} 

