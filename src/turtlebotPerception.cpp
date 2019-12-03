/**
 *BSD 3-Clause License
 *
 *Copyright (c) 2019, Yashaarth Todi
 *All rights reserved.
 *
 *Redistribution and use in source and binary forms, with or without
 *modification, are permitted provided that the following conditions are met:
 *1. Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *2. Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *3. Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 *THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file turtlebotPerception.cpp
 * @brief This file provides the implementation for the perception module
 *
 * This project contains the execution to navigate Turtlebot3 in a warehouse
 * environment using A star path planning, picks up a package and drops it in
 * user defined postitions. Turtebot3 uses OpenManipulator to perform thus
 * pick-place task.
 *
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License.
 *
 * @author Suyash Yeotikar
 * @author Gautam Balachandran
 * @author Yashaarth Todi
 *
 * @date 11-28-2019
 */

#include "turtlebotPerception.hpp"

/**
 * @brief Getter method for the Ros Node
 * @param  none
 * @return The current node handle for the perception
 */
ros::NodeHandle TurtlebotPerception::getPerceptionNode() {
  return TurtlebotPerception::perceptionNode;
}
/**
 * @brief Setter method for the Ros Node
 * @param  New Node to be set
 * @return none
 */
void TurtlebotPerception::setPerceptionNode(ros::NodeHandle n) {
  TurtlebotPerception::perceptionNode = n;
}
/**
 * @brief Getter method for the distance publisher
 * @param  none
 * @return The current distance publisher
 */
ros::Publisher TurtlebotPerception::getDistPub() {
  return TurtlebotPerception::distPub;
}
/**
 * @brief Setter method for the distance publisher
 * @param  New distance publisher to be set
 * @return none
 */
void TurtlebotPerception::setDistPub(ros::Publisher pub) {
  TurtlebotPerception::distPub = pub;
}
/**
 * @brief Getter method for the distance subscriber
 * @param  none
 * @return The current distance subscriber
 */
ros::Subscriber TurtlebotPerception::getDistSub() {
  return TurtlebotPerception::distSub;
}
/**
 * @brief Setter method for the distance subscriber
 * @param  New distance subscriber to be set
 * @return none
 */
void TurtlebotPerception::setDistSub(ros::Subscriber sub) {
  TurtlebotPerception::distSub = sub;
}
/**
 * @brief Getter method for the collision parameter
 * @param  none
 * @return The boolean value for collision
 */
bool TurtlebotPerception::getCollide() {
  return TurtlebotPerception::collide;
}
/**
 * @brief Setter method for the collision parameter
 * @param boolean value for collision
 * @return none
 */
void TurtlebotPerception::setCollide(bool collision) {
  TurtlebotPerception::collide = collision;
}
/**
 * @brief Callback function to get the Laser scan data from the Turtlebot
 * @param Planar laser range-finder data
 * @return none
 */
void TurtlebotPerception::sensorData(
    const sensor_msgs::LaserScan::ConstPtr &msg) {
  ROS_INFO("Perception Callball range data size: [%s]", msg->ranges.size());
}
/**
 * @brief Mock of the function to detect collision
 * @param none
 * @return true if obstacle detected
 */
bool TurtlebotPerception::detectCollision() {
  return true;  // MOCK VALUE FOR TESTING!
}
/**
 * @brief Function to detect the Aruco Marker
 * @param Frame containing the image to be processed and the markerId
 *  to be compared with
 * @return True if the marker detected matches the package required
 */
bool TurtlebotPerception::detectArucoMarker(cv::Mat imageFrame,
                                            double markerId) {
  return true;  // Mock
}
/**
 * @brief Function to detect the depth of the package for grasping
 * @param Frame containing the image to be processed
 * @return The calculated depth of the package
 */
double TurtlebotPerception::packageDepth(cv::Mat packageImage) {
  return 10.0;  // Mock
}

