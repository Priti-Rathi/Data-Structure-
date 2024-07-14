/*Sorting: Write a C++ menu driven program to store the percentage of
marks obtained by the students in an array. Write function for sorting array
of floating point numbers in ascending order using
1. Selection Sort
2. Bubble sort
3. Insertion sort
4. Shell Sort
5. Quick sort
6. Radix sort
7. Display top five scores
Implement 4 methods of sorting. Provide choice to user to take input from
user or using random numbers.
Use Standard Template Library (STL) sort function for above data.*/
#include<iostream>
using namespace std;
class Sorting
{
    public:
    int arr[10],n;
    Sorting()
    {
        cout<<"Enter the number of students whose marks to be stored"<<endl;
        cin>>n;
    }
    void getdata()
    {
        
        cout<<"Enter the scores"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
    void selection_sort(int myarr[])
    {
        for(int i=0;i<n-1;i++)
        {
            int min=i;
            for (int j=i+1;j<n;j++)
            {
                if(myarr[j]<myarr[min])
                {
                    min=j;
                }
            }
            if(min!=i)
            {
                int temp=myarr[min];
                myarr[min]=myarr[i];
                myarr[i]=temp;
            }
            
        }
    }
    void bubble_sort(int myarr[]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < (5 - i - 1); j++) {
      if (myarr[j] > myarr[j + 1]) {
        int temp = myarr[j];
        myarr[j] = myarr[j + 1];
        myarr[j + 1] = temp;
      }
    }
  }
}
void insertion_sort(int myarr[]) {
int key;
  int j = 0;
  for (int i = 1; i < 5; i++) {
    key = myarr[i];
    j = i - 1;
    while (j >= 0 && myarr[j] > key) {
      myarr[j + 1] = myarr[j];
      j = j - 1;
    }
    myarr[j + 1] = key;
  }

}
void shell_sort(int myarr[],int n)
{
int gap;
for(gap=n/2;gap>0;gap/=2)
{
 for(int i=gap;i<n;i+=1)
 {
   int temp=myarr[i];
   int j=0;
   for(j=i;(j>=gap) && (myarr[j-gap]>temp);j-=gap)
   {
     myarr[j]=myarr[j-gap];
     
   }
   myarr[j]=temp;
 }
}
}
int partition(int myarr[],int s,int e)
{
    int pivot=myarr[e];
    int pindex=s;
    for(int i=s;i<e;i++)
    {
        if(myarr[i]<=pivot)
        {
            int temp;
            temp=myarr[i];
            myarr[i]=myarr[pindex];
            myarr[pindex]=temp;
            pindex++;
        }
    }
    int temp;
    temp=myarr[e];
    myarr[e]=myarr[pindex];
    myarr[pindex]=temp;
    return pindex;

}
void quick(int myarr[],int s,int e)
{
    if(s<e)
    {
        int p=partition(myarr,s,e);
        quick(myarr,s,(p-1));
        quick(myarr,(p+1),e);

    }
}
};
int main()
{
    Sorting s;
    int ch;
    do{
    cout<<"\nEnter you choice"<<endl;
    cout<<"1.Selection Sort\n2.Bubble sort\n3.Insertion sort\n4.Shell Sort\n5.Quick sort\n6.Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
        s.getdata();
        cout<<"Unsorted Array"<<endl;
        s.display();
        s.selection_sort(s.arr);
        cout<<"\nSorted Array"<<endl;
        s.display();
        break;
        case 2:
        s.getdata();
        cout<<"Unsorted Array"<<endl;
        s.display();
        s.bubble_sort(s.arr);
        cout<<"\nSorted Array"<<endl;
        s.display();
        break;
        case 3:
        s.getdata();
        cout<<"Unsorted Array"<<endl;
        s.display();
        s.insertion_sort(s.arr);
        cout<<"\nSorted Array"<<endl;
        s.display();
        break;
	case 4:
	s.getdata();
        cout<<"Unsorted Array"<<endl;
        s.display();
        s.shell_sort(s.arr,s.n);
        cout<<"\nSorted Array"<<endl;
        s.display();
        break;

  case 5:
  s.getdata();
  cout<<"Unsorted Array"<<endl;
  s.display();
  s.quick(s.arr,0,(s.n-1));
  cout<<"\nSorted Array"<<endl;
  s.display();

	
    }
    }while(ch!=8);
    return 0;
}