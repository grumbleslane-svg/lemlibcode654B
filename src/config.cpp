#include "config.h"

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup leftMotors({-11, -12, 13}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({-18, 19, 20}, pros::MotorGearset::blue);

// sensors
pros::Imu imu(15);
pros::Rotation verticalEnc(-17);

// tracking wheels
lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_2, 0);

// extra motors
pros::Motor front_motor(-6, pros::MotorGearset::blue);
pros::Motor back_motor(-4, pros::MotorGearset::blue);

// pistons
pros::adi::DigitalOut Wing('A');
pros::adi::DigitalOut ML('B');
pros::adi::DigitalOut MG('C');
pros::adi::DigitalOut MD('D');
bool driverControlEnabled = true;

// drivetrain + chassis
lemlib::Drivetrain drivetrain(&leftMotors, &rightMotors, 11.425,
                              lemlib::Omniwheel::NEW_325, 450, 2);

lemlib::ControllerSettings linearController( //distance >= 48 inches use speed limit = 85. kp = 9, kd = 170, ki = 0
    9, 
    0, 
    170, 
    3, 
    1, 
    100, 
    3, 
    500, 
    22
);
lemlib::ControllerSettings angularController( //almost perfect small jitter
    6, 
    0, 
    59.2, 
    3, 
    1.5, 
    100, 
    3, 
    500, 
    20
);

lemlib::OdomSensors sensors(
    &vertical, 
    nullptr, 
    nullptr, //horizontal gone
    nullptr, 
    &imu
);

lemlib::ExpoDriveCurve throttleCurve(
    3, 
    10, 
    1.019
);
lemlib::ExpoDriveCurve steerCurve(
    3, 
    10, 
    1.019
);

lemlib::Chassis chassis(
    drivetrain, 
    linearController, 
    angularController,          
    sensors, 
    &throttleCurve, 
    &steerCurve
);
