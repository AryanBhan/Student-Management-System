// CODED BY ARYAN BHAN CSE 4th YEAR
#include <bits/stdc++.h>
#include <fstream>
#include <Windows.h>
using namespace std;
class student
{
public:
    long long int roll;
    string Name;
    string Gender;
    int age;
    student *next;
};
student *head = new student();
bool find(long long int x)
{

    if (head == NULL)
        return false;

    student *t = new student;
    t = head;

    while (t != NULL)
    {
        if (t->roll == x)
            return true;
        t = t->next;
    }

    return false;
}
bool check(string Name,string Gender)
{
    for (char i : Name)
    {
        if (isalpha(i)==0)
            return false;
    }
    if (isalpha(Gender[0])==0)
    {
        return false;
    }
    return true;
}
void Insert_Details(long long int roll, string Name,
                    string Gender, int age)
{

    if (!check(Name, Gender))
    {
        cout << "Invalid Record "
             << "Check Name and Gender\n";
        return;
    }
    if (find(roll))
    {
        cout << "Student with this "
             << "record Already Exists\n";
        return;
    }

    student *t = new student();
    t->roll = roll;
    t->Name = Name;
    t->Gender = Gender;
    t->age = age;
    t->next = NULL;

    if (head == NULL || (head->roll >= t->roll))
    {
        t->next = head;
        head = t;
    }

    else
    {
        student *c = head;
        while (c->next != NULL && c->next->roll < t->roll)
        {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
}
void Show_Record()
{
    student *p = head;
    if (p == NULL)
    {
        cout << "No Record "
             << "Available\n";
    }
    else
    {
        cout << "Roll\tName\tGender"
             << "\tage\n";

        while (p != NULL)
        {
            cout << p->roll << " \t"
                 << p->Name << "\t"
                 << p->Gender << "\t"
                 << p->age << endl;
            p = p->next;
        }
    }
}
void Search_Record(long long int roll)
{
    if (!head)
    {
        cout << "No such Record "
             << "Available\n";
        return;
    }
    else
    {
        student *p = head;
        while (p)
        {
            if (p->roll == roll)
            {
                cout << "Roll Number\t"
                     << p->roll << endl;
                cout << "Name\t\t"
                     << p->Name << endl;
                cout << "Gender\t\t"
                     << p->Gender << endl;
                cout << "age\t\t"
                     << p->age << endl;
                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << "No such Record "
                 << "Available\n";
    }
}

void Save_Record()
{
    student *f = head;
    if (f == NULL)
    {
        return;
    }
    else
    {
        ofstream csv_in;
        ofstream fout;
        fout.open("student.txt", ios::out);
        csv_in.open("student.csv", ios::out);
        while (f != NULL)
        {
            fout << f->roll << " \n"
                 << f->Name << "\n"
                 << f->Gender << "\n"
                 << f->age << "\nendline"
                 << endl;
            csv_in << f->roll << ", "
                   << f->Name << ", "
                   << f->Gender << ", "
                   << f->age
                   << endl;
            f = f->next;
        }

        fout.close();
    }
}

void Load_Details()
{
    string line;
    long long int roll;
    string name;
    string gender;
    int age;
    ifstream fin;
    int s = 0;
    fin.open("student.txt", ios::out);
    while (getline(fin, line))
    {
        if (s == 0)
        {
            roll = stoi(line);
            s += 1;
        }
        else if (s == 1)
        {
            name = line;
            s += 1;
        }
        else if (s == 2)
        {
            gender = line;
            s += 1;
        }
        else if (s == 3)
        {
            age = stoi(line);
            s += 1;
        }
        else if (s == 4)
        {
            Insert_Details(roll, name, gender, age);
            s = 0;
        }
    }
    fin.clear();
    fin.close();
}

int main()
{
    head = NULL;
    string Name, Gender;
    long long int Roll;
    int age;
    Load_Details();
    char ch = 'Y';
    while (true)
    {
        cout << "\n\t\t   DCRUST Student Record "
                "Management System\n\n\tPress\n\t1 to "
                "create a new Record\n\t2 to Search a Student "
                "Record\n\t3 to view all students "
                "record\n\t4 to Exit\n";
        cout << "Enter your Choice\n";
        int Choice;
        cin >> Choice;
        if (Choice == 1)
        {
            cout << "Enter Name of Student\n";
            cin >> Name;
            cout << "Enter Roll Number of Student\n";
            cin >> Roll;
            cout << "Enter Gender of Student \n";
            cin >> Gender;
            cout << "Enter age of Student\n";
            cin >> age;
            Insert_Details(Roll, Name, Gender, age);
        }
        else if (Choice == 2)
        {
            cout << "Enter Roll Number of Student whose "
                    "record you want to Search\n";
            cin >> Roll;
            Search_Record(Roll);
        }
        else if (Choice == 3)
        {
            Show_Record();
        }
        else if (Choice == 4)
        {
            Save_Record();
            exit(0);
        }
        else
        {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
        cout << "Do you want to continue:Y/N:";
        cin >> ch;
        if (ch == 'Y')
        {
            system("cls");
        }
        else
        {
            cout << "Do you want to save the record:(Y/N) ";
            cin >> ch;
            if (ch == 'N')
                break;
            else
            {
                Save_Record();
                exit(0);
            }
        }
    }
    return 0;
}
