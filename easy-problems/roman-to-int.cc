#include <iostream>
#include <string>
#include <unordered_map>

int roman_to_int(std::string s)
{
    std::unordered_map<char, int> chars = 
		{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	int num = 0;

	for (int i = 0; i < s.length() - 1; ++i)
	{
		switch(s[i])
		{
		case 'I':
			if(s[i+1] == 'V' || s[i+1] == 'X')
				num -= 1;
			else num += 1;
			break;
		case 'X':
			if(s[i+1] == 'L' || s[i+1] == 'C')
				num -= 10;
			else num += 10;
			break;
		case 'C':
			if(s[i+1] == 'D' || s[i+1] == 'M')
				num -= 100;
			else num += 100;
			break;
		default: 
			num += chars[s[i]];
		}
		std::cout << num << "\t";
	}
	num += chars[s[s.length()-1]];
	std::cout << num << "\n";
	return num;
}


int main()
{
	std::string s1 = "MCCXLIV";
	std::string s2 = "MMCMV";
	std::string s3 = "I";
	
	std::cout << s1 << "\t" << roman_to_int(s1) << "\n"
			  << s2 << "\t" << roman_to_int(s2) << std::endl
			  << s3 << "\t" << roman_to_int(s3) << std::endl;
	
	return 0;
}
