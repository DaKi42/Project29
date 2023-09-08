#include <iostream>
using namespace std;

class Student {
private:
    char* name;
    int age;
    char* email;
public:
    Student();
    Student(const char* n, int a);
    Student(const char* n, int a, const char* i);
    void Input(/*const Student* this*/);
    void Print(/*this*/);
    void setName(const char* i);
    int getName();
    void setAge(int j);
    int getAge();
    void setEmail(const char* k);
    int getEmail();

    Student& AddAge(int a);
    ~Student();
};
Student::Student() {
    this->name = nullptr;
    this->age = 0;
    this->email = nullptr;
    cout << "Constructor by default\n";
}
Student::Student(const char* n, int a) {//Oleg 20
    this->name = new char[strlen(n) + 1];
    strcpy_s(this->name, strlen(n) + 1, n);
    this->age = a;
    cout << "Constructor by 2 params\n";
}
Student::Student(const char* n, int a, const char* i) {//Oleg 20 oleg@gmail.com
    this->name = new char[strlen(n) + 1];
    strcpy_s(this->name, strlen(n) + 1, n);
    this->age = a;
    this->email = new char[strlen(i) + 1];
    strcpy_s(this->email, strlen(i) + 1, i);
    cout << "Constructor by 3 params\n";
}
Student::~Student() {
    delete[] this->name;
    delete[] this->email;
    cout << "Destructor\n";
}
void Student::Input(/*const Student* this*/) {
    char buff[255];
    cout << "Enter name: ";
    cin >> buff;
    if (this->name != nullptr) {
        cout << "Delete..." << name << endl;
        delete[] this->name;
    }
    this->name = new char[strlen(buff) + 1];
    strcpy_s(this->name, strlen(buff) + 1, buff);
    cout << "Enter age: ";
    cin >> this->age;
    cout << "Enter email: ";
    cin >> buff;
    if (this->email != nullptr) {
        cout << "Delete..." << email << endl;
        delete[] this->email;
    }
    this->email = new char[strlen(buff) + 1];
    strcpy_s(this->email, strlen(buff) + 1, buff);
}
void Student::Print(/*this*/) {
    cout << "Name: " << name << "\tAge: " << age << "\tEmail: " << email << endl;
}
void Student::setName(const char* i) {
    if (name != nullptr) {
        cout << "Delete..." << name << endl;
        delete[] name;
    }
    name = new char[strlen(i) + 1];
    strcpy_s(name, strlen(i) + 1, i);
}
int Student::getAge() {
    return age;
}
void Student::setEmail(const char* k) {
    if (email != nullptr) {
        cout << "Delete..." << email << endl;
        delete[] email;
    }
    email = new char[strlen(k) + 1];
    strcpy_s(email, strlen(k) + 1, k);
}
int Student::getEmail() {
    return*email;
}
void Student::setAge(int j) {
    if (j > 0) {
        age = j;
    }
    else {
        cout << "Wrong input!!! Age>0!!!" << endl;
    }
}
int Student::getName() {
    return*name;
}
Student& Student::AddAge(int a) {
    age += a;
    return *this;
}


int main() {
    Student obj1("Olya", 36, "Olya@gmail.com");
    //Student obj2("Oleg", 20, "oleg@gmail.com");
    //Student obj3("Aslan", 20, "gadzhyaslan@gmail.com");
    obj1.Print();

    obj1.AddAge(5);
    obj1.Print();
    //obj2.Print();
    //obj3.Print();


    //obj3.Input();
    //obj3.Print();
}