#pragma once
#include "lemlib/api.hpp"
#include "pros/misc.hpp"

class Autons {
public:
    Autons(lemlib::Chassis* chassis);


    void collect(int time);
    void middle_score(int time);
    void load();

    void long_score(int time);
    void wing();

    void testAuton();      
    void skillsAuton(); 

    void M3L4Right();
    void Push7Left();
    void AWPleft();

    

private:
    lemlib::Chassis* chassis;
};
