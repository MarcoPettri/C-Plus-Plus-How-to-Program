// ListNode.hpp
/*

	ListNode class-template definition.
*/


#ifndef LISTNODE_HPP
#define LISTNODE_HPP


template<typename NODETYPE> class List;

template<typename NODETYPE>
class ListNode {

	friend class List<NODETYPE>;

public:
	explicit ListNode(const NODETYPE& info)
		: data{info}, nextPtr(nullptr) { }

	NODETYPE getData() const { return data; }

private:
	NODETYPE data;
	ListNode<NODETYPE>* nextPtr;
};


#endif