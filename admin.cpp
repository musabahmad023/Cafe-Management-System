#include <iostream>
#include "admin.h"
#include "project.h"
const int MAX_USERS = 5;
const int MAX_LENGTH = 20;
int user_count;
char usernames[MAX_USERS + 1][MAX_LENGTH];
char passwords[MAX_USERS + 1][MAX_LENGTH];

// Admin Functions Definitions
void read_stock(int &items_count, const int max_items, char item_names[20][15], int price[20], int quantity[20], int total_price[20])
{
    items_count = 0;
    ifstream file("admin.txt");
    if (!file)
    {
        cout << "Error! In opening file for reading ....";
        return;
    }

    char line[100];
    file.getline(line, 100, '\n');

    while (file.getline(item_names[items_count], 15, ' '), file >> quantity[items_count] >> price[items_count] >> total_price[items_count])
    {
        file.ignore();
        items_count++;
    }
    file.close();
    cout << line << endl;

    for (int i = 0; i < items_count; i++)
    {
        cout << i + 1 << "." << left << fixed << setw(15) << item_names[i] << "|" << left << fixed << setw(15) << quantity[i] << left << "|" << fixed << setw(15) << price[i] << "|" << left << fixed << setw(15) << total_price[i] << endl;
    }
}

void below_threshold(int &items_count, const int max_items, char item_names[20][15], int price[20], int quantity[20], int total_price[20])
{
    const int threshold = 10;
    read_stock(items_count, max_items, item_names, price, quantity, total_price);

    for (int i = 0; i < items_count; i++)
    {
        if (quantity[i] < threshold)
        {
            cout << i + 1 << "." << item_names[i] << " is less than threshold " << endl;
        }
    }
}

void add_items(int &items_count, const int max_items, char item_names[20][15], int price[20], int quantity[20], int total_price[20])
{
    read_stock(items_count, max_items, item_names, price, quantity, total_price);

    if (items_count >= max_items)
    {
        cout << "\nSorry! Max Limit of Items Reached :( ";
        return;
    }

    cout << "Enter the name of Item :: " << endl;
    cin.getline(item_names[items_count], 15);
    cout << "Enter the Quantity of Item :: " << endl;
    cin >> quantity[items_count];
    cout << "Enter the Price of Item :: " << endl;
    cin >> price[items_count];
    total_price[items_count] = quantity[items_count] * price[items_count];
    cout << "Item added successfully!" << endl;
    items_count++;

    ofstream file("admin.txt", ios::app);
    if (!file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }

    // SIRF NEW LINE KO ADD KRY GA
    file << item_names[items_count - 1] << ' ' << quantity[items_count - 1] << ' ' << price[items_count - 1] << ' ' << total_price[items_count - 1] << '\n';

    file.close();
}
void remove_item(int &items_count, const int max_items, char item_names[20][15], int price[20], int quantity[20], int total_price[20])
{
    read_stock(items_count, max_items, item_names, price, quantity, total_price);

    char search[15];
    cout << "Enter the Item's Name or quantity or price (per item) to remove :: ";
    cin.getline(search, 15);
    bool itemfound = false;

    ofstream file("admin.txt");

    if (!file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }
    file << "Item Name" << setw(10) << "Quantity" << setw(10) << "Price" << setw(15) << "Total Price" << endl;

    for (int i = 0; i < items_count; i++)
    {
        if (strcmp(item_names[i], search) == 0 || quantity[i] == atoi(search) || price[i] == atoi(search))
        {
            items_count--;
            itemfound = true;
            cout << "Item Removed Successfully !! ";
            continue;
        }
        file << item_names[i] << " " << quantity[i] << " " << price[i] << " " << total_price[i] << '\n';
    }
    file.close();

    if (!itemfound)
    {
        cout << "Sorry! Item not found :( ";
    }
}

