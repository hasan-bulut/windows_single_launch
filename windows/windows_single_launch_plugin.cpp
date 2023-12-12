#include "windows_single_launch_plugin.h"
#include "windows_single_launch_control.cpp"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

namespace windows_single_launch
{

  // static
  void WindowsSingleLaunchPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarWindows *registrar)
  {
    auto channel =
        std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
            registrar->messenger(), "windows_single_launch",
            &flutter::StandardMethodCodec::GetInstance());

    auto plugin = std::make_unique<WindowsSingleLaunchPlugin>();

    channel->SetMethodCallHandler(
        [plugin_pointer = plugin.get()](const auto &call, auto result)
        {
          plugin_pointer->HandleMethodCall(call, std::move(result));
        });

    registrar->AddPlugin(std::move(plugin));
  }

  WindowsSingleLaunchPlugin::WindowsSingleLaunchPlugin() {}

  WindowsSingleLaunchPlugin::~WindowsSingleLaunchPlugin() {}

  void WindowsSingleLaunchPlugin::HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result)
  {
    const auto *arguments = std::get_if<flutter::EncodableMap>(method_call.arguments());

    if (method_call.method_name().compare("isLaunched") == 0)
    {
      std::string param1 = std::get<std::string>(arguments->find(flutter::EncodableValue("param1"))->second);
      std::string param2 = std::get<std::string>(arguments->find(flutter::EncodableValue("param2"))->second);

      const char *originalName = param1.c_str();

      int wideCharLength = MultiByteToWideChar(CP_UTF8, 0, param2.c_str(), -1, nullptr, 0);
      wchar_t *wideCharBuffer = new wchar_t[wideCharLength];

      MultiByteToWideChar(CP_UTF8, 0, param2.c_str(), -1, wideCharBuffer, wideCharLength);

      result->Success(flutter::EncodableValue(AppControl(originalName, wideCharBuffer) == 0));
      delete[] wideCharBuffer;
    }
    else
    {
      result->NotImplemented();
    }
  }

} // namespace windows_single_launch
