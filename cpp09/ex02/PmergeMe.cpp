#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) : sequence(src.sequence), deque_seq(src.deque_seq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
    if (this != &rhs)
    {
        sequence = rhs.sequence;
        deque_seq = rhs.deque_seq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse(std::string input_str)
{
    for (size_t idx = 0; idx < input_str.size(); idx++) 
    {
        if (!isdigit(input_str[idx]))
           throw std::runtime_error("Invalid input: encountered a non-numeric character.");
    }
    long parsed_val = std::atol(input_str.c_str());
    if (parsed_val < 0 || parsed_val > std::numeric_limits<int>::max() || parsed_val < std::numeric_limits<int>::min())
        throw std::runtime_error("Invalid input: value must be a positive integer within bounds.");
    
    sequence.push_back(static_cast<int>(parsed_val));
    deque_seq.push_back(static_cast<int>(parsed_val));
}

void PmergeMe::showBefore()
{
    std::cout << "Before: ";
    for(size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showAfter()
{
    std::cout << "After:  ";
    for(size_t i = 0; i < sequence.size(); i++)
    {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::buildT(int upper_limit)
{
    std::vector<int> jacobsthal_seq;
    jacobsthal_seq.push_back(0); 
    jacobsthal_seq.push_back(1); 

    int step = 2;
    while (true)
    {
        int multiplier = -1;
        if (step % 2 == 0)
        {
            multiplier = 1;
        }

        int current_j_val = ((1 << (step + 1)) + multiplier) / 3;
        jacobsthal_seq.push_back(current_j_val);
        if (current_j_val >= upper_limit)
        {
            break;
        }
        step++;
    }
    return jacobsthal_seq;
}

std::deque<int> PmergeMe::buildTD(int upper_limit)
{
    std::deque<int> jacobsthal_seq;
    jacobsthal_seq.push_back(0); 
    jacobsthal_seq.push_back(1); 

    int step = 2;
    while (true)
    {
        int multiplier = -1;
        if (step % 2 == 0)
        {
            multiplier = 1;
        }

        int current_j_val = ((1 << (step + 1)) + multiplier) / 3;
        jacobsthal_seq.push_back(current_j_val);
        if (current_j_val >= upper_limit)
        {
            break;
        }
        step++;
    }
    return jacobsthal_seq;
}

std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> input_container)
{
    if (input_container.size() <= 1)
        return input_container;
    
    std::vector<std::pair<int, int> > paired_elements;
    int unpaired_item = -1;
    bool is_odd_sized = false;
    
    for (size_t i = 0; i + 1 < input_container.size(); i += 2)
    {
        if (input_container[i] > input_container[i + 1])
        {
            paired_elements.push_back(std::make_pair(input_container[i], input_container[i + 1]));
        } else
        {
            paired_elements.push_back(std::make_pair(input_container[i + 1], input_container[i]));
        }
    }
    
    if (input_container.size() % 2 != 0)
    {
        unpaired_item = input_container.back();
        is_odd_sized = true;
    }
    
    std::vector<int> main_chain_candidates;
    for (size_t i = 0; i < paired_elements.size(); i++)
    {
        main_chain_candidates.push_back(paired_elements[i].first);
    }
    
    main_chain_candidates = mergeInsertVec(main_chain_candidates);
    
    std::vector<bool> mapping_flags(paired_elements.size(), false);
    std::vector<std::pair<int, int> > sorted_pairs;
    
    for (size_t i = 0; i < main_chain_candidates.size(); i++)
    {
        for (size_t j = 0; j < paired_elements.size(); j++)
        {
            if (!mapping_flags[j] && paired_elements[j].first == main_chain_candidates[i])
            {
                sorted_pairs.push_back(paired_elements[j]);
                mapping_flags[j] = true;
                break;
            }
        }
    }
    
    std::vector<int> final_sequence;
    if (!sorted_pairs.empty())
    {
        final_sequence.push_back(sorted_pairs[0].second);
    }
    for (size_t i = 0; i < sorted_pairs.size(); i++)
    {
        final_sequence.push_back(sorted_pairs[i].first);
    }
    
    std::vector<int> pend_elements;
    for (size_t i = 0; i < sorted_pairs.size(); i++)
    {
        pend_elements.push_back(sorted_pairs[i].second);
    }
    if (is_odd_sized)
    {
        pend_elements.push_back(unpaired_item);
    }
    
    int pend_size = static_cast<int>(pend_elements.size());
    if (pend_size > 1)
    { 
        std::vector<int> jacob_order = buildT(pend_size);
        for (size_t idx = 2; idx < jacob_order.size(); idx++)
        {
            int group_end = jacob_order[idx];
            if (jacob_order[idx] >= pend_size)
            {
                group_end = pend_size;
            }
            int group_start = jacob_order[idx - 1] + 1;
            for (int pos = group_end; pos >= group_start; pos--)
            {
                int target_val = pend_elements[pos - 1];
                std::vector<int>::iterator search_bound = final_sequence.end();
                if (pos - 1 < static_cast<int>(sorted_pairs.size()))
                {
                    int paired_main_val = sorted_pairs[pos - 1].first;
                    for (std::vector<int>::iterator it = final_sequence.begin(); it != final_sequence.end(); ++it)
                    {
                        if (*it == paired_main_val)
                        {
                            search_bound = it;
                            break;
                        }
                    }
                }
                std::vector<int>::iterator insertion_point = std::lower_bound(final_sequence.begin(), search_bound, target_val);
                final_sequence.insert(insertion_point, target_val);
            }
        }
    }
    return final_sequence;
}

std::deque<int> PmergeMe::mergeInsertDeq(std::deque<int> input_container)
{
    if (input_container.size() <= 1)
        return input_container;
        
    std::deque<std::pair<int, int> > paired_elements;
    int unpaired_item = -1;
    bool is_odd_sized = false;
    
    for (size_t i = 0; i + 1 < input_container.size(); i += 2)
    {
        if (input_container[i] > input_container[i + 1])
        {
            paired_elements.push_back(std::make_pair(input_container[i], input_container[i + 1]));
        } else
        {
            paired_elements.push_back(std::make_pair(input_container[i + 1], input_container[i]));
        }
    }
    
    if (input_container.size() % 2 != 0)
    {
        unpaired_item = input_container.back();
        is_odd_sized = true;
    }
    
    std::deque<int> main_chain_candidates;
    for (size_t i = 0; i < paired_elements.size(); i++)
    {
        main_chain_candidates.push_back(paired_elements[i].first);
    }
    
    main_chain_candidates = mergeInsertDeq(main_chain_candidates);
    
    std::deque<bool> mapping_flags(paired_elements.size(), false);
    std::deque<std::pair<int, int> > sorted_pairs;
    
    for (size_t i = 0; i < main_chain_candidates.size(); i++)
    {
        for (size_t j = 0; j < paired_elements.size(); j++)
        {
            if (!mapping_flags[j] && paired_elements[j].first == main_chain_candidates[i])
            {
                sorted_pairs.push_back(paired_elements[j]);
                mapping_flags[j] = true;
                break;
            }
        }
    }
    
    std::deque<int> final_sequence;
    if (!sorted_pairs.empty())
    {
        final_sequence.push_back(sorted_pairs[0].second);
    }
    for (size_t i = 0; i < sorted_pairs.size(); i++)
    {
        final_sequence.push_back(sorted_pairs[i].first);
    }
    
    std::deque<int> pend_elements;
    for (size_t i = 0; i < sorted_pairs.size(); i++)
    {
        pend_elements.push_back(sorted_pairs[i].second);
    }
    if (is_odd_sized)
    {
        pend_elements.push_back(unpaired_item);
    }
    
    int pend_size = static_cast<int>(pend_elements.size());
    if (pend_size > 1)
    { 
        std::deque<int> jacob_order = buildTD(pend_size);

        for (size_t idx = 2; idx < jacob_order.size(); idx++)
        {
            int group_end = jacob_order[idx];
            if (jacob_order[idx] >= pend_size)
            {
                group_end = pend_size;
            }
            int group_start = jacob_order[idx - 1] + 1;
            for (int pos = group_end; pos >= group_start; pos--)
            {
                int target_val = pend_elements[pos - 1];
                std::deque<int>::iterator search_bound = final_sequence.end();
                if (pos - 1 < static_cast<int>(sorted_pairs.size()))
                {
                    int paired_main_val = sorted_pairs[pos - 1].first;
                    for (std::deque<int>::iterator it = final_sequence.begin(); it != final_sequence.end(); ++it)
                    {
                        if (*it == paired_main_val)
                        {
                            search_bound = it;
                            break;
                        }
                    }
                }
                std::deque<int>::iterator insertion_point = std::lower_bound(final_sequence.begin(), search_bound, target_val);
                final_sequence.insert(insertion_point, target_val);
            }
        }
    }
    return final_sequence;
}

void PmergeMe::sort()
{
    struct timeval begin_vec, finish_vec;
    gettimeofday(&begin_vec, NULL);
    sequence = mergeInsertVec(sequence);
    gettimeofday(&finish_vec, NULL);
    
    double duration_vec = (finish_vec.tv_sec - begin_vec.tv_sec) * 1000000.0
                        + (finish_vec.tv_usec - begin_vec.tv_usec);

    struct timeval begin_deq, finish_deq;
    gettimeofday(&begin_deq, NULL);
    deque_seq = mergeInsertDeq(deque_seq);
    gettimeofday(&finish_deq, NULL);
    
    double duration_deq = (finish_deq.tv_sec - begin_deq.tv_sec) * 1000000.0
                        + (finish_deq.tv_usec - begin_deq.tv_usec);
                        
    showAfter();
    
    std::cout << "Time to process a range of " << sequence.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << duration_vec << " us" << std::endl;

    std::cout << "Time to process a range of " << deque_seq.size()
              << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << duration_deq << " us" << std::endl;
}