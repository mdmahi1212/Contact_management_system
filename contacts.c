#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"

void trimNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

int isValidEmail(const char* email) {
    const char* at = strchr(email, '@');
    if (!at) return 0;

    const char* dot = strchr(at + 1, '.');
    if (!dot) return 0;

    if (at == email) return 0;
    if (dot == at + 1) return 0;
    if (strlen(dot + 1) < 1) return 0;

    return 1;
}

void addContact(
    struct Contact** contacts,
    int* totalContacts,
    int* capacity
)
{
    if (*totalContacts == *capacity) {
        *capacity *= 2;
        struct Contact* temp = realloc(*contacts,
            *capacity * sizeof(struct Contact));
        if (temp == NULL) {
            printf("Memory reallocation failed!\n");
            return;
        }
        *contacts = temp;
    }

    printf("\n--- Add Contact ---\n");

    printf("Name: ");
    fgets((*contacts)[*totalContacts].name, MAX_NAME, stdin);
    trimNewline((*contacts)[*totalContacts].name);

    printf("Phone: ");
    fgets((*contacts)[*totalContacts].phone, MAX_PHONE, stdin);
    trimNewline((*contacts)[*totalContacts].phone);

    printf("Email: ");
    while (1) {
        fgets((*contacts)[*totalContacts].email, MAX_EMAIL, stdin);
        trimNewline((*contacts)[*totalContacts].email);

        if (isValidEmail((*contacts)[*totalContacts].email)) break;
        printf("Invalid email (must contain '@' and '.' after '@'). Try again: ");
    }

    (*totalContacts)++;
    printf("Contact added.\n");

    saveToFile(*contacts, *totalContacts);
    printf("Saved automatically.\n");
}

void displayContacts(struct Contact* contacts, int totalContacts)
{
    printf("\n--- All Contacts ---\n");

    if (totalContacts == 0) {
        printf("No contacts saved.\n");
        return;
    }

    for (int i = 0; i < totalContacts; i++) {
        printf("%d. %s | %s | %s\n",
            i + 1,
            contacts[i].name,
            contacts[i].phone,
            contacts[i].email);
    }
}

void searchContact(struct Contact* contacts, int totalContacts)
{
    if (totalContacts == 0) {
        printf("No contacts.\n");
        return;
    }

    char searchName[MAX_NAME];

    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME, stdin);
    trimNewline(searchName);

    int found = 0;

    for (int i = 0; i < totalContacts; i++) {
        if (strstr(contacts[i].name, searchName)) {
            printf("%d. %s | %s | %s\n",
                i + 1,
                contacts[i].name,
                contacts[i].phone,
                contacts[i].email);
            found = 1;
        }
    }

    if (!found)
        printf("No matching contacts found.\n");
}

void editContact(struct Contact* contacts, int totalContacts)
{
    if (totalContacts == 0) {
        printf("Nothing to edit.\n");
        return;
    }

    displayContacts(contacts, totalContacts);

    int num;
    printf("Enter contact number to edit: ");
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > totalContacts) {
        printf("Invalid number.\n");
        return;
    }

    int index = num - 1;

    printf("New name: ");
    fgets(contacts[index].name, MAX_NAME, stdin);
    trimNewline(contacts[index].name);

    printf("New phone: ");
    fgets(contacts[index].phone, MAX_PHONE, stdin);
    trimNewline(contacts[index].phone);

    printf("New email: ");
    while (1) {
        fgets(contacts[index].email, MAX_EMAIL, stdin);
        trimNewline(contacts[index].email);

        if (isValidEmail(contacts[index].email)) break;
        printf("Invalid email (must contain '@' and '.' after '@'). Try again: ");
    }

    printf("Contact updated.\n");

    saveToFile(contacts, totalContacts);
    printf("Saved automatically.\n");
}

void deleteContact(struct Contact* contacts, int* totalContacts)
{
    if (*totalContacts == 0) {
        printf("Nothing to delete.\n");
        return;
    }

    displayContacts(contacts, *totalContacts);

    int num;
    printf("Enter contact number to delete: ");
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > *totalContacts) {
        printf("Invalid number.\n");
        return;
    }

    int index = num - 1;

    for (int i = index; i < *totalContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    (*totalContacts)--;

    printf("Contact deleted.\n");

    saveToFile(contacts, *totalContacts);
    printf("Saved automatically.\n");
}