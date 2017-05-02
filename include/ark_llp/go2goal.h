#ifndef __GO2GOAL_H
#define __GO2GOAL_H
#include "std_msgs/String.h"

class Go2Goal
{
private:
	void comCb(const std_msgs::StringConstPtr str);
public:
	void set_dest(double x, double y, double z, double theta);
	void add_dest(double x, double y, double z, double theta);
	void false_dest(double x, double y, double z, double theta);

};

#endif