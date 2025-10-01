#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Needed for system("clear") or system("cls")

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_CONTACTS 100

// This is our data blueprint for a single contact
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;
// Global array to store contacts and a counter
Contact contacts[MAX_CONTACTS];
int contact_count = 0;

// Function prototypes (we'll define these later)
void addContact();
void viewContacts();

int main() {
    int choice;

    while (1) { // Infinite loop for the menu
        printf("\n--- Contact Management System ---\n");
        printf("1. Add a new contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear the input buffer to prevent issues with next input
        while(getchar() != '\n'); 

        switch (choice) {
            case 1:
                // addContact(); // We will implement this soon
                printf("Add contact function called.\n");
                break;
            case 2:
                // viewContacts(); // We will implement this soon
                printf("View contacts function called.\n");
                break;
            case 3:
                printf("Search contact function called.\n");
                break;
            case 4:
                printf("Delete contact function called.\n");
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
