#ifndef MOVIE_BOOKING_H
#define MOVIE_BOOKING_H

#define MAX_MOVIES 5

// Structure to hold movie details
typedef struct {
    int movie_id;
    char movie_name[50];
    int available_seats;
    float ticket_price;
} Movie;

// Function declarations
void display_movies(Movie movies[], int num_movies);
void load_data(Movie movies[], int *num_movies);

#endif