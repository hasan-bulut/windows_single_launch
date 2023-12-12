#ifndef FLUTTER_PLUGIN_WINDOWS_SINGLE_LAUNCH_PLUGIN_H_
#define FLUTTER_PLUGIN_WINDOWS_SINGLE_LAUNCH_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace windows_single_launch {

class WindowsSingleLaunchPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  WindowsSingleLaunchPlugin();

  virtual ~WindowsSingleLaunchPlugin();

  // Disallow copy and assign.
  WindowsSingleLaunchPlugin(const WindowsSingleLaunchPlugin&) = delete;
  WindowsSingleLaunchPlugin& operator=(const WindowsSingleLaunchPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace windows_single_launch

#endif  // FLUTTER_PLUGIN_WINDOWS_SINGLE_LAUNCH_PLUGIN_H_
