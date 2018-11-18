/*****************************************************************************************

  ___// OBSERVER DESIGN PATTERN //___
  Here is the implementation of observer design pattern in cpp.

  Basically observer is the class which has feature to register the class object which should be notified for an event.

Desription:

Subject: It is an interface class used to maintain polymorphic hierarchy.

Observer: Class is responsible to pass an event to the registered classes.

ObjectOne, ObjectTwo, ObjectThree: Event hander classes.

SAGA@SAGA:~/Practice/design_patterns$ c++ observer_design_pattern.cpp -std=c++11 -g -o observ
SAGA@SAGA:~/Practice/design_patterns$ ./observ 
ObjectOne :: How's you?
ObjectTwo :: How's you?
ObjectThree :: How's you?
ObjectOne :: Are you Okay?
ObjectTwo :: Are you Okay?

 ******************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Subject
{
	public:
		virtual void notify(const char* str)
		{}
		virtual ~Subject()
		{}
};

class Observer
{
	private:
		vector<Subject*> _observer;
	public:
		Observer(int eventHandlers)
		{
			_observer.reserve(eventHandlers);
		}

		void registerObj(Subject* ob)
		{
			_observer.emplace_back(ob);
		}

		void unregisterObj(Subject* ob)
		{
			auto it = find(_observer.begin(), _observer.end(), ob);
			if(it != _observer. end())
			{
				_observer.erase(it);
			}
		}

		void notify(const char* str)
		{
			for (auto &obj : _observer)
			{
				obj->notify(str);
			}
		}
};


class ObjectOne: public Subject
{
	public:
		virtual void notify(const char* str)
		{
			cout<<"ObjectOne :: "<<str<<endl;
		} 
};

class ObjectTwo: public Subject
{
	public:
		virtual void notify(const char* str)
		{
			cout<<"ObjectTwo :: "<<str<<endl;
		}
};

class ObjectThree: public Subject
{
	public:
		virtual void notify(const char* str)
		{
			cout<<"ObjectThree :: "<<str<<endl;
		}
};

int main()
{
	Observer ob(3);
	ObjectOne *one = new ObjectOne();
	ObjectTwo *two = new ObjectTwo();
	ObjectThree *three = new ObjectThree();

	ob.registerObj(one);
	ob.registerObj(two);
	ob.registerObj(three);
	ob.notify("How's you?");

	ob.unregisterObj(three);
	ob.notify("Are you Okay?");
	return 0;
}
