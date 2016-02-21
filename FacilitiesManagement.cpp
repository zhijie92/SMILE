/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FacilitiesManagement.cpp
 * Author: Amos Laptop
 * 
 * Created on February 19, 2016, 4:56 PM
 */

#include "FacilitiesManagement.h"

int size=0;

FacilitiesManagement::FacilitiesManagement()
{
    fileToArray();
}

FacilitiesManagement::FacilitiesManagement(const FacilitiesManagement& orig)
{
}

FacilitiesManagement::~FacilitiesManagement()
{
}



void FacilitiesManagement::fileToArray ()
{
    size = 0;
    fstream afile;
    afile.open ("facilitiesDB.txt", ios::in);
    
    while (getline(afile, facilities[size].facility.name, ','))
    {
        getline(afile, facilities[size].facility.description, ',');
        afile >> facilities[size].facility.rates;
        afile.clear();
        afile.ignore(100, '\n');
        size++;
    }
    afile.close();
}
int FacilitiesManagement::checkExists (string fac_name)
{
    for (int i=0; i < size; i++)
    {
        if (facilities[i].facility.name == fac_name)
        {
            return 1;
        }
    }
    return 0;
}

int FacilitiesManagement::addFacility(string fac_name, string fac_desc, double rates)
{
    int check = checkExists (fac_name);
    
    if (check != 1)
    {
        fstream outfile;
        outfile.open("facilitiesDB.txt",ios::out | ios::app);

        outfile << fac_name << "," << fac_desc << "," << rates << endl;
        outfile.close();
        return 0;
    }
    else
        return -1;
}
int FacilitiesManagement::removeFacility(string fac_name)
{
    int check = checkExists (fac_name);
    
    if (check == 1)
    {
        fstream outfile;
        outfile.open("facilitiesDB.txt",ios::out | ios::trunc);
        int i;
        for (i=0; i < size; i++)
        {
            if (facilities[i].facility.name == fac_name)
            {
                for (int j=i+1; j < size; j++)
                {
                    outfile << facilities[j].facility.name << "," 
                            << facilities[j].facility.description  << ","
                            << facilities[j].facility.rates 
                            << endl;
                }
                outfile.close();
                return 0;
            }
            else
            {
                outfile << facilities[i].facility.name << "," 
                        << facilities[i].facility.description  << ","
                        << facilities[i].facility.rates 
                        << endl;
            }
            outfile.close();
        }
        return 0;
    }
    else
        return -1;
}
int FacilitiesManagement::editFacility(int opt, string fac_name, string new_name, string fac_desc, double rates)
{
    int check = checkExists (fac_name);
    
    if (check == 1)
    {
        fstream outfile;
        outfile.open("facilitiesDB.txt",ios::out | ios::trunc);

        switch (opt)
        {
        case 1 : for (int i=0; i < size; i++)
                 {
                     if (facilities[i].facility.name == fac_name)
                     {
                         facilities[i].facility.name = new_name;
                         //facilities[i].description = fac_desc;
                         for (int j=0; j < size; j++)
                         {
                             outfile << facilities[j].facility.name << "," 
                                     << facilities[j].facility.description  << ","
                                     << facilities[j].facility.rates 
                                     << endl;
                         }
                         outfile.close();
                         return 0;
                     }
                }
        break;
        case 2 : for (int i=0; i < size; i++)
                 {
                     if (facilities[i].facility.name == fac_name)
                     {
                         //facilities[i].name = new_name;
                         facilities[i].facility.description = fac_desc;
                         for (int j=0; j < size; j++)
                         {
                             outfile << facilities[j].facility.name << "," 
                                     << facilities[j].facility.description  << ","
                                     << facilities[j].facility.rates 
                                     << endl;
                         }
                         outfile.close();
                         return 0;
                     }
                }
        break;
        case 3 : for (int i=0; i < size; i++)
                 {
                     if (facilities[i].facility.name == fac_name)
                     {
                         //facilities[i].name = new_name;
                         //facilities[i].description = fac_desc;
                         facilities[i].facility.rates = rates;
                         for (int j=0; j < size; j++)
                         {
                             outfile << facilities[j].facility.name << "," 
                                     << facilities[j].facility.description  << ","
                                     << facilities[j].facility.rates 
                                     << endl;
                         }
                         outfile.close();
                         return 0;
                     }
                }
        break;
        }
    }
    else
        return -1;
}
void FacilitiesManagement::printAllFacilities()
{
    for (int i=0; i < size; i++)
    {
            cout << "Name: '" << facilities[i].facility.name << "' " 
                 << "Description: '" << facilities[i].facility.description << "'"
                 << "rates: '" << facilities[i].facility.rates << "'"
                 << endl;
    }
}