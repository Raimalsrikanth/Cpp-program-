#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstlib>
#include<conio.h>
#include<iomanip>
Using namespace std;
int main()
{
FILE*fp,*ft;
Charanother,choice;
Struct student
{
Char first name[50],last name[50];
Char course[100];
int section;
};
Struct student e;
Char x first_name[50],xlast_name[50];
long int recsize;
fp=fopen("users.txt","rb+");
if(fp==Null)
{
fp=fopen("users.txt","wbt");
if(fp==Null)
{
puts("cannot open file");
Return 0;
}
}
Recsize=size of(e);
While(1)
{
System("cls");
Cout<<"\t\t======STUDENT DATABASE MANAGEMENT SYSTEM======
Cout<<"\n\n";
Cout<<"\n\n";
Cout<<"\n\t\t\t1.Add Records";
Cout<<"\n\t\t\t2.List Records";
Cout<<"\n\t\t\t3.Modify Records";
Cout<<"\n\t\t\t4.Delete Records";
Cout<<"\n\t\t\t5.Exit program";
Cout<<"\n\n";
Cout<<"\t\t\t select your choice:->";
fflutch(stdin);
Choice=getche();
Switch(choice)
{
Case'1':
f seek (fp,o,SEEK_END);
another='y';
While(another=='y'||another=='y')
{
System("cls");
Cout<<"Enter the First Name:";
Cin>>e.first_name;
Cout<<"Enter the last Name:";
Cin>>e.last_name;
Cout<<"Enter the course:";
Cin>>e.course;
Cout<<"Enter the section:";
Cin>>e.section;
fwrite(&e,recsize,1,fp);
Cout<<"\n Add another record (Y/N)";
flosh(stdin);
another=getchar();
}
break;
Case'2':
System("cls");
Rewind(fp);
Cout<<"==view the records in the database===";
Cout<<"\n";
While(fread(&e,recsize,1,fp)==1)
{
Cout<<"\n";
Cout<<"\n"<<e.course<<setw(10)<<e.last_name;
}
Cout<<"\n\n";
System("pause");
break;
Case'3':
System("cls");
another='y';
While(another=='y'||another=='y')
{
Cout<<"\n Enter the last name of the students";
Cin>>xlast_name;
Rewind(fp);
While(fread(&e,recsize,1,fp)==1)
{
if(strcmp(e.last_name,xlast_name)==0)
{
Cout<<"Enter new the First Name:";
Cin>>e.First_name;
Cout<<"Enter new the last Name:";
Cin>>e.last_name;
Cout<<"Enter new the course:";
Cin>>e.course;
Cout<<"Enter new the section:";
Cin>>e.section;
fseek(fp,-recsize,SEEK_CUR);
fwrite(&e,recsize,1,fp);
break;
}
else
Cout<<"record not found";
}
Cout<<"\n Modify another record (Y/N)";
flush(stdin);
another=getchar();
}
break;
Case'4':
System("cls");
another='y';
While(another=='y'||another=='y')
{
Cout<<"\n Enter the last name of the student to delete:";
Cin>>xlast_name;
ft=fopen("temp.dat","wb");
Rewind(fp);
While(fread(&e,recsize,1,fp)==1)
if(strcmp(e.last_name,xlast_name)!=0)
{
fwrite(&e,recsize,1,ft);
}
fclose(fp);
fclose(ft);
Remove("users.txt");
Remove("temp.dat","users.txt");
fp=fopen("users.txt","rb+");
Cout<<"\n delete another record (Y/N);
fflush(stdin);
another=getchar();
}
break;
