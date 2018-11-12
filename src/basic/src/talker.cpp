#include "basic/talker.h"

Talker::Talker() : loop_rate(10){
	pub = nh.advertise<std_msgs::String>("chatter", 100);
	loop_rate = ros::Rate(1);
	counter = 0;
}

Talker::~Talker(){}

void Talker::talk(int number){
	std_msgs::String msg;
	std::stringstream ss;

	ss << "Hello world ";
	ss << doSomeMath(number);

	msg.data = ss.str();
	pub.publish(msg);
}


int Talker::doSomeMath(int value){
	int next_value = 0;
	next_value = 5 + value;
	return next_value > 50 ? 0 : next_value;
}

void Talker::spin(){

  while(ros::ok())
  {

    talk(counter);
    ros::spinOnce();
    loop_rate.sleep();

    ++counter;
  }
}


