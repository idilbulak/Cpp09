#include "PmergeMe.hpp"

void insertionSortLst(std::list<int>& A, int p, int q) {
	std::list<int>::iterator it = A.begin();
	advance(it, p);
	for (int i = p; i < q; i++) {
		int tempVal = *(next(it));
		std::list<int>::iterator j = next(it);
		while (j != A.begin() && *(prev(j)) > tempVal) {
			*(j) = *(prev(j));
			j--;
		}
		*(j) = tempVal;
		it++;
	}
	// std::list<int> temp(A.begin(), next(it));
	// for (std::list<int>::iterator it = temp.begin(); it != temp.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
}

void mergeLst(std::list<int>& A, int p, int q, int r) {
	std::list<int> LA(A.begin(), next(A.begin(), q - p + 1));
	std::list<int> RA(next(A.begin(), q+1), next(A.begin(), r+1));
	int RIDX = 0;
	int LIDX = 0;
	std::list<int>::iterator it = A.begin();
	advance(it, p);
	while (it != next(A.begin(), r+1)) {
		if (RIDX == RA.size()) {
			*(it) = LA.front();
			LA.pop_front();
			LIDX++;
		} else if (LIDX == LA.size()) {
			*(it) = RA.front();
			RA.pop_front();
			RIDX++;
		} else if (RA.front() > LA.front()) {
			*(it) = LA.front();
			LA.pop_front();
			LIDX++;
		} else {
			*(it) = RA.front();
			RA.pop_front();
			RIDX++;
		}
		it++;
	}
}


// int main() {
//     std::list<int> A;
//     A.push_back(5);
//     A.push_back(2);
//     A.push_back(4);
//     A.push_back(6);
//     A.push_back(1);
//     A.push_back(3);
//     int n = A.size();
// 	insertionSortLst(A, 0, K);
// 	mergeLst(A, 0, K, A.size()-1);
	// for (std::list<int>::iterator it = A.begin(); it != A.end(); ++it)
	// std::cout << *it << " ";
	// std::cout << std::endl;
	// return 0;
// }

