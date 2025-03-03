# Meat's Fairly Efficient Pointerly FizzBuzz

## Intuition

Computers are bad at division. Something we definitely don't want to do is perform three to four separate modulus operations each for ten thousand integers, so what are the alternatives?

## Approach

By iterating through the range 0-N by 3 and 5 respectively, we can leave "breadcrumbs" at all of their multiples, which we can use on a third pass to populate the answer array with the correct data.

`threes * elementLength += 1` Leaves a mark at every number divisible by three. Fives does the same with `fives * elementLength += 2`, and if both land on the same number, the result will be `3`.
Therefor to further optimize this, we can avoid using any comparators or branching by simply feeding these breadcrumbs into an array as the index (`responses[0, 1, 2, or 3]`), effectively creating a jump table. The default value of zero indexes to a format string `%d` for printing the current index as a string into the answer array.

Next up, by using pointers efficiently to avoid multiple Malloc calls, we can significantly reduce both memory usage and execution time. This solution creates a single array containing both the i and j pointers one would expect in `answer[i][j]`, and manually assigns `answer[i]` to point to data elements just before populating them.

## Complexity

- Time complexity: $$O(n)$$

This solution performs four passes across the entire array, including the memset. It will only ever need four passes, however, as opposed to modulus variants which will at some level require a similar sub-linear pass for *every element.*
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

This solution allocates enough space to print `"FizzBuzz"` at most `n` times. This could be optimized further by packing the response strings closer together, but doing so without calling malloc repeatedly and reducing the efficiency of the algorithm would likely require prior knowledge of the results.

## Code

```c []
#define MAXSTRLEN 9

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;

    static const char responses[][MAXSTRLEN] = {"%d", "Fizz", "Buzz", "FizzBuzz"};
    static const size_t elementLength = MAXSTRLEN * sizeof(char);
    // Creates space for the answer array in its entirety
    char** const answer = malloc((n * sizeof(char*)) + (n * elementLength));
    // Creates a pointer to the data segment of the answer array
    char* const elements = (char*)answer + (n * sizeof(char*));
    memset(elements, 0, (n * elementLength));

    for (uint16_t threes = 2; threes < n; threes += 3)
        elements[threes * elementLength] += 1;
    for (uint16_t fives = 4; fives < n; fives += 5)
        elements[fives * elementLength] += 2;
    for (uint16_t i = 0; i < n; i++) {
        answer[i] = &elements[i * elementLength];
        snprintf(answer[i], MAXSTRLEN, responses[(uint8_t)answer[i][0]], i + 1);
    }
    return answer;
}
```
