#ifndef STUDENT_H
#define STUDENT_H
//Headerfiles
#include<iostream>
#include "project.h"
//Funtion Prototypes
void search_item(int& items_count , const int max_items , char item_names[20][15], int price[20], int  quantity[20], int  total_price[20]);
void student_complaints();
void display_notification_for_students();
void student_Function();
void student_register();
int student_login();

#endif