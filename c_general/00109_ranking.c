#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter the number of values = ");
    scanf("%d", &n);

    int value[n], standard_rank[n];

    printf("\nEnter the values :: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter value[%d] = ", i+1);
        scanf("%d", &value[i]);
    }

    // evaluating standard competition rank
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (value[i] < value[j])
            {
                count++;
            }
            standard_rank[i] = count + 1;
        }

    }


    // copying the standard ranks in another array 
    int dense_rank[n];
    for (int i = 0; i < n; i++)
    {
        dense_rank[i] = standard_rank[i];
    }
    
    // evaluting dense rank

    int match[n];
    for (int i = 0; i < n; i++)
    {
        match[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        int match_code = 0;
        for (int x = 0; x < n; x++)
        {
            if (dense_rank[i] != match[x])
            {
                match_code++;
            }
            
        }

        if (match_code == n)
        {
            for (int j = i+1; j < n; j++)
            {
                if (dense_rank[i] == dense_rank[j])
                {
                    match[i] = dense_rank[i];
                    for (int k = 0; k < n; k++)
                    {
                        if (dense_rank[i] < dense_rank[k])
                        {
                            dense_rank[k]--;
                        }

                    }
                }
            }
        }
    }
    

    // printing the values, corresponding standard competition ranks and corresponding dense ranks

    printf("\nThe values, corresponding standard ranks and corresponding dense ranks are as follows::\n");
    printf("\n \t values \t \t standard competition ranks \t \t dense ranks\n");
    printf("\n--------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t %5d \t \t \t \t %5d \t \t \t \t %5d\n", value[i], standard_rank[i], dense_rank[i]);
    }



    return 0;
}