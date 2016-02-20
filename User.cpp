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
        getline(afile,access[tempSize].user,',');
        getline(afile,access[tempSize].pass);
        tempSize++;
    }
    this -> size = tempSize;
    
    afile.close();
    
    return tempSize;
}
/*
int User::accessData(string tempUser)
{
    for (int i = 0; i < size; i++)
    {
        if (access[i].role == 2) // if member
        {
            if (access[i].user == tempUser)
            {
                return i;
            }
        }
    }
}*/