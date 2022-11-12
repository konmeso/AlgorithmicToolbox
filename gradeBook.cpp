#include <iostream> 
#include <string>  

using namespace std;

class GradeBook
{
public:
    explicit GradeBook (string name)
        :courseName(name)
    {

    }

    void setCourseName(string name)
    {
        courseName = name;
    }

    string getCourseName() const
    {
        return courseName;
    }

    void displayMessage() const
    {
        cout << "Welcome to the grade book for\n" << getCourseName() << endl;
    }

private: 
    string courseName;

};

int main()
{
    string nameOfCourse; //creates new variable named nameOfCourse
    GradeBook gradeBook1("CS101 Introduction to C++ Programming");
    GradeBook gradeBook2("CS102 Data Structures in C++");

    cout << "Please enter the course name: " << endl;
    getline(cin,nameOfCourse);

    gradeBook1.setCourseName(nameOfCourse);
    cout << endl;

    myGradeBook.displayMessage();

}