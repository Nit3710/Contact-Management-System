#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Contact
{
    string name;
    string phoneNumber;
};
class ContactManager
{
private:
    vector<Contact> contacts;

public:
    void addContact(const string &name, const string &phoneNumber)
    {
        Contact newContact = {name, phoneNumber};
        contacts.push_back(newContact);
        cout << "Contact added successfully" << endl;
    }
    void searchContact(const string &name)
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            if (name == contact.name)
            {
                cout << "Name:" << contact.name << endl
                     << "Phone Number:" << contact.phoneNumber << endl;
            }
        }
        if (!found)
        {
            cout << "Contact not found" << endl;
        }
    }
    void updateContact(const string &name, const string &newPhone)
    {
        for (auto &contact : contacts)
        {
            if (name == contact.name)
            {
                contact.phoneNumber = newPhone;
                cout << "Contact updated successfully" << endl;
                return;
            }
        }
        cout << "contact not found" << endl;
    }
    void deleteContact(const string &name)
    {
        for (auto it = contacts.begin(); it != contacts.end(); it++)
        {
            if (it->name == name)
            {
                contacts.erase(it);
                cout << "Contact deleted successfully" << endl;
                return;
            }
        }
        cout << "Contact not found" << endl;
    }

    void deleteContacts(const vector<string> &names)
    {
        for (const auto &name : names)
        {
            deleteContact(name);
        }
        cout << "Contacts deleted successfully." << endl;
    }
    void allContacts()
    {
        if (contacts.empty())
        {
            cout << "No contact available" << endl;
        }
        else
        {
            cout << "list of all contacts:" << endl;

            for (auto &contact : contacts)
            {
                cout << "Name:" << contact.name << endl
                     << "Phone number:" << contact.phoneNumber << endl;
            }
        }
    }
};
int main()
{
    ContactManager contactManager;
    int choice;
    string name, phoneNumber;
    vector<string> deleteNames;

    while (true)
    {
        cout << "\nMenu:\n1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Delete Multiple Contacts\n5. Update Contacts\n6. List All Contacts\n7. Exit\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            contactManager.addContact(name, phoneNumber);
            break;
        case 2:
            cout << "Enter name to search: ";
            cin >> name;
            contactManager.searchContact(name);
            break;
        case 3:
            cout << "Enter name to delete: ";
            cin >> name;
            contactManager.deleteContact(name);
            break;
        case 4:
            cout << "Enter names to delete (separated by spaces): ";
            while (cin >> name && name != "done")
            {
                deleteNames.push_back(name);
            }
            contactManager.deleteContacts(deleteNames);
            deleteNames.clear();
            break;
        case 5:
            cout << "Enter name to update: ";
            cin >> name;
            cout << "Enter new phone number: ";
            cin >> phoneNumber;
            contactManager.updateContact(name, phoneNumber);
            break;
        case 6:
            contactManager.allContacts();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}