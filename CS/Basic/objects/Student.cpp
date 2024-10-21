#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
    string studentId;
    string firstName;
    string lastName;
    int gradeLevel;

    Student(string studentId, string firstName, string lastName, int gradeLevel)
        : studentId(studentId), firstName(firstName), lastName(lastName), gradeLevel(gradeLevel) {}

    string getStudentInfo()
    {
        return this->studentId + ": " + this->firstName + " " + this->lastName + "(" + to_string(this->gradeLevel) + "gr" + ")";
    }
};

class Classroom
{
public:
    vector<Student> &students;
    string courseName;
    string teacher;

    Classroom(vector<Student> students, string courseName, string teacher)
        : students(students), courseName(courseName), teacher(teacher) {}

    string getClassIdentity()
    {
        return this->courseName + " " + "managed by " + this->teacher;
    }

    int getNumberOfStudents()
    {
        return this->students.size();
    }
};

class School
{
private:
    vector<Classroom> &classrooms;

public:
    School(vector<Classroom> &classrooms)
        : classrooms(classrooms) {}

    string printHonorsStudents()
    {
        string gradeLevelStudent;
        for (int c = 0; c < classrooms.size(); c++)
        {
            for (int s = 0; s < classrooms[c].students.size(); s++)
            {
                if (classrooms[c].students[s].gradeLevel >= 10)
                {
                    Student student = classrooms[c].students[s];
                    gradeLevelStudent = student.firstName;
                    cout << student.getStudentInfo() + " from " + classrooms[c].teacher + "'s class" << endl;
                }
            }
        }
        return gradeLevelStudent;
    }
};

void entry()
{
    Student student1("AC-343424", "James", "Smith", 6);
    Student student2("AC-343428", "Maria", "Garcia", 5);
    Student student3("AC-343434", "Robert", "Johnson", 3);
    Student student4("AC-343454", "Danny", "Robertson", 10);

    vector<Student> student1List = {student1, student2, student3, student4};
    Classroom class1(student1List, "Algebra II", "Emily Theodore");

    Student student5("AC-340014", "Kent", "Carter", 9);
    Student student6("AC-340024", "Isaiah", "Chambers", 10);
    Student student7("AC-340018", "Leta", "Ferguson", 7);

    vector<Student> student2List = {student5, student6, student7};
    Classroom class2(student2List, "English", "Daniel Pherb");


    vector<Classroom> classnames = {class1, class2};
    School school(classnames);
    school.printHonorsStudents();
}
