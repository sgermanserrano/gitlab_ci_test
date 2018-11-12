#include "basic/talker.h"

#include <gtest/gtest.h>

class MyTestSuite : public ::testing::Test {
public:
  MyTestSuite(){}
  ~MyTestSuite(){}

};


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "TestNode");
  return RUN_ALL_TESTS();
}
