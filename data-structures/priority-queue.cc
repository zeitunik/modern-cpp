#include <iostream>
#include <vector>
#include <cassert>
#include <limits>
#include "../sorting/heap-sort.hh"

template <class T>
T heap_max(std::vector<T> data)
{
	return data.at(0);
}

template <class T>
T pop_heap_max(std::vector<T>& data, size_t heap_size)
{
	assert(heap_size > 0);
	T max = data.at(0);
	data.at(0) = data.at(heap_size);
	--heap_size;
	max_heapify(data, 0, heap_size);
	return max;
}

template <class T>
void heap_increase_key(std::vector<T>& data, int index, T key)
{
	assert(key > data.at(index));
	data.at(index) = key;
	while(index > 0 && data.at(parent(index)) < data.at(index))
	{
		swap(data.at(index), data.at(parent(index)));
		index = parent(index);
	}
}

template <class T>
void max_heap_insert(std::vector<T>& data, T key)
{
	size_t heap_size = data.size();
	++heap_size;
	data.push_back(std::numeric_limits<T>::min());
	heap_increase_key(data, heap_size-1, key);
}

int main(int argc, char** argv)
{
	std::vector<int> numbers{5, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	print(numbers);
	
	build_max_heap(numbers);
	print(numbers);
	heap_increase_key(numbers, 8, 3798);
	print(numbers);
	max_heap_insert(numbers, 42);
	print(numbers);
	
	heap_sort(numbers);
	print(numbers);
	return 0;
}
