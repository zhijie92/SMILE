/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   authentication.cpp
 * Author: reuben
 * 
 * Created on 18 February, 2016, 11:59 PM
 */

#include "Authentication.h"

Authentication::Authentication() 
{
    
}

Authentication::Authentication(const Authentication& orig)
{
    
}

Authentication::~Authentication() 
{
    
}
string Authentication::getUsername()
{
    return username;
}

string Authentication::getPassword()
{
    return password;
}
void Authentication::setUsername(string username)
{
    username = username;
}

void Authentication::setPassword(string password)
{
    password = password;
}

int Authentication::verify(string username, string password, User u)
{
    int size = u.storeData();
    
    for (int i=0; i < size; i++)
    {
        if (u.access[i].user == username)
        {
            if (u.access[i].pass == password)
            {
                return u.access[i].role;
            }
            else
            {
                return -2;
            }
        }
    }
    return -1; 
}
