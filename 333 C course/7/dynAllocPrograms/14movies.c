
/* 14movies.c
 * Dynamically allocates an array of structs that contain fields which are pointers to which
 * memory will need to be allocated in order to store various data.  Virtually no space 
 * is wasted, i.e. memory only allocated when absolutely needed.
 *
 * As each item of data is read, the appropriate pointer field within the nested structure
 * (which is allocated) will be allocated the appropriate amount of memory and is assigned
 * the data (usually with strcpy).  Some of these fields simulate arrays (an array of
 * MoviewReview and an array of strings or pointers to strings) and appropriate
 * memory is allocated.
 *
 * The input format is as follows:
 *    an int representing the number of films being reviewed
 *    For each film the input is:
 *        Title
 *        an int representing the number of reviews for this film and for each
 *        publisher's review, the following:
 *            The publisher of the review
 *            An int representing the number of lines in the review
 *            The lines in the review
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



// Note the structs are defined as data types immediately:
typedef struct {
    char *publisher; // Will need to be allocated.
    int numLines;    // A pointer or an int take the same space so just use int.
    char **lines;    // Will need to be allocated.
} MovieReview;

typedef struct {
    char *title;     // Will need to be allocated.
    int numReviews;  // A pointer or an int take the same space so just use int.
    MovieReview *reviews; // Will need to be allocated.
} Movie;


// Prototypes:
void clean_up_your_mess(Movie *, int);
void printAll(Movie *, int);

// main - Here, does more than a main should: reads input from file, allocates all memory
// to store all data in various portions of the nested structs used.
int main(void) {

    FILE* infile = fopen("Reviews.txt", "r");

    char line[100];
    int numMovies, m, numReviews, r, numLines, l;
    fgets(line, 100, infile);                          // Read the number of movies as string
    sscanf(line, "%d", &numMovies);                    // parse the string for the int numMovies
    Movie *movies = malloc(numMovies * sizeof(Movie));
 // create "array" of Movie(s)
    for (m = 0; m < numMovies; m++) {
        fgets(line, 100, infile);                      // Read a title
        movies[m].title = calloc(strlen(line) + 1, sizeof(char));
        strcpy(movies[m].title, line);
                 // Store it in the title field
        fgets(line, 100, infile);                      // Read the # of reviews and
        sscanf(line, "%d", &numReviews);
        movies[m].numReviews = numReviews;             // put it in the numReviews field then
                                                       // create a numReviews element array to
                                                       // store numReviews reviews and store each:
        movies[m].reviews = malloc(numReviews * sizeof(MovieReview));

        for (r = 0; r < numReviews; r++) {
            fgets(line, 100, infile);                  // Read publisher name and store in field
            movies[m].reviews[r].publisher = calloc(strlen(line) + 1, sizeof(char));
            strcpy(movies[m].reviews[r].publisher, line);

            fgets(line, 100, infile);                  // Read the # of lines in the review & store.
            sscanf(line, "%d", &numLines);
            movies[m].reviews[r].numLines = numLines;

            // Allocate memory for numLines char pointers
            movies[m].reviews[r].lines =
 malloc(numLines * sizeof(char *));

            for (l = 0; l < numLines; l++) {          // for each line of the current review:
                fgets(line, 100, infile);             // read the reivew
                // Allocate memory to the lth review line pointer and copy the line to it:
                movies[m].reviews[r].lines[l] =
 calloc(strlen(line) + 1, sizeof(char));
                strcpy(movies[m].reviews[r].lines[l] , line);
            }
        }
    }

    printAll(movies, numMovies);
    clean_up_your_mess(movies, numMovies);
    fclose(infile);
}

// Iterates through all movies and deallocates all previously allocated memory:
void clean_up_your_mess(Movie *movies, int numMovies) {
    int m,r,l;

    for (m = numMovies - 1; m >= 0; m--) {
       for (r = 0; r < movies[m].numReviews; r++) {
           for (l = 0; l < movies[m].reviews[r].numLines; l++)
                 free(movies[m].reviews[r].lines[l]);

           free(movies[m].reviews[r].lines);
           free(movies[m].reviews[r].publisher);
       }
       free(movies[m].reviews);
       free(movies[m].title);
    }
    free(movies);
    movies = NULL;  // Due to this, no need to set the above pointers to NULL.
}



// Iterates through all movies and prints out all reviews and related information:
void printAll(Movie *movies, int numMovies) {
    int m,r,l;

    for (m = 0; m < numMovies; m++) {
       printf("\n%s", movies[m].title);
       for (r = 0; r < movies[m].numReviews; r++) {
           printf("  %s", movies[m].reviews[r].publisher);
           for (l = 0; l < movies[m].reviews[r].numLines; l++) {
                 printf("    %s", movies[m].reviews[r].lines[l]);

           }
       }
    }
}


