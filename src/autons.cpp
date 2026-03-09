#include "autons.h"
#include "config.h"   // gives access to motors, pistons, sensors

Autons::Autons(lemlib::Chassis* chassis)
    : chassis(chassis) {}

void Autons::collect(bool on){
    if (on == true){
    ML.set_value(true);
    front_motor.move(127);
    }else{
    ML.set_value(false);
    front_motor.move(0);
    }
}

void Autons::middle_score(int time){
    MG.set_value(false);
    front_motor.move(127);
    back_motor.move(127);
    pros::delay(time);
    front_motor.move(0);
    back_motor.move(0);
    MG.set_value(true);

}

void Autons::load(){
    ML.set_value(true);
    front_motor.move(127);
    pros::delay(1100);
    front_motor.move(0);
    pros::delay(200);
    //ML.set_value(false);
}

void Autons::long_score(int time){
    front_motor.move(127);
    back_motor.move(-127);
    pros::delay(time);
    front_motor.move(0);
    back_motor.move(0);

}

void Autons::wing(bool on){
    if (on == true){
    Wing.set_value(true);
    }else{
    Wing.set_value(false);    
    }
    
}


void Autons::testAuton() {
   
    //angular test
    chassis->turnToHeading(90, 1500);
    pros::delay(500);

    // Back to 0°
    chassis->turnToHeading(0, 1500);
    pros::delay(500);

    // 180°
    chassis->turnToHeading(180, 2000);
    pros::delay(500);

    // Back to 0°
    chassis->turnToHeading(0, 2000);
    
    
    //LAteral test
    chassis->moveToPoint(0, 24, 2000,{.maxSpeed = 100});

    pros::delay(500);

    // Backward 24"
    chassis->moveToPoint(0, 0, 2000,{.maxSpeed = 100});

    pros::delay(500);

    // Forward 48"
    chassis->moveToPoint(0, 48, 3000, {.maxSpeed = 85});

    pros::delay(500);

    // Back to start
    chassis->moveToPoint(0, 0, 3000,{.maxSpeed = 85});

    pros::delay(800);
    
}



void Autons::skillsAuton(){

}



void Autons::Push7Right(){
 
    //get blocks
    chassis->setPose(-45.25,-7.5+5,90);
    chassis->turnToHeading(120,400,{},false);//turn toward block
    chassis->moveToPoint(-22,-22,900,{.maxSpeed = 95},true);//go to blocks
    pros::delay(500);
    collect(true);//collect
    chassis->turnToHeading(210,300,{},false);//turn towards goal
    collect(false);//stop

    //score
    chassis->moveToPoint(-37,-47,600,{.maxSpeed = 90},false);//go infornt goal
    chassis->turnToHeading(270,300,{},false);//turn facing alliance
    chassis->moveToPoint(-15,-47,400,{.forwards = false,.maxSpeed = 90},false);//go into goal
    pros::delay(1000);
    long_score(1000);//score, issue with time
    chassis->setPose(-20,-47,270);

    //wing
    chassis->moveToPoint(-47,-47-4,600,{.maxSpeed = 90},false);//reverse
    chassis->turnToHeading(300,600,{},false);//turn toward side
    chassis->moveToPoint(-25,-56-4,600,{.forwards = false,.maxSpeed = 90},false);//go backwards toward point
    chassis->turnToHeading(270,600,{},false);
    chassis->moveToPoint(-1,-56-4,600,{.forwards = false,.maxSpeed = 90},false);//go backwards while wing down

}


void Autons::M3L4Left(){

    //long goal
    chassis->setPose(-47,18.7+2,0);
    chassis->moveToPoint(-47,52,3000,{.maxSpeed = 85},false);//infront loader
    ML.set_value(true);
    chassis->turnToHeading(270,2000,{},false);//turn toward loader
    chassis->moveToPoint(-60,52,900,{.maxSpeed = 80},true);//go to loader
    load();
    chassis->moveToPoint(-20,52,500,{.forwards = false,.maxSpeed = 85},true);//go back
    ML.set_value(false);
    pros::delay(1000);
    long_score(1000);//score, issue with time

    //middle goal
    chassis->moveToPoint(-38,52,1000,{.maxSpeed = 90},false);//move back a little bit
    chassis->turnToHeading(150,1000,{},false);// turn toward blocks
    chassis->moveToPoint(-22+8,22.6,1000 ,{.maxSpeed = 85} , true);//go to blocks
    pros::delay(500);
    collect(true);//intake,fix this
    chassis->turnToHeading(315,1000,{},false);//rotate 180 and face middle goal
    collect(false);//stop intake
    chassis->moveToPoint(-1,3,1000,{.forwards = false,.maxSpeed = 85},false);//go to middle goal
    chassis->setPose(-7,7,315);//reset pose
    middle_score(1000);//score

    ///wing
    chassis->moveToPoint(-20,20,1000,{.maxSpeed = 85},false);//reverse a bit
    chassis->turnToHeading(330,1000,{},false);//turn toward front of long goal
    chassis->moveToPoint(-40,35,1000,{},false);//go to side of goal
    chassis->turnToHeading(270,1000,{},false);//rotate facing alliance side
    chassis->moveToPoint(-10,35,2000,{.forwards = false,.maxSpeed = 60},false);//go backwards with wing



}


void Autons::AWPleft(){

}

































//old autons for ref
/*
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
    
    chassis->moveToPoint(-30.5, 47.236, 1000, {},false);
    chassis->moveToPose(-30.5, 57.7, 91, 1000,{},false); 

    chassis->moveToPose(-10, 57.7, 91, 1000,{},true); 
    pros::delay(500); 
    Wing.set_value(false);
    
}
*/