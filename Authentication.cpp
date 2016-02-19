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
   // this->username = username;
   // this->password = password;
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

int Authentication::verify(string username, string password)
{
    fstream afile;
    afile.open("userDB.txt",ios::in);
    UserDB access[MAX];     
    
    if (!afile)
    {
        cout << "userDB.txt opened for reading failed" << endl;
        return -1;
    }
    
    int size=0;
    char rubbish;
    while (afile >> access[size].role)
    {
        afile.get(rubbish);
        getline(afile,access[size].user,',');
        getline(afile,access[size].pass);
        size++;
    }

    afile.close();
    for (int i=0; i < size; i++)
    {
        if (access[i].user == username)
        {
            if (access[i].pass == password)
            {
                return access[i].role;
            }
            else
            {
                return -2;
            }
        }
    }
    return -1;
    
}