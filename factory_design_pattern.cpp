/**************************************************************************************************************************
			__// FACTORY DESIGN PATTERN //__
Basically here we have created a factory class method which is resposible in creation of class object as per user's interest.
Also we have created a Interface class to maintain polymorphic relationship.

This pattern wildly used when run time object creation is required. That's why this pattern is called virtual constructor.


TESTINGS: 

SAGA@GASA:~/Practice/design_patterns/design_pattern_cpp$ c++ factory_design_pattern.cpp -o factory
SAGA@GASA:~/Practice/design_patterns/design_pattern_cpp$ ./factory 
Please enter type of the class:
	type		class
	1		Machine
	2		Assembly
	3		HighLevel
Enter type 0 to exit the application
1
Type: Machine Language
Human Readability: False
2
Type: Assembly Language
Human Readability: True
3
Type: HighLevel Language
Human Readability: True
4
Unknwon type provided
0
*****************************************************************************************************************************/

#include <iostream>

using namespace std;

class ILanguage
{
	private:
		bool _isHumanReadable;
		string _type;
	public:
		ILanguage(bool isHR,string type):_isHumanReadable(isHR),_type(type)
	{}

		string type()
		{
			return _type;
		}

		bool isHumanReadable()
		{
			return _isHumanReadable;
		}
};

class MachineLanguage:public ILanguage
{
	public:
		MachineLanguage():ILanguage(false,"Machine Language")
	{}
};

class AssemblyLanguage:public ILanguage
{
	public:
		AssemblyLanguage():ILanguage(true,"Assembly Language")
	{}
};

class HighLevelLanguage:public ILanguage
{
	public:
		HighLevelLanguage():ILanguage(true,"HighLevel Language")
	{}
};


class LanguageFactory
{
	public:
	static ILanguage* createLanguageInstance(int type)
	{
		ILanguage * intPtr = NULL;
		switch(type)
		{
			case 1:
				intPtr = new MachineLanguage();
				break;
			case 2:
				intPtr = new AssemblyLanguage();
				break;
			case 3:
				intPtr = new HighLevelLanguage();
				break;
			default:
				cout<<"Unknwon type provided"<<endl;
				break;
		}
		return intPtr;
	}
};


int main()
{
	int type;
	ILanguage *ip = NULL;
		cout<<"Please enter type of the class:\n\ttype\t\tclass\n\t1\t\tMachine\n\t2\t\tAssembly\n\t3\t\tHighLevel"<<endl;
		cout<<"Enter type 0 to exit the application"<<endl;
	while(true)
	{
		cin>>type;
		if(type == 0)
		{
			break;
		}

		ip = LanguageFactory::createLanguageInstance(type);
		if(ip)
		{
			cout<<"Type: "<<ip->type()<<endl;
			cout<<"Human Readability: "<<((ip->isHumanReadable()==false)?"False":"True")<<endl;
			delete ip;
			ip = NULL;
		}
	}
	return 0;
}
