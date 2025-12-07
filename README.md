# Contact Management System (C)

A clean, beginner-friendly Contact Management System written in C.
It uses **dynamic memory allocation**, **file-based storage**, and a modular multi-file structure.
Contacts are stored, loaded, edited, deleted, and saved through a simple console menu.

The project is built to teach core C concepts while still functioning as a practical program.

---

## Features

### Dynamic Storage

Contacts are stored in a dynamically expanding array using `malloc` and `realloc`.

### Add Contact

Enter a name, phone number, and email.
Email is validated so it must contain `@` and a dot after it.

### View All Contacts

Prints every saved contact in a simple numbered list.

### Search

Searches by partial or full name using substring matching.

### Edit

Choose a contact number and update the stored name, phone, and email.

### Delete

Removes a selected contact and shifts the remaining list correctly.

### Automatic Saving

Every add, edit, or delete action triggers an automatic save.
On exit, the program also saves one final time.

### Persistent Storage

Contacts are loaded from `contacts.txt` at startup.
If the file doesn’t exist, the program starts with an empty list.

### Input Safety

* Uses `fgets` for strings
* Clears the input buffer
* Trims newline characters
* Checks invalid input for menu choices

### Modular Design

Separated into logical files:

* **contacts.h** → declarations
* **contacts.c** → contact operations
* **fileio.c** → saving and loading
* **main.c** → UI loop and control flow

---

## How It Works Internally

* Memory starts at `INITIAL_CAPACITY` (10 contacts).
* When the list fills, capacity doubles using `realloc`.
* All operations modify the in-memory list first.
* Saving writes every contact as a comma-separated line:

  ```
  name,phone,email
  ```
* Loading parses each line and rebuilds the dynamic array while expanding if needed.

---

## Project Structure

```
/project-folder
│
├── main.c
├── contacts.c
├── contacts.h
├── fileio.c
└── contacts.txt   (created automatically)
```

---

## Compilation

### GCC (Linux / macOS / Windows with MinGW)

```
gcc main.c contacts.c fileio.c -o contacts
./contacts
```

### Visual Studio

* Create or open a C project
* Add all `.c` and `.h` files to the project
* Build and run normally
* Program generates `contacts.txt` in the working directory

---

