#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    protected:
    string name;
    int age;    
    public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
    virtual ~Person() {}
};

class Professor : public Person{
  int publications;

  public:
    static int cur_id;
    Professor() { cur_id++; }
    void getdata() {
        cin >> name >> age >> publications;
    }
    void putdata() {
        cout << name << age << publications << cur_id;
    }
};

int Professor::cur_id = 0;
class Student : public Person {
    int marks[6];
    static int cur_id;
    public:
        Student() { cur_id++; }
        void getdata() {
            cin >> name >> age;
            for (int i = 0; i < 6; i++)
                cin >> marks[i];
        }
        void putdata() {
            int sum = 0;
            for (int i = 0; i < 6; i++)
                sum += marks[i];
               
            cout << name << age << sum << cur_id;
        }
};

int Student::cur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
