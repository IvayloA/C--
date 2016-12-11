#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
     public:
        string profession;
        int age;

        Person(): profession("unemployed"), age(16) { }
        void display()
        {
             cout << "My profession is: " << profession << endl;
             cout << "My age is: " << age << endl;
             walk();
             talk();
        }
        void walk() { cout << "I can walk." << endl; }
        void talk() { cout << "I can talk." << endl; }

    public: string toString(){
        return profession; }
};

class MathsTeacher : public Person
{
    public:
       void teachMaths() { cout << "I can teach Maths." << endl; }
};

class Footballer : public Person
{
    public:
       void playFootball() { cout << "I can play Football." << endl; }
};

 void writeSomething(Person person){
     person.display();
 }


 void toTxtFile(Person person,string fileName){
    ofstream myFile("person.txt");
        myFile << person.toString();

    myFile.close();
}


int main(){
     MathsTeacher teacher;
     teacher.profession = "Teacher";
     teacher.age = 23;
     writeSomething(teacher);
     teacher.teachMaths();

     Footballer footballer;
     footballer.profession = "Footballer";
     footballer.age = 19;
     writeSomething(footballer);
     footballer.playFootball();


     toTxtFile(teacher,"teacher.txt");
     toTxtFile(footballer,"footballer.txt");

     return 0;
}
