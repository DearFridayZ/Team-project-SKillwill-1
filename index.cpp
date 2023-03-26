#include <iostream>
#include <string>

using namespace std;

class Subject {
    public:
        virtual string getName() const = 0;
        virtual string getLastLecture() const = 0;
};

class Web : public Subject {
    private:
        string lastLecture;
    public:
        Web(string lastLecture) : lastLecture(lastLecture) {}
        string getName() const override {
            return "Web";
        }
        string getLastLecture() const override {
            return lastLecture;
        }
};

class Mobile : public Subject {
    private:
        string lastLecture;
    public:
        Mobile(string lastLecture) : lastLecture(lastLecture){}
        string getName() const override {
            return "Mobile";
        }
    string getLastLecture() const override {
        return lastLecture;
    }
};


class Person {
    protected:
        string firstName;
        string lastName;
    public:
        Person(string firstName, string lastName) : firstName(firstName),lastName(lastName){}
        virtual string getFullName() const = 0;
};

class Lecturer : public Person {
    private:
        Subject* subject;
        string chapter;
    public:
        Lecturer(string firstName, string lastName, Subject* subject, string chapter) 
            : Person(firstName,lastName), subject(subject),chapter(chapter){}
        string getFullName() const override{
            return firstName + " " + lastName;
        }
        string getSubjectName() const  {
            return subject->getName();
        }
        string getChapter() const {
            return chapter;
        }
        
        void teach() const {
            cout << getFullName() << " is teaching: " << getSubjectName() << "'\n";
        }
    
};

class Student : public Person {
    private:
        Subject* subject;
        char section;
        string className;
        int quizScore;
        string level;
    public:
        Student(string firstName, string lastName, Subject* subject, char section, string className, int quizScore, string level) : Person(firstName, lastName), subject(subject), section(section), className(className), quizScore(quizScore),level(level) {}

        string getFullName() const override {
            return firstName + " " + lastName;
        }
        string getSubjectName() const {
            return subject->getName();
        }
        char getSection() const {
            return section;
        }
        string getClassName() const {
            return className;
        }
        int getQuizScore() const {
            return quizScore;
        }
        string getLevel() const {
            return level;
        }
        void attendClass() const {
            cout << getFullName() << " is attending " << getSubjectName() << " class  " << className<< "in section " << section << " , with current quiz score of: " << quizScore << " His current Level is " << level << '\n';
        }
};

int main() {

    Subject* webSubject = new Web("Responsive Web Design");
    Subject* mobileSubject = new Mobile("Mobile Developement and its trickstery ! ");
    

    Lecturer* webLecturer = new Lecturer("Nika", "Nikadze", webSubject, "Chapter 1");
    Lecturer* mobileLecturer = new Lecturer("Teo", "Teodze", mobileSubject, "Chapter 4");
    
    Student* webStudent = new Student("Iakob", "iakobishvili", webSubject,'C'," Web-Development Course ", 500, "Code-God ");
    Student* mobileStudent = new Student("Valeri", "Valeriani", mobileSubject,'B'," Front-End-Developement Course ", 100, " ROOKIE");

    webLecturer->teach();
    mobileLecturer->teach();
    webStudent->attendClass();
    mobileStudent->attendClass();

    delete webSubject;
    delete mobileSubject;
    delete webLecturer;
    delete mobileLecturer;
    delete webStudent;
    delete mobileStudent;
    
    

    return 0;

    
}