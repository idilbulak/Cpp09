#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstdio>

#define K 5

void insertionSortVec(std::vector<int>& A, int p, int q);
void mergeVec(std::vector<int>& A, int p, int q, int r);
void mergeInsertVec(std::vector<int>& A, int p, int r);

void insertionSortLst(std::list<int>& A, int p, int q) ;

void mergeLst(std::list<int>& A, int p, int q, int r);

#endif

// https://iq.opengenus.org/merge-insertion-sort/