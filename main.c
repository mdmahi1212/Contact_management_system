#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)

#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (c == EOF) clearerr(stdin);
}

int main()
{
    int totalContacts = 0;
    int capacity = INITIAL_CAPACITY;

    struct Contact* contacts = malloc(capacity * sizeof(struct Contact));
    if (contacts == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    loadFromFile(&contacts, &totalContacts, &capacity);

    int choice;

    while (1) {
        showMenu();

        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        clearInputBuffer();

        handleChoice(choice,
            &contacts,
            &totalContacts,
            &capacity);
    }

    free(contacts);
    return 0;
}

void showMenu()
{
    printf("\n=== CONTACT MANAGER ===\n");
    printf("1. Add Contact\n");
    printf("2. View All\n");
    printf("3. Search\n");
    printf("4. Edit\n");
    printf("5. Delete\n");
    printf("6. Save\n");
    printf("7. Exit\n");
}

void handleChoice(
    int choice,
    struct Contact** contacts,
    int* totalContacts,
    int* capacity
)
{
    switch (choice) {
    case 1:
        addContact(contacts, totalContacts, capacity);
        break;
    case 2:
        displayContacts(*contacts, *totalContacts);
        break;
    case 3:
        searchContact(*contacts, *totalContacts);
        break;
    case 4:
        editContact(*contacts, *totalContacts);
        break;
    case 5:
        deleteContact(*contacts, totalContacts);
        break;
    case 6:
        saveToFile(*contacts, *totalContacts);
        break;
    case 7:
        saveToFile(*contacts, *totalContacts);
        printf("Goodbye.\n");
        free(*contacts);
        exit(0);
    default:
        printf("Invalid choice.\n");
    }
}