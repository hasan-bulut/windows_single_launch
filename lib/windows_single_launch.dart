import 'dart:io';

import 'package:flutter/material.dart';

import 'windows_single_launch_platform_interface.dart';

class WindowsSingleLaunch {
  void singleRunApp({required Widget app, required String originalName, required String windowTitleName}) async {
    if (await WindowsSingleLaunchPlatform.instance.isLaunched(originalName, windowTitleName) == true) {
      runApp(app);
    } else {
      exit(0);
    }
  }
}
