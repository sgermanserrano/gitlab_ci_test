#include "basic/listener.h"

#include <gtest/gtest.h>

// Publisher
ros::Publisher chatterPublisher;
ros::Subscriber chatterSubscriber;

std::string outStr = "";

void callback(const std_msgs::String &msg){
  outStr = msg.data;
}

class ListenerTest : public ::testing::Test {
public:
  ListenerTest(){
  }

  ~ListenerTest(){}


};

TEST_F(ListenerTest, sendTopic){

  std_msgs::String msg;
  msg.data = "This is a test";

  chatterPublisher.publish(msg);

  int counter = 0;

  ros::Rate loop_rate(10);
  ROS_INFO("Spin");
  while (counter < 10){
  loop_rate.sleep();
  ros::spinOnce();
  counter++;
  }

  ASSERT_STRCASEEQ(msg.data.c_str(), outStr.c_str());
}


int main(int argc, char **argv) {


  ros::init(argc, argv, "TestListenerNode");
  ros::NodeHandle nh;

  chatterPublisher = nh.advertise<std_msgs::String>("chatter", 100, true);

  ros::Subscriber chatterSubscriber = nh.subscribe("received_chatter",100, callback);

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



