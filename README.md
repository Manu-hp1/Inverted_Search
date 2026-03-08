# 🔎 Inverted Search Engine using C

A **menu-driven Inverted Search application developed in C**, designed to index multiple text files and perform efficient keyword-based searches using **hashing and linked lists**.

This project demonstrates strong fundamentals in **Data Structures, File Handling, Dynamic Memory Management, and Modular Design**.

---

## 🚀 Project Description

The Inverted Search Engine builds an index of words from multiple text files and maps them to the files in which they appear.

Instead of scanning entire files during every search, the program creates a structured database (inverted index) for faster lookups.

This project focuses on implementing efficient search logic using core C programming concepts.

---

## 🎯 Objective

- Implement a file-based inverted indexing system  
- Apply hashing and linked list data structures  
- Practice modular programming and memory management  
- Build a real-world text searching CLI application  

---

## ✨ Features

- Index multiple text files  
- Validate duplicate and empty files  
- Create hash table with 26 buckets (a–z)  
- Store word, file name, and occurrence count  
- Search for a word across indexed files  
- Display file count and word frequency  
- Save database to file  
- Load database from file  
- Menu-driven command-line interface  

---

## 🛠️ Technologies & Concepts Used

- C Programming
- Hashing Technique
- Singly Linked Lists
- Dynamic Memory Allocation
- File Handling (fopen, fscanf, fwrite, fread)
- Pointers
- Modular Programming
- Command Line Arguments

---

## 🧠 How the Application Works

- A hash table with 26 indexes is created (one for each alphabet).
- Words from input files are read and inserted into the appropriate bucket.
- Each word node maintains:
  - Word
  - File name
  - Word occurrence count
- Searching becomes efficient because the system directly accesses the corresponding bucket instead of scanning all files.
- The database can be saved and reloaded for future use.

---

## 📂 Project Structure

Inverted_Search/
├── main.c
├── create_db.c
├── search.c
├── update_db.c
├── save_db.c
├── load_db.c
├── validation.c
├── header.h
└── Makefile

---

## ▶️ Compilation and Execution

### Compile:
gcc *.c -o inverted_search

### Run:
./inverted_search file1.txt file2.txt file3.txt

---

## 🧪 Sample Usage

==================== INVERTED SEARCH ENGINE ====================
1] Create Database
2] Display Database
3] Search Word
4] Save Database
5] Update Database
6] Exit

Enter choice: 3
Enter word to search: data

Word "data" found in:
file1.txt - 3 times
file2.txt - 1 time

---

## 📊 Key Functionalities

- Hash-based word indexing  
- Efficient search implementation  
- File-based database persistence  
- Modular and structured architecture  
- Duplicate file validation  

---

## 📈 Learning Outcome

This project strengthened my understanding of:

- Hashing and indexing mechanisms  
- Linked list implementation  
- Dynamic memory management  
- Efficient searching techniques  
- Designing modular CLI tools in C  

It significantly improved my problem-solving ability and understanding of search engine fundamentals.

---

## 🌍 Real-World Applications

- Search Engines  
- Document Indexing Systems  
- Log File Analysis Tools  
- Text Processing Systems  
- Information Retrieval Systems  

---

## 👨‍💻 Author

Manu H P  
Embedded Systems Enthusiast  
Skilled in C Programming, Linux, and System-Level Concepts  

---

## 📎 GitHub Repository

https://github.com/Manu-hp1/Inverted_Search

---

## 📄 License

This project is developed for learning and educational purposes.
