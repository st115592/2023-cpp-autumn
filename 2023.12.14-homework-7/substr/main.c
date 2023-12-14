#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

char* subbstr(char* string, int lenstr, int start);

int main(int argc, char* argv[])
{
	int len = 0;
	printf("Enter line length:\n");
	scanf_s("%d", &len);
	int start = 0;
	printf("Enter which character to start with:\n");
	scanf_s("%d", &start);


	FILE* f = fopen("in.txt", "r");
	char string[256] = { 0 };
	fscanf(f, "%s", &string);
	fclose(f);


	char* t = subbstr(string, len, start);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", t);
	fclose(f);

	free(t);

	return EXIT_SUCCESS;
}

char* subbstr(char* string, int lenstr, int start)
{
	int l = strlen(string);
	if (lenstr <= 0 && start >= l)
	{
		return 0;
	}

	if (start < 0)
	{
		start = l + start;
	}

	char* word = (char*)malloc(sizeof(char*) * (lenstr + 1));

	for (int i = 0; i < lenstr + 1; i++)
	{
		word[i] = string[start + i];
	}
	word[lenstr] = '\0';

	return word;
}
