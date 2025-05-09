#  Contact Book Manager Application 

 A C++ application that implements a fully functional **Contact Book** using a custom `Array` data structure. The program allows you to add, search, delete, update, and manage contacts efficiently with features for:

- **Classification** (Friends, Work, Family, Others, Favorites)
- **Searching** by Name and Phone Number
- **Saving** and **Loading** from files
- **Reversing** and **Clearing** the contact list

---

##  **Features:**

* **Add New Contacts:** Store detailed information including address, phone numbers, emails, and classification.
* **Search Contacts:** Find contacts by name or phone number easily.
* **Update and Delete:** Edit existing contacts or remove them.
* **Classifications:** Separate contacts into different categories (Friends, Family, Work, etc.).
* **Favorites List:** Mark contacts as favorite for quick access.
* **File Storage:** Save and load contacts to and from files.
* **Reverse Contacts:** Display the list in reverse order.
* **Clear All Contacts:** Remove all data from the Contact Book.

---

## **Requirements:**

* C++ Compiler (e.g., g++)
* Basic understanding of Object-Oriented Programming (OOP)

---


##  **Implementation Details:**

* **Array Data Structure:** Custom implementation with dynamic resizing.
* **Classes:**

  * `Person`: Stores personal information of the contact.
  * `Address`: Manages address details.
  * `ContactBook`: Handles all CRUD operations for contacts.
  * `Array`: Template-based dynamic array.
* **File Handling:** Data is saved and loaded using file I/O.

---

##  **Complexity Analysis:**

| Operation              | Time Complexity  | Space Complexity |
| ---------------------- | ---------------- | ---------------- |
| Insertion (Append)     | O(1) (Amortized) | O(n)             |
| Deletion               | O(n)             | O(n)             |
| Search (By Name/Phone) | O(n)             | O(1)             |
| Resize                 | O(n)             | O(n)             |
| Reverse                | O(n)             | O(1)             |

---

## **UML**

![UML](https://github.com/ShamsAlalfy/Contact-Book-Manager/blob/main/Contact%20Book%20Manager/Contact%20UML.jpg)
