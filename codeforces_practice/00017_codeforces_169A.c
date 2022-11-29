#include<stdio.h>

void bubble_sort(int *, int);

void swap(int *, int *);

int main()
{
    int n, a, b;

    scanf("%d", &n);
    int complexity[n];

    scanf("%d", &a);
    scanf("%d", &b);
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &complexity[j]);
    }

    bubble_sort(complexity, n);

    printf("%d\n", complexity[a-1] - complexity[a]);
    
    return 0;
}

void bubble_sort(int * array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int sort_code = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(array + j) < *(array + j + 1))
            {
                sort_code = 1;
                swap((array + j), (array + j + 1));
            }
            
        }

        if (sort_code == 0)
        {
            break;
        }
        
    }
    
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// https://codeforces.com/problemset/problem/169/A