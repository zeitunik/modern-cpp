#include <iostream>
#include <vector>
#include <cmath>


inline int left(const int index)
{
	return (index<<1) + 1;
}

inline int right(const int index)
{
	return (index+1)<<1;
}

inline int parent(const int index)
{
	if (index == 0) return -1;
	return std::floor((index - 1) / 2.);
}

template <class T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <class T>
void max_heapify(std::vector<T>& data, int index, size_t heap_size)
{
	T l = left(index);
	T r = right(index);
	T largest = -1;
	// std::cout << "left: " << l << " right: " << r << std::endl;
	
	if ( l < heap_size && data.at(l) > data.at(index) )
		largest = l;
	else largest = index;
	
	if ( r < heap_size && data.at(r) > data.at(largest) )
		largest = r;
		
	// std::cout << "largest: " << largest << std::endl;
		
	if (largest != index)
	{
		// swap largest child with parent
		swap<int>(data.at(index), data.at(largest));
		max_heapify(data, largest, heap_size);
	}
}

template <class T>
void build_max_heap(std::vector<T>& data)
{
	// the last floor(data.size()/2) elements of the array are going to 
	// be the leaves in the tree so they are heaps already
	size_t heap_size = data.size();
	for ( int i = heap_size / 2 - 1; i >= 0; --i )
	{
		max_heapify(data, i, heap_size);
	}
}

template <class T>
void heap_sort(std::vector<T>& data)
{
	build_max_heap(data);
	size_t heap_size = data.size();
	for (int i = data.size()-1; i >= 0; --i)
	{
		// swap current element with the first one (largest in heap)
		swap<int>(data.at(i), data.at(0));
		--heap_size;
		max_heapify(data, 0, heap_size);
	}
}

template <class T>
void print(const std::vector<T>& data)
{
	for(T d: data)
	{
		std::cout << d << "\t";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	int num = 5;
	std::cout << "Parent of " << num << " is: " << parent(num)
			<< "\nLeft child of " << num << " is: " << left(num)
			<< "\nRight child of " << num << " is: " << right(num) << "\n";
	
	std::vector<int> numbers{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	print(numbers);
	max_heapify(numbers, 1, numbers.size());	
	print(numbers);
	std::cout << std::endl;
	
	std::vector<int> numbers2{5, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	std::vector<int> numbers3 = numbers2;
	print(numbers2);
	build_max_heap(numbers2);
	print(numbers2);
	
	heap_sort(numbers3);
	print(numbers3);
	
	return 0;
}
