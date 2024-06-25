#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <vector>

template <typename T, typename _Container = std::deque<T> >
class MutantStack : public std::stack<T, _Container>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack &other){
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

	typedef MutantStack<T, _Container>                                         stack_type;
	typedef typename stack_type::stack::container_type::iterator               iterator;
	typedef typename stack_type::stack::container_type::const_iterator         const_iterator;
	typedef typename stack_type::stack::container_type::reverse_iterator       reverse_iterator;
	typedef typename stack_type::stack::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}


private:
	std::deque<int> v;
};

#endif
