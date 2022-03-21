#include<iostream>
#include<string>

#ifndef MAX
#define MAX 30
#endif

using namespace std;

class Student{
    
    protected:
    
        string Name;
        int Age;
        string Department;
        int Year;

    public:

        Student(string, int, string, int);
        Student();
        void print();
};

Student::Student(string name, int age, string department, int year){

    this->Name       = name;
    this->Age        = age;
    this->Department = department;
    this->Year       = year;
}

Student::Student(){

    cin.clear();
    cout<<"Enter Name : ";
    getline(cin>>ws,Name);
    cout<<"Enter Age : ";
    cin>>ws>>Age;
    cout<<"Enter Department : ";
    getline(cin>>ws,Department);
    cout<<"Enter Year : ";
    cin>>Year;

    cout<<endl;
}

void Student::print(){

    cout<<"Name         : "<<this->Name<<endl;
    cout<<"Age          : "<<this->Age<<endl;
    cout<<"Department   : "<<this->Department<<endl;
    cout<<"Year         : "<<this->Year<<endl;
    cout<<endl;
}

int main()
{
    Student S[MAX];
    
    int size;
    cout<<"Enter the size of student array ?"<<endl;
    cin>> size;

    for(int i=0; i<size; i++)
        S[i]; 

    for(int j=0; j<size; j++)
        S[j].print();      
}