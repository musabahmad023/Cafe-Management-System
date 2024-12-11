#ifndef ADMIN_H
#define ADMIN_H
//Headerfiles
#include<iostream>
#include "project.h"

//Funtion Prototypes
void admin_register();
int admin_login();
void read_stock(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void below_threshold(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void add_items(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void remove_item(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void search_item(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void update_item(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void order_item(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void add_notification_for_employees();
void add_notification_for_students();
void admin_Functions();
void display_notification_for_employees();
void display_notification_for_students();
void display_complaints_of_employees();
void display_complaints_of_students();
void add_user();
void read_employee();
void remove_user();
void search_user();
void update_user();
void read_student();
void remove_student();
void search_student();
void update_student();

void add_student();

#endif