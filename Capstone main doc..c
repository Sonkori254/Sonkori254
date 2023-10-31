#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPLOYEE_USERNAME "Santosh"
#define EMPLOYEE_PASSWORD "pinchez"

// Define structures for employee, bus, and booking information
struct Employee {
char username[50];
char password[50];
};

struct BusInfo {
int bus_number;
char source[50];
char destination[50];
int total_seats;int available_seats;
int *booked_seats;
};

struct Booking {
int bus_number;
int seat_number;
};

// Declare arrays for storing employee, bus, and booking data
 struct Employee employees[10];
 struct BusInfo buses[10];
 struct Booking bookings[100];

int employeeCount = 0;
int busCount = 0;
int bookingCount = 0;

void initializeData() {
// Initialize employee and bus data
struct Employee emp;
strcpy(emp.username, EMPLOYEE_USERNAME);
strcpy(emp.password, EMPLOYEE_PASSWORD);
employees[employeeCount++] = emp;

int i = 0;
while (i < 10) {
struct BusInfo bus;
bus.bus_number = i + 1;
strcpy(bus.source, "Nairobi");
strcpy(bus.destination, "Kisumu");
bus.total_seats = 50;
bus.available_seats = 40;
bus.booked_seats = (int *)malloc(40 * sizeof(int));
for (int j = 0; j < 40; j++) {
bus.booked_seats[j] = 0;
}
buses[busCount++] = bus;
    i++;
}
}

int login() {
char username[50];
char password[50];
printf("Username: ");
scanf("%s", username);
printf("Password: ");
scanf("%s", password);

int i = 0;
while (i < employeeCount) {
if (strcmp(username, employees[i].username) == 0 && strcmp(password, employees[i].password) == 0) {
printf("Login successful. Welcome, %s!\n", employees[i].username);
return 1; // Successful login
}
    i++;
}

printf("Login failed. Invalid username or password.\n");
return 0; // Failed login
}
void addBusSchedule() {
  // Get the bus details from the user
  struct BusInfo bus;
  printf("Enter bus number: ");
  scanf("%d", &bus.bus_number);
  printf("Enter source: ");
  scanf("%s", bus.source);
  printf("Enter destination: ");
  scanf("%s", bus.destination);
  printf("Enter total seats: ");
  scanf("%d", &bus.total_seats);
  bus.available_seats = bus.total_seats;
  bus.booked_seats = (int *)malloc(bus.total_seats * sizeof(int));
  for (int i = 0; i < bus.total_seats; i++) {
    bus.booked_seats[i] = 0;
  }

  // Add the bus to the bus array
  buses[busCount++] = bus;
}

void removeBusSchedule() {
  // Get the bus number from the user
  int bus_number;
  printf("Enter bus number to remove: ");
  scanf("%d", &bus_number);

  // Find the bus in the bus array
  int bus_index = -1;
  for (int i = 0; i < busCount; i++) {
    if (buses[i].bus_number == bus_number) {
      bus_index = i;
      break;
    }
  }

  // If the bus is found, remove it from the bus array
  if (bus_index != -1) {
    free(buses[bus_index].booked_seats);
    buses[bus_index] = buses[busCount - 1];
    busCount--;
  } else {
    printf("Bus not found.\n");
  }
}

void displayBusSchedules() {
  // Print the bus details
  printf("\nBus Schedules:\n");
  for (int i = 0; i < busCount; i++) {
    printf("Bus Number: %d\n", buses[i].bus_number);
    printf("Source: %s\n", buses[i].source);
    printf("Destination: %s\n", buses[i].destination);
    printf("Total Seats: %d\n", buses[i].total_seats);
    printf("Available Seats: %d\n\n", buses[i].available_seats);
  }
}

void bookTicket() {
  // Get the bus number and seat number from the user
  int bus_number, seat_number;
  printf("Enter bus number: ");
  scanf("%d", &bus_number);
  printf("Enter seat number: ");
  scanf("%d", &seat_number);

  // Find the bus in the bus array
  int bus_index = -1;
  for (int i = 0; i < busCount; i++) {
    if (buses[i].bus_number == bus_number) {
      bus_index = i;
      break;
    }
  }

  // If the bus is found, book the seat
  if (bus_index != -1) {
    if (buses[bus_index].available_seats > 0 && buses[bus_index].booked_seats[seat_number] == 0) {
      buses[bus_index].booked_seats[seat_number] = 1;
      buses[bus_index].available_seats--;

      printf("Ticket booked successfully!\n");
    } else {
      printf("Seat not available.\n");
    }
  } else {
    printf("Bus not found.\n");
  }
}

int main () {{
    int login() {
char username[50];
char password[50];
printf("Username: ");
scanf("%s", username);
printf("Password: ");
scanf("%s", password);

int i = 0;
while (i < employeeCount) {
if (strcmp(username, employees[i].username) == 0 && strcmp(password, employees[i].password) == 0) {
printf("Login successful. Welcome, %s!\n", employees[i].username);
return 1; // Successful login
}
    i++;
}

printf("Login failed. Invalid username or password.\n");
return 0; // Failed login
}

void employeeMenu() {
int choice;
do {
printf("\nEmployee Menu:\n");
printf("1. Add Bus Schedule\n");
printf("2. Remove Bus Schedule\n");
printf("3. Display Bus Schedules\n");
printf("4. Book Ticket\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
// Implement the function to add a bus schedule

break;
case 2:
// Implement the function to remove a bus schedule


break;
case 3:
// Implement the function to display bus schedules

break;
case 4:
// Implement the function to book a ticket

case 5:
printf("Goodbye!\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 5);
}


}

  return 0;
			   }
