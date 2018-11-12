#ifndef TALKER_H_
#define TALKER_H_

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

class Talker {
public:
	Talker();
	~Talker();

	void spin();

	int doSomeMath(int value);
	void talk(int number);

	ros::NodeHandle nh;
	ros::Publisher pub;

private:
	int counter;
	ros::Rate loop_rate;

};






#endif /* TALKER_H_ */
