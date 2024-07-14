/*
Problem Statement:Sparse Matrix: Write a menu driven C++ program with class for Sparse 
Matrix. Write functions to perform Sparse Matrix operations as listed 
below
1. Read sparse matrix
2. Display sparse matrix
3. Add two sparse matrices
4. Find transpose using Simple transpose algorithm
5. Find transpose using Fast transpose algorithm
Compare complexity of simple and fast transpose using counter.*/
#include<iostream>
using namespace std;
class SparseMatrix{
    int matrix1[100][100],rows,col;
    int sparse[100][3];
    public:
    void getdata();
    void create();
    void display();
    SparseMatrix addition(SparseMatrix);
    void simple_transpose();
    void fast_transpose();
};
void SparseMatrix::getdata(){
    cout<<"Enter the number of rows"<<endl;
    cin>>rows;
    cout<<"Enter the number of columns"<<endl;
    cin>>col;
    cout<<"Enter the elements of sparse matrix"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix1[i][j];
        }
    }

}
void SparseMatrix::create()
{
    int k=1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix1[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=matrix1[i][j];
                k++;
            }
        }
    }
    sparse[0][0]=rows;
    sparse[0][1]=col;
    sparse[0][2]=k-1;

}
void SparseMatrix::display(){
   
    cout<<"\n\tRows Columns Values";
    for(int i=0;i<=sparse[0][2];i++)
    {
        cout<<"\n";
        for(int j=0;j<3;j++)
        {
            cout<<"\t"<<sparse[i][j];
        }
    }

}
void SparseMatrix::simple_transpose()
{
    int transpose[100][3];
    int k = 0;
    for (int z = 0; z <= sparse[0][1]; z++) {
        for (int i = 1; i <= sparse[0][2]; i++) {
            if (sparse[i][1] == z) {
                transpose[k][0] = sparse[i][1];
                transpose[k][1] = sparse[i][0];
                transpose[k][2] = sparse[i][2];
                k++;
            }
        }
    }

    cout<<"\nSimple transpose Result:";
    cout << "\n\tRows Columns Values";
    cout<<"\n\t"<<col<<"\t"<<rows<<"\t"<<k;
    for (int i = 0; i < k; i++) {
        cout << "\n";
        for (int j = 0; j < 3; j++) {
            cout << "\t" << transpose[i][j];
        }
    }
}

void SparseMatrix::fast_transpose()
{
    int loc,i,cols;
    int result[100][3];
    int total[sparse[0][1]],index[sparse[0][1]+1];
    for(i=0;i<sparse[0][1];i++)
    {
        total[i]=0;
    }
    for(i=1;i<=sparse[0][2];i++)
    {
        cols=sparse[i][1];
        total[cols]++;

    }
    index[0]=1;
    for(i=1;i<=sparse[0][1];i++)
    {
        index[i]=index[i-1]+total[i-1];
    }
    result[0][0]=sparse[0][1];
    result[0][1]=sparse[0][0];
    result[0][2]=sparse[0][2];

    for(i=1;i<=sparse[0][2];i++)
    {
        cols=sparse[i][1];
        loc=index[cols];
        result[loc][0]=sparse[i][1];
        result[loc][1]=sparse[i][0];
        result[loc][2]=sparse[i][2];
        index[cols]++;
        
    }
    cout<<"\n\t Fast Transpose Result";
    cout<<"\n\tRows Columns Values";
    for(int i=0;i<=result[0][2];i++)
    {
        cout<<"\n";
        for(int j=0;j<3;j++)
        {
            cout<<"\t"<<result[i][j];
        }
    }
    
}
SparseMatrix SparseMatrix::addition(SparseMatrix s) {
    SparseMatrix obj;
    int i = 1, j = 1, k = 1, m = sparse[0][2], n = s.sparse[0][2];
    obj.sparse[0][0] = sparse[0][0];
    obj.sparse[0][1] = sparse[0][1];
    while (i <= m && j <= n) {
        if (sparse[i][0] == s.sparse[j][0]) {
            if (sparse[i][1] == s.sparse[j][1]) {
                obj.sparse[k][0] = sparse[i][0];
                obj.sparse[k][1] = sparse[i][1];
                obj.sparse[k][2] = sparse[i][2] + s.sparse[j][2];
                i++, j++, k++;
            }
            else if (sparse[i][1] < s.sparse[j][1]) {
                obj.sparse[k][0] = sparse[i][0];
                obj.sparse[k][1] = sparse[i][1];
                obj.sparse[k][2] = sparse[i][2];
                i++, k++;
            }
            else {
                obj.sparse[k][0] = s.sparse[j][0];
                obj.sparse[k][1] = s.sparse[j][1];
                obj.sparse[k][2] = s.sparse[j][2];
                j++, k++;
            }
        }
        else if (sparse[i][0] < s.sparse[j][0]) {
            obj.sparse[k][0] = sparse[i][0];
            obj.sparse[k][1] = sparse[i][1];
            obj.sparse[k][2] = sparse[i][2];
            i++, k++;
        }
        else {
            obj.sparse[k][0] = s.sparse[j][0];
            obj.sparse[k][1] = s.sparse[j][1];
            obj.sparse[k][2] = s.sparse[j][2];
            j++, k++;
        }
    }

    while (i <= m) {
        obj.sparse[k][0] = sparse[i][0];
        obj.sparse[k][1] = sparse[i][1];
        obj.sparse[k][2] = sparse[i][2];
        i++, k++;
    }

    while (j <= n) {
        obj.sparse[k][0] = s.sparse[j][0];
        obj.sparse[k][1] = s.sparse[j][1];
        obj.sparse[k][2] = s.sparse[j][2];
        j++, k++;
    }

    obj.sparse[0][2] = k - 1;
    return obj;
}

    
int main(){
    SparseMatrix mat1,mat2,mat3;
    int op,choice;
    do{
    cout<<"Enter the correct choice:"<<endl;
    cout<<"1.Read matrix\n2.Display Matrix\n3.Simple Transpose\n4.Fast Transpose\n5.Addition of two sparse matrix\n";
    
    cin>>op;
    switch(op){
        case 1:
            cout<<"\nEnter the data for matrix 1:"<<endl;
            mat1.getdata();
            mat1.create();
            cout << "\nEnter data for matrix 2:\n";
            mat2.getdata();
            mat2.create();
            break;
            
        case 2:
            cout<<"\nDisplaying Triplets"<<endl;
            mat1.display();
            cout<<"\nDisplaying Triplets"<<endl;
            mat2.display();
            break;

        case 3:
            cout<<"\n\nSimple Transpose of matrix 1";
            mat1.simple_transpose();
            cout<<"\n\nSimple Transpose of matrix 2";
            mat2.simple_transpose();
            break;

        case 4:
            cout<<"\n\nFast Transpose of matrix 1";
            mat1.fast_transpose();
            cout<<"\n\nFast Transpose of matrix 2";
            mat2.fast_transpose();
            break;

        case 5:
            cout << "\n\nAddition of Sparse Matrix:\n";
            mat3 = mat1.addition(mat2);
            mat3.display();
            break;
    }
    cout<<"\nDo you want to continue 1 for yes and 0 for no"<<endl;
    cin>>choice;
    }while(choice==1);
    
    return 0;
}