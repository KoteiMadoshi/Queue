#ifndef ARRAYQUEUE_HPP_INCLUDED
#define ARRAYQUEUE_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include "queue.hpp"

using namespace std;

//queue class
//
// 
//

template < class value_type >
class arrayqueue : public queue<value_type> {
	public:
		//constructor
		arrayqueue();
		arrayqueue(int);
		//copy constructor
		arrayqueue(const arrayqueue<value_type>&);
		//destructor
		~arrayqueue();

		//operator
		bool empty() const;
		value_type read_front() const;
		void push_back(const value_type&);
		void pop_front();
		void print_queue() const;

		//friend ostream& operator<<(ostream& os, arrayqueue<value_type>& q);


	private:
		value_type* queue;
		int maxdim;
		int head;
		int tail;

};

template < class value_type >
arrayqueue<value_type>::arrayqueue() {
	this->maxdim = 10;
	this->queue = new value_type[this->maxdim];
	this->head = 0;
	this->tail = 0;
}

template < class value_type >
arrayqueue<value_type>::arrayqueue(int maxdim) {
	this->maxdim = maxdim;
	this->queue = new value_type[this->maxdim];
	this->head = 0;
	this->tail = 0;
}

template < class value_type >
arrayqueue<value_type>::arrayqueue(const arrayqueue<value_type>& q) {
	this->maxdim = q.maxdim;
	this->queue = new value_type[this->maxdim];
	this->tail = 0;
	for (int i = 0; i < (q.tail - q.head); ++i) {
		queue[i] = q[i + (q.head%q.maxdim)];
		this->tail += 1;
	}
	this->head = 0;
}

template < class value_type >
arrayqueue<value_type>::~arrayqueue() {
	delete[] this->queue;
}

template < class value_type >
bool arrayqueue<value_type>::empty() const {
	return (this->head == this->tail);
}

template < class value_type >
value_type arrayqueue<value_type>::read_front() const {
	invalidread error;
	if (this->empty()) {
		throw error;
	}
	else {
		return this->queue[this->head % this->maxdim];
	}
}

template < class value_type >
void arrayqueue<value_type>::push_back(const value_type& x) {
	invalidpush error;
	if ((this->tail - this->head) == this->maxdim) {
		throw error;
	}
	else {
		this->queue[this->tail % maxdim] = x;
		this->tail += 1;
	}
}

template < class value_type >
void arrayqueue<value_type>::pop_front() {
	invalidpop error;
	if (this->empty()) {
		throw error;
	}
	else {
		this->head += 1;
	}
}

template < class value_type >
void arrayqueue<value_type>::print_queue() const {
	cout << "Queue: [";
	for (int i = this->head; i < this->tail; ++i) {
		if (i == this->tail - 1) {
			cout << queue[i % maxdim];
		}
		else {
			cout << queue[i % maxdim] << ", ";
		}
	}
	cout << "]." << endl;
}

/*
template < class value_type >
ostream& operator<<(ostream& os, arrayqueue<value_type>& q) {
	os << "Queue: [";
	for (int i = q.head; i < q.tail; ++i) {
		if (i == q.tail - 1) {
			os << q.queue[i % q.maxdim];
		}
		else {
			os << q.queue[i % q.maxdim] << ", ";
		}
	}
	os << "].\n";

	return os;
}*/

#endif // !ARRAYQUEUE_HPP_INCLUDED