#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

typedef unsigned int    u32;
typedef unsigned long   u64;
typedef unsigned float  f32;
typedef unsigned double f64;

class core{
public:
  //core:
  VkInstance instance;
  VkPhysicalDevice * gpu;
  VKDevice device;

  //instance:
  VkInstanceCreateInfo instance_info;

  //physical device:
  u32 gpu_select; 
  VkPhysicalDeviceProperties gpu_properties;
  VkQueueFamilyProperties * queue_family_properties;
  
public:
  void create_instance();
  void get_physical_device();
  void create_device();
  void get_device_queues();

  //instance:
  void set_instance_create_info();
  void set_instance_layers();
  void get_instance_extensions();
  void ste_instance_extensions();

  //physical device:
  void select_default_physical_device();
  void get_physical_device_properties();
  void get_physical_device_queue_family_properties();
   
  
  void cleanup();
};

x//helpers
void vk_check(VkResult res);
