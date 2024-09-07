#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <string>
#include <vector>

class PmergeMe {
public:
	PmergeMe(void);
	PmergeMe(PmergeMe const &rhs);
	PmergeMe &operator=(PmergeMe const &rhs);
	~PmergeMe(void);

	bool   parsing(char **argv, std::vector<int> &vec, std::list<int> &lst);
	double mergeInsertionSort(std::vector<int> &vec);
	double mergeInsertionSort(std::list<int> &lst);

private:
	std::vector<int> mainVec;
	std::vector<int> auxVec;
	std::list<int>	 mainLst;
	std::list<int>	 auxLst;

	void			 createPairs(std::list<int> const &lst);
	void			 createPairs(std::vector<int> const &vec);
	void			 sortVecPairs(void);
	void			 sortLstPairs(void);
	void			 binarySearchLst(int value);
	void			 binarySearchVec(int value);
	std::vector<int> createJacobSeq(size_t size);
};

#endif
