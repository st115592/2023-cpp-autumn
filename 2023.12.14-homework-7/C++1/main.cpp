#include<iostream>
#include<string>
#include<fstream>

int WordCounter(std::string filename)
{
	std::ifstream fin(filename);
	int n = 0;
	std::string word = "";
	while (!fin.eof())
	{
		fin >> word;
		++n;
	}
	fin.close();
	return n;
}

void WordsArray(std::string filename, std::string* WordsArr)
{
	std::ifstream fin(filename);

	int i = 0;
	while (!fin.eof())
	{
		fin >> WordsArr[i];
		++i;
	}
	fin.close();
}

bool isSyntax(char c)
{
	return (c == '.' || c == ',' ||
		c == ';' || c == ':' ||
		c == '!' || c == '?');
}

void Syntax(std::string* WordsArr, int n)
{
    for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < WordsArr[i].length(); ++j)
		{
			if (isSyntax(WordsArr[i][j]))
			{
				WordsArr[i].erase(j, 1);
			}
		}
	}
}
std::string MostCommonWord(std::string* WordsArr, int n)
{
	std::string common = WordsArr[0];
	int repeatCount = 0;

	for (int i = 0; i < n; ++i)
	{
		int repeat = 0;
		for (int j = i; j < n; ++j)
		{
			if (WordsArr[i] == WordsArr[j])
			{
				++repeat;
			}
		}
		if (repeat > repeatCount)
		{
			repeatCount = repeat;
			common = WordsArr[i];
		}
	}
	return common;
}

int main(int argc, char* argv[])
{
	int n = WordCounter("in.txt");
	std::string* WordsArr = new std::string[n];

	WordsArray("in.txt", WordsArr);
	Syntax(WordsArr, n);

	std::ofstream fout("out.txt");
	fout << "'"<< MostCommonWord(WordsArr, n) << "' - most common word in text" << std::endl;

	return EXIT_SUCCESS;
}
