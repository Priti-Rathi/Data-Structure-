/*Write a menu driven C++ program to store sets for students names participating in different events in eguinox such as coding contest ,Project competition,Paper presentation,Master Mind etc.
1.Fint out students who have participated in coding and project both.
2.Find out participants who have participated in coding or project competition or both or mastermind
3.Find out participants who have participated in Coding but not in master mind
4.Find out participants who have participated in all events*/
  #include<iostream>
  using namespace std;
  
  class Student{
  public:
  char name[20];
  int p,i,op,ch;
  void getdata(){
  cout<<"Enter the name of student"<<endl;
  cin>>name;
  do{
  cout<<"Enter the event in which student is participating"<<endl;
  cout<<"1.Coding\n2.Project\n3.master mind\n4.All"<<endl;
  cin>>p;
  cout<<"\nHave you participated in any other event:(1 for yes,0 for No)"<<endl;
  cin>>ch;
  }while(ch==1);
  }
  };
  int main(){
  Student s[20];
  int i,n,op,res,chh;
  cout<<"Enter the number of students:"<<endl; 
  cin>>n;
  for(i=0;i<n;i++)
  {
  s[i].getdata();
  }
  do{
  cout<<"Enter the event whose participants is to be find"<<endl;
  cout<<"1.Coding and Project\n2.Coding or Project or Master mind\n3.Coding but not mastermind\n4.All"<<endl;
  cin>>op;
  
  switch (op){
  case 1:
{
    cout << "Students who participated in Coding and Project:" << endl;
    for (i = 0; i < n; i++) {
        if (s[i].p == 1 || s[i].p == 2||s[i].p==4) {
            cout <<endl<< s[i].name;
        }
    }
    break;
}

  case 2:
  {
  for(i=0;i<n;i++){
  if(s[i].p==1||s[i].p==2||s[i].p==3||s[i].p==4){
  cout<<endl<<s[i].name;
  }
  }
  break;
  }
  case 3:
  {
  for(i=0;i<n;i++){
  if(s[i].p==1||s[i].p!=3||s[i].p!=4){
  cout<<endl<<s[i].name;
  }
  }
  break;
  }
  case 4:
  {
  for(i=0;i<n;i++){
  if(s[i].p==4){
  cout<<endl<<s[i].name;
  }
  }
  break;
  }
  }
  cout<<"\nDo you want to find of any other event:(1 for yes,0 for No)"<<endl;
  cin>>chh;
  }while(chh==1);
  return 0;
  }