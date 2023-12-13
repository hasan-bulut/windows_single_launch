import 'dart:io';

import 'package:flutter/material.dart';
import 'package:windows_single_launch/windows_single_launch_method_channel.dart';

class WindowsSingleLaunch {
  void singleRunApp(
      {required Widget app,
      required String originalName,
      required String windowTitleName}) async {
    if (await MethodChannelWindowsSingleLaunch()
            .isLaunched(originalName, windowTitleName) ==
        true) {
      runApp(app);
    } else {
      exit(0);
    }
  }
}
