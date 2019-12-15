#include <iostream>
#include <unordered_set>

int digit_squared_sum(int n)
{
	int sum = 0;
	while(n != 0)
	{
		int r = n % 10;
		sum += r*r;
		n /= 10;
	}
	return sum;
}

bool is_happy(int n) 
{
	/** use a walker and runner pointers to find a cycle
	 */
	
	int fast = n;
	int slow = n;
	
	do
	{
		slow = digit_squared_sum(slow);
		fast = digit_squared_sum(digit_squared_sum(fast));
	}while(slow != fast);
	
	if(slow == 1) return true;
	return false;        
}

bool is_happy2(int n)
{
	std::unordered_set<int> sums;
	
	int num = n;
	while(num != 1)
	{
		num = digit_squared_sum(n);
		/*int d = num;
		num = 0;
		while(d != 0)
		{
			int r = d % 10;
			num += r*r;
			d /= 10;
		}*/
		if(sums.find(num) != sums.end())
			return false;
		else 
			sums.insert(num);
	}
	return true;
}

int main()
{
	std::cout << 19 << "\t" << is_happy(19) << "\n"
			<< 20 << "\t" << is_happy2(20) << "\n";
	return 0;
}
