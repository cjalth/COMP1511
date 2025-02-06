// CS Bookshelf
//
// This program was written by Caitlin Wong (z5477471)
// on 19/07/2023
//
// This program stores the information of books in a digital bookshelf.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////
///////////////////////////      CONSTANTS      ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided constants
#define MAX_STR_LEN 32
#define MAX_RATING 5
#define MIN_RATING 1

// Provided enums
enum book_genre {CLASSICS, FANTASY, MYSTERY, NON_FICTION, SCI_FI, INVALID};

// Added defines
#define HELP '?'
#define ADD_BOOK 'a'
#define PRINT_SHELF 'p'
#define COUNT_BOOKS 'c'
#define INSERT_BOOKS 'i'
#define READ_PAGES 'r'
#define READ_STATS 's'
#define ADD_SHELF 'A'
#define NEXT_SHELF '>'
#define PREV_SHELF '<'
#define PRINT_SHELVES 'P'
#define DELETE_BOOK 'd'
#define DELETE_SHELF 'D'
#define GENRE_SHELF 'G'
#define SEARCH_BOOKS 'S'

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// USER DEFINED TYPES  ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct shelf {
    // the name of the shelf
    char name[MAX_STR_LEN];
    // pointer to the list of books on the shelf
    struct book *books;
    // pointer to the next shelf
    struct shelf *next;
};

struct book {
    // title of the book
    char title[MAX_STR_LEN];
    // author of the book
    char author[MAX_STR_LEN];
    // genre of the book
    enum book_genre genre;
    // rating of book out of 5
    int rating;
    // number of pages in the book
    int pages_count;
    // number of pages read
    int pages_read;

    struct book *next;
};

// Extra structs


////////////////////////////////////////////////////////////////////////////////
////////////////////// PROVIDED FUNCTION PROTOTYPE  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void print_usage(void);
void print_book(struct book *book);
void scan_title_author(char title[MAX_STR_LEN], char author[MAX_STR_LEN]);
void scan_string(char string[MAX_STR_LEN]);
enum book_genre scan_genre(void);
void print_reading_stats(
    double average_rating,
    int total_read,
    int total_pages,
    enum book_genre longest_grouping,
    int grouping_length
);
void print_shelf_summary(
    int is_selected,
    int n,
    char name[MAX_STR_LEN],
    int num_books
);
void genre_to_string(enum book_genre genre, char genre_string[MAX_STR_LEN]);

// Additional provided function prototypes
// You won't need to use these functions!
// We use just them to implement some of the provided helper functions.
int scan_token(char *buffer, int buffer_size);
enum book_genre string_to_genre(char *genre_str);

////////////////////////////////////////////////////////////////////////////////
////////////////////////  YOUR FUNCTION PROTOTYPE  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct shelf *create_shelf(char name[MAX_STR_LEN]);
struct book *create_book(
    char title[MAX_STR_LEN],
    char author[MAX_STR_LEN],
    enum book_genre genre,
    int rating,
    int pages_count
);

// Stage 1 prototypes
void commands(struct shelf *selected, struct shelf *head_shelf);
void add_books(struct shelf *selected);
void print_shelf(struct shelf *selected);
void count_books(struct shelf *selected);

// Stage 2 prototypes
int error_check(    
    char title[MAX_STR_LEN],
    char author[MAX_STR_LEN],
    enum book_genre genre,
    int rating,
    int pages_count,
    struct shelf *selected
);
void insert_books(struct shelf *selected);
int list_length(struct shelf *selected);
void read_pages(struct shelf *selected);
void reading_stats(struct shelf *selected);

// Stage 3 prototypes
struct shelf *add_shelf(struct shelf *head_shelf);
struct shelf *next_shelf(struct shelf *selected, struct shelf *head_shelf);
struct shelf *prev_shelf(struct shelf *selected, struct shelf *head_shelf);
void print_shelves(struct shelf *selected, struct shelf *head_shelf);
void delete_book(struct shelf *selected);
struct shelf *delete_shelf(struct shelf *selected, struct shelf *head_shelf);
void free_shelf(struct shelf *selected);
void free_everything(struct shelf *head_shelf);

