#include "include/windows_single_launch/windows_single_launch_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "windows_single_launch_plugin.h"

void WindowsSingleLaunchPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  windows_single_launch::WindowsSingleLaunchPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
