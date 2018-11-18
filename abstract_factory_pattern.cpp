/*********************************************************************************************************************
				__// ABSTARCT FACTORY DESIGN PATTERN //__
Description:
	This design pattern is just used for the creation of related objects. Here, i have used example of browsers ( firefox and chrome). As per the macro if mozilla browser is selected then related basic and specific info objects are generated.


SAGA@GASA:~/Practice/design_patterns/design_pattern_cpp$ c++ abstract_factory_pattern.cpp -o abs
SAGA@GASA:~/Practice/design_patterns/design_pattern_cpp$ ./abs 

Name: Google Chrome
OpenSource: No
Default SearchEngine: Google
Written In: C++ython
Founder: Jeff Nelson
Version: 65
Website: www.google.com/chrome

**********************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//#define MOZILLA
#define CHROME

class BasicInfo
{
	protected:
		string _name;
		bool _isOpenSource;
		string _defaultSearchEngine;
		string _writtenIn;
		string _founder;
	public:
		BasicInfo(string name,bool isOpenSource, string defaultSearchEngine, string writtenIn, string founder):_name(name),_isOpenSource(isOpenSource),_defaultSearchEngine(defaultSearchEngine),_writtenIn(writtenIn),_founder(founder)
	{} 

		void printInfo()
		{
			cout<<"\nName: "<<_name<<
				"\nOpenSource: "<<((_isOpenSource == false)?"No":"Yes")<<
				"\nDefault SearchEngine: "<<_defaultSearchEngine<<
				"\nWritten In: "<<_writtenIn<<
				"\nFounder: "<<_founder<<endl;
		}
};


class FireFoxBasicInfo:public BasicInfo
{
	public:
		FireFoxBasicInfo():BasicInfo("Mozilla Firefox",true,"Google","JavaScript","Blake Ross")
	{}
};

class ChromeBasicInfo:public BasicInfo
{
	public:
		ChromeBasicInfo():BasicInfo("Google Chrome",false,"Google","C++ython","Jeff Nelson")
	{}
};

class SpecificInfo
{
	protected:
		int _version;
		string _website;
	public:
		SpecificInfo(int version, string website):_version(version),_website(website)
	{} 

		void printInfo()
		{
			cout<<"Version: "<<_version<<
				"\nWebsite: "<<_website<<endl;
		}
};


class FireFoxSpecificInfo:public SpecificInfo
{
	public:
		FireFoxSpecificInfo():SpecificInfo(59,"mozilla.org/firefox")
	{}
};

class ChromeSpecificInfo:public SpecificInfo
{
	public:
		ChromeSpecificInfo():SpecificInfo(65,"www.google.com/chrome")
	{}
};


class BrowserFactory
{
	private:
		SpecificInfo *sInfo;
		BasicInfo *bInfo;

	public:
		BrowserFactory(BasicInfo* bi, SpecificInfo* si):bInfo(bi),sInfo(si)
	{}

		~BrowserFactory()
		{
			if(sInfo)
			{
				delete sInfo;
			}

			if(bInfo)
			{
				delete bInfo;
			}
		}

		virtual void print()
		{
			bInfo->printInfo();
			sInfo->printInfo();
		}
};

class FirefoxFactory:public BrowserFactory
{
	public:
		FirefoxFactory():BrowserFactory(new FireFoxBasicInfo(), new FireFoxSpecificInfo())
	{}
};

class ChromeFactory:public BrowserFactory
{
	public:
		ChromeFactory():BrowserFactory(new ChromeBasicInfo(),new ChromeSpecificInfo())
	{}
};

int main()
{
	BrowserFactory *bf = NULL ;
#ifdef MOZILLA
	bf = new FirefoxFactory();
#endif
#ifdef CHROME
	bf = new ChromeFactory();
#endif
	bf->print();
	
	if(bf)
	{
		delete bf;
	}
	return 0;
}
