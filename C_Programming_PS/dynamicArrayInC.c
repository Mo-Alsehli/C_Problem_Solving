#include <stdio.h>
#include <stdlib.h>

/*
Prob Definition:
Snow Howler is the librarian at the central library of the city of HuskyLand. He must handle requests which come in the following forms:
1 x y : Insert a book with y  pages at the end of the Xth shelf.

2 x y : Print the number of pages in the Yth  book on the Xth  shelf.

3 x : Print the number of books on the Xth  shelf.
Snow Howler has got an assistant, Oshie, provided by the Department of Education. Although inexperienced, Oshie can handle all of the queries of types 2 and 3.
Help Snow Howler deal with all the queries of type 1.

Oshie has used two arrays: int* total_number_of_books;
 * This stores the total number of books on each shelf.

int** total_number_of_pages;
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.

Solution:
In the updated code, we allocate memory for total_number_of_books and total_number_of_pages arrays using calloc to initialize them with zeros. Inside the first type of query (type_of_query == 1), we read the values of x and y representing the shelf number and the number of pages respectively. Then, we increment the number of books on the xth shelf and reallocate memory for the updated number of books on that shelf. Finally, we store the number of pages for the newly inserted book.



*/

int *total_number_of_books;
int **total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    total_number_of_books = (int *)calloc(total_number_of_shelves, sizeof(int));
    total_number_of_pages = (int **)calloc(total_number_of_shelves, sizeof(int *));

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    while (total_number_of_queries--)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            // Increase the number of books on the xth shelf
            total_number_of_books[x]++;

            // Reallocate memory for the updated number of books on the xth shelf
            total_number_of_pages[x] = (int *)realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));

            // Add the number of pages for the newly inserted book
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;
        }
        else if (type_of_query == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", total_number_of_pages[x][y]);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", total_number_of_books[x]);
        }
    }

    free(total_number_of_books);

    for (int i = 0; i < total_number_of_shelves; i++)
    {
        free(total_number_of_pages[i]);
    }

    free(total_number_of_pages);

    return 0;
}
