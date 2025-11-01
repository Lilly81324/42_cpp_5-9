#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>

void push_before(unsigned int pos, unsigned int to, std::vector<int *> &list);

void	ft_swap(int *pos1, int *pos2);

void insert(unsigned int pos, unsigned int from, unsigned int to, std::vector<int *> &list);

void sortPairs(std::vector<int *> &list);

void cpy(std::vector<int *> &list);

void merge_sort(std::vector<int *> &list);

#endif