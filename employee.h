#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include "project.h"

//Funtion Prototypes
void employee_complaints();
void employee_Function();
void search_item(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void display_notification_for_employees();
void employee_register();
int employee_login() ;

#endif