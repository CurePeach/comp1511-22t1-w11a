#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 256

#define SUCCESS 0
#define NOT_FOUND 1

// STRUCT DEFINITIONS

struct movie {
    char title[MAX_STR_LENGTH];
    double rating;
    int length;

    struct movie *next;
};

struct genre {
    char name[MAX_STR_LENGTH];

    struct movie *movies;
    struct genre *next;
};

struct cinema {
    struct genre *genres;
};

// FUNCTION PROTOTYPES
struct cinema *create_cinema();
void add_genre(struct cinema *cinema, char *genre_name);
int add_movie(
    struct cinema *cinema,
    char *genre_name,
    char *movie_title,
    double rating,
    int length
);
void print_genre(struct cinema *cinema, char *genre_name);
struct genre *find_genre(struct cinema *cinema, char *genre_name);
struct movie *find_last_movie(struct genre *genre);
struct movie *new_movie(char *movie_title, double rating, int length);
void print_movie(struct movie *movie);

// This function has been provided for you to test!
int main(void) {
    struct cinema *cinema = create_cinema();
    
    add_genre(cinema, "Action");
    
    // Will only work after finishing this function!
    add_movie(cinema, "Action", "Scooby Doo", 7.5, 90);
    add_movie(cinema, "Action", "Mission Impossible", 8.2, 93);

    // Note that this shouldn't work because we don't have a genre named "Drama"
    // in our cinema
    add_movie(cinema, "Drama", "Squid Game", 9.7, 600);
    
    // Will only work after finishing this function!
    print_genre(cinema, "Action");

    // This shouldn't work because we don't have a genre named "Drama" in our
    // cinema
    print_genre(cinema, "Drama");

    return 0;
}

//
// Creates a new `struct cinema` and returns it.
//
// `create_cinema` takes in no parameters.
//
// `create_cinema` will return a pointer to a new `struct cinema`.
//
struct cinema *create_cinema() {
    struct cinema *new = malloc(sizeof(struct cinema));
    new->genres = NULL;

    return new;
}

//
// Adds a genre to the head of the provided cinema of `genre_name`
//
// `add_genre` takes in these parameters:
// - `cinema` a pointer to the `struct cinema` to add the genre to
// - `genre_name` name of the genre to add to the cinema
//
// `add_genre` returns nothing.
//
// ASSUMPTIONS:
// - `cinema` will always be a valid pointer
// - `genre_name` will always be a valid string of `MAX_STR_LENGTH` size
//
void add_genre(struct cinema *cinema, char *genre_name) {
    struct genre *new = malloc(sizeof(struct genre));
    strcpy(new->name, genre_name);
    new->movies = NULL;
    new->next = NULL;

    new->next = cinema->genres;
    cinema->genres = new;
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////// Implement the functions below! ////////////////////////
////////////////////////////////////////////////////////////////////////////////

//
// Adds a movie to the end of the desired genre in the desired cinema.
//
// `add_movie` takes in these parameters:
// - `cinema` - a pointer to the `struct cinema` to add the movie to
// - `genre_name` - name of the desired genre for the movie to add to the cinema
// - `movie_title` - name of the movie to add to the genre
// - `rating` - Rating /10 of the provided movie
// - `length` - Length (in minutes) of the provided movie
//
// `add_movie` returns, in order of precedence:
// `NOT_FOUND` if genre was not found in cinema
// `SUCCESS` if movie is added
//
// ASSUMPTIONS:
// - `cinema` will always be a valid pointer
// - `genre_name` will always be a valid string of `MAX_STR_LENGTH` size
// - `movie_title` will always be a valid string of `MAX_STR_LENGTH` size
// - `rating` will always be a positive integer between [0, 10] inclusive
// - `length` will always be a positive number
//
int add_movie(
    struct cinema *cinema,
    char *genre_name,
    char *movie_title,
    double rating,
    int length
) {
    struct genre *to_add = find_genre(cinema, genre_name);
    if (to_add == NULL) {
        return NOT_FOUND;
    }
    
    struct movie *end = find_last_movie(to_add);
    
    struct movie *new = new_movie(movie_title, rating, length);
    if (end == NULL) {
        to_add->movies = new;
    } else {
        end->next = new;
    }
    
    return SUCCESS;
}

//
// Prints all the movies in the desired genre
//
// Each movie of the genre is printed on a new line in the format:
//
// <movie1-TITLE>, <movie1-RATING>/10 (<movie1-LENGTH> minutes)
// <movie2-TITLE>, <movie2-RATING>/10 (<movie2-LENGTH> minutes)
// <movie3-TITLE>, <movie3-RATING>/10 (<movie3-LENGTH> minutes)
// ...
//
// `print_genre` takes in these parameters:
// - `cinema` a pointer to the `struct cinema` to print the genre
// - `genre_name` name of the desired genre to print in the cinema
//
// `print_genre` returns nothing.
//
// ASSUMPTIONS:
// - `cinema` will always be a valid pointer
// - `genre_name` will always be a valid string of `MAX_STR_LENGTH` size
void print_genre(struct cinema *cinema, char *genre_name) {
    struct genre *genre = find_genre(cinema, genre_name);
    if (genre == NULL) {
        return;
    }

    struct movie *curr = genre->movies;
    while (curr != NULL) {
        print_movie(curr);
        curr = curr->next;
    }
    
    return;
}

// Finds the genre in the cinema with the given name
// Takes in a cinema and the name of a genre
// Returns the genre if found, otherwise NULL
//
// Assumes cinema is valid
struct genre *find_genre(struct cinema *cinema, char *genre_name) {
    struct genre *curr = cinema->genres;
    while (curr != NULL) {
        if (strcmp(curr->name, genre_name) == 0) {
            return curr; 
        }
        
        curr = curr->next;
    }

    return NULL;
}

// Finds the last movie in a genre
// Takes in the genre
// Returns NULL if there are no movies, otherwise the last movie
//
// Assumes genre is valid
struct movie *find_last_movie(struct genre *genre) {
    struct movie *curr = genre->movies;
    if (curr == NULL) {
        return NULL;
    }
    
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    return curr;
}

// Creates a new movie with the given details
// Takes in a movie title, rating and length
// Returns the new movie
struct movie *new_movie(char *movie_title, double rating, int length) {
    struct movie *new = malloc(sizeof(struct movie));
    strcpy(new->title, movie_title);
    new->rating = rating;
    new->length = length;
    new->next = NULL;
    
    return new;
}

// Prints a movie in the format: <title>, <rating>/10 (<length> minutes) where
// rating is to one decimal place
// Takes in a movie
// Returns nothing
void print_movie(struct movie *movie) {
    printf(
        "%s, %.1lf/10 (%d minutes)\n", 
        movie->title,
        movie->rating,
        movie->length
    );

    return;
}
