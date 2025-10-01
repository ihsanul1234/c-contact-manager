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
void addContact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    Contact new_contact;
    printf("Enter name: ");
    fgets(new_contact.name, MAX_NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(new_contact.phone, MAX_PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0;

    printf("Enter email: ");
    fgets(new_contact.email, MAX_EMAIL_LENGTH, stdin);
    new_contact.email[strcspn(new_contact.email, "\n")] = 0;

    contacts[contact_count] = new_contact;
    contact_count++;

    printf("Contact added successfully!\n");
}
void viewContacts() {
    if (contact_count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- All Contacts ---\n");
    for (int i = 0; i < contact_count; i++) {
        printf("Contact #%d\n", i + 1);
        printf("  Name:  %s\n", contacts[i].name);
        printf("  Phone: %s\n", contacts[i].phone);
        printf("  Email: %s\n", contacts[i].email);
        printf("\n");
    }
    printf("--------------------\n");
}
// ... inside the switch
case 1:
    addContact();
    break;
case 2:
    viewContacts();
    break;
// ...
