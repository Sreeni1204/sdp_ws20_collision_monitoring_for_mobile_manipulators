/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2019 Kinova inc. All rights reserved.
*
* This software may be modified and distributed under the
* terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/

/*
 * This file has been auto-generated and should not be modified.
 */
 
#ifndef _KORTEX_PRODUCTCONFIGURATION_ROS_CONVERTER_H_
#define _KORTEX_PRODUCTCONFIGURATION_ROS_CONVERTER_H_

#include "ros/ros.h"

#include <string>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <chrono>

#include <ProductConfiguration.pb.h>

#include "kortex_driver/generated/common_ros_converter.h"
#include "kortex_driver/generated/actuatorconfig_ros_converter.h"
#include "kortex_driver/generated/actuatorcyclic_ros_converter.h"
#include "kortex_driver/generated/base_ros_converter.h"
#include "kortex_driver/generated/grippercyclic_ros_converter.h"
#include "kortex_driver/generated/interconnectcyclic_ros_converter.h"
#include "kortex_driver/generated/basecyclic_ros_converter.h"
#include "kortex_driver/generated/controlconfig_ros_converter.h"
#include "kortex_driver/generated/deviceconfig_ros_converter.h"
#include "kortex_driver/generated/devicemanager_ros_converter.h"
#include "kortex_driver/generated/interconnectconfig_ros_converter.h"
#include "kortex_driver/generated/visionconfig_ros_converter.h"


#include "kortex_driver/CompleteProductConfiguration.h"
#include "kortex_driver/ProductConfigurationEndEffectorType.h"


int ToRosData(Kinova::Api::ProductConfiguration::CompleteProductConfiguration input, kortex_driver::CompleteProductConfiguration &output);
int ToRosData(Kinova::Api::ProductConfiguration::ProductConfigurationEndEffectorType input, kortex_driver::ProductConfigurationEndEffectorType &output);

#endif