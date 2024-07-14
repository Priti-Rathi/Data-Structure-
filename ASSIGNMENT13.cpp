/*A list of data representing various environmental parameters such as 
temperature, humidity, pollution levels, etc is maintained using appropriate
data structure. Write a C++ program that uses data structures to perform the
following operations:
1. Find the maximum and minimum values of each parameter in the list.
2. Calculate the average value of each parameter in the list.
3. Sort the list in ascending order of any one parameter.
4. Find the highest and lowest values of any one parameter that are
considered safe for the environment.
5. Calculate the impact of the parameter values on the environment based
on certain pre-defined criteria.
6. Analyze the impact of the environmental parameters on the health and
safety of the society.
7. Ensure that the program follows ethical and professional practices, such
as ensuring the privacy and security of the data.
You should implement the program using appropriate data structures that
take into account the size and complexity of the data, and demonstrate an
understanding of the societal and environmental issues related to the data.
Your program should also demonstrate an understanding of the impact of
the parameter values on the environment, and the need for sustainable
development. Finally, your program should adhere to ethical principles and
professional practices, such as ensuring the confidentiality, privacy, and
security of the data*/
#include<iostream>
using namespace std;
#include<string>
class Environmental_p
{
    public:
    int temp[10];
    int humidity[10];
    int p_level[10];
    int i,n;
    Environmental_p()
    {
        cout<<"Enter the number of entries to be taken in the list"<<endl;
        cin>>n;
    }
    void getdata()
    {
        for(i=0;i<n;i++)
        {
        cout<<"Enter the temparature"<<endl;
        cin>>temp[i];
        cout<<"Enter the humidity"<<endl;
        cin>>humidity[i];
        cout<<"Enter the pollution level"<<endl;
        cin>>p_level[i];
        }
    }
    void display()
    {
        for(i=0;i<n;i++)
    {
        cout<<temp[i]<<"\t\t"<<humidity[i]<<"\t\t"<<p_level[i]<<endl;
    }
    }
    int max_temp()
    {
        int max=0;
        for(i=0;i<n;i++)
        {
            if(temp[i]>max)
            {
                max=temp[i];
            }
       
        }
         return max;
    }
    int max_hum()
    {
        int max1=0;
        for(i=0;i<n;i++)
        {
            if(humidity[i]>max1)
            {
                max1=humidity[i];
            }
        }
        return max1;
    }
    int max_pollution()
    {
        int max2=0;
        for(i=0;i<n;i++)
        {
            if(p_level[i]>max2)
            {
                max2=p_level[i];
            }
        }
        return max2;
    }
    int min_temp()
    {
        int min=temp[0];
        for(i=0;i<n;i++)
        {
            if(temp[i]<min)
            {
                min=temp[i];
            }
       
        }
         return min;
    }
    int min_hum()
    {
        int min1=humidity[0];
        for(i=0;i<n;i++)
        {
            if(humidity[i]<min1)
            {
                min1=humidity[i];
            }
        }
        return min1;
    }
    int min_pollution()
    {
        int min2=p_level[0];
        for(i=0;i<n;i++)
        {
            if(p_level[i]<min2)
            {
                min2=p_level[i];
            }
        }
        return min2;
    }
    void average_temp()
    {
        int avg=0;
        for(i=0;i<n;i++)
        {
             avg=avg+temp[i];
        }
        int avg_temp=avg/n;
        cout<<"The average of temperature list is:"<<avg_temp<<endl;
    }
    void average_hum()
    {
        int avg=0;
        for(i=0;i<n;i++)
        {
             avg=avg+humidity[i];
        }
        int avg_hum=avg/n;
        cout<<"The average of temperature list is:"<<avg_hum<<endl;
    }
    void average_level()
    {
        int avg=0;
        for(i=0;i<n;i++)
        {
             avg=avg+p_level[i];
        }
        int avg_pollution=avg/n;
        cout<<"The average of temperature list is:"<<avg_pollution<<endl;
    }
    void bubbleSort_temp()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (temp[j] > temp[j + 1])
                {
                   
                    int tempVal = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = tempVal;
                }
            }
        }
    }
    void bubbleSort_hum()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (humidity[j] > humidity[j + 1])
                {
                    int HumVal;
                    HumVal = humidity[j];
                    humidity[j] = humidity[j + 1];
                    humidity[j + 1] = HumVal;
                }
            }
        }
    }
    void bubbleSort_pol()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (p_level[j] > p_level[j + 1])
                {
                    int polVal;
                    polVal = p_level[j];
                    p_level[j] = p_level[j + 1];
                    p_level[j + 1] = polVal;
                }
            }
        }
    }

};
int main()
{
    Environmental_p e;
    int n,i,ch,op,opt;
    /*In u want to take input from user in main function make sure u use e.n 
    to take input as it is already declared in class*/
    cout<<"Enter your choice"<<endl;
    do{
    cout<<"1.Getdata\n2.display\n3.Maximum of each parameter\n4.Minimum of each parameter\n5.Average of list of each parameter\n6.Bubble sort\n0.Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
    e.getdata();
    break;
    case 2:
    cout<<"Temperature\tHumidity\tPollution level"<<endl;
    e.display();
    break;
    case 3:
    
    do
    {
    cout<<"Enter your choice"<<endl;
    cout<<"1.Temparature\n2.Humidity\n3.Pollution Level\n4.Exit"<<endl;
    cin>>opt;
       switch(opt)
       {
            case 1:
            int maxTemp;
            maxTemp = e.max_temp();
            cout<<"The maximum temperature is:"<<maxTemp<<endl;
            break;
            case 2:
            int maxHumidity;
            maxHumidity=e.max_hum();
            cout<<"The maximum humidity is:"<<maxHumidity<<endl;
            break;
            case 3:
            int maxPollution;
            maxPollution=e.max_pollution();
            cout<<"The maximum pollution leval is:"<<maxPollution<<endl;
            break;
            case 4:
            break;
       }
    }while(opt!=4);
    break;
    case 4:
    do
    {
    cout<<"Enter your choice"<<endl;
    cout<<"1.Temparature\n2.Humidity\n3.Pollution Level\n4.Exit"<<endl;
    cin>>op;
    
       switch(op)
       {
        case 1:
        int minTemp;
        minTemp = e.min_temp();
        cout<<"The minimum temperature is:"<<minTemp<<endl;
        break;
        case 2:
        int minHumidity;
        minHumidity=e.min_hum();
        cout<<"The minimum humidity is:"<<minHumidity<<endl;
        break;
        case 3:
        int minPollution;
        minPollution=e.min_pollution();
        cout<<"The minimum pollution leval is:"<<minPollution<<endl;
        break;
        case 4:
        break;
       } 
    }while(op!=4);
    break;
    case 5:
    e.average_temp();
    e.average_hum();
    e.average_level();
    break;
    case 6:
    e.bubbleSort_temp();
    cout << "List sorted based on temperature in ascending order." << endl;
    //e.display();
    e.bubbleSort_hum();
    cout << "List sorted based on humidity in ascending order." << endl;
    //e.display();
    e.bubbleSort_pol();
    cout << "List sorted based on pollution level in ascending order." << endl;
    e.display();
    break;
     }
    }while(ch!=0);
return 0;
}