/*
		__// NULL OBJECT DESIGN PATTERN //__

Testings:
$ c++  null_object.cpp  -o test
$ ./test 
WelCome AaKaasH!
WelCome DhvanisH!

*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
		virtual ~Student() { }
		virtual string getName() const=0;
};

class idolStudent : public Student
{
	public:
		string getName() const { return "idolStudent"; }
};

class Aakash : public Student
{
	public:
		string getName() const { return "AaKaasH"; }
};

class Dhvanish : public Student
{
	public:
		string getName() const { return "DhvanisH"; }
};

void welComeStudent (const Student & student = idolStudent())
{
	cout << "WelCome " << student.getName() << "!" << endl;
}

int main()
{
	welComeStudent(Aakash());
	welComeStudent(Dhvanish());
	welComeStudent();
	return 0;
}

