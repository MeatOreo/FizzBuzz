#include "fizzBuzz.c"
#define TESTRANGE 10000

int main(void)
{
        int returnSize;
        char ** answer = fizzBuzz(TESTRANGE, &returnSize);
        
        for(int i = 0; i < TESTRANGE; i++)
        {
                printf("%s", answer[i]);
                if(((i+1) % 3 == 0) && ((i+1) % 5 == 0))
                {
                        if(strcmp(answer[i], "FizzBuzz") != 0)
                        {
                                return -69;
                        }
                }
                else if((i+1) % 3 == 0)
                {
                        if(strcmp(answer[i], "Fizz") != 0)
                        {
                                return -69;
                        }
                }
                else if((i+1) % 5 == 0)
                {
                        if(strcmp(answer[i], "Buzz") != 0)
                        {
                                return -69;
                        }
                }
        }

        return 0;
}