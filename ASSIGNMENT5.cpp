/*Polynomial operations: Write a menu driven C++ program with class for 
single variable polynomial and write functions to perform following 
polynomial operations using arrays 
1. Read polynomial
2. Display polynomial
3. Add two polynomials 
You can try above polynomial operation using Linked list*/
#include <iostream>
#include <cmath>
using namespace std;
class polynomial
{
public:
    int exp[20], coef[20], i, n;
    int result = 0;
    void read()
    {
	cout<<"\nEnter the number of terms"<<endl;
	cin>>n;
        for (i = 0; i <n; i++)
        {
            cout << "Enter Exponent of " << i + 1 << " term" << endl;
            cin >> exp[i];
            cout << "Enter Coefficient of " << i + 1 << " term" << endl;
            cin >> coef[i];
        }
    }
    void display()
    {
    	cout<<"Display of polynomial"<<endl;
        int i;
	    for(i=0;i<n;i++)//iterating loop for total_terms
	   { 
		if(coef[i]<0)
		{
			cout<<"-"<<(-1)*coef[i]<<"x^"<<exp[i];
		}
		else
		{
			cout<<"+"<<coef[i]<<"x^"<<exp[i]; 
    }
       }
    }
    void evaluate(double a)
    {
        for (i = 0; i < n; i++)
        {
            result += (coef[i]) * (pow(a, exp[i]));
        }

        cout << "\nThe evalution of above polynomial is:" << result << endl;
    }
    polynomial add(polynomial ob2)
{
    int i =0, j =0, k = 0;
    polynomial C;
    while ((i<n) && (j<ob2.n))
    {
        if(exp[i] == ob2.exp[j])
        {
            C.coef[k] = coef[i] + ob2.coef[j];
            C.exp[k] = exp[i];
            i++;
            j++;
            k++;
        }
        else if(exp[i] > ob2.exp[j])
        {
            C.coef[k] =coef[i];
            C.exp[k] = exp[i];
            i++;
            k++;
             }
        else
        {
            C.coef[k] = ob2.coef[j];
            C.exp[k] = ob2.exp[j];
            j++; k++;
        }
    } // end of while
    while(i < n)
    {
       C.coef[k] = coef[i];
       C.exp[k] = exp[i];
       i++;
       k++;
    }
     while(j <ob2.n)
    {
          C.coef[k] = ob2.coef[j];
          C.exp[k] = ob2.exp[j];
          j++;
          k++;
    }
    C.n = k;
    return C;
}
    	
    
};

int main()
{
    polynomial ob1,ob2,C;
    int n,i,op,choice;
    double ev;
     do
    {
       cout<<"Enter 1 = to read polynomials \nEnter 2 = to display polynomial\nEnter 3 = to evaluate polynomial\nEnter 4 = to add  two   polynomial\n";
       cin>>op;
       switch(op)
       {
          case 1:   
                ob1.read();
                ob2.read();
                break;
         case 2:ob1.display();
                ob2.display();  
                break;
         case 3: cout << "\nEnter the value of x: ";
    		cin >> ev;
    		cout<<"\nEvaluation of first polynomial:";
    		ob1.evaluate(ev);
    		cout<<"\nEvaluation of second polynomial:";
    		ob2.evaluate(ev);
    		break;
        case 4:C = ob1.add(ob2);
               C.display();  
               break;
        default:cout<<"enter correct choice"<<endl;
                break;
     }
     cout<<"\nDo you want to continue 1 for yes and 0 for no"<<endl;
     cin>>choice;
     }while(choice==1);
     return 0;
     }