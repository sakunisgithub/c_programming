#include<stdio.h>
#include<stdlib.h>

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    int * number_of_books_in_the_shelves = (int *) calloc(total_number_of_shelves,  sizeof(int));

    // int number_of_pages_in_the_books[total_number_of_shelves][1100];

    int ** number_of_pages_in_the_books = (int **) malloc(total_number_of_shelves * sizeof(int *)); // this is an 1D array that stores the pointers to the 1D arrays that are corresponding to each shelf

    for (int i = 0; i < total_number_of_shelves; i++)
    {
        number_of_pages_in_the_books[i] = (int *) calloc(1100, sizeof(int)); // for each shelf we create one 1D array
    }

    while (total_number_of_queries > 0)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1)
        {
            int shelf_number;
            scanf("%d", &shelf_number);

            int page_number_of_new_book;
            scanf("%d", &page_number_of_new_book);

            for (int i = 0; i < 1100; i++)
            {
                if (*(*(number_of_pages_in_the_books + shelf_number) + i) == 0)
                {
                    *(*(number_of_pages_in_the_books + shelf_number) + i) = page_number_of_new_book;
                    break;
                }
                
            }

            *(number_of_books_in_the_shelves + shelf_number) += 1;

        }
        else if (type_of_query == 2)
        {
            int shelf_number;
            scanf("%d", &shelf_number);

            int book_number;
            scanf("%d", &book_number);

            printf("%d\n", (*(*(number_of_pages_in_the_books + shelf_number) + book_number)));
        }
        else if (type_of_query == 3)
        {
            int shelf_number;
            scanf("%d", &shelf_number);

            printf("%d", *(number_of_books_in_the_shelves + shelf_number));
        }
        
        total_number_of_queries--; 
        
    }
    
    free(number_of_books_in_the_shelves);

    for (int i = 0; i < total_number_of_shelves; i++)
    {
        free(number_of_pages_in_the_books[i]);
    }

    free(number_of_pages_in_the_books);
    
    return 0;
}