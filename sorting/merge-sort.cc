#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

template <class T>
void merge(std::vector<T>& data, int low, int middle, int high)
{
	T limit = std::numeric_limits<T>::max();
	size_t size_left = middle - low + 1; 
	size_t size_right = high - middle; 

	std::vector<T> L(size_left + 1);
	std::vector<T> R(size_right + 1);
	
	for (int i = 0; i < size_left; ++i)
		L[i] = data[low + i];
	for (int i = 0; i < size_right; ++i)
		R[i] = data[middle + 1 + i];
		
	L[size_left] = limit;
	R[size_right] = limit;
	
	int i = 0, j = 0;
	
	for(int k = low; k <= high; ++k)
	{
		if(L[i] <= R[j])
		{
			data[k] = L[i];
			++i;
		}
		else
		{
			data[k] = R[j];
			++j;
		}
	}
}

template <class T>
void merge_sort(std::vector<T>& data, int low, int high)
{
	/** need to pass the first and last index of the vector, 
	 * not the size of the vector!!!
	 */
	 
	if (low < high)
	{
		int middle = low + std::floor((high - low) / 2.f);
		merge_sort(data, low, middle);
		merge_sort(data, middle+1, high);
		merge(data, low, middle, high); 
	}
}

int main(int argc, char **argv)
{
	
	std::vector<int> numbers_half_sorted{1, 4, 6, 2, 3, 15};
	merge(numbers_half_sorted, 0, 2, numbers_half_sorted.size()-1);
	
	for(int num: numbers_half_sorted)
	{
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	
	std::vector<int> numbers{10, 4, 6, 1, 20, 15};
	merge_sort(numbers, 0, numbers.size()-1);
	
	for(int num: numbers)
	{
		std::cout << num << "\t";
	}
	std::cout << std::endl;


	return 0;
}
