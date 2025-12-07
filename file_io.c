#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"

void saveToFile(struct Contact* contacts, int totalContacts)
{
    FILE* file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Could not save file.\n");
        return;
    }

    for (int i = 0; i < totalContacts; i++) {
        fprintf(file, "%s,%s,%s\n",
            contacts[i].name,
            contacts[i].phone,
            contacts[i].email);
    }

    fclose(file);
    printf("Contacts saved.\n");
}

void loadFromFile(
    struct Contact** contacts,
    int* totalContacts,
    int* capacity
)
{
    FILE* file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("No contacts.txt found. Starting fresh.\n");
        return;
    }

    char line[MAX_LINE];
    *totalContacts = 0;

    while (fgets(line, sizeof(line), file) != NULL) {

        line[strcspn(line, "\n")] = 0;

        if (*totalContacts == *capacity) {
            *capacity *= 2;
            struct Contact* temp = realloc(*contacts,
                *capacity * sizeof(struct Contact));
            if (temp == NULL) {
                printf("Memory reallocation failed while loading!\n");
                fclose(file);
                return;
            }
            *contacts = temp;
        }

        char* name = strtok(line, ",");
        char* phone = strtok(NULL, ",");
        char* email = strtok(NULL, ",");

        if (name && phone && email) {
            strncpy((*contacts)[*totalContacts].name, name, MAX_NAME - 1);
            (*contacts)[*totalContacts].name[MAX_NAME - 1] = '\0';

            strncpy((*contacts)[*totalContacts].phone, phone, MAX_PHONE - 1);
            (*contacts)[*totalContacts].phone[MAX_PHONE - 1] = '\0';

            strncpy((*contacts)[*totalContacts].email, email, MAX_EMAIL - 1);
            (*contacts)[*totalContacts].email[MAX_EMAIL - 1] = '\0';

            (*totalContacts)++;
        }
    }

    fclose(file);
    printf("Loaded %d contacts.\n", *totalContacts);
}