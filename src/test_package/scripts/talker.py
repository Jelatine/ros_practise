#!/usr/bin/env python
import rospy
from std_msgs.msg import String
pub=rospy.Publisher("pub",String,queue_size=1)
rospy.init_node("talker",anonymous=True)
rate=rospy.Rate(10)
while not rospy.is_shutdown():
    hello_str="hello world %s" % rospy.get_time()
    pub.publish(hello_str)
    rate.sleep();
