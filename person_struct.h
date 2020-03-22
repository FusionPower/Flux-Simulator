#include<stdio.h>
#include <math.h>
#include<string.h>
#pragma once

struct Person {
    
    float contagion_probability;
    float mortality_probability; // <- NUEVO
    bool risk_pobaltion; // <- NUEVO; 1 if person above 60 (risk), 0 if not
    int status; // 0 healthy, 1 sick, 3 cured, -1 dead
    int illness; // define some chronic disease, not chronic, doesn't hace illnes
    int time_left; //counter for time to be cured or death based on the stats above 
    double x;
    double y; 
};
