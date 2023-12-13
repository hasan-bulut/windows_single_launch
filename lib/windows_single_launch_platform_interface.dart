import 'windows_single_launch_method_channel.dart';

abstract class WindowsSingleLaunchPlatform {
  /// Constructs a WindowsSingleLaunchPlatform.
  WindowsSingleLaunchPlatform() : super();

  static WindowsSingleLaunchPlatform _instance = MethodChannelWindowsSingleLaunch();

  /// The default instance of [WindowsSingleLaunchPlatform] to use.
  ///
  /// Defaults to [MethodChannelWindowsSingleLaunch].
  static WindowsSingleLaunchPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [WindowsSingleLaunchPlatform] when
  /// they register themselves.
  static set instance(WindowsSingleLaunchPlatform instance) {
    _instance = instance;
  }

  Future<bool?> isLaunched(String param1, String param2) {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
