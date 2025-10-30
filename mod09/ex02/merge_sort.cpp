
#include <vector>

/**
 * @brief Puts the number from <pos> left, to <to>, shifting the rest right
 * @param pos Index of the number to move, last position to be shifted
 * @param to Index of the position to move <pos> to
 * @note If <position> is left of <to>, or exceeds list size, nothing happens
 */
template<typename T>
void push_before(unsigned int pos, unsigned int to, std::vector<T> &list)
{
	// This code is redundant, because you should never call this with bad input!
	if (position < to || position > list.size() - 1)
		return ;
	// ---------------------
	T temp = list[pos];
	while (pos > to)
	{
		pos--;
		list[pos + 1] = list[pos];
	}
	list[pos] = temp;
}


/**
 * @brief Insert number from array into a sorted range
 * @param pos is the position of the number in the array, that you want to insert/move
 * @param from is the index of the start of the sorted range (inclusive)
 * @param to is the index of the end of the sorted range (inclusive)
 * @param list is the array/list to service
 * 
 * @warning <pos>, <to> and <from> have to be valid indices in list
 * @warning <pos> > to >= from
 */
void insert(unsigned int pos, unsigned int from, unsigned int to, std::vector<int> &list)
{
	unsigned int mid = (from + to) / 2;
	// Position found
	if (to - from <= 1)
	{
		// if before start, push to start
		if (list[pos] < list[from])
			push_before(pos, from, list);
		// if before end, push to end
		else if (list[pos] < list[to])
			push_before(pos, to, list);
		// bigger then end, push just after end
		else
			push_before(pos, to + 1, list);
			// this could in theory exceed the limit, but in practice, should never
	}
	// Element has to go in left half
	else if (list[mid] > list[pos])
		insert(pos, from, mid, list);
	else
		insert(pos, mid, to, list);
}

int main(void)
{
	std::vector<int> vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(9);
	vec.push_back(10);
	vec.push_back(8);
	// 2 3 4 5 6 7 9 10 8
	// 0 1 2 3 4 5 6 7  8
	insert(8, 0, 7, vec);
	return (0);
}