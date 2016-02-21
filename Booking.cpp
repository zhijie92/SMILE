/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Booking.cpp
 * Author: Amos
 * 
 * Created on 21 February, 2016, 1:42 AM
 */

#include "Booking.h"

FacilitiesManagement fac;
int s = 0;

Booking::Booking()
{
    fileToArray ();
}

Booking::Booking(const Booking& orig)
{
}

Booking::~Booking()
{
}

void Booking::fileToArray ()
{
    s = 0;
    char rubbish;
    fstream afile;
    afile.open ("BookingDatesDB.txt", ios::in);
    
    while (getline(afile, bookingdates[s].facility.name, ','))
    {
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                afile >> bookingdates[s].dates[i][j];
                afile >> rubbish;
            }
        }
        s++;
    }
    afile.close();
}

int Booking::checkExists (string fac_name)
{
    for (int i=0; i < s; i++)
    {
        if (bookingdates[i].facility.name == fac_name)
        {
            return 1;
        }
    }
    return 0;
}

void Booking::populate (string fac_name)
{
    fstream outfile;
    outfile.open("BookingDatesDB.txt",ios::out);
    
    outfile << fac_name << ",";
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            outfile << "0" << "-";
        }           
    }
    outfile << endl;   
    outfile.close();
  
    bookingdates[s].facility.name = fac_name; 
    for (int k = 0; k < 12; k++)
    {
        for (int m = 0; m < 31; m++)
        {
        bookingdates[s].dates[k][m] = 0;
        }
    }
    s++;
}

int Booking::checkAlreadyBooked (string fac_name, int month, int day)
{
    for (int i=0; i < s; i++)
    {
        if (bookingdates[i].facility.name == fac_name)
        {
            if (bookingdates[i].dates[month-1][day-1] == 1)
                return 1;
            else
                return 0;
        }
    }
}

int Booking::newBooking(string fac_name, int month, int day)
{
    int check = fac.checkExists (fac_name);
    int check2 = checkExists (fac_name);
    
    if (check == 0)
        return -2;
    
    if (check2 == 0)
    {
        populate (fac_name);
    }
    int check3 = checkAlreadyBooked (fac_name, month, day);
    if (check3 == 1)
        return -1;
    if (check == 1 && check3 == 0)
    {
        fstream outfile;
        outfile.open("BookingDatesDB.txt",ios::out | ios::trunc);

        for (int i=0; i < s; i++)
        {
            if (bookingdates[i].facility.name == fac_name)
            {
                bookingdates[i].dates[month-1][day-1] = 1;
                for (int j=0; j < s; j++)
                {
                    outfile << bookingdates[j].facility.name << ","; 
                     for (int k = 0; k < 12; k++)
                     {
                         for (int m = 0; m < 31; m++)
                         {
                             outfile << bookingdates[j].dates[k][m] << "-";
                         }
                     }
                    outfile << endl;
                }
                outfile.close();
                return 0;
            }
        }
    }
}