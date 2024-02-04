#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *range;
    int size;
    int i;

    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;
    /*size = abs(end - start) + 1; but malloc is the only allowed function.*/
    range = malloc(size * sizeof(int));
    if (!range)
        return (NULL);
    i = 0;
    while (i < size)
    {
        if (start <= end)
            range[i] = start + i;
        else
            range[i] = start - i;
        i++;
    }
    return (range);
}

#include <stdio.h>

int main(void)
{
    int start = 0;
    int end = 0;
    int *range = ft_range(start, end);
    int size;

    // Calculate the size of the range
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    // Print the range
    int i = 0;
    while (i < size)
    {
        printf("%d ", range[i]);
        i++;
    }
    printf("\n");

    // Free the allocated memory
    free(range);
    
    return 0;
}