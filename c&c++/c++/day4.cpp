#include<iostream>
using namespace std;

class uniData{
    private:
        string name;
        int marks;
        string rollnumber;

    public:
        uniData(string n,int m,string rno){
            if(m>100){
                throw invalid_argument("Marks cannot be greater than 100");
            }
            marks=m;
            name=n;
            rollnumber=rno;
        }
        

        //Set marks
        void setMarks(int m){
            if(m>100){
                throw invalid_argument("Marks cannot be greater than 100");
            }
            marks=m;
        }

        //Get data
        void getData(){
            cout<<"Name: "<<name<<endl;
            cout<<"Marks: "<<marks<<endl;
            cout<<"Roll Number: "<<rollnumber<<endl;
        }
};

// Base class
class Animal {
    public:
        void eat() {
            cout << "This animal is eating" << endl;
        }
};

// Derived class
class Dog : public Animal {
    public:
        void bark() {
            cout << "The dog is barking" << endl;
        }
};

int main(){
    uniData LK("Lakshin",99,"03214813123");
    LK.getData();
    LK.setMarks(55);
    LK.getData();
    Dog myDog;
    myDog.eat();  
    myDog.bark();
    return 0;
}