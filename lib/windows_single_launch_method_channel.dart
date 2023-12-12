import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'windows_single_launch_platform_interface.dart';

/// An implementation of [WindowsSingleLaunchPlatform] that uses method channels.
class MethodChannelWindowsSingleLaunch extends WindowsSingleLaunchPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('windows_single_launch');

  @override
  Future<bool?> isLaunched(String param1, String param2) async {
    final isLaunched = await methodChannel.invokeMethod<bool>('isLaunched', {'param1': param1, 'param2': param2});
    return isLaunched;
  }
}