void search_item(int &items_count, const int max_items, char item_names[20][15], int price[20], int quantity[20], int total_price[20])
{
    read_stock(items_count, max_items, item_names, price, quantity, total_price);
    char search[15];
    cout << "Enter the Item's Name or quantity or price (per item) to search :: ";
    cin.getline(search, 15);
    bool itemfound = false;
    for (int i = 0; i < items_count; i++)
    {
        if (strcmp(item_names[i], search) == 0 || quantity[i] == atoi(search) || price[i] == atoi(search))
        {
            cout << setw(20) << "Item Name" << setw(10) << "Quantity" << setw(15) << "Price" << setw(15) << "Total Price" << endl;
            cout << setw(20) << item_names[i] << setw(10) << quantity[i] << setw(15) << price[i] << setw(15) << total_price[i] << endl;
            itemfound = true;
        }
    }
    if (itemfound == false)
    {
        cout << "Sorry! Item not found :( ";
    }
}
void update_item(int &items_count, const int max_items, char item_names[20][15], int price[20], int quantity[20], int total_price[20])
{
    read_stock(items_count, max_items, item_names, price, quantity, total_price);
    char search[15];
    cout << "Enter the Item's Name or quantity or price (per item) to update :: ";
    cin.getline(search, 15);
    bool itemfound = false;

    ofstream file("admin.txt");

    if (!file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }
    file << "Item Names " << setw(15) << "Quantity " << setw(10) << "Price " << setw(15) << "Total Price" << '\n';
    for (int i = 0; i < items_count; i++)
    {
        if (strcmp(item_names[i], search) == 0 || quantity[i] == atoi(search) || price[i] == atoi(search))
        {
            char new_name[15];
            int new_qty, new_price, new_tprice;
            cout << "Enter the updated name of Item :: ";
            cin.getline(new_name, 15);
            cout << "Enter the updated quantity of Item :: ";
            cin >> new_qty;
            cout << "Enter the updated price of Item :: ";
            cin >> new_price;
            itemfound = true;
            cout << "Item Updated Successfully !! ";
            new_tprice = new_qty * new_price;
            strcpy(item_names[i], new_name);
            quantity[i] = new_qty;
            price[i] = new_price;
            total_price[i] = new_tprice;
        }
        file << item_names[i] << " " << quantity[i] << " " << price[i] << " " << total_price[i] << '\n';
    }
    file.close();

    if (!itemfound)
    {
        cout << "Sorry! Item not found :( ";
    }
}
void order_item(int &items_count, const int max_items, char item_names[20][15], int price[20], int quantity[20], int total_price[20])
{
    read_stock(items_count, max_items, item_names, price, quantity, total_price);
    char search[15];
    cout << "Enter the Item's Name or quantity or price (per item) to update :: ";
    cin.getline(search, 15);
    bool itemfound = false;

    ofstream file("admin.txt");

    if (!file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }
    file << "Item Names " << setw(15) << "Quantity " << setw(10) << "Price " << setw(15) << "Total Price" << '\n';
    for (int i = 0; i < items_count; i++)
    {
        if (strcmp(item_names[i], search) == 0 || quantity[i] == atoi(search) || price[i] == atoi(search))
        {
            int new_qty, new_tprice;
            cout << "Enter the quantity you want to order  :: ";
            cin >> new_qty;
            itemfound = true;
            cout << "Item Ordered Successfully !! ";
            new_tprice = new_qty * price[i];
            quantity[i] += new_qty;
            total_price[i] += new_tprice;
        }
        file << item_names[i] << " " << quantity[i] << " " << price[i] << " " << total_price[i] << '\n';
    }
    file.close();

    if (!itemfound)
    {
        cout << "Sorry! Item not found :( ";
    }
}
void add_notification_for_students()
{
    char notification[1000];
    ofstream file("admin_notifiction.txt", ios::app);
    if (!file)
    {
        cout << "Error! In Opening File for Writing......";
        return;
    }

    cout << "Enter the notification: ";
    cin.getline(notification, 1000);

    file << notification << '\n'; // Write the notification to the file
    file.close();
}
void add_notification_for_employees()
{
    char notification[1000];
    ofstream file("notification_for_employees.txt", ios::app);
    if (!file)
    {
        cout << "Error! In Opening File for Writing......";
        return;
    }

    cout << "Enter the notification: ";
    cin.getline(notification, 1000);

    file << notification << '\n'; // Write the notification to the file
    file.close();
}
void display_notification_for_students()
{
    ifstream input_file("admin_notifiction.txt");
    if (!input_file)
    {
        cout << "Error! In Opening File for Reading......";
        return;
    }
    char line[1000];
    while (input_file.getline(line, 1000, '\n'))
    {
        cout << line << endl;
    }
}
void display_notification_for_employees()
{
    ifstream input_file("notification_for_employees.txt");
    if (!input_file)
    {
        cout << "Error! In Opening File for Reading......";
        return;
    }
    char line[1000];
    while (input_file.getline(line, 1000, '\n'))
    {
        cout << line << endl;
    }
}
void read_employee()
{
    user_count = 0;
    ifstream file("employee.login.txt");
    if (!file)
    {
        cout << "Error! In opening file for reading ....";
        return;
    }

    while (file.getline(usernames[user_count], MAX_LENGTH, '\n'))
    {
        file.getline(passwords[user_count], MAX_LENGTH, '\n');
        user_count++;
    }
    file.close();

    cout << left << fixed << setw(15) << "User Names" << "|" << left << fixed << setw(15) << "Passwords" << endl;
    for (int i = 0; i < user_count; i++)
    {
        cout << i + 1 << "." << left << fixed << setw(13) << usernames[i] << "|" << left << fixed << setw(15) << passwords[i] << endl;
    }
}

