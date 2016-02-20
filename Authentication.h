/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   authentication.h
 * Author: reuben
 *
 * Created on 18 February, 2016, 11:59 PM
 */

#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "User.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Authentication
{
    public:
        Authentication();
        Authentication(const Authentication& orig);
        virtual ~Authentication();
        string getUsername();
        string getPassword();
        void setUsername(string);
        void setPassword(string);
        int verify(string, string, User);

    private:
        string username; //store user's username
        string password; //store user's password
    
};

#endif /* AUTHENTICATION_H */