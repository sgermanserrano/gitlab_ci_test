#ifndef LISTENER_H_
#define LISTENER_H_

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <string>

class Listener {
public:

  Listener();
  ~Listener();

  void spin();

  void chatterCallback(const std_msgs::String &msg);

  std::string getString();

  void setString(const std::string & str);



private:
  ros::NodeHandle nh;
  ros::Subscriber sub;
  ros::Publisher pub;

  std_msgs::String storedString;


};



#endif /* LISTENER_H_ */
