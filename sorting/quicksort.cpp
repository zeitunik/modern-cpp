#include <iostream>
#include <vector>
#include <random>

template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
int partition(std::vector<T>& data, int low,  int high)
{
	int pivot_value = data[high];
	int pivot_index = low;
	
	for (int j = low; j < high; ++j)
	{
		if (data.at(j) <= pivot_value)
		{
			swap(data.at(j), data.at(pivot_index));
			++pivot_index;
		}
	}
	swap(data.at(pivot_index), data.at(high));
	return pivot_index;
}

template <class T>
int random_partition(std::vector<T>& data, int low, int high)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(low, high);
	int random_index = dist(gen);
	// std::cout << "random index: " << random_index << "\n";
	swap(data.at(random_index), data.at(high));
	return partition(data, low, high);	
}

template <class T>
void quicksort(std::vector<T>& data, int low, int high)
{
	if(low < high)
	{
		int pivot = random_partition(data, low, high);
		quicksort(data, low, pivot-1);
		quicksort(data, pivot+1, high);
	}
}


std::vector<int> random_vector(const size_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(-100, 100);
	std::vector<int> numbers(size);
	for(int& num: numbers)
		num = dist(gen);
	
	return numbers;
}

template <class T>
void print(const std::vector<T>& data)
{
	for(T d: data)
		std::cout << d << "\t";
	
	std::cout << "\n";
}

int main()
{
	auto numbers = random_vector(10);
	print(numbers);
	
	// std::cout << "Pivot index: " << random_partition(numbers, 0, numbers.size()-1) << "\n";
	
	quicksort(numbers, 0, numbers.size()-1);
	
	print(numbers);

	return 0;
}
