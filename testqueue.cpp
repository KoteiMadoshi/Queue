#include <iostream>
#include <time.h>
#include "arrayqueue.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	arrayqueue<int> queue;
	srand(time(NULL));

	queue.print_queue();
	cout << endl;

	try
	{
		queue.pop_front();
	}
	catch (invalidpop error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		cout << "First element: " << queue.read_front() << endl;
	}
	catch (invalidread error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		for (int i = 0; i < 20; ++i) {
			queue.push_back(rand() % 100);
		}
	}
	catch (invalidpush error)
	{
		error.print_error();
		cout << endl;
	}
	queue.print_queue();
	cout << endl;

	try
	{
		cout << "First element: " << queue.read_front() << endl << endl;
	}
	catch (invalidread error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		queue.pop_front();
	}
	catch (invalidpop error)
	{
		error.print_error();
		cout << endl;
	}
	queue.print_queue();
	cout << endl;
	
	try
	{
		queue.push_back(69420);
		queue.print_queue();
		cout << endl;

	}
	catch (invalidpush error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		queue.push_back(1);
	}
	catch (invalidpush error)
	{
		error.print_error();
		cout << endl;
	}


	cout << endl;
	system("PAUSE");
	return 0;
}