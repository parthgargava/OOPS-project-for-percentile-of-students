# include<conio.h>
# include<stdio.h>
# include<string.h>
# include<iostream>
using namespace std;
class TOTAL;
class INTERNAL
{
protected:
int sub1,sub2,sub3;
public:
INTERNAL()
{
sub1=sub2=sub3=0;
}
void GET_INT();
void PUT_INT();
};

void INTERNAL::GET_INT()
{
cout<<"\nENTER THE INTERNAL MARKS : ";
cout<<"\nOOPS : ";
cin>>sub1;
cout<<"DS : ";
cin>>sub2;
cout<<"DBMS : ";
cin>>sub3;
}

void INTERNAL::PUT_INT()
{
cout<<"\n\n INTERNAL MARKS : ";
cout<<"\nOOPS : "<<sub1;
cout<<"\nDS : "<<sub2;
cout<<"\nDBMS : "<<sub3;
}


class EXTERNAL
{
protected:
int m1,m2,m3;
public:
EXTERNAL()
{
m1=m2=m3=0;
}
void GET_EXT();
void PUT_EXT();
};

void EXTERNAL::GET_EXT()
{
cout<<"\nENTER THE EXTERNAL MARKS : ";
cout<<"\nOOPS : ";
cin>>m1;
cout<<"DS : ";
cin>>m2;
cout<<"DBMS : ";
cin>>m3;
}

void EXTERNAL::PUT_EXT()
{
cout<<"\n\n INTERNAL MARKS : ";
cout<<"\nOOPS : "<<m1;
cout<<"\nDS : "<<m2;
cout<<"\nDBMS : "<<m3;
}

class TOTAL:public INTERNAL,public EXTERNAL
{
protected:
int total;
public:
TOTAL()
{
total=0;
}
void GET_DATA();
int GET_TOTAL();
};

void TOTAL::GET_DATA()
{
GET_INT(); GET_EXT();
}

int TOTAL::GET_TOTAL()
{
int total1,total2;
total1=(sub1+sub2+sub3);
total2=(m1+m2+m3);
return (total1+total2);
}

class person
{
char name[50];
int age;
char DOB[10];
public:
person()
{
age=0;
DOB[0]='\0';
}
void IN();
void OUT();
};
void person::IN()
{
cout<<"Enter PRESONAL details of the Student. . . "<<endl;
cout<<"Enter the Name : ";
cin>>name;
cout<<"Enter the age : ";
cin>>age;
cout<<"enter the date of birth: ";
cin>>DOB;
}

void person::OUT()
{
cout<<"\nName: ";
cout<<name;
cout<<"\nAge : "<<age;
cout<<"\n date of birth: "<<DOB;
}

class STUDENT :public person
{
public:
int roll;
int marks;
public:
STUDENT()
{
roll=0;
}
void INPUT();
void OUTPUT();
};

void STUDENT::INPUT()
{
//IN();
cout<<"Enter details. . . "<<endl;
cout<<"\nEnter the Roll. No. : ";
cin>>roll;
TOTAL t;
t.GET_DATA();
marks=t.GET_TOTAL();
}

void STUDENT::OUTPUT()
{
cout<<"\n\nPRESONAL details. . . ";
cout<<"\nRoll. No.: "<<roll;
OUT();
}


class batch
{
int n;
public:
batch()
{
    n=0;
}
batch(int n)
{
STUDENT ob[n];
for(int k=0;k<n;k++)
{
    ob[k].INPUT();
}
sort(ob,n);
int ran=rank(ob);
percentile(ran);
}
void get();
void sort(STUDENT ob[],int n);
int rank(STUDENT ob[]);
void percentile(int x);
};
void batch::get()
{
cout<<"enter the number of students : "<<endl;
cin>>n;
batch c(n);
}
void batch::sort(STUDENT ob[],int n)
{
int i;
int j;
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(ob[j].marks<ob[j+1].marks)
{
swap(ob[j].roll,ob[j+1].roll);
swap(ob[j].marks,ob[j+1].marks);
}
}
}
}
int batch::rank(STUDENT ob[])
{
    int i;
    int id;
    int x;
    cout<<"enter the ROLL NO. for PERCENTILE CALCULATION : "<<endl;
    cin>>id;
    for(i=0;i<n;i++)
    {
    if(ob[i].roll==id)
    {
    x=ob[i].marks;
    break;
    }
    }
    return (i);
}
void batch::percentile(int x)
{
float p=((n-x)/n)*100;
cout<<"The Percentile is : "<<p<<endl;
}
void swap(int x,int y)
{
int tmp;
if(x<y)
{
    tmp=x;
    x=y;
    y=tmp;
}
}
int main()
{
int id;
batch b;
b.get();
return 0;
}
