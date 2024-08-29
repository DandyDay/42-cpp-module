#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
class PmergeMe
{
public:
	class Pair {
	public:
		Pair(int max, Pair *big, Pair *small);
		Pair(const Pair &other);
		Pair &operator=(const Pair &other);
		~Pair();

		int max;
		Pair *big;
		Pair *small;

	private:
		Pair();
	};
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void analyze();

private:
	PmergeMe();
	static const int jacobsthalNumbers[];

	std::vector<int> values;
	std::vector<Pair *> numVector;
	std::deque<Pair *> numDeque;
	double timeVector;
	double timeDeque;

	static int stoi(std::string &str);
	static int stoi(char *str);

	void measureSortingByVector();
	void measureSortingByDeque();

	void sort(std::vector<Pair *> &vec);
	void sort(std::deque<Pair *> &deq);

	void binaryInsert(std::vector<Pair *> &vec, size_t len, Pair *val);
	void binaryInsert(std::deque<Pair *> &deq, size_t len, Pair *val);
};

std::ostream &operator<<(std::ostream &os, PmergeMe::Pair &p);

#endif
