/**
 * @file include/lemlib/chassis/odom.hpp
 * @author LemLib Team
 * @brief This is the header file for the odom.cpp file. Its not meant to be used directly, only through the chassis
 * class
 * @version 0.4.5
 * @date 2023-01-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "lemlib/pose.hpp"
#include "lemlib/chassis/odom.hpp"
#include "lemlib/chassis/chassis.hpp"

namespace lemlib {
class Odometry {
    public:
        /**
         * @brief Construct a new Odometry object
         *
         * @param chassis pointer to the chassis object
         */
        Odometry(OdomSensors_t& sensors, Drivetrain_t& drive);

        /**
         * @brief Get the Pose
         *
         * @note Units are in radians. Locked from 0 to 2pi. Right is 0, increasing counter-clockwise
         *
         * @return Pose
         */
        Pose getPose();

        /**
         * @brief Set the Pose
         *
         * @note Units are in radians. Right is 0, increasing counter-clockwise
         *
         * @param pose
         */
        void setPose();

        /**
         * @brief Update the pose of the robot
         *
         * @note this should be called in a loop, ideally every 10ms (the sensor polling rate)
         */
        void update();
    private:
        float prevVertical = 0;
        float prevVertical1 = 0;
        float prevVertical2 = 0;
        float prevHorizontal = 0;
        float prevHorizontal1 = 0;
        float prevHorizontal2 = 0;
        float prevImu = 0;
        Pose pose = Pose(0, 0, 0); // the pose of the robot
};
} // namespace lemlib
