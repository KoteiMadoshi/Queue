#include <iostream>
#include <time.h>
#include "arrayqueue.hpp"
#include "linkedqueue.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	arrayqueue<int> queue;
	//linkedqueue<int> queue;
	srand(time(NULL));

	queue.print_queue();
	cout << endl;

	try
	{
		queue.pop_front();
	}
	catch (invalidqueueoperator error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		cout << "First element: " << queue.read_front() << endl;
	}
	catch (invalidqueueoperator error)
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
	catch (invalidqueueoperator error)
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
	catch (invalidqueueoperator error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		queue.pop_front();
	}
	catch (invalidqueueoperator error)
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
	catch (invalidqueueoperator error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		queue.push_back(1);
		queue.print_queue();
		cout << endl;
	}
	catch (invalidqueueoperator error)
	{
		error.print_error();
		cout << endl;
	}

	arrayqueue<int> queue2(queue);
	//linkedqueue<int> queue2(queue);

	cout << "Queue2: " << endl;
	queue2.print_queue();
	cout << endl;

	arrayqueue<int> queue3(1000);
	//linkedqueue<int> queue3;
	try
	{
		queue3 = queue2;
	}
	catch (invalidqueueoperator error)
	{
		error.print_error();
	}
	cout << "Queue3: " << endl;
	queue3.print_queue();
	cout << endl;

	cout << ((queue2 == queue3) ? "Queue2 e Queue3 uguali." : "Queue2 e Queue3 non uguali.") << endl;


	cout << endl;
	system("PAUSE");
	return 0;
}
