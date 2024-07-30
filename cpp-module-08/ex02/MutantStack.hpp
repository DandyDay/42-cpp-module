#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename _Container = std::deque<T> >
class MutantStack : public std::stack<T, _Container>
{
public:
	typedef MutantStack<T, _Container>                                         stack_type;
	typedef typename stack_type::stack::container_type::iterator               iterator;
	typedef typename stack_type::stack::container_type::const_iterator         const_iterator;
	typedef typename stack_type::stack::container_type::reverse_iterator       reverse_iterator;
	typedef typename stack_type::stack::container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack() : std::stack<T, _Container>() {}
	MutantStack(const MutantStack &other) : std::stack<T, _Container>()
	{
		this->c = other.c;
	}
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
		{
			this->c = other.c;
		}
		return *this;
	}
	~MutantStack() {}

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
