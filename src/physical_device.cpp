#include "core.h"

void core::get_physical_device(){

  u32 count = 0;
  
  vk_check(vkEnumeratePhysicalDevices(
				      instance,
				      &count,
				      nullptr));

  gpu = new VkPhyscicalDevice[count];
  
  vk_check(vkEnumeratePhysicalDevices(
				      instance,
				      &count,
				      gpu));

};


void core::select_default_physical_device(){

  gpu_select = 0; // @TODO: needs to be updated

}

void core::get_physical_device_properties(){

  gpu_properties = VK_NULL_HANDLE;
  
  vk_check( vkGetPhysicalDeviceProperties(
					  gpu[gpu_select],
					  &gpu_properties));

  if(gpu_properties == VK_NULL_HANDLE){
    Exit(-1);
  }
  
}


void core::get_physical_device_queue_family_properties(){


  u32 count = 0;
  
  
  vkGetPhysicalDeviceQueueFamilyProperties(
					   gpu[gpu_select],
					   &count,
					   nullptr);
  
  queue_family_properties = new VkQueueFamilyProperties[count];

  vkGetPhysicalDeviceQueueFamilyProperties(
					   gpu[gpu_select],
					   &count,
					   queue_family_proeprties);
 }


