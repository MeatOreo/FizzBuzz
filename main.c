#include <stdio.h>
#include "fizzBuzz.c"

int main(int argc, char ** argv)
{
        int returnSize;
        int n = (argc > 1) ? atol(argv[1]) : 21;

        char ** answer = fizzBuzz(n, &returnSize);

        for (int i = 0; i < n; i++)
        {
                printf("%s\n", answer[i]);
        }
}