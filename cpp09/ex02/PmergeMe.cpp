#include "PmergeMe.hpp"
#include <cmath>
#include <ctime>

PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(PmergeMe const &rhs) {
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this == &rhs) {
		return (*this);
	}
	this->mainLst = rhs.mainLst;
	this->auxLst = rhs.auxLst;
	this->auxVec = rhs.auxVec;
	this->mainVec = rhs.mainVec;
	return (*this);
}

PmergeMe::~PmergeMe(void) {
}

std::vector<int> PmergeMe::createJacobSeq(size_t size) {
	std::vector<int> jacobIdx;
	std::vector<int> jacobSeq;
	size_t			 i = 2;

	jacobSeq.push_back(0);
	jacobSeq.push_back(1);
	while (true) {
		jacobSeq.push_back(2 * jacobSeq[i - 2] + jacobSeq[i - 1]);
		size_t value = jacobSeq[i];
		size_t old = jacobSeq[i - 1];
		++i;
		jacobIdx.push_back(static_cast<int>(value));
		while (--value > old) {
			if (value > size) {
				continue;
			}
			jacobIdx.push_back(static_cast<int>(value));
		}
		if (jacobIdx.size() >= size) {
			return (jacobIdx);
		}
	}
}

void PmergeMe::createPairs(std::list<int> const &lst) {
	std::list<int>::const_iterator curr, next;

	curr = lst.begin();
	next = lst.begin();

	++next;
	while (curr != lst.end()) {
		if (next == lst.end()) {
			this->auxLst.push_back(*curr);
			break;
		}
		if (*curr > *next) {
			this->mainLst.push_back(*curr);
			this->auxLst.push_back(*next);
		} else {
			this->mainLst.push_back(*next);
			this->auxLst.push_back(*curr);
		}
		std::advance(curr, 2);
		std::advance(next, 2);
	}
}

void PmergeMe::sortLstPairs(void) {
	std::list<int>::iterator currMain = this->mainLst.begin();
	std::list<int>::iterator currAux = this->auxLst.begin();
	std::list<int>::iterator nextMain = this->mainLst.begin();
	std::list<int>::iterator nextAux = this->auxLst.begin();

	nextMain++;
	nextAux++;

	if (currMain == this->mainLst.end()) {
		return;
	}
	while (nextMain != this->mainLst.end()) {
		if (nextMain == this->mainLst.end()) {
			break;
		}
		if (*currMain > *nextMain) {
			std::iter_swap(currMain, nextMain);
			std::iter_swap(currAux, nextAux);
			currMain = this->mainLst.begin();
			currAux = this->auxLst.begin();
			nextMain = this->mainLst.begin();
			nextAux = this->auxLst.begin();
			nextMain++;
			nextAux++;
		} else {
			currMain++;
			currAux++;
			nextMain++;
			nextAux++;
		}
	}
}

void PmergeMe::createPairs(std::vector<int> const &vec) {
	std::vector<int>::const_iterator it;

	it = vec.begin();
	while (it != vec.end()) {
		if ((it + 1) == vec.end()) {
			this->auxVec.push_back(*it);
			break;
		}
		if (*it > *(it + 1)) {
			this->mainVec.push_back(*it);
			this->auxVec.push_back(*(it + 1));
		} else {
			this->mainVec.push_back(*(it + 1));
			this->auxVec.push_back(*it);
		}
		it += 2;
	}
}

void PmergeMe::sortVecPairs(void) {
	std::vector<int>::iterator currMain = this->mainVec.begin();
	std::vector<int>::iterator currAux = this->auxVec.begin();

	if (currMain == this->mainVec.end()) {
		return;
	}
	while (currMain + 1 != this->mainVec.end()) {
		if (*currMain > *(currMain + 1)) {
			std::iter_swap(currMain, currMain + 1);
			std::iter_swap(currAux, currAux + 1);
			currMain = this->mainVec.begin();
			currAux = this->auxVec.begin();
		} else {
			++currMain;
			++currAux;
		}
	}
}

void PmergeMe::binarySearchVec(int value) {
	int left = 0;
	int right = this->mainVec.size() - 1;

	while (left <= right) {
		int mid = std::floor((left + right) / 2);
		if (value < this->mainVec[mid]) {
			right = mid - 1;
		} else if (value > this->mainVec[mid]) {
			left = mid + 1;
		} else {
			this->mainVec.insert(this->mainVec.begin() + mid, value);
			return;
		}
	}
	this->mainVec.insert(this->mainVec.begin() + left, value);
}

void PmergeMe::binarySearchLst(int value) {
	int						 left = 0;
	int						 right = this->mainLst.size() - 1;
	std::list<int>::iterator it;

	while (left <= right) {
		int mid = std::floor((left + right) / 2);
		it = this->mainLst.begin();
		std::advance(it, mid);
		if (value < *it) {
			right = mid - 1;
		} else if (value > *it) {
			left = mid + 1;
		} else {
			this->mainLst.insert(it, value);
			return;
		}
	}

	it = this->mainLst.begin();
	std::advance(it, left);
	this->mainLst.insert(it, value);
}

double PmergeMe::mergeInsertionSort(std::vector<int> &vec) {
	std::vector<int>::iterator it;
	struct timespec			   begin, end;

	clock_gettime(CLOCK_MONOTONIC, &begin);
	this->createPairs(vec);
	sortVecPairs();
	std::vector<int> jacobIdx = this->createJacobSeq(this->auxVec.size());

	int idx = -1;
	while (++idx >= 0) {
		it = this->auxVec.begin();
		if (static_cast<size_t>(jacobIdx[idx] - 1) >= this->auxVec.size()) {
			continue;
		}
		binarySearchVec(this->auxVec[jacobIdx[idx] - 1]);
		if (this->mainVec.size() == vec.size()) {
			break;
		}
	}
	vec.clear();
	vec = this->mainVec;
	clock_gettime(CLOCK_MONOTONIC, &end);
	return ((end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1e9);
}

double PmergeMe::mergeInsertionSort(std::list<int> &lst) {
	std::list<int>::iterator it;
	struct timespec			 begin, end;

	clock_gettime(CLOCK_MONOTONIC, &begin);
	this->createPairs(lst);
	sortLstPairs();

	std::vector<int> jacobIdx = this->createJacobSeq(this->auxLst.size());

	int idx = -1;
	while (++idx >= 0) {
		it = this->auxLst.begin();
		if (static_cast<size_t>(jacobIdx[idx] - 1) >= this->auxLst.size()) {
			continue;
		}
		std::advance(it, jacobIdx[idx] - 1);
		binarySearchLst(*it);
		if (this->mainLst.size() == lst.size()) {
			break;
		}
	}
	lst.clear();
	lst = this->mainLst;
	clock_gettime(CLOCK_MONOTONIC, &end);
	return ((end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1e9);
}

bool PmergeMe::parsing(char **argv, std::vector<int> &vec, std::list<int> &lst) {
	std::stringstream stream;
	std::string		  str(argv[0]);
	int				  nbr;

	for (int i = 1; argv[i]; ++i) {
		str += " " + std::string(argv[i]);
	}
	stream << str;
	while (!stream.eof()) {
		if (!(stream >> nbr)) {
			return (false);
		}
		if (nbr < 0) {
			return (false);
		}
		lst.push_back(nbr);
		vec.push_back(nbr);
	}
	return (true);
}
