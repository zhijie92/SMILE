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
}

FacilitiesManagement::FacilitiesManagement(const FacilitiesManagement& orig)
{
}

FacilitiesManagement::~FacilitiesManagement()
{
}



void FacilitiesManagement::fileToArray ()
{
    fstream afile;
    afile.open ("facilitiesDB.txt", ios::in);
    
    while (getline(afile, facilities[size].name, ','))
    {
        getline(afile, facilities[size].description);
        size++;
    }
    afile.close();
}
int FacilitiesManagement::checkExists (string fac_name)
{
    for (int i=0; i < size; i++)
    {
        if (facilities[i].name == fac_name)
        {
            return 1;
        }
    }
    return 0;
}

int FacilitiesManagement::addFacility(string fac_name, string fac_desc)
{
    int check = checkExists (fac_name);
    
    if (check != 1)
    {
        fstream outfile;
        outfile.open("facilitiesDB.txt",ios::out | ios::app);

        outfile << fac_name << "," << fac_desc << endl;
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
            if (facilities[i].name == fac_name)
            {
                for (int j=i+1; j < size; j++)
                {
                    outfile << facilities[j].name << "," 
                            << facilities[j].description 
                            << endl;
                }
                outfile.close();
                return 0;
            }
            else
            {
                outfile << facilities[i].name << "," 
                        << facilities[i].description 
                        << endl;
            }
        }     
    }
    else
        return -1;
}
