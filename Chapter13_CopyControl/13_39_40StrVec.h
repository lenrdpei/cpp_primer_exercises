/*
 * This file contains template from "C++ Primer, Fifth Edition", by Stanley B.
 */

#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>

// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec
{
public:
	// copy control members
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

	StrVec(const StrVec &src) // copy constructor
	{
		auto data = alloc_n_copy(src.elements, src.first_free);
		elements = data.first;
		first_free = cap = data.second;
	}
	StrVec &operator=(const StrVec &rhs) // copy assignment
	{
		auto data = alloc_n_copy(rhs.elements, rhs.first_free);
		free();
		elements = data.first;
		first_free = cap = data.second;
		return *this;
	}

	~StrVec() // destructor
	{
		free();
	}

	// additional constructor
	StrVec(const std::initializer_list<std::string> &ls)
	{
		auto data = alloc_n_copy(ls.begin(), ls.end());
		elements = data.first;
		first_free = cap = data.second;
	}

	std::string *begin() { return elements; }
	std::string *end() { return first_free; }
	void push_back(const std::string &s) // copy the element
	{
		chk_n_alloc();
		alloc.construct(first_free++, s);
	}

	// add elements
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t newcp)
	{
		if (newcp <= capacity())
			return;
		auto newdata = alloc.allocate(newcp);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcp;
	}

private:
	static std::allocator<std::string> alloc; // allocates the elements

	// utility functions:
	//  used by members that add elements to the StrVec
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	// used by the copy constructor, assignment operator, and destructor
	std::pair<std::string *, std::string *> alloc_n_copy(const std::string *b, const std::string *e)
	{
		std::string *data = alloc.allocate(e - b);
		return {data, std::uninitialized_copy(b, e, data)};
	}
	void free() // destroy the elements and free the space
	{
		if (elements)
		{
			for (auto p = elements; p != first_free; ++p)
				alloc.destroy(p);
			alloc.deallocate(elements, cap - elements);
		}
	}
	void reallocate() // get more space and copy the existing elements
	{
		size_t cp = size() ? 2 * size() : 1;
		std::string *data = alloc.allocate(cp);
		std::string *dest = data;
		std::string *elem = elements;
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = data;
		first_free = dest;
		cap = data + cp;
	}
	std::string *elements;	 // pointer to the first element in the array
	std::string *first_free; // pointer to the first free element in the array
	std::string *cap;		 // pointer to one past the end of the array
};

#endif
