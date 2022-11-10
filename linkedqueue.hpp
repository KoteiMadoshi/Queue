#ifndef LINKEDQUEUE_HPP_INCLUDED
#define LINKEDQUEUE_HPP_INCLUDED

#include <iostream>
#include "queue.hpp"

using namespace std;

template< class value_type >
class linkedqueue;

template< class value_type >
class node {
	friend class linkedqueue<value_type>;
	private:
		value_type e;
		node<value_type>* next;
};

template< class value_type >
class linkedqueue : public queue<value_type> {
	public:
		//constructor
		linkedqueue();
		//copy constructor
		linkedqueue(const linkedqueue<value_type>&);
		//destructor
		~linkedqueue();

		//operator
		bool empty() const;
		value_type read_front() const;
		void push_back(const value_type&);
		void pop_front();
		void print_queue() const;

		void operator=(const linkedqueue<value_type>&);
		bool operator==(const linkedqueue<value_type>&);


	private:
		node<value_type>* head;
		node<value_type>* tail;
};

template< class value_type >
linkedqueue<value_type>::linkedqueue() {
	this->head = nullptr;
}

template< class value_type >
linkedqueue<value_type>::linkedqueue(const linkedqueue<value_type>& q) {
	node<value_type>* iter;
	iter = q.head;
	while (iter != nullptr) {
		this->push_back(iter->e);
		iter = iter->next;
	}
}

template< class value_type >
linkedqueue<value_type>::~linkedqueue() {
	while (!this->empty()) {
		this->pop_front();
	}
}

template< class value_type >
bool linkedqueue<value_type>::empty() const {
	return (this->head == nullptr);
}

template< class value_type >
value_type linkedqueue<value_type>::read_front() const {
	invalidqueueoperator error;
	if (this->empty()) {
		throw error.invalidread();
	}
	return this->head->e;
}

template< class value_type >
void linkedqueue<value_type>::push_back(const value_type& x) {
	node<value_type>* newnode = new node<value_type>;
	newnode->e = x;
	newnode->next = nullptr;
	if (this->head ==  nullptr) {
		this->head = newnode;
		this->tail = newnode;
	}
	else {
		this->tail->next = newnode;
		tail = newnode;
	}
}

template< class value_type>
void linkedqueue<value_type>::pop_front() {
	invalidqueueoperator error;
	if (this->empty()) {
		throw error.invalidpop();
	}
	node<value_type>* oldhead;
	oldhead = this->head;
	this->head = this->head->next;
	delete oldhead;
}

template< class value_type>
void linkedqueue<value_type>::print_queue() const {
	cout << "Queue: [";
	node<value_type>* iter;
	iter = this->head;
	while (iter != nullptr) {
		if (iter->next == nullptr) {
			cout << iter->e;
		}
		else {
			cout << iter->e << ", ";
		}
		iter = iter->next;
	}
	cout << "]." << endl;
}

template< class value_type >
void linkedqueue<value_type>::operator=(const linkedqueue<value_type>& q) {
	node<value_type>* iter;
	if (!this->empty()) {
		iter = this->head;
		while (iter != nullptr) {
			this->pop_front();
			iter = iter->next;
		}
	}
	iter = q.head;
	while (iter != nullptr) {
		this->push_back(iter->e);
		iter = iter->next;
	}
}

template< class value_type >
bool linkedqueue<value_type>::operator==(const linkedqueue<value_type>& q) {
	if (this->empty() && q.empty()) {
		return true;
	}
	else if (this->empty() != q.empty()) {
		return false;
	}
	else {
		node<value_type>* iter;
		node<value_type>* iterq;
		iter = this->head;
		iterq = q.head;
		while (iter != nullptr && iterq != nullptr) {
			if (iter->e != iterq->e) {
				return false;
			}
			iter = iter->next;
			iterq = iterq->next;
		}
		if (iter != iterq) {
			return false;
		}
		return true;
	}
}



#endif // !LISTQUEUE_HPP_INCLUDED
