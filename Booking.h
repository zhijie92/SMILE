/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Booking.h
 * Author: Amos
 *
 * Created on 21 February, 2016, 1:42 AM
 */

#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "FacilitiesManagement.h"
#include "MemberProfile.h"

class Booking {
public:
    Booking();
    Booking(const Booking& orig);
    virtual ~Booking();
    
    void fileToArray ();
    int checkExists (string str);
    void populate (string fac_name);
    int checkAlreadyBooked (string fac_name, int month, int day);
    int newBooking(string fac_name, int month, int day, string username);
private:
    struct BookingDatesDB
    {
        Facilities facility;
        int dates[12][31];
    }bookingdates[100];
};

#endif /* BOOKING_H */

