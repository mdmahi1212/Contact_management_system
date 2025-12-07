#ifndef CONTACTS_H
#define CONTACTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_EMAIL 50
#define MAX_LINE 256

struct Contact {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
};

void showMenu();

void handleChoice(
    int choice,
    struct Contact** contacts,
    int* totalContacts,
    int* capacity
);

void addContact(
    struct Contact** contacts,
    int* totalContacts,
    int* capacity
);

void displayContacts(
    struct Contact* contacts,
    int totalContacts
);

void searchContact(
    struct Contact* contacts,
    int totalContacts
);

void editContact(
    struct Contact* contacts,
    int totalContacts
);

void deleteContact(
    struct Contact* contacts,
    int* totalContacts
);

void saveToFile(
    struct Contact* contacts,
    int totalContacts
);

void loadFromFile(
    struct Contact** contacts,
    int* totalContacts,
    int* capacity
);

void clearInputBuffer();
void trimNewline(char* str);
int isValidEmail(const char* email);

#endif