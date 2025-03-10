#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_booking.h"

void display_movies(Movie movies[], int num_movies) {
    printf("\nAvailable Movies:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("Movie ID: %d\n", movies[i].movie_id);
        printf("Movie Name: %s\n", movies[i].movie_name);
        printf("Available Seats: %d\n", movies[i].available_seats);
        printf("Ticket Price: %.2f\n", movies[i].ticket_price);
        printf("-------------------------------------\n");
    }
}

void load_data(Movie movies[], int *num_movies) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    fscanf(file, "%d\n", num_movies);  // Read number of movies

    for (int i = 0; i < *num_movies; i++) {
        fscanf(file, "%d\n", &movies[i].movie_id);

        // Read movie name (handling newline characters properly)
        fgets(movies[i].movie_name, 50, file);
        movies[i].movie_name[strcspn(movies[i].movie_name, "\n")] = '\0';  // Remove trailing newline

        fscanf(file, "%d %f\n", &movies[i].available_seats, &movies[i].ticket_price);
    }

    fclose(file);
}
