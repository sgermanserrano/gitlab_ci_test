#include "basic/talker.h"

#include <gtest/gtest.h>

class MyTestSuite : public ::testing::Test {
public:
	MyTestSuite(){}
	~MyTestSuite(){}

};

TEST_F(MyTestSuite, lowValue){
	Talker rt;
	int initial_value = 3;
	int value = rt.doSomeMath(initial_value);
	ASSERT_EQ(value, initial_value+5) << "Value should be its initial value plus 5";
}

TEST_F(MyTestSuite, highValue){
	Talker rt;
	int initial_value = 49;
	int value = rt.doSomeMath(initial_value);
	ASSERT_EQ(value, 0) << "Value should be 0";
}

//int main(int argc, char **argv) {
//	testing::InitGoogleTest(&argc, argv);
//	ros::init(argc, argv, "TestNode");
//	return RUN_ALL_TESTS();
//}



