#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAXSTRLEN 9

char **fizzBuzz(int n, int *returnSize)
{
        *returnSize = n; // Why tho

        static const char responses[][MAXSTRLEN] = {"%d", "Fizz", "Buzz", "FizzBuzz"};
        static const size_t elementLength = MAXSTRLEN * sizeof(char);

        // Allocates enough space for every element's pointer followed by every element's data
        // No need for _Alignof() because char has an aligmnent of 1
        char **const answer = malloc((n * sizeof(char *)) + (n * elementLength));
        char *const elements = (char *)answer + (n * sizeof(char *)); // Points to beginning of answer data, after the pointers
        memset(elements, 0, (n * elementLength));                     // Zeros the data portion of the array

        for (uint16_t threes = 2; threes < n; threes += 3)
                elements[threes * elementLength] += 1;
        for (uint16_t fives = 4; fives < n; fives += 5)
                elements[fives * elementLength] += 2;
        for (uint16_t i = 0; i < n; i++)
        {
                answer[i] = &elements[i * elementLength]; // Point answer[i] to the correct element
                snprintf(answer[i], MAXSTRLEN, responses[(uint8_t)answer[i][0]], i + 1);
        }
        return answer;
}
