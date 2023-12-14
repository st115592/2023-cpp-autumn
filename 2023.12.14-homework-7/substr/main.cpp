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

char* SubStr(char* str, int len, int index)
{
	if (len <= 0 || index >= StrLength(str) || index < 0)
	{
		return 0;
	}

	char* sub = (char*)malloc(sizeof(char*) * (len + 1));

	for (int i = 0; i <= len; i++)
	{
		sub[i] = str[index + i];
	}
	sub[len] = '\0';

	return sub;
}

int main(int argc, char* argv[])
{
	int index = 0;
	printf("Enter which index to start from: ");
	scanf("%d", &index);
	int len = 0;
	printf("Enter the length of substring : ");
	scanf("%d", &len);

	FILE* f = fopen("in.txt", "r");
	char str[255] = { 0 };
	fscanf(f, "%s", &str);
	fclose(f);

	char* k = SubStr(str, len, index);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", k);
	fclose(f);

	free(k);

	return EXIT_SUCCESS;
}
