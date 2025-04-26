#include<iostream>
#include<fstream>
using namespace std;
class record
{
int rollno;
char name[20];
int marks;
friend class student;
};
class hashing
{
int r,pos;
hashing()
{
r=-1;
pos=-1;
}
friend class student;
};
class student
{
int rel=1;
hashing h[10];
public:
void  create_wor();
void create_wr();
void display();
void retrive();
};
void student::create_wor() {
int loc;
char ch;
record rec;
fstream fout;
fout.open("student1.txt", ios::binary | ios::out);
do {
cout << "enter roll no,name, marks" << endl;
cin >> rec.rollno >> rec.name >> rec.marks;
fout.write((char*)&rec, sizeof(rec));
loc = rec.rollno % 10;
if(h[loc].r==-1)
{
h[loc].r = rec.rollno;
h[loc].pos = rel;
rel++;
}
else
{
for(int i=loc+1; i!=loc; i=(i+1)%10)
{
if(h[i].r==-1)
{
h[i].r = rec.rollno;
h[i].pos = rel;
rel++;
break;
}
}
}
cout << "do you want to add more records" << endl;
cin >> ch;
} while (ch == 'y');
fout.close();
}
void student::create_wr()
{
int loc,newloc,tempr,tempos;
char ch;
record rec;
fstream fout;
fout.open("student1.txt", ios::binary | ios::out);
do {
cout << "enter roll no,name, marks" << endl;
cin >> rec.rollno >> rec.name >> rec.marks;
fout.write((char*)&rec, sizeof(rec));
loc = rec.rollno % 10;
if(h[loc].r==-1)
{
h[loc].r = rec.rollno;
h[loc].pos = rel;
rel++;
}
else
{
   tempr=h[loc].r;
tempos=h[loc].pos;
newloc=tempr%10;
if(loc!=newloc)
{

  for(int i=loc+1; i!=loc; i=(i+1)%10)
{
if(h[i].r==-1)
{
h[i].r=tempr;
h[i].pos=tempos;
rel++;
break;
}
}
}
else
{
    for(int i=loc+1; i!=loc; i=(i+1)%10)
{
if(h[i].r==-1)
{
h[i].r=rec.rollno;
h[i].pos=rel;
rel++;
break;
}
}
}

}
cout << "do you want to add more records" << endl;
cin >> ch;
}
while (ch == 'y');
fout.close();
}
void student::display()
{
record r;
fstream fin;
for(int i=0; i<10; i++)
{
cout<<h[i].r<<" "<<h[i].pos<<endl;
}
cout<<"-------------------------------------------------"<<endl;
fin.open("student1.txt",ios::in);
while(fin.read((char*)&r,sizeof(r)))
{
cout<<r.rollno<<" "<<r.name<<" "<<r.marks<<endl;
}
fin.close();
}
void student::retrive()
{
record rec;
fstream fin;
int roll1,loc,r1;
cout << "enter roll no to be searched" << endl;
cin >>roll1;
fin.open("student1.txt",ios::in);
loc=roll1%10;
for(int i=0; i<10; i++)
{
if(h[loc].r==roll1)
{
r1=(h[loc].pos-1)*sizeof(rec);
fin.seekg(r1,ios::beg);
fin.read((char*)&rec,sizeof(rec));
cout<<rec.rollno<<" "<< rec.name<<" "<<rec.marks;
break;
}
else
{
loc=loc+1;
}
}
fin.close();
}
int main()
{
student s;
s.create_wor();
   s.create_wr();
s.display();
s.retrive();
return 0;
}
