#include "basic/listener.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "listener_node");
  Listener listener_node;

  listener_node.spin();

  return 0;
}





