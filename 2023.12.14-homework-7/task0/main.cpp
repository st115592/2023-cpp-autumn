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


int WordCounter(char *str)
{
   int count = 0;
   for(int i = 0; i < StrLength(str); ++i)
   {
       if(str[i] = 'b')
       {
           ++count;
       }
   }
   return count;
}

int main(int argc, char* argv[])
{
  FILE* f = fopen("in.txt", "r");
  char str[255] = { 0 };
  fscanf(f, "%s", &str);

  int k = WordCounter(str);

  f = fopen("out.txt", "w");
  fprintf(f, "%d", k);
  fclose(f);

  return EXIT_SUCCESS;
}
