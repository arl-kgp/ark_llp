#include "go2goal.h"
#include <ros/ros.h>
#include "std_msgs/Empty.h"
#include <sstream>        
void Go2Goal::comCb(const std_msgs::StringConstPtr str)
{      
 int k=0;
 char a[100],b[100],c[100];
 const char *string=str->data.c_str();
 while(*(string) != 'T' && *(string) != '\0')
 {
 string++;
 }
 while(*(string)  != '(' && *(string) != '\0')
 {
 string++;
 }
 k=0;
 while(*(string) != ',' && *(string) != '\0')
 {
 a[k]=*(string+1);
 string++;
 k++;
 }
 a[k]='\0';
 k=0;
 string++;
 while(*(string) != ',' && *(string) != '\0')
 {
 b[k]=*(string+2);
 string++;
 k++;
 }
 b[k]='\0';
 k=0;
 string++;
 while(*(string) != ',' && *(string) != '\0')
 {
 c[k]=*(string+2);
 string++;
 k++;
 }
 c[k]='\0';
 k=0;
 x11=atof(a);
 y11=atof(b);
 z11=atof(c);
 check=true;
 return;
}

void Go2Goal::set_dest(double x, double y, double z, double theta)
{
  ros::NodeHandle n;                                           //communication of this node with ros system
  ros::Publisher go = n.advertise<std_msgs::String>("/tum_ardrone/com", 1, 1);//behaviour of autopilot is set by sending commands to 											tum_ardrone/com 
  ros::Publisher takeoff_pub = n.advertise<std_msgs::Empty>("/ardrone/takeoff",1, 1);

  ros::Rate loop_rate(10);

  std_msgs::String m_clear, m_point, m_start;
  std::stringstream clear, point, start;

  clear << "c clearCommands";
  point << "c goto ";
  point << x << " " << y << " " << z << " " << theta;
  start << "c start";
  m_clear.data = clear.str();
  m_point.data = point.str();
  m_start.data = start.str();
 
  takeoff_pub.publish(std_msgs::Empty());
  ros::spinOnce();
  loop_rate.sleep();
  go.publish(m_clear);
  ros::spinOnce();
  loop_rate.sleep();
  go.publish(m_point);
  ros::spinOnce();
  loop_rate.sleep();
  go.publish(m_start);
  ros::spinOnce();
  loop_rate.sleep();

}

void Go2Goal::add_dest(double x, double y, double z, double theta)
{
  ros::NodeHandle n;
  ros::Publisher go = n.advertise<std_msgs::String>("/tum_ardrone/com", 1, 1);
  ros::Rate loop_rate(10);

  std_msgs::String m_point, m_start;
  std::stringstream point, start;

  point << "c goto "; 
  point << x << " " << y << " " << z << " " << theta;
  start << "c start";
  m_point.data = point.str();
  m_start.data = start.str();

  go.publish(m_point);
  ros::spinOnce();
  loop_rate.sleep();
  go.publish(m_start);
  ros::spinOnce();
  loop_rate.sleep();

}


void Go2Goal::false_dest(double x, double y, double z, double theta)
{
  check=false;
  ros::NodeHandle n;
  ros::Publisher go = n.advertise<std_msgs::String>("/tum_ardrone/com", 1, 1);
  ros::Subscriber sub = n.subscribe("/tum_ardrone/com", 10 , &Go2Goal::comCb, this);
  ros::Rate loop_rate(10);
  while(check==false)
  {
  ros::spinOnce();
  loop_rate.sleep();
  }
 
  if(check==true)
  {
  std_msgs::String m_clear, m_point, m_start, m_false;
  std::stringstream clear, point, start, false_point;
  clear << "c clearCommands";
  point << "c goto ";
  point << x11 << " " << y11 << " " << z11 << " " << theta11;
  false_point << "c goto ";
  false_point << x << " " << y << " " << z << " " << theta;
  start << "c start";
  m_clear.data = clear.str();
  m_false.data = false_point.str();
  m_point.data = point.str();
  m_start.data = start.str();
  go.publish(m_clear);
  ros::spinOnce();
  loop_rate.sleep();
  go.publish(m_false);
  ros::spinOnce();
  loop_rate.sleep();
  go.publish(m_point);
  ros::spinOnce();
  loop_rate.sleep();
  go.publish(m_start);
  ros::spinOnce();
  loop_rate.sleep();
  }
  }
