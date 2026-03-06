#pragma once
#include "lemlib/api.hpp"
#include "pros/misc.hpp"

class Autons {
public:
    Autons(lemlib::Chassis* chassis);


    void collect(bool on);
    void middle_score(int time);
    void load();

    void long_score(int time);
    void wing(bool on);

    void testAuton();      
    void skillsAuton(); 

    void M3L4Left();
    void Push7Right();
    void AWPleft();

    

private:
    lemlib::Chassis* chassis;
};
