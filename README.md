# Windows Single Launch

Launch Windows applications from a single instance. Brings the current instance to the front on each launch.

If you do not want a new instance to run every time you run your application, you can use this plugin. With its simple use, it forces your application to run in a single instance in a good way. If the application is already open, when you run it again, it brings the current application to the front, and if it is hidden, it makes it visible.

## Usage

1. Add `WidgetsFlutterBinding.ensureInitialized();` to the start of your apps `main` function.
2. Use `WindowsSingleLaunch.singleRunApp()` instead of `runApp()` to run your application.
3. singleRunApp(<br>
`app:` (Your application),<br>
`originalName:` (OriginalName of your application written in windows/runner/Runner.rc),<br>
`windowTitleName:` (title of your application written in windows/runner/main.cpp)<br>
):

## Example

```
void main() {
  WidgetsFlutterBinding.ensureInitialized();

  WindowsSingleLaunch().singleRunApp(
    app: const MyApp(),
    originalName: "windows_single_launch_example.exe",
    windowTitleName: "Windows Single Launch",
  );
}
```