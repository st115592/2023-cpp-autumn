#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include<cstdio>

int StrLength(char *str)
{
    int counter = 0;
    while(str[counter] != 0)
    {
        ++counter;
    }

    return counter;
}

int StrCmp(char* str1, char* str2)
{
	int l = StrLength(str1) > StrLength(str2) ? StrLength(str1) : StrLength(str2);
	int count = 0;

	for (int i = 0; i < l; i++)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
			{
				return 1;
				break;
			}
			else
			{
				return -1;
				break;
			}
		}
		else
		{
			++count;
		}
	}

	if (StrLength(str1) == StrLength(str2) && count == StrLength(str1))
	{
		return 0;
	}
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");
	char str1[255] = { 0 };
	fscanf(f, "%s", &str1);
	char str2[255] = { 0 };
	fscanf(f, "%s", &str2);
	fclose(f);

	int k = StrCmp(str1, str2);

	f = fopen("out.txt", "w");
	fprintf(f, "%d", k);
	fclose(f);

	return EXIT_SUCCESS;
}
