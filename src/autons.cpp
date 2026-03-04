#include "autons.h"
#include "config.h"   // gives access to motors, pistons, sensors

Autons::Autons(lemlib::Chassis* chassis)
    : chassis(chassis) {}

// Example auton
void Autons::skills(){

}
void Autons::testAuton() {
   
}

// Add more autons here
void Autons::skillsAuton() {
    front_motor.move(127);
    pros::delay(10000);
    front_motor.move(0);
}

void Autons::RedRight() {
    chassis->setPose(-61.4, -18.6, 182);
    chassis->moveToPoint(-61.4, -20, 5000,{.maxSpeed=97},true);
}
void Autons::BlueRight() {
    chassis->setPose(-61.4, -18.6, 182);
    chassis->moveToPoint(-61.4, -20, 5000,{.maxSpeed=97},true);
}
void Autons::BlueLeft() {
    RedLeft();

}
void Autons::RedLeft() {
    chassis->setPose(-47.4, 17.6, 79.5); // starting pose

    front_motor.move(127); // start intake

    chassis->moveToPoint(-21+2, 21, 5000,{.maxSpeed=100},true);// goes infront of middle goal
    chassis->waitUntil(10);
    ML.set_value(true);
    chassis->waitUntilDone();
    chassis->turnToHeading(315, 3000,{},false);// turns backwards
    ML.set_value(false);
    pros::delay(200); 
    // trns backwards

    MG.set_value(false);
    lemlib::MoveToPointParams params;
    params.forwards = false;
    chassis->moveToPoint(-11, 11, 3000, params,true); // moves to goal, backwards
    pros::delay(800);               //let robot settle
    back_motor.move(127);  // outake blocks
    pros::delay(1500);

    chassis->setPose(-11.0,11.0,chassis->getPose().theta);   // scores blocks
    front_motor.brake(); //stop front motor
    back_motor.brake();    // stop back motor
    ML.set_value(true);
    //--
    //--
    //---------------------Long goal scoring-------------------------------------
    //--
    //--
    //--
    
    front_motor.move(0);
    MG.set_value(true);
    front_motor.move(127);
    chassis->moveToPoint(-41.427+1, 48.244+5, 5000,{.maxSpeed=97}, false); // goes infront of match loader
    
    chassis->turnToHeading(278,3000,{},false); //turns to face match loader
    
    chassis->moveToPose(-60.75-6, 46.5+10,278, 2000,{.minSpeed=90},true); // goes to match loader

    
    pros::delay(1300); // intake
    front_motor.move(0);



    chassis->moveToPoint(-20.5+2, 47.236, 1000, params, false); // should go backward into long goal
    pros::delay(900); // let robot settle
    front_motor.move(127);
    back_motor.move(-127); // score blocks
    pros::delay(1500);
    front_motor.move(0); // stop front motor
    back_motor.move(0); 
     //--
    //--
    //---------------------Wing-------------------------------------
    //--
    //--
    //--
    /*
    chassis->moveToPoint(-30.5, 47.236, 1000, {},false);
    chassis->moveToPose(-30.5, 57.7, 91, 1000,{},false); 

    chassis->moveToPose(-10, 57.7, 91, 1000,{},true); 
    pros::delay(500); 
    Wing.set_value(false);
    */
}
