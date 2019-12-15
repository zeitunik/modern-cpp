#include <iostream>
#include <string>
#include <stack>

std::string reverse_words(std::string s) 
{        
	// std::string reverse{s};
	
	std::stack<char> reverse;
	for(int start = 0,  end = 0; end <= s.length(); ++end)
	{
		if(s[end] == ' ' || end == s.length())
		{
			int j = 0;
			while(!reverse.empty())
			{
				s[start + j] = reverse.top();
				reverse.pop();
				++j;
			}
			start = end+1;
		}
		else
		{
			reverse.push(s[end]);
		}
	}
	return s;
}

std::string reverse_words2(std::string s)
{
	std::string reverse{s};
	
	for(int start = 0, end = 0; end <= s.length(); ++end)
	{
		if(s[end] == ' ' || end == s.length()) 
		{
			for(int j = start; j < end; ++j )
			{
				reverse[j] = s[start + end - 1 - j];
			}
			start = end + 1;
		}
	}
	return reverse;
}

int main()
{
	std::string s1{"Hello, World!"};
	std::string s2{"Bari Luys, Tikin Arus"};
	std::cout 	<< s1 << "\t" << reverse_words(s1) << std::endl 
				<< s2 << "\t" << reverse_words(s2) << std::endl;
	return 0;
}
