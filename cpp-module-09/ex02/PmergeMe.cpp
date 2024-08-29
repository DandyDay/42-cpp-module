#include "PmergeMe.hpp"
#include <sstream>
#include <stdexcept>
#include <iostream>

const int PmergeMe::jacobsthalNumbers[] = {
	1,			3,			5,			11,			21,			43,			85,
	171,		341,		683,		1365,		2731,		5461,		10923,
	21845,		43691,		87381,		174763,		349525,		699051,		1398101,
	2796203,	5592405,	11184811,	22369621,	44739243,	89478485,	178956971,
	357913941,	715827883,	1431655765};

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		values.push_back(PmergeMe::stoi(argv[i]));
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	if (this != &other)
	{
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	for (size_t i = 0; i < numVector.size(); i++)
		delete numVector[i];
	numVector.clear();
	for (size_t i = 0; i < numDeque.size(); i++)
		delete numDeque[i];
	numDeque.clear();
	values.clear();
}

int PmergeMe::stoi(std::string &str)
{
	std::stringstream ss(str);
	int ret;
	ss >> ret;
	if (ret <= 0 || !ss.eof() || ss.fail())
		throw std::invalid_argument("invalid input");
	return ret;
}

int PmergeMe::stoi(char *str)
{
	std::stringstream ss(str);
	int ret;
	ss >> ret;
	if (ret <= 0 || !ss.eof() || ss.fail())
		throw std::invalid_argument("invalid input");
	return ret;
}

void PmergeMe::measureSortingByVector()
{
	clock_t start = std::clock();
	for (size_t i = 0; i < values.size(); i++)
	{
		numVector.push_back(new Pair(values[i], NULL, NULL));
	}
	sort(numVector);
	clock_t end = std::clock();
	timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 100;
}

void PmergeMe::measureSortingByDeque()
{
	clock_t start = std::clock();
	for (size_t i = 0; i < values.size(); i++)
	{
		numDeque.push_back(new Pair(values[i], NULL, NULL));
	}
	sort(numDeque);
	clock_t end = std::clock();
	timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 100;
}

void PmergeMe::sort(std::vector<Pair *> &vec)
{
	if (vec.size() == 1)
		return ;

	// make pairs
	std::vector<Pair *> pairList;
	for (size_t i = 1; i < vec.size(); i+=2)
	{
		if (vec[i - 1]->max < vec[i]->max)
			pairList.push_back(new Pair(vec[i]->max, vec[i], vec[i - 1]));
		else
			pairList.push_back(new Pair(vec[i - 1]->max, vec[i - 1], vec[i]));
	}

	// recursive call
	sort(pairList);

	// main chain
	std::vector<Pair *> mainChain;
	mainChain.push_back(pairList[0]->small);
	for (size_t i = 0; i < pairList.size(); i++)
		mainChain.push_back(pairList[i]->big);

	// insertion
	// Steinhaus method
	size_t jIdx = 0;
	int restPairs = pairList.size() - 1 + vec.size() % 2;
	for (; jIdx < 33; jIdx++)
	{
		if (restPairs <= jacobsthalNumbers[jIdx] - 1)
			break;
	}

	// insert small ones
	int first, last;
	for (size_t i = 1; i < jIdx; i++)
	{
		last = jacobsthalNumbers[i - 1];
		first = jacobsthalNumbers[i] - 1;
		for (int i = first; i >= last; i--)
			binaryInsert(mainChain, first + last + 1, pairList[i]->small);
	}

	// insert odd element
	if (vec.size() % 2 == 1)
		binaryInsert(mainChain, mainChain.size(), vec[vec.size() - 1]);

	// insert rest
	first = pairList.size() - 1;
	last = jacobsthalNumbers[jIdx - 1];
	for (int i = first; i >= last; i--)
		binaryInsert(mainChain, first + last + 1, pairList[i]->small);

	for (size_t i = 0 ; i < pairList.size(); i++)
		delete pairList[i];

	vec = mainChain;
}

