#include <iostream>
#include "heap-sort.hh"


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
