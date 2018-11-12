#include "basic/listener.h"

Listener::Listener(){
  sub = nh.subscribe("chatter", 100, &Listener::chatterCallback, this);
  pub = nh.advertise<std_msgs::String>("received_chatter", 100);
  storedString.data = "";
}

Listener::~Listener(){

}

void Listener::spin(){
  ros::spin();
}

void Listener::chatterCallback(const std_msgs::String &msg){
  ROS_INFO("I heard [%s]", msg.data.c_str());
  setString(msg.data);
  pub.publish(msg);
}

std::string Listener::getString(){
  return storedString.data;
}

void Listener::setString(const std::string & str){
  storedString.data = str;
}
