# c-contact-manager
## **_Simple Contact Management System in C_**

This is a simple but robust command-line application written in C for managing personal contacts. It's a great beginner project for practicing fundamental C concepts like structs, file I/O, and string manipulation.

The application allows users to add, view, search for, and delete contacts. All contact data is persisted to a binary file (contacts.dat), so your information is saved even after the program is closed.

## **Features**

-Add a New Contact: Save a person's name, phone number, and email address.
-View All Contacts: Displays a clean, numbered list of all saved contacts.
-Search for a Contact: Find a specific contact by their name.
-Delete a Contact: Remove a contact from your list.
-Data Persistence: Contact information is automatically saved to contacts.dat on exit and loaded on startup.

## **Getting Started**

Follow these instructions to compile and run the project on your local machine.

## **Prerequisites**

You need a C compiler installed on your system. The most common one is `gcc`, which is part of the GNU Compiler Collection.
## **Compilation**

1. Clone the repository or download the main.c file to your computer.
2. Open your terminal or command prompt and navigate to the directory where the file is located.
3. Run the following command to compile the source code into an executable file named contact_manager:

`gcc main.c -o contact_manager`

## **Running the Application**

Once the compilation is successful, you can run the program with this command:

**On macOS or Linux:**

`./contact_manager`

**On Windows:**

`contact_manager.exe`

You will then be greeted with the main menu, and you can start managing your contacts.