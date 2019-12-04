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
void max_heapify(std::vector<T>& data, int index)
{
	T l = left(index);
	T r = right(index);
	T largest = -1;
	// std::cout << "left: " << l << " right: " << r << std::endl;
	
	if ( l < data.size() && data.at(l) >= data.at(index) )
		largest = l;
	else largest = index;
	
	if ( r < data.size() && data.at(r) >= data.at(largest) )
		largest = r;
		
	// std::cout << "largest: " << largest << std::endl;
		
	if (largest != index)
	{
		// swap largest child with parent
		T temp = data.at(index);
		data.at(index) = data.at(largest);
		data.at(largest) = temp;
		max_heapify(data, largest);
	}
}


int main(int argc, char** argv)
{
	int num = 5;
	std::cout << "Parent of " << num << " is: " << parent(num)
			<< "\nLeft child of " << num << " is: " << left(num)
			<< "\nRight child of " << num << " is: " << right(num) << "\n";
	
	std::vector<int> numbers{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	max_heapify(numbers, 1);
	
	for (int num: numbers)
		std::cout << num << "\t";
	std::cout << std::endl;
	
	return 0;
}