void add_user()
{
    const int MAX_USERS = 5;
    const int MAX_LENGTH = 20;
    read_employee();

    if (user_count >= MAX_USERS)
    {
        cout << "\nSorry! Max Limit of Users Reached :( ";
        return;
    }

    cout << "Enter the User Name :: " << endl;
    cin.getline(usernames[user_count], MAX_LENGTH);

    cout << "Enter the Password of User :: " << endl;
    cin.getline(passwords[user_count], MAX_LENGTH);

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], usernames[user_count]) == 0)
        {
            cout << "Sorry!! User already Exist ... :(" << endl;
            return;
        }
    }

    user_count++;

    ofstream output_file("employee.login.txt", ios::app);
    if (!output_file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }

    // sirf newly added username or password ko file mn write kr rhy hain
    output_file << usernames[user_count - 1] << '\n';
    output_file << passwords[user_count - 1] << '\n';
    cout << "User Added Successfully !! :) " << endl;

    output_file.close();
}
void remove_user()
{
    read_employee();
    char search[20];
    cout << "Enter the User Name to remove  :: ";
    cin.getline(search, 20);
    bool userfound = false;

    ofstream file("employee.login.txt");

    if (!file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], search) == 0)
        {
            user_count--;
            userfound = true;
            cout << "User Removed Successfully !! ";
            continue;
        }
        file << usernames[i] << "\n";
        file << passwords[i] << "\n";
    }
    file.close();

    if (!userfound)
    {
        cout << "Sorry! User not found :( ";
    }
}
void search_user()
{
    read_employee();
    char search[20];
    cout << "Enter the User Name to search :: ";
    cin.getline(search, 20);
    bool userfound = false;
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], search) == 0)
        {
            cout << left << fixed << setw(15) << "User Names" << "|" << left << fixed << setw(15) << "Passwords" << endl;
            cout << i + 1 << "." << left << fixed << setw(13) << usernames[i] << "|" << left << fixed << setw(15) << passwords[i] << endl;
            userfound = true;
            break;
        }
    }
    if (userfound == false)
    {
        cout << "Sorry! user not found :( ";
    }
}
void update_user()
{
    read_employee();

    ofstream file("employee.login.txt");

    if (!file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }
    char search[20];
    cout << "Enter the User Name to Update :: ";
    cin.getline(search, 20);
    char updated_name[20], updated_password[20];
    cout << "Enter the Updated User Name  :: ";
    cin.getline(updated_name, 20);
    cout << "Enter the Updated User Password :: ";
    cin.getline(updated_password, 20);
    bool userfound = false;
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], search) == 0)
        {
            strcpy(usernames[i], updated_name);
            strcpy(passwords[i], updated_password);
            userfound = true;
        }
        file << usernames[i] << "\n";
        file << passwords[i] << "\n";
    }
}
void read_student()
{
    user_count = 0;
    ifstream file("student.login.txt");
    if (!file)
    {
        cout << "Error! In opening file for reading ....";
        return;
    }

    while (file.getline(usernames[user_count], MAX_LENGTH, '\n'))
    {
        file.getline(passwords[user_count], MAX_LENGTH, '\n');
        user_count++;
    }
    file.close();

    cout << left << fixed << setw(15) << "User Names" << "|" << left << fixed << setw(15) << "Passwords" << endl;
    for (int i = 0; i < user_count; i++)
    {
        cout << i + 1 << "." << left << fixed << setw(13) << usernames[i] << "|" << left << fixed << setw(15) << passwords[i] << endl;
    }
}

