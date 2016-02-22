/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.cpp
 * Author: reuben
 * 
 * Created on 20 February, 2016, 4:29 PM
 */

#include "User.h"

User::User()
{
    storeData();
}

User::User(const User& orig)
{
}

User::~User()
{
}

int User::storeData()
{
    fstream afile;
    afile.open("userDB.txt",ios::in);  
    
    if (!afile)
    {
        cout << "userDB.txt opened for reading failed" << endl;
        return -1;
    }
    
    int tempSize=0;
    char rubbish;
    while (afile >> access[tempSize].role)
    {
        afile.get(rubbish);
        getline(afile, access[tempSize].user,',');
        getline(afile, access[tempSize].pass);
        tempSize++;
    }
    this -> size = tempSize;
    afile.close();
    
    return tempSize;
}

int User::accessData(string tempUser)
{
    for (int i = 0; i < this -> size; i++)
    {
        if (this -> access[i].user == tempUser)
        {
            return i;
        }
    }
}

void User::change(int option, string tempOld, string tempNew)
{
    int location;
    //1 = change username
    //2 = change password
    if (option == 1)
    {
        location = accessData(tempOld);
        access[location].user = tempNew;
    }
    else if (option == 2)
    {
        location = accessData(tempOld);
        access[location].pass = tempNew;
    }
    
    updateUserDB();
}

void User::updateUserDB()
{
    fstream afile;
    afile.open("userDB.txt",ios::out);
    
    if (!afile)
    {
        cout << "userDB Opened for writing fail" << endl;
    }
    
    for (int i = 0; i < this -> size; i++)
    {
        afile << access[i].role << ',' << access[i].user << ',' << access[i].pass << endl;
    }
    
    afile.close();   
}