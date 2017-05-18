#ifndef __GO2GOAL_H
#define __GO2GOAL_H
#include "std_msgs/String.h"

class Go2Goal
{    
private://these functions can only be accessed and changed by functions in public not by any other function
	void comCb(const std_msgs::StringConstPtr str); 
        double x11,y11,z11,theta11; 
        bool check;
                         
public://these functions can be accessed and changed by any other function
	void set_dest(double x, double y, double z, double theta);
	void add_dest(double x, double y, double z, double theta);
	void false_dest(double x, double y, double z, double theta);
   	

};

#endif

//class is like a prototype of functions.All these functions are defined in go2goal.cc and the prototypes are included by including 
//go2goal.h