void add_student()
{
    const int MAX_USERS = 5;
    const int MAX_LENGTH = 20;
    read_student();

    if (user_count >= MAX_USERS)
    {
        cout << "\nSorry! Max Limit of Users Reached :( ";
        return;
    }

    cout << "Enter the User Name :: " << endl;
    cin.getline(usernames[user_count], MAX_LENGTH);

    cout << "Enter the Password of User :: " << endl;
    cin.getline(passwords[user_count], MAX_LENGTH);

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], usernames[user_count]) == 0)
        {
            cout << "Sorry!! User already Exist ... :(" << endl;
            return;
        }
    }

    user_count++;

    ofstream output_file("student.login.txt", ios::app);
    if (!output_file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }

    // sirf newly added username or password ko file mn write kr rhy hain
    output_file << usernames[user_count - 1] << '\n';
    output_file << passwords[user_count - 1] << '\n';
    cout << "User Added Successfully !! :) " << endl;

    output_file.close();
}
void remove_student()
{
    read_student();
    char search[20];
    cout << "Enter the User Name to remove  :: ";
    cin.getline(search, 20);
    bool userfound = false;

    ofstream file("student.login.txt");

    if (!file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], search) == 0)
        {
            user_count--;
            userfound = true;
            cout << "User Removed Successfully !! ";
            continue;
        }
        file << usernames[i] << "\n";
        file << passwords[i] << "\n";
    }
    file.close();

    if (!userfound)
    {
        cout << "Sorry! User not found :( ";
    }
}
void search_student()
{
    read_employee();
    char search[20];
    cout << "Enter the Student Name to search :: ";
    cin.getline(search, 20);
    bool userfound = false;
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], search) == 0)
        {
            cout << left << fixed << setw(15) << "Student Names" << "|" << left << fixed << setw(15) << "Passwords" << endl;
            cout << i + 1 << "." << left << fixed << setw(13) << usernames[i] << "|" << left << fixed << setw(15) << passwords[i] << endl;
            userfound = true;
            break;
        }
    }
    if (userfound == false)
    {
        cout << "Sorry! user not found :( ";
    }
}
void update_student()
{
    read_student();

    ofstream file("employee.login.txt");

    if (!file)
    {
        cout << "Error! In opening file for writing....";
        return;
    }
    char search[20];
    cout << "Enter the User Name to Update :: ";
    cin.getline(search, 20);
    char updated_name[20], updated_password[20];
    cout << "Enter the Updated User Name  :: ";
    cin.getline(updated_name, 20);
    cout << "Enter the Updated User Password :: ";
    cin.getline(updated_password, 20);
    bool userfound = false;
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], search) == 0)
        {
            strcpy(usernames[i], updated_name);
            strcpy(passwords[i], updated_password);
            userfound = true;
        }
        file << usernames[i] << "\n";
        file << passwords[i] << "\n";
    }
    if (userfound == false)
    {
        cout << "Sorry! user not found :( ";
    }
    file.close();
}
int admin_login()
{
    const int MAX_USERS = 5;
    const int MAX_LENGTH = 20;
    char **usernames = new char *[MAX_USERS];
    char **passwords = new char *[MAX_USERS];

    for (int i = 0; i < MAX_USERS; ++i)
    {
        usernames[i] = new char[MAX_LENGTH];
        passwords[i] = new char[MAX_LENGTH];
    }
    bool userfound = false;

    ifstream file("admin.login.txt");
    if (!file)
    {
        cout << "Error! In opening file for reading... ";
        return userfound;
    }

    int user_count = 0;
    while (file.getline(usernames[user_count], MAX_LENGTH, '\n') && file.getline(passwords[user_count], MAX_LENGTH, '\n'))
    {
        user_count++;
        if (user_count >= MAX_USERS)
        {
            break;
        }
    }
    file.close();

    char *input_username = new char[MAX_LENGTH];
    char *input_password = new char[MAX_LENGTH];

    cin.ignore(); // Clear the newline character from the buffer

    cout << "Enter username :: ";
    cin.getline(input_username, MAX_LENGTH);
    cout << "Enter password :: ";
    cin.getline(input_password, MAX_LENGTH);

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], input_username) == 0 && strcmp(passwords[i], input_password) == 0)
        {
            cout << "Successfully Logged In " << endl;
            userfound = true;
            return userfound;
        }
    }

    if (!userfound)
    {
        cout << "Invalid Username or Password " << endl;
        cout << "Would you like to register? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            cin.ignore();
            admin_register();
        }
    }

    // Deallocate memory
    delete[] input_username;
    delete[] input_password;

    for (int i = 0; i < MAX_USERS; ++i)
    {
        delete[] usernames[i];
        delete[] passwords[i];
    }

    delete[] usernames;
    delete[] passwords;
    return userfound;
}

