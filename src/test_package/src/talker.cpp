#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
using namespace std;
using namespace ros;
int main(int argc,char** argv){
	init(argc,argv,"talker");
	NodeHandle n;
	Publisher pub=n.advertise<std_msgs::String>("pub",1);
	Rate rate(10);
	int count=0;
	while(ok()){
		std::stringstream ss;
		ss<<"SEND:"<<count;
		count++;
		std_msgs::String msg;
		msg.data=ss.str();
		pub.publish(msg);
		spinOnce();
		rate.sleep();
	}
	return 0;
}

