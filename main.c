
#include <stdio.h>
#include <stdlib.h>
#include "movie_booking.h"

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    // Load movie data from the file
    load_data(movies, &num_movies);

    int choice;
    while (1) {
        // Display menu
        printf("\nMovie Ticket Booking System\n");
        printf("1. View Available Movies\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_movies(movies, num_movies);  // Display movies
                break;
            case 2:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
