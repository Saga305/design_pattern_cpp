/*************************************************************************************************************************
			__// SINGLETON DESIGN PATTERN //__

Here is the implemation of singleton design pattern with double checked locking for thread safe implementation.

SAGA@SAGA:~/Practice/design_patterns/design_pattern_cpp$ c++ singleton_design_pattern.cpp -std=c++11 -o singleton
SAGA@SAGA:~/Practice/design_patterns/design_pattern_cpp$ ./singleton 
KRK is 2 rupees person.
***************************************************************************************************************************/

#include <iostream>
#include <string>
#include <mutex>
#include <cstdio>
#include <cstdarg>

using namespace std;

std::mutex mlock;  //critical section

class Singleton
{
	private:
		static Singleton* _instance;

		/*
		 * Make constructor private to avoid outside object creation.
		 */
		Singleton()
		{}
	public:
		~Singleton()
		{
			if(_instance)
			{
				delete _instance;
				_instance = nullptr;
			}
		}

		/*
		 * Static method used to get a single instance of the class.
		 */
		static Singleton* getInstance()
		{

			/*
			 * Double check locking for thread safe implementation.
			 */
			if(nullptr == _instance)
			{
				mlock.lock();
				if(nullptr == _instance)
				{
					_instance = new Singleton();
				}
				mlock.unlock();
			}
			return _instance;
		}

		/*
		 * Variable price list creator.
		 */
		void createLogMsg(char* buf, const char *fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			vsprintf(buf, fmt, args);
			va_end(args);
		}

};

Singleton* Singleton::_instance = nullptr;

int main()
{
	Singleton* ptr = Singleton::getInstance();
	if(ptr)
	{
		char buffer[100] = {0};
		ptr->createLogMsg(buffer,"%s%d%s","KRK is ",2," rupees person.");
		std::cout<<buffer<<std::endl;
	}
	return 0;
}
