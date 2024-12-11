#include<iostream>
#include "employee.h"
#include "project.h"

// Employee Functions Definitions

void employee_complaints()
{
    char complaints[1000];
    ofstream file("employee.complaints.txt", ios::app);
    if (!file) // will tell if the file is not opened
     {
        cout << "Error! In Opening File for Writing......";
        return;
    }

    cout << "Enter the complaints :: ";
    cin.getline(complaints, 1000);

    file << complaints << '\n';  // Write the complaints to the file
    file.close();

    cout << "\nComplaint Submitted Successfully!" << endl
     <<  " \nThank you :) , for helping us identify areas where we can improve."
        <<  "\nWe value your feedback, as it helps us enhance our services." << endl;
}
void display_complaints_of_employees()
{
    ifstream input_file("employee.complaints.txt");
    if (!input_file) // will tell if the file is not opened
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

int employee_login()
 {
    const int MAX_USERS = 5;
    const int MAX_LENGTH = 20;
    char** usernames = new char* [MAX_USERS];
    char** passwords = new char* [MAX_USERS];

    for (int i = 0; i < MAX_USERS; ++i) {
        usernames[i] = new char[MAX_LENGTH];
        passwords[i] = new char[MAX_LENGTH];
    }
bool userfound = false;
    ifstream file("employee.login.txt");
    if (!file) // will tell if the file is not opened
     {
        cout << "Error! In opening file for reading... ";
        return userfound;
    }

    int user_count = 0;
    while (file.getline(usernames[user_count], MAX_LENGTH, '\n') && file.getline(passwords[user_count], MAX_LENGTH, '\n')) {
        user_count++;
        if (user_count >= MAX_USERS) {
           break;
        }
    }
    file.close();

    char* input_username = new char[MAX_LENGTH];
    char* input_password = new char[MAX_LENGTH];

    cin.ignore();  // Clear the newline character from the buffer

    cout << "Enter username :: ";
    cin.getline(input_username, MAX_LENGTH);
    cout << "Enter password :: ";
    cin.getline(input_password, MAX_LENGTH);

    
    for (int i = 0; i < user_count; i++) {
        if (strcmp(usernames[i], input_username) == 0 && strcmp(passwords[i], input_password) == 0)
         {
            cout << "Successfully Logged In " << endl;
            userfound = true;
            return userfound;
        }
    }

    if (!userfound) {
        cout << "Invalid Username or Password " << endl;
        cout << "Would you like to register? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cin.ignore();
            employee_register();
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

void employee_register() {
    const int MAX_USERS = 5;
    const int MAX_LENGTH = 20;
    char** usernames = new char* [MAX_USERS];
    char** passwords = new char* [MAX_USERS];

    for (int i = 0; i < MAX_USERS; ++i) {
        usernames[i] = new char[MAX_LENGTH];
        passwords[i] = new char[MAX_LENGTH];
    }

    ifstream read_file("employee.login.txt");
    if (!read_file)  // will tell if the file is not opened
    {
        cout << "Error! In opening file for reading... ";
        return;
    }

    int user_count = 0;
    while (read_file.getline(usernames[user_count], MAX_LENGTH, '\n') && read_file.getline(passwords[user_count], MAX_LENGTH, '\n')) {
        user_count++;
        if (user_count >= MAX_USERS) {
            break;
        }
    }
    read_file.close();

    if (user_count >= MAX_USERS) {
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
            if (choice == 'y' || choice == 'Y') {
                cin.ignore();
                employee_register();
            }
            return;
        }
    }
    ofstream write_file("employee.login.txt", ios::app);
    if (!write_file) // will tell if the file is not opened
    {
        cout << "Error! In opening file for writing... ";
        return;
    }

    write_file << usernames[user_count] << '\n';
    write_file << passwords[user_count] << '\n';

    cout << "Successfully Registered " << endl;
    // Deallocate memory
    for (int i = 0; i <= user_count; ++i) {
        delete[] usernames[i];
        delete[] passwords[i];
    }

    delete[] usernames;
    delete[] passwords;
}
