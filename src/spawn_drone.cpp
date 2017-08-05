#include <iostream>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo.hh>

int main(int _argc, char** _argv){
    gazebo::setupServer(_argc, _argv);
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    node->Init();
    
    // Create a publisher on the ~/factory topic
    gazebo::transport::PublisherPtr factoryPub =
    node->Advertise<gazebo::msgs::Factory>("~/factory");
    
    // Wait for a subscriber to connect
    factoryPub->WaitForConnection();
     
    // Create the message
    gazebo::msgs::Factory msg;
         
    msg.set_sdf_filename("model://sjtu_drone");
    
    // Pose to initialize the model to..gazebo::math::Pose(
//    gazebo::msgs::Set(msg.mutable_pose()->mutable_position(),
//                      gazebo::math::Vector3(0, 0, 1));
//    gazebo::msgs::Set(msg.mutable_pose()->mutable_orientation(),
//                      gazebo::math::Quaternion(0, 0, 0, 0));
    msg.mutable_pose()->mutable_position()->set_x(0);
    msg.mutable_pose()->mutable_position()->set_y(0);
    msg.mutable_pose()->mutable_position()->set_z(1);
    msg.mutable_pose()->mutable_orientation()->set_w(1);
    msg.mutable_pose()->mutable_orientation()->set_x(0);
    msg.mutable_pose()->mutable_orientation()->set_y(0);
    msg.mutable_pose()->mutable_orientation()->set_z(0);
     
    // Send the message
    factoryPub->Publish(msg);    
}