void admin_register()
{
    const int MAX_USERS = 5;
    const int MAX_LENGTH = 20;
    char **usernames = new char *[MAX_USERS];
    char **passwords = new char *[MAX_USERS];

    for (int i = 0; i < MAX_USERS; ++i)
    {
        usernames[i] = new char[MAX_LENGTH];
        passwords[i] = new char[MAX_LENGTH];
    }

    ifstream read_file("admin.login.txt");
    if (!read_file)
    {
        cout << "Error! In opening file for reading... ";
        return;
    }

    int user_count = 0;
    while (read_file.getline(usernames[user_count], MAX_LENGTH, '\n') && read_file.getline(passwords[user_count], MAX_LENGTH, '\n'))
    {
        user_count++;
        if (user_count >= MAX_USERS)
        {
            break;
        }
    }
    read_file.close();

    if (user_count >= MAX_USERS)
    {
        cout << "\nSorry! Max Users Limit Exceeded :(" << endl;
        return;
    }
    cout << "Enter your Username :: " << endl;
    cin.getline(usernames[user_count], MAX_LENGTH, '\n');
    cout << "Enter your Password :: " << endl;
    cin.getline(passwords[user_count], MAX_LENGTH, '\n');

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(usernames[i], usernames[user_count]) == 0)
        {
            cout << "Sorry! User Already Exist .... :( " << endl;
            cout << "Would you like to register? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cin.ignore();
                admin_register();
            }
            return;
        }
    }
    ofstream write_file("admin.login.txt", ios::app);
    if (!write_file)
    {
        cout << "Error! In opening file for writing... ";
        return;
    }

    write_file << usernames[user_count] << '\n';
    write_file << passwords[user_count] << '\n';

    cout << "Successfully Registered " << endl;
    // Deallocate memory
    for (int i = 0; i <= user_count; ++i)
    {
        delete[] usernames[i];
        delete[] passwords[i];
    }

    delete[] usernames;
    delete[] passwords;
}