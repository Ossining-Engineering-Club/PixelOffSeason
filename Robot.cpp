#include "Robot.h"

Robot::Robot() {
}

void Robot::RobotInit()

{
    camera= CameraServer::GetInstance()->StartAutomaticCapture();
    camera.SetResolution(240,320);
    camera.SetExposureAuto();
    camera.SetFPS(60);
    camera.SetBrightness(20);
    smartDashboard->init();
}

void Robot::Autonomous() {
}

void Robot::OperatorControl() {
     Wait(1);
     while(IsOperatorControl() && IsEnabled()) {
            m_left.Set(-0.65*stick1.GetY());
            m_right.Set(-0.65*stick2.GetY());
            m_updown.Set(0.4*stick3.GetY());
            while(stick1.GetRawButton(1)) {
                wheels.Set(-0.1);
                }
            while(stick2.GetRawButton(1)){
                wheels.Set(0.99);
            }
            wheels.Set(0);
            //smartDashboard -> PutNumber("Stick 3", stick3.GetZ());
        }
}

void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif