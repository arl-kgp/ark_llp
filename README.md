
- Run the simulator
`$ roslaunch cvg_sim gazebo iarc_with_bots.launch`
`roslaunch cvg_sim_gazebo iarc_world.launch`

- Run Ground Truth Publisher
`$ rosrun quad_simulator gtpub`

- Run Autopilot
`$ rosrun tum_ardrone drone_autopilot`

- In your code include `ark_llp/go2goal.h`
- Create a `Go2Goal` object
- Use function `set_dest(double x, y, z, theta)` to set destination and clear previous waypoints
- Use function `add_dest(double x, y, z, theta)` to add next waypoint to queue