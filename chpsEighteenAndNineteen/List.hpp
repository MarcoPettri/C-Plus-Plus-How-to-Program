// List.hpp
/*
	List class-template definition.

*/

#ifndef LIST_HPP
#define LIST_HPP

#include<iostream>
#include<initializer_list>
#include "ListNode.hpp"

template<typename NODETYPE>
class List
{
	
public:
	List() = default;

	explicit List(const NODETYPE& val) {
		this->insertAtBack(val);
	}

	List(const std::initializer_list<NODETYPE>& list) {
		this->insertAtBack(list);
	}

	List(const List<NODETYPE>& list) {

		for (auto it{ list.begin() }, end{ list.end() }; it != end; ++it) {
			NODETYPE elem{ *it };
			this->insertAtBack(elem);
		}
	}
	
	~List() {
		if (!isEmpty()) {
		
			ListNode<NODETYPE>* currentPtr{ firstPtr };
			ListNode<NODETYPE>* tempPtr{ nullptr };

			while (currentPtr != nullptr) {

				tempPtr = currentPtr;
				
				currentPtr = currentPtr->nextPtr;

				delete tempPtr;
			}
		}
	
	}

	void insertAtFront(const NODETYPE& value) {
		
		ListNode<NODETYPE>* newPtr{ getNewNode(value) };

		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;

		}
		else {
			newPtr->nextPtr = firstPtr;
			firstPtr = newPtr;
		}
	}
	
	void insertAtFront(const std::initializer_list<NODETYPE>& list) {

		for (const auto& elem : list) {
			this->insertAtFront(elem);
		}
	}
	
	void insertAtBack(const NODETYPE& value) {

		ListNode<NODETYPE>* newPtr{ getNewNode(value) };

		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;
		}
		else {
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}

	void insertAtBack(const std::initializer_list<NODETYPE>& list) {

		for (const auto& elem : list) {
			this->insertAtBack(elem);
		}
	}

	bool removeFromFront(NODETYPE& value) {
		
		if (isEmpty()) {
			return false; 
		}
		else {

			ListNode<NODETYPE>* tempPtr{ firstPtr };

			if (firstPtr == lastPtr) {
				firstPtr = lastPtr = nullptr;

			}
			else {
				firstPtr = firstPtr->nextPtr;
			}

			value = tempPtr->data;
			delete tempPtr;
			
			return true;
		}
	}


	bool removeFromBack(NODETYPE& value) {

		if (isEmpty()) { 
			return false; 
		}
		else {
			ListNode<NODETYPE>* tempPtr{ lastPtr }; 

			if (firstPtr == lastPtr) { 
				firstPtr = lastPtr = nullptr; 
			}
			else {

				ListNode<NODETYPE>* currentPtr{ firstPtr };
       
				while (currentPtr->nextPtr != lastPtr) {
					currentPtr = currentPtr->nextPtr; 
				}

				lastPtr = currentPtr; 
				currentPtr->nextPtr = nullptr; 
			}

			value = tempPtr->data; 
			delete tempPtr; 
			return true; 
		}
	}


	bool isEmpty() const {
		return firstPtr == nullptr;
	}


	void print() const {

		if (isEmpty()) {
			std::cout << "The list is empty\n" << std::endl;
			return;
		}

		ListNode<NODETYPE>* currentPtr{ firstPtr };

		std::cout << "The List is: ";

		while (currentPtr != nullptr) {
			std::cout << currentPtr->data << " ";
			currentPtr = currentPtr->nextPtr;
		}
		std::cout <<  "\n" << std::endl;
	}
	
	int size() const {
		int size{};

		for (auto it{ this->begin() }, end{ this->end() }; 
			it != end; ++size, ++it);

		return size;
	}

	struct Iterator
	{
		using pointer = ListNode<NODETYPE>*;
		using value_type = NODETYPE*;
		using reference = NODETYPE&;

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return m_ptr->data; }

		value_type operator->() { return &(m_ptr->data); }

		Iterator& operator++() {

			m_ptr = m_ptr->nextPtr;
			return *this;
		}

		Iterator operator++(int) {

			Iterator tmp = *this;
			++(*this);
			return tmp;
		}

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
	};


	struct reversed_iterator
	{
		using pointer = ListNode<NODETYPE>*;
		using value_type = NODETYPE*;
		using reference = NODETYPE&;

		reversed_iterator(pointer ptr) : m_ptr(ptr), c_ptr(ptr)
		{
			if (m_ptr != nullptr) {

				while (c_ptr->nextPtr != nullptr) {
					c_ptr = c_ptr->nextPtr;
				}
			}
		}

		reference operator*() const { return c_ptr->data; }

		value_type operator->() { return &(c_ptr->data); }

		reversed_iterator& operator++() {

			if (c_ptr == m_ptr) {
				c_ptr = nullptr;
			}
			else {
				pointer temp{ m_ptr };
				while (temp->nextPtr != c_ptr) {

					temp = temp->nextPtr;
					
				}
				c_ptr = temp;
			}
			return *this;
		}

		reversed_iterator operator++(int) {

			reversed_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		friend bool operator== (const reversed_iterator& a, const reversed_iterator& b) { return a.c_ptr == b.c_ptr; };
		friend bool operator!= (const reversed_iterator& a, const reversed_iterator& b) { return a.c_ptr != b.c_ptr; };

	private:
		pointer m_ptr; // First Ptr
		pointer c_ptr; //  Current Ptr
	};

	Iterator begin() const  noexcept { return   Iterator(firstPtr); }
	Iterator end()   const  noexcept { return   Iterator(lastPtr->nextPtr); }
	reversed_iterator rbegin() const  noexcept { return   reversed_iterator(firstPtr); }
	reversed_iterator rend()   const  noexcept { return   reversed_iterator(lastPtr->nextPtr); }


private:
	ListNode<NODETYPE>* firstPtr{ nullptr };
	ListNode<NODETYPE>* lastPtr{ nullptr };


	ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
		return new ListNode<NODETYPE>{ value };
	}

};

#endif // !LIST_HPP
