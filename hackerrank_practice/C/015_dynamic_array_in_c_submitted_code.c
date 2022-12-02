#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    int * total_number_of_books = (int *) calloc(total_number_of_shelves,  sizeof(int));
    
    int ** total_number_of_pages = (int **) malloc(total_number_of_shelves * sizeof(int *)); // this is an 1D array that stores the pointers to the 1D arrays that are corresponding to each shelf

    for (int i = 0; i < total_number_of_shelves; i++)
    {
        total_number_of_pages[i] = (int *) calloc(1100, sizeof(int)); // for each shelf we create one 1D array
    }
    
    while (total_number_of_queries > 0) {
        total_number_of_queries--;
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            
            int shelf_number;
            scanf("%d", &shelf_number);

            int page_number_of_new_book;
            scanf("%d", &page_number_of_new_book);

            for (int i = 0; i < 1100; i++)
            {
                if (*(*(total_number_of_pages + shelf_number) + i) == 0)
                {
                    *(*(total_number_of_pages + shelf_number) + i) = page_number_of_new_book;
                    break;
                }
                
            }
            
            *(total_number_of_books + shelf_number) += 1;
            
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}