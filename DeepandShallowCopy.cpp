#include <bits/stdc++.h>
using namespace std;

class Student{
    int age;
    char *name;

    public:
    Student(int age, char*name){
        this->age = age;
        //shallow copy
        //this->name = name;

        //deep copy

        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    void display(){
        cout<<age<<" "<<name<<" "<<endl;
    }
};

int main() {
    char name[] = "Varun";
    Student s1(20,name);

    s1.display();

    name[0] = 'T';

    Student s2(25,name);

    s2.display();

    s1.display();

    return 0;
}
