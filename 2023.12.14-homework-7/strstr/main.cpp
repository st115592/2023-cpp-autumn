#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include<cstdio>

int StrStr(char* str, char* sub)
{
	if (str == sub || *sub == '\0')
	{
		return 0;
	}

	int i = 0;
	int j = 0;
	while (sub[i] != '\0')
	{
		if (str[j] == '\0')
		{
			j = -1;
			break;
		}

		if (str[j + i] == sub[i])
		{
			i++;
		}
		else
		{
			j++;
			i = 0;
		}
	}

	return j;
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");
	char str[255] = { 0 };
	fscanf(f, "%s", &str);
	char sub[255] = { 0 };
	fscanf(f, "%s", &sub);
	fclose(f);

	int k = StrStr(str, sub);

	f = fopen("out.txt", "w");
	fprintf(f, "%d - index of the first letter", k);
	fclose(f);

	return EXIT_SUCCESS;
}
