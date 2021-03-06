#pragma once

#include <frc/WPIlib.h>
using namespace frc;

class Robot : public frc::SampleRobot {
 public:
  Robot();

  cs::UsbCamera camera{}; 

  SmartDashboard *smartDashboard;
  
  Joystick stick1{0}; //left
  Joystick stick2{1}; //right
  Joystick stick3{2}; //arm

  Spark m_left{0};
  Spark m_right{1};
  Spark m_updown{3};

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

 private:
};
