#include<iostream>
#include<string>

#ifndef MAX
#define MAX 30
#endif

using namespace std;

class Student{
    
    private:
    
        string Name;
        int Age;
        string Department;
        int Year;

    public:

        void input(string, int, string, int);
        void read();
        void print();
};

void Student::input(string name, int age, string department, int year){

    this->Name       = name;
    this->Age        = age;
    this->Department = department;
    this->Year       = year;
}

void Student::read(){

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
    
    int i;
    for(i=0; i<size-1; i++)
        S[i].read();

    S[i].input("Sriparno Ganguly", 20, "Computer Science and Technology", 2024);
    for(int j=0; j<size; j++)
        S[j].print();
    
    return 0;
}
