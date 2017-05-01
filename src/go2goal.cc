#include "go2goal.h"

void Go2Goal::set_dest()
{
  ros::NodeHandle n;
  ros::Publisher go = n.advertise<std_msgs::String>("/tum_ardrone/com", 1, 1);

  std_msgs::String m_clear, m_point, m_start;
  std::stringstream clear, point, start;

  clear << "c clearCommands";
  point << "c goto -2 -1 3 0";
  start << "c start";
  m_clear.data = clear.str();
  m_point.data = point.str();
  m_start.data = start.str();

  go.publish(m_clear);
  ros::spinOnce();
  go.publish(m_point);
  ros::spinOnce();
  go.publish(m_start);
  ros::spinOnce();
}
