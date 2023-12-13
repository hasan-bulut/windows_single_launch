import 'package:flutter/services.dart';

class MethodChannelWindowsSingleLaunch {
  final methodChannel = const MethodChannel('windows_single_launch');

  Future<bool?> isLaunched(String param1, String param2) async {
    final isLaunched = await methodChannel
        .invokeMethod<bool>('isLaunched', {'param1': param1, 'param2': param2});
    return isLaunched;
  }
}
