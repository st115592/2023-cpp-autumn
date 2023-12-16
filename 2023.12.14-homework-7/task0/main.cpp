#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a = 0;
	int counter = 0;
	while (a != EOF)
	{
		++counter;
		a = getc(f);
	}
    fclose(f);

	f = fopen("in.txt", "r");
	char* text = (char*)malloc(sizeof(char*) * counter);

	for (int i = 0; i < counter; i++)
	{
		text[i] = getc(f);
	}
	text[counter - 1] = '\0';

	fclose(f);

	int bos = 0;
	int eos = 0;
	int biggestSen = 0;
	int words = 0;
	int senSize = 0;

	for (int i = 0; i < counter; i++)
	{
		if (text[i] == ' ')
		{
			++words;
			++senSize;
		}
		else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
		{
		    bos = eos;
			eos = i;

			if (biggestSen < senSize)
			{
				if (bos != 0)
				{
					bos = bos + 2;
				}
				biggestSen = senSize;
			}
			senSize = 0;
		}
	}

	f = fopen("out.txt", "w");
	for (int i = bos; i < eos + 1; i++)
	{
		fprintf(f, "%c", text[i]);
	}
	fprintf(f, "\n");
	fprintf(f, "\n");
    fprintf(f, "%d", words + 1); // +1 because there is no space before the first word//
    fprintf(f, " - amount of words in text");
	fclose(f);

	return EXIT_SUCCESS;
}
