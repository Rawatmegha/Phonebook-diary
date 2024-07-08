#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a contact
struct Contact {
    char name[100];
    char phone[11]; // Increased size to accommodate 10 digits and null terminator
};

// Function to check if a contact with the given name already exists
bool contactExists(const struct Contact phoneBook[], int numContacts, const char *name) {
    for(int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return true; // Contact with the same name already exists
        }
    }
    return false; // Contact with the same name does not exist
}

// Function to add a contact to the phone book
void addContact(struct Contact phoneBook[], int *numContacts) {
    if (*numContacts < 100) {
        printf("Enter the name: ");
        fgets(phoneBook[*numContacts].name, sizeof(phoneBook[*numContacts].name), stdin);

        // Remove trailing newline character
        size_t len_name = strlen(phoneBook[*numContacts].name);
        if (len_name > 0 && phoneBook[*numContacts].name[len_name - 1] == '\n') {
            phoneBook[*numContacts].name[len_name - 1] = '\0';
        }

        if (contactExists(phoneBook, *numContacts, phoneBook[*numContacts].name)) {
            // Contact with the same name already exists
            char updateChoice;
            printf("Contact with the same name already exists. Do you want to update the contact? (y/n): ");
            scanf(" %c", &updateChoice);

            if (updateChoice == 'y' || updateChoice == 'Y') {
                // Update the existing contact
                printf("Enter the updated phone number (10 digits): ");
                fgets(phoneBook[*numContacts].phone, sizeof(phoneBook[*numContacts].phone), stdin);

                // Remove trailing newline character
                size_t len_phone = strlen(phoneBook[*numContacts].phone);
                if (len_phone > 0 && phoneBook[*numContacts].phone[len_phone - 1] == '\n') {
                    phoneBook[*numContacts].phone[len_phone - 1] = '\0';
                }

                printf("Contact updated successfully!\n");
                return;
            } else {
                printf("Contact not updated.\n");
                return;
            }
        } else {
            // Contact with the same name does not exist, proceed to add
            do {
                printf("Enter the phone number (10 digits): ");
                fgets(phoneBook[*numContacts].phone, sizeof(phoneBook[*numContacts].phone), stdin);

                // Remove trailing newline character
                size_t len_phone = strlen(phoneBook[*numContacts].phone);
                if (len_phone > 0 && phoneBook[*numContacts].phone[len_phone - 1] == '\n') {
                    phoneBook[*numContacts].phone[len_phone - 1] = '\0';
                }

                // Check if the phone number has exactly 10 digits
                if (strlen(phoneBook[*numContacts].phone) == 10) {
                    break; // Valid phone number, exit the loop
                } else {
                    printf("Invalid phone number. Please enter a 10-digit number.\n");
                }
            } while (1); // Repeat until a valid phone number is entered

            (*numContacts)++;
            printf("Contact added successfully!\n");
        }
    } else {
        printf("Phone book is full. Cannot add more contacts.\n");
    }
}

// Rest of the code remains unchanged...

void displayContacts(const struct Contact phoneBook[], int numContacts) {
    if (numContacts > 0) {
        printf("\n--- Contacts ---\n");
        for (int i = 0; i < numContacts; i++) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            printf("-----------------\n");
        }
    } else {
        printf("No contacts available.\n");
    }
}

int main() {
    struct Contact phoneBook[100]; // Array to store contacts
    int numContacts = 0; // Number of contacts in the phone book

    int choice;

    do {
        // Display menu
        printf("\n--- Phone Management Diary ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Consume the newline character from the buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                displayContacts(phoneBook, numContacts);
                break;
            case 3:
                printf("Exiting the program.\n");
                break; 
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}*/

