#include <iostream>
#include "concurrency.hh"

using namespace zbase;

int
main(int argc, char *argv[])
{
	thread_pool{2, 
		    []() { std::cout << "thread begin" << std::endl; }, 
		    []() { std::cout << "thread end" << std::endl; }};
	
	task_pool tp{2, 
		    []() { std::cout << "thread begin" << std::endl; }, 
		    []() { std::cout << "thread end" << std::endl; }};
	tp.wait([]() { std::cout << "wait" << std::endl; });
	return 0;
}