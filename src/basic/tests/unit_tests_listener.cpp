#include "basic/listener.h"

#include <gtest/gtest.h>

class MyTestSuite : public ::testing::Test {
public:
	MyTestSuite(){}
	~MyTestSuite(){}

};

TEST_F(MyTestSuite, equalStrings){
	Listener rt;
	std_msgs::String testString;
	testString.data = "This is a test";
	rt.chatterCallback(testString);
	ASSERT_STRCASEEQ(rt.getString().c_str(), testString.data.c_str()) << "Value should be the same";
}


//int main(int argc, char **argv) {
//	testing::InitGoogleTest(&argc, argv);
//	ros::init(argc, argv, "TestNode");
//	return RUN_ALL_TESTS();
//}



