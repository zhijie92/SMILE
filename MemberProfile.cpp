/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MemberProfile.cpp
 * Author: reuben
 * 
 * Created on 19 February, 2016, 10:30 PM
 */

#include "MemberProfile.h"
#include "User.h"

MemberProfile::MemberProfile()
{
}

MemberProfile::MemberProfile(const MemberProfile& orig)
{
}

MemberProfile::~MemberProfile()
{
}

string MemberProfile::getName()
{
    return name;
}
string MemberProfile::getNric()
{
    return nric;
}

char MemberProfile::getGender()
{
    return gender;
}

string MemberProfile::getAddress()
{
    return address;
}

string MemberProfile::getBookingPreference()
{
    return bookingPreference;
}

bool MemberProfile::getNotification()
{
    return notification;
}
        
void MemberProfile::setName(string name)
{
    name = name;
}
void MemberProfile::setNric(string nric)
{
    nric = nric;
}

void MemberProfile::setGender(char gender)
{
    gender = gender;
}

void MemberProfile::setAddress(string address)
{
    address = address;
}

void MemberProfile::setBookingPreference(string bookingPreference)
{
    bookingPreference = bookingPreference;
}

void MemberProfile::setNotification(bool notification)
{
    notification = notification;
}

/*
void MemberProfile::displayParticulars(string tempUser)
{
    int index;
    index = User.accessData(tempUser);
}*/