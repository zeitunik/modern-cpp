#include <iostream>
#include <vector>


template <class T> 
void insertion_sort(std::vector<T>& data)
{
	for(int i = 1; i < data.size(); ++i)
	{	
		T key = data[i];
		
		int j = i - 1;
		while( (j >= 0) && (data[j] > key) )
		{	
			data[j+1] = data[j];
			--j;
		}
		data[j+1] = key;
	}
}


int main()
{
	std::vector<double> numbers{3, 5, 2, 7, 1};
	insertion_sort(numbers);
	
	for(double num: numbers)
	{
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	
	return 0;
}
