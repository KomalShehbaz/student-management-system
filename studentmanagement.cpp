#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct student
{
    string name;
    int age;
    int marks;
    int id;
};
void addstudent(student s[], int &count)
{
    int n;
    int newid;
    cout << "Enter how many students information you want to add" << endl;
    cin >> n;

    if (n > 100)
    {
        cout << "you can add only 100 students information\n";
        return;
    }
    if (count + n > 100)
    {
        cout << "you can add only" << 100 - count << " more student" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cout << "Enter " << count + 1 << " student data:\n";
        cout << "Enter student name:\n";
        getline(cin, s[count].name);
        cout << "Enter student age:\n";
        cin >> s[count].age;
        cout << "Enter student marks:\n";
        cin >> s[count].marks;
        cout << "Enter student id:\n";
        cin >> newid;

        while (true)
        {
            bool isduplicate = false;
            for (int j = 0; j < count; j++)
            {
                if (newid == s[j].id)
                {

                    isduplicate = true;
                    break;
                }
            }
            if (isduplicate)
            {

                cout << "This id already exist please enter a new id\n";
                cin >> newid;
                ;
            }
            else
            {
                s[count].id = newid;
                break;
            }
        }
        count++;
    }
    cout << "Students data have been added successfully\n";
}
void displaystudent(student s[], int count)
{
    if (count == 0)
    {
        cout << "No student information are stored yet please add the student first" << endl;
        return;
    }
    cout << "student data is given as:\n";
    for (int i = 0; i < count; i++)
    {
        cout << "The " << i + 1 << " student data is: \n";
        cout << "Student Name: ";
        cout << s[i].name << endl;
        cout << "Student age: ";
        cout << s[i].age << endl;
        cout << "Student Marks: ";
        cout << s[i].marks << endl;
        cout << "Student id: ";
        cout << s[i].id << endl;
    }
}
void updatestudent(student s[], int count)
{

    int sid;
    cout << "Enter student id whose information you want to update\n";
    cin >> sid;
    for (int i = 0; i < count; i++)
    {
        if (s[i].id == sid)
        {
            cin.ignore();
            cout << "Enter  new student name\n";
            getline(cin, s[i].name);
            cout << "Enter  new student age\n";
            cin >> s[i].age;
            cout << "Enter new student marks\n";
            cin >> s[i].marks;
            cout << "Enter new student id\n";
            cin >> sid;
            while (true)
            {
                bool isduplicate = false;
                for (int j = 0; j < count; j++)
                {
                    if (j != i && sid == s[j].id)
                    {
                        isduplicate = true;
                        break;
                    }
                }
                if (isduplicate)
                {
                    cout << "This id already exist please enter a new id\n";
                    cin >> sid;
                }
                else
                {
                    s[i].id = sid;
                    break;
                }
            }
            cout << "Students data is updated successfully\n";
            return;
        }
    }
    cout << "student id not found" << endl;
}
void deletestudent(student s[], int &count)
{
    int sid;
    cout << "Enter student id whose information you want to delete\n";
    cin >> sid;
    for (int i = 0; i < count; i++)
    {
        if (s[i].id == sid)
        {
            for (int j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }
            count--;
            cout << "student data is deleted successfully\n";
            return;
        }
    }
    cout << "Student id not found" << endl;
}
void Addfile(student s[], int count)
{
    ofstream file("studentmanagement.txt");
    for (int i = 0; i < count; i++)
    {

        file << s[i].name << endl;
        file << s[i].age << endl;
        file << s[i].marks << endl;
        file << s[i].id << endl;
    }
    cout << " Students data has been stored to the file successfully" << endl;
}
void getfile(student s[], int &count)
{
    ifstream infile("studentmanagement.txt");

    while (getline(infile, s[count].name))
    {
        infile >> s[count].age >> s[count].marks >> s[count].id;
        infile.ignore();

        count++;
    }
}

int main()
{
    student *s = new student[100];
    int option = 0;
    int count = 0;
    cout << "     ========================================\n";
    cout << "          STUDENT MANAGEMENT SYSTEM" << endl;
    cout << "     ========================================\n";

    while (option != 7)
    {
        cout << "-------------------------\n";
        cout << "Enter what you like to do" << endl;
        cout << "1- Add the student data\n2- Display the student data\n3- Update the student \n4- Delete the student\n5- Store  data to the file\n6- Get data from the file\n7- Exit the progrma\n";
        cout << "-------------------------\n";
        cin >> option;
        switch (option)
        {
        case 1:
            addstudent(s, count);
            break;
        case 2:
            displaystudent(s, count);
            break;
        case 3:
            updatestudent(s, count);
            break;
        case 4:
            deletestudent(s, count);
            break;
        case 5:
            Addfile(s, count);
            break;
        case 6:
            getfile(s, count);
            break;
        case 7:
            cout << "Program exited";
            break;
        default:
            cout << "Please enter a valid option between 1-7";
            return 0;
        }
    }
    return 0;
}
