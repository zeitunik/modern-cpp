#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool valid_bracket_string(std::string s) 
{
	if(s.empty()) return true;
        
	std::stack<char, std::vector<char>> brackets;
	for(auto ch: s)
	{
		switch(ch)
		{
			case ')': 
				if(brackets.empty() || brackets.top() != '(')
					return false;
				else
					brackets.pop();
				break;
			case ']':
				if(brackets.empty() || brackets.top() != '[')
					return false;
				else 
					brackets.pop();
				break;
			case '}':
				if(brackets.empty() || brackets.top() != '{')
					return false;
				else
					brackets.pop();
				break;
			default: brackets.push(ch);
		}
		//if(!brackets.empty())
			//std::cout << brackets.top() << "\n";
	}
	
	if(!brackets.empty()) return false;
	
	return true;
}

int main()
{

	std::string s1 = "";
	std::string s2 = "()";
	std::string s3 = "[(){}]";
	std::string s4 = "{}]";
	
	std::cout << s1 << "\t" << valid_bracket_string(s1) << "\n"
				<< s2 << "\t" << valid_bracket_string(s2) << "\n"
				<< s3 << "\t" << valid_bracket_string(s3) << "\n"
				<< s4 << "\t" << valid_bracket_string(s4) << "\n";
	
	return 0;
}
