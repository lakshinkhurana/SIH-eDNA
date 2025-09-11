#include<iostream>
using namespace std;

class Staff {
private:
    int Staff_id;
    char name[30];

public:
    void getDetails() {
        cout << "Enter Name and ID: " << endl;
        cin.ignore(); // Clear input buffer
        cin.getline(name, 30); // Specify the maximum size for safety
        cin >> Staff_id;
    }

    void showDetails() const {
        cout << "Name: " << name << endl;
        cout << "Staff ID: " << Staff_id << endl;
    }
};

class Teacher : public Staff {
private:
    char Subject[30];
    char Class[30];

public:
    void getClass() {
        cout << "Enter Subject and Class: " << endl;
        cin.ignore(); // Clear input buffer
        cin.getline(Subject, 30);
        cin.getline(Class, 30);
    }

    void showClass() const {
        cout << "Subject: " << Subject << endl;
        cout << "Class: " << Class << endl;
    }
};

class Officer : public Staff {
private:
    int grade;

public:
    void getGrade() {
        cout << "Enter Grade: " << endl;
        cin >> grade;
    }

    void showGrade() const {
        cout << "Grade: " << grade << endl;
    }
};

class Typist : public Staff {
private:
    int speed;

public:
    void getSpeed() {
        cout << "Enter Typing Speed: " << endl;
        cin >> speed;
    }

    void showSpeed() const {
        cout << "Typing Speed: " << speed << " WPM" << endl;
    }
};

class Casual : public Typist {
private:
    int wages;

public:
    void getWage() {
        cout << "Enter Wages: " << endl;
        cin >> wages;
    }

    void showWages() const {
        cout << "Wages: " << wages << endl;
    }
};

class Regular : public Typist {};

int main() {
    Teacher teacher;
    teacher.getDetails();
    teacher.getClass();
    teacher.showDetails();
    teacher.showClass();

    Officer officer;
    officer.getDetails();
    officer.getGrade();
    officer.showDetails();
    officer.showGrade();

    Casual casualTypist;
    casualTypist.getDetails();
    casualTypist.getSpeed();
    casualTypist.getWage();
    casualTypist.showDetails();
    casualTypist.showSpeed();
    casualTypist.showWages();

    return 0;
}
