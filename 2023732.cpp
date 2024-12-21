#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;

class Graph
{
private:
    map<string, vector<string>> adjList;

public:
    void addConnection(const string &supplier, const string &retailer)
    {
        adjList[supplier].push_back(retailer);
    }

    void displayNetwork()
    {
        cout << "\n\033[1;36mSupplier Network:\033[0m\n";
        for (const auto &pair : adjList)
        {
            cout << pair.first << " supplies to: ";
            for (const string &retailer : pair.second)
            {
                cout << retailer << " ";
            }
            cout << endl;
        }
    }
};

// Pharmacy Management System
class Pharmacy {
private:
    LinkedList inventoryList;
    unordered_map<int, Medicine *> idTable;
    unordered_map<string, Medicine *> nameTable;
    queue<string> orderQueue;
    stack<string> undoStack;
    Graph supplierNetwork;
    AVLTree medicineTree;
    double totalSales = 0.0;
    const string managerUsername = "admin";
    const string managerPassword = "abc";

    void displayWelcomeMessage()
    {
        const int totalWidth = 60;
        const string message = "Welcome to Pharmacy Management System";
        int padding = (totalWidth - message.length()) / 2;

        cout << string(totalWidth, '-') << endl;
        cout << string(padding, ' ') << message << endl;
        cout << string(totalWidth, '-') << endl;
    }

public:
    Pharmacy()
    {
        preAddItems();
    }
    void preAddItems()
    {
        addMedicine(101, "Paracetamol", 50, 10.5, "2024-12-31");
        addMedicine(102, "Ibuprofen", 30, 15.0, "2025-01-15");
        addMedicine(103, "Amoxicillin", 20, 25.0, "2024-11-20");
        addMedicine(104, "CoughSyrup", 40, 8.5, "2025-06-10");
        addMedicine(105, "VitaminC", 100, 5.0, "2025-03-01");
        addMedicine(106, "Metformin", 60, 12.0, "2024-10-05");
        addMedicine(107, "Aspirin", 70, 9.0, "2025-02-14");
        addMedicine(108, "Cetirizine", 80, 7.5, "2025-04-25");
        addMedicine(109, "Antacid", 90, 6.0, "2024-09-10");
        addMedicine(110, "Loperamide", 50, 4.5, "2024-12-20");
        addMedicine(111, "SalineNasalSpray", 20, 18.5, "2025-07-01");
        addMedicine(112, "Azithromycin", 30, 22.0, "2024-08-15");
        addMedicine(113, "Doxycycline", 40, 19.5, "2024-11-30");
        addMedicine(114, "Lorazepam", 15, 35.0, "2025-06-12");
        addMedicine(115, "Multivitamins", 200, 10.0, "2025-01-20");
        addMedicine(116, "Insulin", 25, 120.0, "2025-03-30");
        addMedicine(117, "Prednisone", 35, 8.0, "2024-12-25");
        addMedicine(118, "Epinephrine", 10, 150.0, "2025-05-15");
        addMedicine(119, "Omeprazole", 60, 11.0, "2024-09-28");
        addMedicine(120, "Albuterol Inhaler", 45, 25.0, "2025-04-10");
        addMedicine(121, "FolicAcid", 100, 5.5, "2025-03-14");
        addMedicine(122, "Warfarin", 50, 30.0, "2024-12-19");
        addMedicine(123, "Clopidogrel", 30, 40.0, "2024-08-09");
        addMedicine(124, "Levothyroxine", 90, 13.5, "2025-02-27");
        addMedicine(125, "Losartan", 70, 15.5, "2024-11-01");
        addMedicine(126, "Metoprolol", 85, 17.0, "2025-06-18");
        addMedicine(127, "Hydrochlorothiazide", 65, 6.5, "2024-09-13");
        addMedicine(128, "Atorvastatin", 75, 22.0, "2024-10-24");
        addMedicine(129, "Rosuvastatin", 55, 25.0, "2025-05-22");
        addMedicine(130, "Ranitidine", 95, 5.5, "2024-12-15");
        addMedicine(131, "Diazepam", 20, 30.0, "2025-02-01");
        addMedicine(132, "Codeine", 10, 50.0, "2024-11-11");
        addMedicine(133, "Diclofenac", 100, 7.5, "2025-06-05");
        addMedicine(134, "Loratadine", 90, 6.5, "2024-12-08");
        addMedicine(135, "Miconazole", 40, 18.0, "2025-01-30");
        addMedicine(136, "Fluconazole", 35, 20.0, "2025-03-11");
        addMedicine(137, "Salbutamol", 50, 25.0, "2024-09-30");
        addMedicine(138, "Hydrocortisone", 30, 15.0, "2025-04-20");
        addMedicine(139, "Clotrimazole", 25, 12.0, "2025-02-25");
        addMedicine(140, "Enalapril", 60, 10.5, "2024-12-03");
        addMedicine(141, "Propranolol", 70, 9.5, "2025-03-09");
        addMedicine(142, "Sildenafil", 15, 50.0, "2025-06-07");
        addMedicine(143, "Tamsulosin", 40, 18.0, "2024-11-21");
        addMedicine(144, "Finasteride", 30, 20.0, "2024-10-28");
        addMedicine(145, "Clindamycin", 45, 19.0, "2025-05-08");
        addMedicine(146, "Chloramphenicol", 25, 22.0, "2024-12-02");
        addMedicine(147, "AmphotericinB", 15, 150.0, "2024-09-19");
        addMedicine(148, "Vancomycin", 10, 200.0, "2025-01-23");
        addMedicine(149, "Cephalexin", 35, 30.0, "2024-11-17");
        addMedicine(150, "Zincals;dfokSulfate", 100, 3.5, "2025-02-28");
    }

    bool authenticateManager()
    {
        string username, password;
        cout << "\033[1;33mEnter username: \033[0m";
        cin >> username;
        cout << "\033[1;33mEnter password: \033[0m";
        cin >> password;

        if (username == managerUsername && password == managerPassword)
        {
            cout << "\033[1;32m\nAuthentication successful!\033[0m\n";
            displayWelcomeMessage();
            return true;
        }
        else
        {
            cout << "\033[1;31mInvalid credentials!\033[0m\n";
            return false;
        }
    }

    void customerMenu() {
        int choice;
        do {
            cout << "\n\033[1;34mCustomer Menu:\033[0m\n";
            cout << "1. Display Medicines\n";
            cout << "2. Place an Order\n";
            cout << "3. Review Order\n";
            cout << "4. Print Receipt\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    medicineTree.display();
                    break;
                case 2: {
                    string name;
                    int quantity;
                    cout << "Enter Medicine Name to order: ";
                    cin >> name;
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    orderMedicine(name, quantity);
                    break;
                }
                case 3:
                    reviewOrder();
                    break;
                case 4:
                    printReceipt();
                    break;
                case 5:
                    cout << "\033[1;32mThank you for visiting. Goodbye!\033[0m\n";
                    break;
                default:
                    cout << "\033[1;31mInvalid choice! Please try again.\033[0m\n";
            }
        } while (choice != 5);
    }
