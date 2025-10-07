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
void searchContact();
void deleteContact();
void saveContactsToFile();
void loadContactsFromFile();

int main() {
    int choice;
    loadContactsFromFile();

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
        system("clear");

        switch (choice) {
            case 1:
                addContact();
                printf("Add contact function called.\n");
                break;
            case 2:
                viewContacts();
                printf("View contacts function called.\n");
                break;
            case 3:
                searchContact();           
                printf("Search contact function called.\n");
                break;
            case 4:
                deleteContact();                
                printf("Delete contact function called.\n");
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                saveContactsToFile();
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

// Function to save all contacts to a file
void saveContactsToFile() {
    FILE *file = fopen("contacts.dat", "wb"); // wb = write binary
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(contacts, sizeof(Contact), contact_count, file);
    fclose(file);
}

// Function to load contacts from a file
void loadContactsFromFile() {
    FILE *file = fopen("contacts.dat", "rb"); // rb = read binary
    if (file == NULL) {
        // This is okay on the first run, means no file exists yet
        return; 
    }

    // Read structs one by one until the end of the file
    while(fread(&contacts[contact_count], sizeof(Contact), 1, file) == 1) {
        contact_count++;
        if (contact_count >= MAX_CONTACTS) {
            break; // Stop if the array is full
        }
    }
    fclose(file);
}
// (Don't forget the function prototypes at the top of the file!)

void searchContact() {
    char search_name[MAX_NAME_LENGTH];
    int found = 0;
    printf("Enter name to search for: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("\n--- Contact Found ---\n");
            printf("  Name:  %s\n", contacts[i].name);
            printf("  Phone: %s\n", contacts[i].phone);
            printf("  Email: %s\n", contacts[i].email);
            printf("---------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    char search_name[MAX_NAME_LENGTH];
    int found_index = -1;
    printf("Enter name of contact to delete: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        // Shift all elements after the found index to the left
        for (int i = found_index; i < contact_count - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        contact_count--;
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}