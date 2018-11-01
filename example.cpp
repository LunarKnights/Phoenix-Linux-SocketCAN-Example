#include "ctre/Phoenix.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "Platform-linux-socket-can.h"
#include <math.h>
#include "ctre/phoenix/unmanaged/Unmanaged.h"
#include "ros/ros.h"
#include "std_msgs/Int32.h"

using namespace ctre::phoenix;
using namespace ctre::phoenix::platform;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;
int kTimeoutMs = 30;
int programCounter = 0;
int main(int argc, char **argv) {

    ros::init(argc,argv, "talon_Node");
    auto nh = ros::NodeHandle();
    
    ros::Publisher joint_v = nh.advertise<std_msgs::Int32>("joint_V", 1000);
    ros::Publisher setpoint = nh.advertise<std_msgs::Int32>("joint_Set",1000);
    ros::Publisher errorP = nh.advertise<std_msgs::Int32>("joint_error",1000);
    ctre::phoenix::platform::can::SetCANInterface("can0");
    //ctre::phoenix::
    TalonSRX * talon = new TalonSRX(1);

//    talon->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,kTimeoutMs);
//    talon->SetSensorPhase(true);

//    talon->ConfigNominalOutputForward(0,kTimeoutMs);
//    talon->ConfigNominalOutputReverse(0,kTimeoutMs);

//    talon->ConfigPeakOutputForward(1,kTimeoutMs);
//    talon->ConfigPeakOutputReverse(-1,kTimeoutMs);
//
//    talon->Config_kF(0,1.25,kTimeoutMs);
//    talon->Config_kP(0,.5115,kTimeoutMs);
//    talon->Config_kI(0,0,kTimeoutMs);
//    talon->Config_kD(0,0,kTimeoutMs);


//    talon->SetStatusFramePeriod(StatusFrame::Status_1_General_,5,kTimeoutMs);
//    double theta = 0;
    ros::Rate update_rate(100);
while(ros::ok()){

     if(programCounter++%10==0){
//         std::cout << "T: " << talon->GetClosedLoopTarget()<<" A: "<< talon->GetSelectedSensorVelocity()<<" E: "<<talon->GetClosedLoopError() <<std::endl;
     }
     
//     std_msgs::Int32 velocity;
//     std_msgs::Int32 setpointV;
//     std_msgs::Int32 error;
//     velocity.data = talon->GetSelectedSensorVelocity();
//     setpointV.data = talon->GetClosedLoopTarget();
//     error.data = talon->GetClosedLoopError();
    // velocity.header.stamp = ros::Time::now();
     
//     joint_v.publish(velocity);
//     setpoint.publish(setpointV);
//     errorP.publish(error);
    ctre::phoenix::unmanaged::FeedEnable(10);
//    theta++;
//    double targetVelocity_UnitsPer100ms = sin(theta/20) * 20 * 4096 / 600;
//    talon->Set(ControlMode::Velocity,targetVelocity_UnitsPer100ms);
talon->Set(ControlMode::PercentOutput,.2);
    ros::spinOnce();
    update_rate.sleep();
}
    return 0;
}