// Stage 4 prototypes
struct shelf *genre_shelf(struct shelf *selected, struct shelf *head_shelf);
void convert_genre(enum book_genre genre, char genre_string[MAX_STR_LEN]);
struct book *genre_delete (struct shelf *current, struct book *curr_book);
void move_genre_books(struct shelf *head_shelf, struct shelf *new_shelf, enum book_genre genre);
int title_author(char title [MAX_STR_LEN], char author[MAX_STR_LEN], struct book *new_book);
void search_books(struct shelf *head_shelf);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void) {
    
    printf("Welcome to Bookshelf Manager!\n");

    struct shelf *head_shelf = create_shelf("tbr");
    struct shelf *selected = head_shelf;

    commands(selected, head_shelf);

    printf("\nGoodbye\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Stage 1.1, 1st function
//
// Parameters:
//      name - The new name of the shelf being created
// Returns:
//      The new shelf that's created
//
struct shelf *create_shelf(char name[MAX_STR_LEN]) {
    // Mallocs, initialises, and returns a new shelf.
    struct shelf *new_shelf = malloc(sizeof(struct shelf));
    new_shelf->books = NULL;
    new_shelf->next = NULL;
    strcpy(new_shelf->name, name);

    return new_shelf;
}

// Stage 1.1, 2nd function
// 
// Parameters:
//      title       - The book's title (a char string)
//      author      - The book's author (a char string)
//      book_genre  - enum category 
//      rating      - integer of the rating
//      pages_count - integer of number of pages
//
// Returns:
//      The newly created book
//
struct book *create_book(
    char title[MAX_STR_LEN],
    char author[MAX_STR_LEN],
    enum book_genre genre,
    int rating,
    int pages_count
) {
    // Mallocs, initialises, and returns a new book.
    struct book *new_book = malloc(sizeof(struct book));
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->rating = rating;
    new_book->pages_read = 0;
    new_book->pages_count = pages_count;
    new_book->genre = genre;
    new_book->next = NULL;

    return new_book;
}

// Stage 1.2: The command loop
//
// Parameters:
//      command - a char character that is scanned in.
//
void commands(struct shelf *selected, struct shelf *head_shelf) {
    char command;
    printf("Enter command: ");
    while (scanf(" %c", &command) == 1) {
        if (command == HELP) {
            print_usage();
        } else if (command == ADD_BOOK) {
            add_books(selected);
        } else if (command == PRINT_SHELF) {
            print_shelf(selected);
        } else if (command == COUNT_BOOKS) {
            count_books(selected);
        } else if (command == INSERT_BOOKS) {
            insert_books(selected);
        } else if (command == READ_PAGES) {
            read_pages(selected);
        } else if (command == READ_STATS) {
            reading_stats(selected);
        } else if (command == ADD_SHELF) {
            head_shelf = add_shelf(head_shelf);
        } else if (command == NEXT_SHELF) {
            selected = next_shelf(selected, head_shelf);
        } else if (command == PREV_SHELF) {
            selected = prev_shelf(selected, head_shelf);
        } else if (command == PRINT_SHELVES) {
            print_shelves(selected, head_shelf);
        } else if (command == DELETE_BOOK) {
            delete_book(selected);
        } else if (command == DELETE_SHELF) {
            // Checks if there's only 1 shelf left
            if ((selected == head_shelf) && (head_shelf->next == NULL)) {
                selected = delete_shelf(selected, head_shelf);
                head_shelf = selected;
            } else {
                selected = delete_shelf(selected, head_shelf);
            }
        } else if (command == GENRE_SHELF) {
            head_shelf = genre_shelf(selected, head_shelf);
        } else if (command == SEARCH_BOOKS) {
            search_books(head_shelf);
        }
        printf("Enter command: ");
    }
    free_everything(head_shelf);
}

// Stage 1.3: Add books
// Adds a newly created book to the selected shelf after scanning in the 
// title, author, genre, rating and page count of the book. The scanned 
// information will first be error checked before being added to the shelf list.
// 
// Parameters:
//      title       - The book's title (a char string)
//      author      - The book's author (a char string)
//      book_genre  - enum category 
//      rating      - integer of the rating
//      pages_count - integer of number of pages
//
void add_books(struct shelf *selected) {
    char title[MAX_STR_LEN];
    char author[MAX_STR_LEN];
    enum book_genre genre;
    int rating;
    int pages_count;

    scan_title_author(title, author);
    genre = scan_genre();
    scanf("%d %d", &rating, &pages_count);

    struct book *current_book = selected->books;

    // If the book passes the error check
    if (error_check(title, author, genre, rating, 
                    pages_count, selected) == 1) {

        // If the shelf is currently empty
        if (selected->books == NULL) {
            selected->books = create_book(title, author, 
                                            genre, rating, pages_count);
        } else {
            // Run through the whole shelf and adds the new book at the end
            while (current_book->next != NULL) {
                current_book = current_book->next;
            }
            current_book->next = create_book(title, author, 
                                            genre, rating, pages_count);
        }
        printf("Book: '%s' added!\n", title);
    }
}

// Stage 1.4: Print Books
// Prints the whole list of books on the selected shelf.
//
void print_shelf(struct shelf *selected) {
    struct book *current_book = selected->books;
    // Checks if there's currently no books on the shelf.
    if (selected->books == NULL) {
        printf("There are no books on this shelf!\n");

    } else if (selected != NULL) {
        // Traverses the whole list until it reaches the end. 
        while (current_book != NULL) {
            print_book(current_book);
            current_book = current_book->next;
        } 
    }
}

// Stage 1.5, 1st function: Count books on the shelf
// Counts the number of books on a selected shelf and prints out the total.
// 
// Parameters:
//      length - amount of books in a shelf
//
void count_books(struct shelf *selected) {
    
    // Function that checks the length of a list
    int length = list_length(selected);

    if (selected->books == NULL) {
        printf("There are no books on this shelf!\n");
        return;
    }
    if (length == 1) {
        printf("There is 1 book on this shelf!\n");

    } else {
        printf("There are %d books on this shelf!\n", length);
    }
}


// Stage 2.1: Handling Errors
// Checks if any invalid inputs have been entered by the user.
// 
// Parameters:
//      title       - The book's title (a char string)
//      author      - The book's author (a char string)
//      book_genre  - enum category 
//      rating      - integer of the rating
//      pages_count - integer of number of pages
//
int error_check(    
    char title[MAX_STR_LEN],
    char author[MAX_STR_LEN],
    enum book_genre genre,
    int rating,
    int pages_count,
    struct shelf *selected
) {
    struct book *current_book = selected->books;

    // Checks if genre is a genre listed in the enum book_genre
    if (genre == INVALID) {
        printf("ERROR: Invalid book genre\n");
        return 0;

        // Checks if the rating is between 1 and 5
    } else if (rating <= 0 || rating > 5) {
        printf("ERROR: Rating should be between 1 and 5\n");
        return 0;

        // Checks if the page count is a negative number.
    } else if (pages_count <= 0) {
        printf("ERROR: Page count should be positive\n");
        return 0;

    } else {
        while (current_book != NULL) {
            // Checks if the title and author of the book exists already
            if ((strcmp(current_book->title, title) == 0) 
                && (strcmp(current_book->author, author) == 0)) {

                printf("ERROR: a book with title: '%s' by '%s' already "
                "exists in this shelf\n", title, author);
                return 0;
            }
            current_book = current_book->next;
        } 
        return 1;
    }
}

// Stage 2.2, 1st function: Insert Book
// Inserts a new book into a specified position in the selected shelf.
// 
// Parameters:
//      title       - The book's title (a char string)
//      author      - The book's author (a char string)
//      book_genre  - enum category 
//      rating      - integer of the rating
//      pages_count - integer of number of pages
//      position    - integer which denotes the place book is inserted
//
void insert_books(struct shelf *selected) {
    char title[MAX_STR_LEN];
    char author[MAX_STR_LEN];
    enum book_genre genre;
    int rating;
    int pages_count;
    int position = 0;
    int i = 1;
    scanf("%d", &position);
    scan_title_author(title, author);
    genre = scan_genre();
    scanf("%d %d", &rating, &pages_count);
    struct book *current_book = selected->books;
    // Checks if the position to be inserted is a negative number
    if (position < 0) {
        printf("ERROR: n must be at least 0\n");
        return;
    } 
    if (error_check(title, author, genre, rating, 
                    pages_count, selected) == 1) {
        if (selected->books == NULL) {
            // If there are currently no books in the shelf
            selected->books = create_book(title, author, 
                                            genre, rating, pages_count);
        } else if (position == 0) {
            // If the position entered is the head of the shelf
            struct book *new_head = create_book(title, author, 
                                                genre, rating, pages_count);
            new_head->next = current_book;
            selected->books = new_head;
        } else if (position >= list_length(selected)) {
            // If the position is bigger than the amount of books on the shelf
            while (current_book->next != NULL) {
                current_book = current_book->next;
            }
            current_book->next = 
            create_book(title, author, genre, rating, pages_count);
        } else if (position > 0 && position < list_length(selected)) {
            struct book *inserted_book = 
            create_book(title, author, genre, rating, pages_count);
            while (position > i && current_book->next != NULL) {
                current_book = current_book->next;
                i++;
            }
            inserted_book->next = current_book->next;
            current_book->next = inserted_book;
        }
        printf("Book: '%s' inserted!\n", title);
    }   
}

// Stage 2.2, 2nd function & Stage 1.5, 2nd function: List Length
// Checks what the length of a shelf is.
//
int list_length(struct shelf *selected) {
    struct book *current_book = selected->books;
    int i = 0;
    if (selected->books == NULL) {
        return 0;
    } else if (selected != NULL) {
        while (current_book != NULL) {
            current_book = current_book->next;
            i++;
        }
    }
    return i;
}

// Stage 2.3: Read Pages
// Updates the amount of pages read in a book on a selected shelf.
// 
// Parameters:
//      title       - The book's title (a char string)
//      author      - The book's author (a char string)
//      pages       - integer to update number of pages read 
//      pages_count - integer of number of pages
//      pages_read  - integer of current number of pages read
//      remaining   - integer of pages left to read
//
void read_pages(struct shelf *selected) {
    char title[MAX_STR_LEN];
    char author[MAX_STR_LEN];
    int pages;
    int book_exists = 0;

    scan_title_author(title, author);
    scanf("%d", &pages);
    struct book *current_book = selected->books;
    struct book *changed_book = NULL;

    // Checks if the inputted pages read is negative.
    if (pages <= 0) {
        printf("ERROR: n must be a positive integer\n");
        return;
    } 

    // Checks if the book exists in the shelf
    while (current_book != NULL) {
        if ((strcmp(current_book->title, title) == 0) 
            && (strcmp(current_book->author, author) == 0)) {
            book_exists++;
            changed_book = current_book;
        }
        current_book = current_book->next;
    } 
    if (book_exists == 0) {
        printf("ERROR: No book '%s' by '%s' exists\n", title, author);
        return;
    }

    int total_read = changed_book->pages_read + pages;
    int page_count = changed_book->pages_count;

    // Checks if the pages read is more than the pages remaining
    if (page_count < total_read) {
        int remaining = changed_book->pages_count - changed_book->pages_read;
        printf("ERROR: cannot read %d pages, there are "
                "only %d left to read\n", pages, remaining);
    } else {
        printf("Pages read for '%s' has been increased by %d\n", title, pages);
        changed_book->pages_read = changed_book->pages_read + pages;
    }
}

// Stage 2.4: Reading Stats
// Prints the average rating, total page count, total pages read and 
// the longest 'genre grouping' of all books in a selected shelf.
// 
// Parameters:
//      average_total   - The total of all the ratings added 
//      average_amount  - The number of books on the shelf
//      average_rating  - The average rating of all books in selected shelf
//      total_read      - The total pages read for books on selected shelf.
//      total_pages     - The total pages for books on selected shelf.
//      longest_grouping- The longest grouping of adjacent genres
//      grouping_length - The length of the longest genre grouping
//
void reading_stats(struct shelf *selected) {
    struct book *current_book = selected->books;
    // Checks if there's no books on the shelf
    if (selected->books == NULL) {
        printf("No books on this shelf, so no stats to display!\n");
        return;
    }
    double average_total = 0;
    int average_amount = 0;
    int total_read = 0;
    int total_pages = 0;
    int grouping_length = 1;
    int highest_length = 0;
    enum book_genre longest_grouping = current_book->genre;

    // Calculates total rating, pages read, page count
    // and longest genre/ genre group length
    while (current_book != NULL) {
        average_total = average_total + current_book->rating;
        average_amount++;
        total_read = total_read + current_book->pages_read;
        total_pages = total_pages + current_book->pages_count;

        if (current_book->next != NULL && 
            (current_book->genre == current_book->next->genre)) {
            grouping_length++;
            if (grouping_length > highest_length) {
                longest_grouping = current_book->genre;
                highest_length = grouping_length;
                grouping_length = 1;
            }
        } else {
            if (grouping_length > highest_length) {
                longest_grouping = current_book->genre;
                highest_length = grouping_length;
                grouping_length = 1;
            }
        }
        current_book = current_book->next;
    }  
    double average_rating = average_total / average_amount;

    if (grouping_length < highest_length) {
        grouping_length = highest_length;
    }
    print_reading_stats(average_rating, total_read, total_pages, 
                        longest_grouping, grouping_length);
}

// Stage 3.1: Create multiple shelves
// Creates an empty new shelf and inserts it into the list of shelves 
// so that the list is in alphabetical order.
// 
// Parameters:
//      name    - The name of the new shelf being created
//
struct shelf *add_shelf(struct shelf *head_shelf) {
    char name[MAX_STR_LEN];
    scan_string(name);
    struct shelf *current_shelf = head_shelf;

    while (current_shelf != NULL) {
        // Checks if the name of the shelf exists already
        if (strcmp(current_shelf->name, name) == 0) {
            printf("ERROR: a shelf with name '%s' already exists\n", name);
            return head_shelf;
        }
        current_shelf = current_shelf->next;
    } 
    current_shelf = head_shelf;

    // Creates new shelf and checks where it should be inserted
    struct shelf *new_shelf = create_shelf(name);
    struct shelf *prev_shelf = NULL;
    if (strcmp(new_shelf->name, current_shelf->name) < 0) {
        new_shelf->next = head_shelf;
        return new_shelf;
    } else {
        while (current_shelf != NULL && 
            (strcmp(new_shelf->name, current_shelf->name) > 0)) {
            prev_shelf = current_shelf;
            current_shelf = current_shelf->next;
        }
        new_shelf->next = current_shelf;
        prev_shelf->next = new_shelf;
        return head_shelf;
    }
}


// Stage 3.2, 1st function: Next Shelf
// Selects the next shelf in the list of shelves and loops to the head shelf
// if the selected shelf is at the tail of the list.
//
struct shelf *next_shelf(struct shelf *selected, struct shelf *head_shelf) {
    struct shelf *current_shelf = selected;

    // Checks if the selected shelf is at the tail of the list.
    if (current_shelf->next == NULL) {
        return head_shelf;
    } else {
        return current_shelf->next;
    }
}

// Stage 3.2, 2nd function: Previous Shelf
// Selects the previous shelf in the list of shelves and loops to the tail shelf
// if the selected shelf is at the head of the list.
//
struct shelf *prev_shelf(struct shelf *selected, struct shelf *head_shelf) {
    struct shelf *current_shelf = head_shelf;

    if (selected == head_shelf) {
        while (current_shelf->next != NULL) {
            current_shelf = current_shelf->next;
        }
        return current_shelf;
    } else {
        while (current_shelf != NULL) {
            if (strcmp(current_shelf->next->name, selected->name) == 0) {
                return current_shelf;
            } 
            current_shelf = current_shelf->next;
        } 
        return selected;
    }
}

// Stage 3.3: Print Shelves
// Prints the list of shelves from head to tail, displaying the shelf name,
// and number of books for each shelf.
// 
// Parameters:
//      is_selected - an integer, returns 1 if shelf is selected, 0 if not
//      num_books   - The number of books on the given shelf
//      n           - The position of the given shelf in the list of shelves
//      name        - The name of the given shelf (a string of characters)
//
void print_shelves(struct shelf *selected, struct shelf *head_shelf) {
    struct shelf *current_shelf = head_shelf;
    int is_selected = 0;
    int num_books = 0;
    int n = 0;

    while (current_shelf != NULL) {
        // Checks which shelf is currently selected
        if (strcmp(current_shelf->name, selected->name) == 0) {
            is_selected = 1;
        } else {
            is_selected = 0;
        }

        num_books = list_length(current_shelf);
        print_shelf_summary(is_selected, n, current_shelf->name, num_books);
        current_shelf = current_shelf->next;
        n++;
    } 
}

// Stage 3.4: Delete Book
// Searches for a book with a matching title and author to the ones inputted
// in a selected shelf and frees all its associated memory.
//
// Parameters:
//      title       - The book's title (a char string)
//      author      - The book's author (a char string)
//      book_exists - integer counter that checks if the book exists
//
void delete_book(struct shelf *selected) {
    char title[MAX_STR_LEN];
    char author[MAX_STR_LEN];
    int book_exists = 0;

    scan_title_author(title, author);
    struct book *current_book = selected->books;
    struct book *deleted_book = NULL;
    struct book *prev_book = NULL;

    // Checks if the book exists in the shelf
    while (current_book != NULL) {
        if ((strcmp(current_book->title, title) == 0) 
            && (strcmp(current_book->author, author) == 0)) {
            book_exists++;
            deleted_book = current_book;
        }
        current_book = current_book->next;
    } 
    if (book_exists == 0) {
        printf("ERROR: No book '%s' by '%s' exists\n", title, author);
        return;
    }

    current_book = selected->books;
    while (current_book->next != deleted_book) {
        current_book = current_book->next;
    }

    prev_book = current_book;
    if (prev_book->next->next == NULL) {
        prev_book->next = NULL;
        free(deleted_book);
    } else {
        prev_book->next = prev_book->next->next;
        free(deleted_book);
    }
}

// Stage 3.5, 1st function: Delete Shelf
// Deletes and frees the selected shelf and all its books then assigns the
// previous shelf to be the new selected shelf. When the last shelf is
// deleted, creates a new shelf "tbr".
//
struct shelf *delete_shelf(struct shelf *selected, struct shelf *head_shelf) {
    struct shelf *current = head_shelf;

    if (selected == head_shelf) {
        if (head_shelf->next == NULL) {
            struct shelf *new_shelf = create_shelf("tbr");
            free_shelf(current);
            free(current);
            return new_shelf;
        }
        head_shelf = head_shelf->next;
        free_shelf(selected);
        free(selected);
        return head_shelf;
    }

    while ((current->next != selected) && (current->next != NULL)) {
        current = current->next;
    }
    free_shelf(selected);

    if (current->next->next == NULL) {
        current->next = NULL;
        free(selected);
        return current;
    } else {
        current->next = current->next->next;
        free(selected);
        return current;
    }
}


// Stage 3.5, 2nd function: Delete Shelf
// Deletes and frees all the books on a shelf.
//
void free_shelf(struct shelf *selected) {
    struct book *current_book = selected->books;

    while (current_book != NULL) {
        struct book *deleted_book = current_book;
        current_book = current_book->next;
        free(deleted_book);
    }
}

// Stage 3.5, 3rd function: Delete Shelf
// Once [CTRL + D] is inputted, this function frees all
// malloc'd memory remaining.
void free_everything(struct shelf *head_shelf) {

    while (head_shelf != NULL) {
        struct shelf *next_shelf = head_shelf->next;
        free_shelf(head_shelf);
        free(head_shelf);
        head_shelf = next_shelf;
    }
}


// Stage 4.1, 1st function: Create Genre Shelf
// Creates a new genre shelf that moves all books with that 
// particular genre into the new shelf.
// 
// Parameters:
//      genre           - the genre to be converted to a string
//      genre_string    - the char array the name of genre should be written to
//
struct shelf *genre_shelf(struct shelf *selected, struct shelf *head_shelf) {
    struct shelf *current = head_shelf;
    enum book_genre genre;
    char genre_string[MAX_STR_LEN];
    genre = scan_genre();
    // Checks if genre is a genre listed in the enum book_genre
    if (genre == INVALID) {
        printf("ERROR: Invalid book genre\n");
        return head_shelf;
    } 
    // Converts genre to string
    convert_genre(genre, genre_string);

    while (current != NULL) {
        // Checks if a shelf with the same name exists already
        if (strcmp(current->name, genre_string) == 0) {
            printf("ERROR: a shelf with name '%s' already exists\n",
                     genre_string);
            return head_shelf;
        }
        current = current->next;
    } 
    current = head_shelf;

    // Creates new shelf and checks where it should be inserted
    struct shelf *new_shelf = create_shelf(genre_string);
    struct shelf *prev_shelf = NULL;
    if (strcmp(new_shelf->name, current->name) < 0) {
        new_shelf->next = head_shelf;
        move_genre_books(head_shelf, new_shelf, genre);
        return new_shelf;
    } else {
        while (current != NULL && 
            (strcmp(new_shelf->name, current->name) > 0)) {
            prev_shelf = current;
            current = current->next;
        }
        new_shelf->next = current;
        prev_shelf->next = new_shelf;
        move_genre_books(head_shelf, new_shelf, genre);
        return head_shelf;
    }
}


// Stage 4.1, 2nd function: Create Genre Shelf
// Moves the books from other shelves with the same 
// genre as the new genre shelf.
//
void move_genre_books(struct shelf *head_shelf, struct shelf *new_shelf, 
                    enum book_genre genre) {
    struct shelf *current = head_shelf;
    // Find all the books with the same genre from all the other shelves
    while (current != NULL) {
        struct book *curr_book = current->books;

        while (curr_book != NULL) {

            // Check if there's books with the same title and author
            if ((curr_book->genre == genre) && (title_author(curr_book->title,
                curr_book->author, new_shelf->books) == 0)) {
                // Add pages read together
                new_shelf->books->pages_read = 
                new_shelf->books->pages_read + curr_book->pages_read;
                curr_book = genre_delete(current, curr_book);

            } else if ((curr_book->genre == genre) && 
                    (title_author(curr_book->title, 
                    curr_book->author, new_shelf->books) == 1)) {

                struct book *new_book = 
                create_book(curr_book->title, curr_book->author, 
                curr_book->genre, curr_book->rating, curr_book->pages_count);
                new_book->pages_read = curr_book->pages_read;
                new_shelf->books = new_book;

            } else {
                curr_book = curr_book->next;
            }
            curr_book = genre_delete(current, curr_book);
        }
        current = current->next;
    } 
}

// Stage 4.1, 3rd function: Create Genre Shelf
// Checks if a book with a duplicate title and author already 
// exists in the new genre shelf. 
//
int title_author(char title [MAX_STR_LEN], 
                char author[MAX_STR_LEN], struct book *new_book) {
    while (new_book != NULL) {
        // Checks if the title and author of the book exists already
        if ((strcmp(new_book->title, title) == 0) 
            && (strcmp(new_book->author, author) == 0)) {
            return 0;
        }
        new_book = new_book->next;
    } 
    return 1;
}

// Stage 4.1, 4th function: Create Genre Shelf
// Deletes the book from its original shelf after it's 
// been moved to the new genre shelf. 
//
struct book *genre_delete (struct shelf *current, struct book *curr_book) {

    struct book *current_book = current->books;
    struct book *next = curr_book->next;
    struct book *prev_book = NULL;

    while (current_book != NULL) {
        if (current_book == curr_book) {
            if (prev_book == NULL) {
                current->books = next;
            } else {
                prev_book->next = next;
            }
            free(curr_book);
            return next;
        }
        prev_book = current_book;
        current_book = current_book->next;
    }
    return next;
}



// Stage 4.1, 5th function: Create genre shelf
// Converts the genre to a string which will be the 
// new name of the new genre shelf.
//
void convert_genre(enum book_genre genre, char genre_string[MAX_STR_LEN]) {
    if (genre == CLASSICS) {
        strcpy(genre_string, "classics");
    } else if (genre == FANTASY) {
        strcpy(genre_string, "fantasy");
    } else if (genre == MYSTERY) {
        strcpy(genre_string, "mystery");
    } else if (genre == NON_FICTION) {
        strcpy(genre_string, "non_fiction");
    } else if (genre == SCI_FI) {
        strcpy(genre_string, "sci_fi");
    } else {
        strcpy(genre_string, "invalid");
    }
}

// Stage 4.2: Search Title Pattern
void search_books(struct shelf *head_shelf) {
    char pattern[MAX_STR_LEN];
    // Scan in the pattern to search
    scan_string(pattern);

    // Search through all bookshelves for books that match the pattern
    // A . matches with any character   
    // A * matches with any number of characters
    // Any non-whitespace characters other than * and .
    
    // If no books match pattern
    printf("No books matching the pattern '%s'\n", pattern);

    // Print books in increasing string length
    // For books with same length, print in alphabetical order
    // If duplicate books: print book with highest pages_read

}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////  PROVIDED FUNCTIONS  ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Prints the Bookshelf Manager usage instructions,
// displaying the different commands and their arguments.
//
void print_usage(void) {
    printf(
        "=====================[  Bookshelf Manager ]=====================\n"
        "      ===============[     Usage Info     ]===============      \n"
        "  ?                                                             \n"
        "    Show help                                                   \n"
        "  a [title] [author] [genre] [rating] [pages_count]             \n"
        "    Add a book to the shelf                                     \n"
        "  p                                                             \n"
        "    Print out all of the books on the shelf                     \n"
        "  c                                                             \n"
        "    Count all of the books on the shelf                         \n"
        "                                                                \n"
        "  i [n] [title] [author] [genre] [rating] [page_count]          \n"
        "    Insert a book into the shelf at position `n`                \n"
        "  r [title] [author] [n]                                        \n"
        "    Read `n` pages of the book with matching `title` and        \n"
        "    `author`                                                    \n"
        "  s                                                             \n"
        "    Display the reading stats                                   \n"
        "                                                                \n"
        "  A [name]                                                      \n"
        "    Add a new empty shelf in alphabetical order                 \n"
        "  >                                                             \n"
        "    Select the next shelf in the shelf list.                    \n"
        "  <                                                             \n"
        "    Select the previous shelf in the shelf list.                \n"
        "  P                                                             \n"
        "    Print out the shelves list                                  \n"
        "  d [title] [author]                                            \n"
        "    Delete book with matching `title` and `author` from         \n"
        "    the selected shelf.                                         \n"
        "  D                                                             \n"
        "    Remove the selected shelf.                                  \n"
        "                                                                \n"
        "  G [genre]                                                     \n"
        "    Create a new shelf with all the books of `genre`            \n"
        "  S [pattern]                                                   \n"
        "    Search for titles that match `pattern` across all shelves   \n"
        "================================================================\n"
    );
}

// Formats and prints out a book struct,
//
// Parameters:
//      book - The struct book to print.
// 
void print_book(struct book *book) {
    char genre_string[MAX_STR_LEN];
    genre_to_string(book->genre, genre_string);

    printf(" ---------------------------------- \n");
    printf("| %-32s |\n", book->title);
    printf("| %-32s |\n", book->author);
    printf("| %-32s |\n", genre_string);
    printf("| Rating: %d/%d     Pages: %4d/%4d |\n", 
            book->rating, MAX_RATING, book->pages_read, book->pages_count);
    printf(" -----------------V---------------- \n");
}


// Scan in the title and authors strings into the provided char array, placing 
// '\0' at the end.
//
// Parameters:
//      title  - a char array of length MAX_STR_LEN, which will be used
//              to store the title.
//      author - a char array of length MAX_STR_LEN, which will be used
//              to store the author.
// 
// Usage: 
// ```
//      char title[MAX_STR_LEN];
//      char author[MAX_STR_LEN];
//      scan_title_author(title, author);
// ```
void scan_title_author(
    char title[MAX_STR_LEN],
    char author[MAX_STR_LEN]
) {
    scan_token(title, MAX_STR_LEN);
    scan_token(author, MAX_STR_LEN);
}

// Scan in a string into the provided char array, placing '\0' at the end.
//
// Parameters:
//      string  - a char array of length MAX_STR_LEN, which will be used
//              to store the string.
//
// Usage: 
// ```
//      char string[MAX_STR_LEN];
//      scan_string(string);
// ```
void scan_string(char string[MAX_STR_LEN]) {
    scan_token(string, MAX_STR_LEN);
}

// Scans a string and converts it to a genre.
//
// Returns:
//      The corresponding genre, if the string was valid,
//      Otherwise, returns INVALID.
// 
// Usage: 
// ```
//      enum genre genre = scan_genre();
// ```
//
enum book_genre scan_genre(void) {
    char genre[MAX_STR_LEN];
    scan_token(genre, MAX_STR_LEN);
    return string_to_genre(genre);
}

// Formats and prints out the reading statistics
//
// Parameters:
//      average_rating  - The average rating of all books in selected shelf
//      total_read      - The total pages read for books on selected shelf.
//      total_pages     - The total pages for books on selected shelf.
//      longest_grouping  - The longest grouping of adjacent genres
//      grouping_length  - The length of the longest genre grouping
//
void print_reading_stats(
    double average_rating,
    int total_read,
    int total_pages,
    enum book_genre longest_grouping,
    int grouping_length
) {
    char genre_name[MAX_STR_LEN];
    genre_to_string(longest_grouping, genre_name);
    printf("  Average Rating    :  %.2lf / %d\n", average_rating, MAX_RATING);
    printf("  Pages Read        : %5d / %5d\n", total_read, total_pages);
    printf("  Longest Grouping  : %s of length %d\n", 
            genre_name, grouping_length);
}

// Formats and prints out various information about a given shelf.
//
// Parameters:
//      is_selected - 1, if this shelf is the currently selected shelf, 
//                    0, otherwise.
//      n           - The position of the given shelf in the list of shelves, 
//                    starting from 0.
//      name        - The name of the given shelf.
//      num_books   - The number of books in the given shelf.
//
void print_shelf_summary(
    int is_selected, 
    int n, 
    char name[MAX_STR_LEN],
    int num_books
) {
    printf("     ---------------------------------- \n");
    printf("    | Shelf: %-25d |\n", n);

    if (is_selected) {
        printf("--->");
    } else {
        printf("    ");
    }

    printf("| %-32s |\n", name);
    printf("    | Books: %-25d |\n", num_books);
    printf("     -----------------V---------------- \n");
}

// Get a string from an enum book_genre
// 
// Parameters:
//      genre           - the genre to be converted to a string
//      genre_string    - the char array the name of genre should be written to
//
void genre_to_string(enum book_genre genre, char genre_string[MAX_STR_LEN]) {
    if (genre == CLASSICS) {
        strcpy(genre_string, "CLASSICS");
    } else if (genre == FANTASY) {
        strcpy(genre_string, "FANTASY");
    } else if (genre == MYSTERY) {
        strcpy(genre_string, "MYSTERY");
    } else if (genre == NON_FICTION) {
        strcpy(genre_string, "NON_FICTION");
    } else if (genre == SCI_FI) {
        strcpy(genre_string, "SCI_FI");
    } else {
        strcpy(genre_string, "INVALID");
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////// ADDITIONAL PROVIDED FUNCTIONS ///////////////////////////
////////////////////////////////////////////////////////////////////////////////
// You don't need to use any of these, or understand how they work!
// We use them to implement some of the provided helper functions.

// Convert a string into an enum book_genre
// 
// Parameters:
//      genre_str   - a string version of the genre
// Returns:
//      enum book_genre
//
enum book_genre string_to_genre(char *genre_str) {
    int len = strlen(genre_str);

    if (strncasecmp(genre_str, "classics", len) == 0) {
        return CLASSICS;
    } 
    if (strncasecmp(genre_str, "fantasy", len) == 0) {
        return FANTASY;
    } 
    if (strncasecmp(genre_str, "mystery", len) == 0) {
        return MYSTERY;
    }
    if (strncasecmp(genre_str, "non_fiction", len) == 0) {
        return NON_FICTION;
    } 
    if (strncasecmp(genre_str, "sci_fi", len) == 0) {
        return SCI_FI;
    } 

    return INVALID;
}

// Scan a token into the provided buffer of buffer_size
// 
// Parameters:
//      buffer      - the buffer being scanned into
//      buffer_size - the size of buffer
// Returns:
//      the number of chars scanned
//
int scan_token(char *buffer, int buffer_size) {
    if (buffer_size == 0) {
        return 0;
    }

    char c;
    int i = 0;
    int num_scanned = 0;

    // consume all leading whitespace
    scanf(" ");

    // Scan in characters until whitespace
    while (i < buffer_size - 1
        && (num_scanned = scanf("%c", &c)) == 1 
        && !isspace(c)) {

        buffer[i++] = c;
    }

    if (i > 0) {
        buffer[i] = '\0';
    }

    return num_scanned;
}
