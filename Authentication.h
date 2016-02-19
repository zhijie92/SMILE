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

#include <string>
#include <iostream>
#include <fstream>

const int MAX = 500;
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
        int verify(string, string);
        int index(string, string);

    private:
        string username; //store user's username
        string password; //store user's password

        struct UserDB //store all the role, user and pass from the DB
        {
            int role; //1 for club manager - 2 for club member
            string user;
            string pass;
        };
};

#endif /* AUTHENTICATION_H */