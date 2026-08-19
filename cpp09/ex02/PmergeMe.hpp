#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <sys/time.h>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <limits>
class PmergeMe
{
private:
        std::vector<int> sequence;
        std::deque<int>  deque_seq;
        std::vector<int> mergeInsertVec(std::vector<int> data);
        std::deque<int> mergeInsertDeq(std::deque<int> data);
        std::vector<int> buildT(int maxNeeded);
        std::deque<int> buildTD(int maxNeeded);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& p);
        PmergeMe& operator=(const PmergeMe& p);
        ~PmergeMe();

        void parse(std::string arg);
        void sort();
        void showBefore();
        void showAfter();
};