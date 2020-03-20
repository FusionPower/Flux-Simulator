#include<stdio.h>
#include <math.h>
#include<string.h>
#pragma once

struct Person {
    
    float contagion_probability; 
    int status; // 0 healthy, 1 sick, 3 cured, -1 dead
    int illness; // define some chronic disease, not chronic, doesn't hace illnes
    int time_left; //counter for time to be cured or death basen on the stats above 
    double x;
    double y; 
};