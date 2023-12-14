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

char* StrMult(char* str, int n)
{
	int len = 0;
	char* multi = (char*)malloc(sizeof(char*) * ((StrLength(str)) * n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < StrLength(str); ++j)
		{
			multi[j + len] = str[j];
		}
		len = len + StrLength(str);
	}
	multi[len] = '\0';

	return multi;
}

int main(int argc, char* argv[])
{
    int n = 0;
	printf("Enter multiplier: ");
	scanf("%d", &n);

	FILE* f = fopen("in.txt", "r");
	char str[255] = { 0 };
	fscanf(f, "%s", &str);

	char* k = StrMult(str, n);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", k);
	fclose(f);

	free(k);

	return EXIT_SUCCESS;
}