void PmergeMe::sort(std::deque<Pair *> &deq)
{
	if (deq.size() == 1)
		return ;

	// make pairs
	std::deque<Pair *> pairList;
	for (size_t i = 1; i < deq.size(); i += 2)
	{
		if (deq[i - 1]->max < deq[i]->max)
			pairList.push_back(new Pair(deq[i]->max, deq[i], deq[i - 1]));
		else
			pairList.push_back(new Pair(deq[i - 1]->max, deq[i - 1], deq[i]));
	}

	// recursive call
	sort(pairList);

	// main chain
	std::deque<Pair *> mainChain;
	mainChain.push_back(pairList[0]->small);
	for (size_t i = 0; i < pairList.size(); i++)
		mainChain.push_back(pairList[i]->big);

	// insertion
	// Steinhaus method
	size_t jIdx = 0;
	int restPairs = pairList.size() - 1 + deq.size() % 2;
	for (; jIdx < 33; jIdx++)
	{
		if (restPairs <= jacobsthalNumbers[jIdx] - 1)
			break;
	}

	// insert small ones
	int first, last;
	for (size_t i = 1; i < jIdx; i++)
	{
		last = jacobsthalNumbers[i - 1];
		first = jacobsthalNumbers[i] - 1;
		for (int i = first; i >= last; i--)
			binaryInsert(mainChain, first + last + 1, pairList[i]->small);
	}

	// insert odd element
	if (deq.size() % 2 == 1)
		binaryInsert(mainChain, mainChain.size(), deq[deq.size() - 1]);

	// insert rest
	first = pairList.size() - 1;
	last = jacobsthalNumbers[jIdx - 1];
	for (int i = first; i >= last; i--)
		binaryInsert(mainChain, first + last + 1, pairList[i]->small);

	for (size_t i = 0 ; i < pairList.size(); i++)
		delete pairList[i];

	deq = mainChain;
}

void PmergeMe::binaryInsert(std::vector<Pair *> &vec, size_t len, Pair *val)
{
	int start, end, mid, midVal;

	start = 0;
	end = len - 1;

	while (start <= end)
	{
		mid = (start + end) / 2;
		midVal = vec[mid]->max;

		if (midVal > val->max)
			end = mid - 1;
		else if (midVal < val->max)
			start = mid + 1;
		else
		{
			vec.insert(vec.begin() + mid, val);
			return;
		}
	}
	vec.insert(vec.begin() + start, val);
}

void PmergeMe::binaryInsert(std::deque<Pair *> &deq, size_t len, Pair *val)
{
	int start, end, mid, midVal;

	start = 0;
	end = len - 1;

	while (start <= end)
	{
		mid = (start + end) / 2;
		midVal = deq[mid]->max;

		if (midVal > val->max)
			end = mid - 1;
		else if (midVal < val->max)
			start = mid + 1;
		else
		{
			deq.insert(deq.begin() + mid, val);
			return;
		}
	}
	deq.insert(deq.begin() + start, val);
}

void PmergeMe::printResult()
{
	measureSortingByVector();
	measureSortingByDeque();

	std::cout << "Before:\t";
	for (size_t i = 0; i < values.size(); i++)
		std::cout << values[i] << " ";
	std::cout << std::endl;

	std::cout << "After:\t";
	for (std::vector<PmergeMe::Pair *>::iterator it = numVector.begin(); it != numVector.end(); it++)
		std::cout << **it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << values.size() << " elements with std::vector : " << timeVector << " ms" << std::endl;
	std::cout << "Time to process a range of " << values.size() << " elements with std::deque :  " << timeDeque << " ms" << std::endl;
}

PmergeMe::Pair::Pair()
{
}

PmergeMe::Pair::Pair(int max, Pair *big, Pair *small) : max(max), big(big), small(small)
{
}

PmergeMe::Pair::Pair(const Pair &other) : max(other.max), big(other.big), small(other.small)
{
}

PmergeMe::Pair &PmergeMe::Pair::operator=(const Pair &other)
{
	if (this != &other)
	{
		delete this->big;
		delete this->small;
		this->max = other.max;
		this->big = other.big;
		this->small = other.small;
	}
	return *this;
}

PmergeMe::Pair::~Pair()
{
}

std::ostream &operator<<(std::ostream &os, PmergeMe::Pair &p)
{
	// TODO: insert return statement here
	if (p.big == NULL && p.small == NULL)
		os << p.max;
	else
		os << "[" << *p.big << ", " << *p.small << "]";
	return os;
}
