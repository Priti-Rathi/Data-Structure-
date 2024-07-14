/*Searching: Write a C++ program to store roll numbers of students in an 
array who attended online lectures in random order. Write function for 
searching, whether a particular student attended lecture or not using 
1. Linear search 
2. Binary search 
3. Jump search 
compare the searching methods based on complexities of an algorithm
Provide choice to user to take input from user or using random numbers
Use Visual C++ compiler to compile and execute the program.*/
#include<iostream>
using namespace std;
void sequential_search(int n,int a[],int num)
{
    int temp=-1;
    for(int i=0;i<n;i++)
    {
    if(a[i]==num)
    {
        cout<<"The number "<<num<<" found at "<<i+1<<" location"<<endl;
        temp=0;
    }
    }
    if(temp==-1)
    {
        cout<<"Element not found"<<endl;
    }
}
int binary_search(int n,int a[],int num)
{
    int flag=0,low=0,high=n-1;
    int middle,position;
    while(low<=high)
    {
        middle=(low+high)/2;
        if(a[middle]==num)
        {
            position=middle;
            flag=1;
            break;
        }
        else if(a[middle]>num)
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }
    if(flag==1)
    {
        cout<<"The number "<<num<<" found at location "<<position+1<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
        position=-1;
    }
    return position;
}
void jump_search(int n, int arr[], int num) {
    int m;
    cout << "Enter the jump value" << endl;
    cin >> m;

    int i = 0;
    int temp = -1;
    while (i < n) {
        if (arr[i] == num) {
            cout << "The number " << num << " found at " << i + 1 << " location" << endl;
            temp = 0; 
            break;   
        } else if (arr[i] > num) {
            for (int j = i - m; j < i; j++) {
                if (j >= 0 && arr[j] == num) {
                    cout << "The number " << num << " found at " << j + 1 << " location" << endl;
                    temp = 0;
                }
            }
            break;
        } else {
            i += m;
        }
    }

    if (temp == -1) {
        cout << "Element not found" << endl;
    }
}

    
int main()
{
    int no,arr[100],value,output,ch;
    cout<<"Enter the number of elements you want to take input"<<endl;
    cin>>no;
    do
    {
    cout<<"Enter your choice"<<endl;
    cout<<"1.Sequential Search\n2.Binary Search\n3.Jump Search\n4.Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
    cout<<"Enter "<<no<<" elements in random order"<<endl;
    for(int i=0;i<no;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number to be searched"<<endl;
    cin>>value;
    sequential_search(no,arr,value);
    break;


    case 2:
    cout<<"Enter "<<no<<" elements in ascending order"<<endl;
    for(int i=0;i<no;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number to be searched"<<endl;
    cin>>value;
    binary_search(no,arr,value);
    break;
    case 3:
    cout<<"Enter "<<no<<" elements in ascending order"<<endl;
    for(int i=0;i<no;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number to be searched"<<endl;
    cin>>value;
    jump_search(no,arr,value);
    break;
    case 4:
    break;

    }
    }while(ch!=4);
return 0;
}