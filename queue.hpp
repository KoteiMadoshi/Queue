#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

#include <iostream>

using namespace std;

template < class value_type >
class queue {
	public:
		virtual bool empty() const = 0;
		virtual value_type read_front() const = 0;
		virtual void push_back(const value_type&) = 0;
		virtual void pop_front() = 0;
};

class invalidpop {
public:
	invalidpop() {
		this->error = "Queue empty. Impossible to pop an element.";
	}

	void print_error() {
		cout << error << endl;
	}

private:
	string error;
};

class invalidpush {
public:
	invalidpush() {
		this->error = "Queue full. Impossible to push an element.";
	}

	void print_error() {
		cout << error << endl;
	}

private:
	string error;
};

class invalidread {
public:
	invalidread() {
		this->error = "Queue empty. Impossible to read an element.";
	}

	void print_error() {
		cout << error << endl;
	}

private:
	string error;
};

#endif // !QUEUE_HPP_INCLUDED
