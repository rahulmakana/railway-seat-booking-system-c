#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 10
#define SEAT_FARE 250

int seats[TOTAL_SEATS];
char passengerName[TOTAL_SEATS][50];
int fare[TOTAL_SEATS];

void initializeSeats();
void displaySeats();
void bookSeat();
void cancelSeat();

int main() {
    int choice;

    initializeSeats();

    do {
        printf("\n===== Railway Ticket Booking System =====\n");
        printf("1. Book Seat\n");
        printf("2. Cancel Seat\n");
        printf("3. View Seat Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter numbers only.\n");
            while(getchar() != '\n'); // clear buffer
            continue;
        }

        switch(choice) {
            case 1:
                bookSeat();
                break;
            case 2:
                cancelSeat();
                break;
            case 3:
                displaySeats();
                break;
            case 4:
                printf("Thank you for using the system.\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    } while(choice != 4);

    return 0;
}

void initializeSeats() {
    for(int i = 0; i < TOTAL_SEATS; i++) {
        seats[i] = 0;
        fare[i] = 0;
        strcpy(passengerName[i], "None");
    }
}

void displaySeats() {
    printf("\n--- Seat Status ---\n");
    for(int i = 0; i < TOTAL_SEATS; i++) {
        if(seats[i] == 0) {
            printf("Seat %d : Available\n", i + 1);
        } else {
            printf("Seat %d : Booked | Name: %s | Fare: Rs.%d\n",
                   i + 1, passengerName[i], fare[i]);
        }
    }
}

void bookSeat() {
    int seatNo;

    printf("Enter seat number to book (1-%d): ", TOTAL_SEATS);

    if(scanf("%d", &seatNo) != 1) {
        printf("Invalid input! Seat number must be numeric.\n");
        while(getchar() != '\n');
        return;
    }

    if(seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("Invalid seat number! Choose between 1 and %d.\n", TOTAL_SEATS);
        return;
    }

    if(seats[seatNo - 1] == 1) {
        printf("Error: Seat %d is already booked.\n", seatNo);
        return;
    }

    printf("Enter passenger name: ");
    scanf(" %[^\n]", passengerName[seatNo - 1]);

    seats[seatNo - 1] = 1;
    fare[seatNo - 1] = SEAT_FARE;

    printf("Seat %d booked successfully!\n", seatNo);
    printf("Fare: Rs.%d\n", SEAT_FARE);
}

void cancelSeat() {
    int seatNo;

    printf("Enter seat number to cancel (1-%d): ", TOTAL_SEATS);

    if(scanf("%d", &seatNo) != 1) {
        printf("Invalid input! Seat number must be numeric.\n");
        while(getchar() != '\n');
        return;
    }

    if(seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("Invalid seat number! Choose between 1 and %d.\n", TOTAL_SEATS);
        return;
    }

    if(seats[seatNo - 1] == 0) {
        printf("Error: Seat %d is already available.\n", seatNo);
        return;
    }

    seats[seatNo - 1] = 0;
    fare[seatNo - 1] = 0;
    strcpy(passengerName[seatNo - 1], "None");

    printf("Seat %d cancelled successfully!\n", seatNo);
}