#include<iostream>
#include<fstream>
#include<string>

int palindrom(std::string str)
{
	int len = str.size();
	std::string rstr = str;

	for (int i = 0; i < len; i++)
	{
		rstr[i] = str[len - i - 1];
	}
	for (int i = 0; i < len; i++)
	{
		if (rstr[i] != str[i])
		{
			return 0;
			break;
		}
		else
		{
			return 1;
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	std::string str = { 0 };
	while (!fin.eof())
	{
		fin >> str;
	}
	fin.close();

	int k = palindrom(str);

	std::ofstream fout("out.txt");

	if(k == 0)
    {
        fout << "not a palindrome" << std::endl;
    }
    else
    {
        fout << "palindrome" << std::endl;
    }
	fout.close();

	return EXIT_SUCCESS;
}
