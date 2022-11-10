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

class invalidqueueoperator {
public:
	invalidqueueoperator() {
		this->error = "Invalid operator!";
	}

	invalidqueueoperator invalidpop() {
		this->error = "Queue empty. Impossible to pop an element.";
		return *this;
	}

	invalidqueueoperator invalidpush() {
		this->error = "Queue full. Impossible to push an element.";
		return *this;
	}

	invalidqueueoperator invalidread() {
		this->error = "Queue empty. Impossible to read an element.";
		return *this;
	}

	invalidqueueoperator invalidassignment() {
		this->error = "Invalid assignment. The maximum dimension of the left queue is lesser than the maximum dimension of the right one.";
		return *this;
	}

	void print_error() {
		cout << error << endl;
	}

private:
	string error;
};


#endif // !QUEUE_HPP_INCLUDED
