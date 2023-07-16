#include "core.h"


void core::set_instance_create_info(){

  VkApplicationInfo appinfo;
  appinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appinfo.pNext = nullptr;
  appinfo.pApplicationName = "ross";
  appinfo.applicationVersion = VK_MAKE_VERSION(0,0,0);
  appinfo.pEngineName = "ross";
  appinfo.engineVersion = VK_MAKE_VERSION(0,0,0);
  appinfo.apiVersion = VK_API_VERSION_1_3;
  
  instance_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instance_info.pNext = nullptr;
  instance_info.flags = 0;
  instance_info.pApplicationInfo = &appinfo;

}

void core::set_instance_layers(){

  cont char ** layernames = new cont char*[1];
  layernames[0] = "VK_LAYER_KHRONOS_validation";
  
  instance_info.enabledLayerCount = 1;
  instance_info.ppEnabledLayerNames = layernames;

 }

void core::get_instance_extensions(){

  if(!glfwInit()){
    printf("\nGlfW initialization failed\n");
  }
  extension = glfwGetRequiredInstanceExtensions(&extension_count);
}

void core::set_instance_extensions(){
  instance_info.enabledExtensionCount = extension_count;
  instance_info.ppEnabledExtensionNames = extension;
  
}

void core::create_instance(){

  set_instance_crate_info();
  set_instance_extensions();
  get_instance_extensions();
  set_instance_extensions();

  vk_check( vkCreateInstance(
			     &instance_info,
			     nullptr,
			     &instance));
  printf("\nInstance Creation Successful\n");
}



