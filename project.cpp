#include <iostream>
#include "admin.cpp"
#include "project.h"
#include "student.cpp"
#include "employee.cpp"
using namespace std;
int main() 
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY | FOREGROUND_GREEN);
cout << "\n\n\n ............WELCOME TO CAFE DIGITAL SYSTEM........... \n\n\n "<<endl;
    int choice;
    cout << "Enter :: "
        << "\n1 for admin"
        << "\n2 for Employee"
        << "\n3 for Student/Staff "
        << "\nEnter your choice :: "<<endl;
    cin >> choice;

    switch (choice)
     {
    case 1: {
        int adminChoice;
        cout << "\n\nEnter 1 to login \n2 for new registration :: ";
        cin >> adminChoice;

        switch (adminChoice)
         {
        case 1:
            if(admin_login())
            {
                admin_Functions();
            }
            break;
        case 2:
            cin.ignore();
            admin_register();
            break;
        default:
            cout << "Invalid Choice :(" << endl;
        }
        break;
    }
    case 2:
    {
        int employe_choice;
        cout << "\n\nEnter 1 to login \n2 for new registration :: "<<endl;
        cin >> employe_choice;
        switch (employe_choice)
        {
        case 1:
            if (employee_login())
            {
                employee_Function();
            }
            break;
        case 2:
            cin.ignore();
            employee_register();
            break;
        default:
            cout << "Invalid Choice :(" << endl;
            return 1;
        }
        break;
    }

    case 3: {
        int choice;
        cout << "\n\nEnter 1 to login \n2 for new registration :: "<<endl;
        cin >> choice;
        switch (choice) {
        case 1:
            if (student_login())
            {
                student_Function();
            }
            
            break;
        case 2:
            cin.ignore();
            student_register();
            break;
        default:
            cout << "Invalid Choice :(" << endl;
        }
        break;
    }
    }
}
void admin_Functions() 
{
    
    int items_count = 0, max_items = 20;
    char item_names[20][15];
    int price[20], quantity[20], total_price[20];

    int mainChoice;
    do{
       cout <<"\n\n\nHere is the list of Menu:: "<<endl
       << "\n01.  to Print Stock"
        << "\n02.  to see items below threshold"
        << "\n03.  to add a new item"
        << "\n04.  to search any item"
        << "\n05.  to remove any item"
        << "\n06.  to update any item"
        << "\n07.  to order any item"
        << "\n08.  to exit "
        << "\n09.  to add notification for Students"
        << "\n10.  to display notification for Students "
        << "\n11.  to display Employee Data "
        << "\n12.  to add Employee "
        << "\n13.  to remove Employee "
        << "\n14.  to search Employee "
        << "\n15.  to update Employee data "
        << "\n16.  to add notification for Employees "
        << "\n17.  to display notification for Employees "
        << "\n18.  to display Complaints of Student "
        << "\n19.  to display Complaints of Employees "
        << "\n20.  to display Students Data "
        << "\n21.  to add Student "
        << "\n22.  to remove Student "
        << "\n23.  to search Student "
        << "\n24.  to update Student data "

        << "\n\n\nEnter your choice :: " << endl;
    cin >> mainChoice;

    switch (mainChoice) {
    case 1:
        cin.ignore(); // Clear the newline character from the buffer
        read_stock(items_count, max_items, item_names, price, quantity, total_price);
        break;
    case 2:
        cin.ignore(); // Clear the newline character from the buffer
        below_threshold(items_count, max_items, item_names, price, quantity, total_price);
        break;
    case 3:
        cin.ignore(); // Clear the newline character from the buffer
        add_items(items_count, max_items, item_names, price, quantity, total_price);
        break;
    case 4:
        cin.ignore(); // Clear the newline character from the buffer
        search_item(items_count, max_items, item_names, price, quantity, total_price);
        break;
    case 5:
        cin.ignore(); // Clear the newline character from the buffer
        remove_item(items_count, max_items, item_names, price, quantity, total_price);
        break;
    case 6:
        cin.ignore(); // Clear the newline character from the buffer
        update_item(items_count, max_items, item_names, price, quantity, total_price);
        break;
    case 7:
        cin.ignore();// Clear the newline character from the buffer
        order_item(items_count, max_items, item_names, price, quantity, total_price);
        break;
    case 8:
        cout << "\n Good Bye :) " << endl;
        return;  // Exit the program
    case 9:
        cin.ignore();
        add_notification_for_students();
        break;
    case 10:
        cin.ignore(); // Clear the newline character from the buffer
        display_notification_for_students();
        break;
    case 11:
        cin.ignore(); // Clear the newline character from the buffer
        read_employee();
        break;
    case 12:
        cin.ignore(); // Clear the newline character from the buffer
        add_user();
        break;
    case 13:
        cin.ignore(); // Clear the newline character from the buffer
        remove_user();
        break;
    case 14:
        cin.ignore(); // Clear the newline character from the buffer
        search_user();
        break;
    case 15:
        cin.ignore(); // Clear the newline character from the buffer
        update_user();
        break;
    case 16:
        cin.ignore(); // Clear the newline character from the buffer
        add_notification_for_employees();
        break;
    case 17:
        cin.ignore(); // Clear the newline character from the buffer
        display_notification_for_employees();
        break;
    case 18:
        cin.ignore(); // Clear the newline character from the buffer
        display_complaints_of_students();
        break;
    case 19:
        cin.ignore(); // Clear the newline character from the buffer
        display_complaints_of_employees();
        break;
    case 20:
        cin.ignore(); // Clear the newline character from the buffer
        read_student();
        break;
    case 21:
        cin.ignore(); // Clear the newline character from the buffer
        add_student();
        break;
    case 22:
        cin.ignore(); // Clear the newline character from the buffer
        remove_student();
        break;
    case 23:
        cin.ignore(); // Clear the newline character from the buffer
        search_student();
        break;
    case 24:
        cin.ignore(); // Clear the newline character from the buffer
        update_student();
        break;
    default:
        cout << "Please! Enter a Valid Choice :)" << endl;
    }
    } while(mainChoice!=8);
}
void student_Function()
{
    int items_count = 0, max_items = 20;
    char item_names[20][15];
    int price[20], quantity[20], total_price[20];

   int student_choice;
   do{
    cout<< "\n\n\nEnter :: " 
    << "\nEnter 1 to search Items "
    << "\nEnter 2 to Display Notifications/Messeges " 
    << "\nEnter 3 to Submit Complain " 
    << "\nEnter 4 to exit "
    << "\nEnter your Choice :: "<<endl;

    cin >> student_choice;

    switch (student_choice)
    {
    case 1:
        cin.ignore();
        search_item(items_count, max_items, item_names, price, quantity, total_price);
        break;
    case 2:
        cin.ignore();
        display_notification_for_students();
        break;
    case 3:
        cin.ignore(); // Clear the newline character from the buffer
        student_complaints();
        break;
    case 4:
    cout<<"\nGood Bye! :)"<<endl; // Exit the program
    exit(0);
         break;
    default:
        cout<<"\nPlease Enter a Valid Choice :("<<endl;
    }
   }while(student_choice!=4);
}
void employee_Function()
{
    int items_count = 0, max_items = 20;
    char item_names[20][15];
    int price[20], quantity[20], total_price[20];

   int employee_choice;
    do{
   cout << "\n\n\nEnter :: "
    << "\nEnter 1 to search Items "
    << "\nEnter 2 to Display Notifications/Messeges " 
    << "\nEnter 3 to Submit Complain " 
    << "\nEnter your Choice :: "<<endl;
    cin >> employee_choice;

    switch (employee_choice)
    {
    case 1:
        cin.ignore(); // Clear the newline character from the buffer
        search_item(items_count, max_items, item_names, price, quantity, total_price);
        break;

    case 2:
        cin.ignore();
        display_notification_for_employees();
        break;
    case 3:
        cin.ignore(); // Clear the newline character from the buffer
        employee_complaints(); 
        break;
    case 4:
    cout<<"\nGood Bye! :)"<<endl; // Exit the program
    exit(0);
        break;
    default:
        cout<<"\nPlease Enter a Valid Choice :("<<endl;
    }
    }while(employee_choice!=4);
}
