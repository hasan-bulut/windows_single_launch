import 'package:flutter/material.dart';
import 'package:windows_single_launch/windows_single_launch.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();

  WindowsSingleLaunch().singleRunApp(
    app: const MyApp(),
    originalName: "windows_single_launch_example.exe",
    windowTitleName: "Windows Single Launch",
  );
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
      ),
    );
  }
}
