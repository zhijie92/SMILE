/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facilities.cpp
 * Author: Amos Laptop
 * 
 * Created on February 19, 2016, 4:44 PM
 */

#include "Facilities.h"

Facilities::Facilities()
{
}

Facilities::Facilities(const Facilities& orig)
{
}

Facilities::~Facilities()
{
}

int Facilities::GetFacilityID() const
{
    return facilityID;
}
 
void Facilities::SetFacilityID(const int id)
{
    facilityID = id;
}
 
string Facilities::GetFacilityName() const
{
    return facilityName;
}
 
void Facilities::SetFacilityName(const string name)
{
    facilityName = name;
}
 
string Facilities::GetFacilityDescription() const
{
return facilityDescription;
}
 
void Facilities::SetFacilityDescription(const string desc)
{
facilityDescription = desc;
}