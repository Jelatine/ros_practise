#include <ros/ros.h>
#include <std_msgs/String.h>
using namespace ros;
void pub_callback(const std_msgs::String::ConstPtr& msg){
	ROS_INFO("RECEIVE:[%s]",msg->data.c_str());
}
int main(int argc ,char** argv){
	init(argc,argv,"listener");
	NodeHandle n;
	Subscriber sub=n.subscribe("pub",1,pub_callback);
	spin();
	return 0;
}
