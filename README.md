# Contact Management System (C)

A simple console-based Contact Management System written in C. It lets you manage a list of contacts, save them automatically, and load them when the program starts. The code is structured for beginners but follows real project organization with multiple files and headers.

---

## Features

### Add Contacts

Create a contact with name, phone, and email.

### View All Contacts

See every saved entry in a clean list.

### Search

Find a contact by name or phone number.

### Edit

Update a contact’s information.

### Delete

Remove a contact and keep the list organized.

### Automatic Saving

Data is written to a file on exit and loaded on startup.

### Clear Menu System

Easy navigation through every option.

### Modular Code

Organized into separate `.c` and `.h` files.

---

## How It Works

The program keeps contacts in an array of structs.
Actions like adding or deleting update this list in memory.
When you exit, the entire list is saved to a text file.
When you start the program again, it reads the file back.

---

## Skills Covered

* Structs
* Arrays
* Functions
* Pointers
* File handling
* Modular C programming

---

## Basic File Structure

```
main.c
contacts.c
contacts.h
data.txt
README.md
```

---

## Compile and Run

### GCC

```
gcc main.c contacts.c -o contacts
./contacts
```

### Visual Studio

Build the solution and run the generated executable.


