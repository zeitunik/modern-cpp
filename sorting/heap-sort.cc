#include <iostream>
#include <vector>
#include <cmath>


inline int left(const int index)
{
	return index<<1;
}

inline int right(const int index)
{
	return (index<<1) + 1;
}

inline int parent(const int index)
{
	return std::floor(index/2.);
}


int main(int argc, char** argv)
{
	int num = 5;
	std::cout << "Parent of " << num << " is: " << parent(num)
			<< "\nLeft child of " << num << " is: " << left(num)
			<< "\nRight child of " << num << " is: " << right(num) << "\n"; 
	
	return 0;
}
