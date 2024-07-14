/*Linked list operations: Create a linked list of names and birthdays of
students. Write a menu driven C++ program to perform following
operations
1. Insert name and birthday of new student
2. Delete a student entry
3. Display a happy birthday message for whom today (based on system date) is birthday
4. Display list of students with their birthdays*/
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

struct Student {
    string name;
    string birthday;
    Student* next;
};

Student* head = nullptr;

// Insert at Begin
void Insert_Record(string name, string birthday) {
    Student* s = new Student();
    s->name = name;
    s->birthday = birthday;
    s->next = nullptr;

    if (head == nullptr || (head->name >= s->name)) {
        s->next = head;
        head = s;
    } else {
        Student* c = head;
        while (c->next != nullptr && c->next->name < s->name) {
            c = c->next;
        }
        s->next = c->next;
        c->next = s;
    }

    cout << "Data inserted" << endl;
}

string Delete_Record(string name) {
    Student* s = head;
    Student* p = nullptr;

    // Deletion at Begin
    if (s != nullptr && s->name == name) {
        head = s->next;
        delete s;
        cout << "Record Deleted " << endl;
        return "";
    }

    // Deletion Other than Begin
    while (s != nullptr && s->name != name) {
        p = s;
        s = s->next;
    }

    if (s == nullptr) {
        cout << "Record does not Exist" << endl;
        return "Record not found";
    }

    p->next = s->next;
    delete s;
    cout << "Record Deleted " << endl;
    return "";
}

void Show_Record() {
    Student* p = head;
    if (p == nullptr) {
        cout << "No Record available" << endl;
    } else {
        cout << "Name\tBirthday\n";
        while (p != nullptr) {
            cout << p->name << "\t" << p->birthday << "\n";
            p = p->next;
        }
    }
}

bool isBirthdayToday(const string& date) {
    time_t now = time(0);
    tm today = *localtime(&now);

    stringstream ss(date);
    int year, month, day;
    char discard;

    ss >> year >> discard >> month >> discard >> day;

    if (month == today.tm_mon + 1 && day == today.tm_mday) {
        return true;
    }

    return false;
}

void displayBirthdayMessages() {
    Student* current = head;

    while (current != nullptr) {
        if (isBirthdayToday(current->birthday)) {
            cout << "Happy Birthday, " << current->name << "!" << endl;
        }
        current = current->next;
    }
}

int main() {
    string name, birthday;
    int op;

    do {
        cout << "Enter your choice" << endl;
        cout << "1. Insert name and birthday of new student\n2. Delete a student entry\n3. Display a happy birthday message for whom today is their birthday\n4. Display list of students with their birthdays\n5. Exit" << endl;
        cin >> op;

        switch (op) {
            case 1:
                cout << "Enter Name of Student: ";
                cin >> name;
                cout << "Enter Birthday of Student (YYYY-MM-DD): ";
                cin >> birthday;
                Insert_Record(name, birthday);
                break;
            case 2:
                cout << "Enter the name of Student whose record is to be deleted: ";
                cin >> name;
                Delete_Record(name);
                break;
            case 3:
                displayBirthdayMessages();
                break;
            case 4:
                cout << "Display list of students with their birthdays" << endl;
                Show_Record();
                break;
            case 5:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Enter correct choice" << endl;
        }
    } while (op != 5);

    // Clean up and release memory
    Student* current = head;
    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}