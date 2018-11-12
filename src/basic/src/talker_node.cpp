#include "basic/talker.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "talker");

  Talker talker_node;

  talker_node.spin();

  return 0;

}
