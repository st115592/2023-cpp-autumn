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

char* StrCat(char* str1, char* str2)
{
	int len1 = StrLength(str1);
	int len2 = StrLength(str2);
	for (int i = 0; i < len2 + 1; i++)
	{
		str1[len1] = str2[i];
		len1++;
	}

	return str1;
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");
	char str1[255] = {0};
	fscanf(f, "%s", &str1);
	char str2[255] = {0};
	fscanf(f, "%s", &str2);
	fclose(f);

	char* k = StrCat(str1, str2);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", k);
	fclose(f);

	return EXIT_SUCCESS;
}
