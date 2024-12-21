#include <iostream>
struct Medicine
{
    int id;
    string name;
    int quantity;
    double price;
    string expiryDate;

    Medicine(int id, string name, int quantity, double price, string expiryDate)
        : id(id), name(name), quantity(quantity), price(price), expiryDate(expiryDate) {}
};

struct Node
{
    Medicine *medicine;
    Node *next;

    Node(Medicine *medicine) : medicine(medicine), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addMedicine(Medicine *medicine)
    {
        Node *newNode = new Node(medicine);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
