플러그인과 모듈 그리고 github
===
> **플러그인이나 모듈 그 자체는 Github 같은 플랫폼이 아니다**
> 

대신, 플러그인이나 모듈은 코드의 한 부분으로 특정 기능을 구현하거나 네이티브 기능에 접근하기 위한 코드 집합체이다. GitHub 와 같은 플랫폼은 이러한 플러그인이나 모듈의 소스 코드를 호스팅하고 버전 관리, 협업, 이슈 추적등을 지원하는 도구이다. 

### 플러그인과 모듈

- **플러그인(Plugin):** 플러그인은 크로스 플랫폼 프레임워크에서 네이티브 기능을 사용할 수 있도록 도와주는 코드 라이브러리이다. 예를 들어**, Flutter 플러그인**은 Dart 코드에서 Android 와 ios의 네이티브 기능을 사용할 수 있도록 해준다.
- **모듈(Module) :** 모듈은 특정 기능을 독립적으로 구현한 코드 집합으로, 재사용 가능하고 다른 프로젝트에 수비게 통합할 수 있다.

### Github 와 같은 플랫폼

GitHub와 같은 플랫폼은 소스 코드를 호스팅하고, 버전 관리, 협업, 이슈 추적등을 지원한다. 이러한 플랫폼을 사용하여 플러그인이나 모듈의 소스 코드를 관리하고, 다른 개발자와 공유할 수 있다.  

**예시: Flutter 플러그인**

Flutter 에서 플러그인을 사용하는 예

1. **플러그인 작성**
    
    Flutter 플러그인을 작성할 때, Android 와 ios 의 네이티브 코드를 포함하는 디렉토리 구조를 가진다. 
    

1. **GitHub 에 소스 코드 호스팅**
    
    작성된 플러그인의 소스 코드를 Github 와 같은 플랫폼에 호스팅하여 버전 관리와 협업을 지원한다. 
    

1. **프로젝트에 플러그인 통합**
    
    **Flutter 프로젝트에서 해당 플러그인을 사용하려면 `pubspec.yaml` 파일에 의존성을 추가한다**. 
    
    [Flutter 와 플러그인의 관계](https://www.notion.so/Flutter-d3d86231767441c38ce0f8add0bb36c9?pvs=21)
    

### **1. 플러그인 작성 예시 코드**

Android 코드(Kotlin)

```kotlin
package com.example.myplugin

import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import io.flutter.plugin.common.PluginRegistry.Registrar

class MyPlugin: MethodCallHandler {
    companion object {
        @JvmStatic
        fun registerWith(registrar: Registrar) {
            val channel = MethodChannel(registrar.messenger(), "my_plugin")
            channel.setMethodCallHandler(MyPlugin())
        }
    }

    override fun onMethodCall(call: MethodCall, result: Result) {
        if (call.method == "getPlatformVersion") {
            result.success("Android ${android.os.Build.VERSION.RELEASE}")
        } else {
            result.notImplemented()
        }
    }
}

```

ios 코드(Swift)

```swift
import Flutter
import UIKit

public class SwiftMyPlugin: NSObject, FlutterPlugin {
    public static func register(with registrar: FlutterPluginRegistrar) {
        let channel = FlutterMethodChannel(name: "my_plugin", binaryMessenger: registrar.messenger())
        let instance = SwiftMyPlugin()
        registrar.addMethodCallDelegate(instance, channel: channel)
    }

    public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        if call.method == "getPlatformVersion" {
            result("iOS " + UIDevice.current.systemVersion)
        } else {
            result(FlutterMethodNotImplemented)
        }
    }
}

```

Dart 코드

```swift
import 'dart:async';

import 'package:flutter/services.dart';

class MyPlugin {
  static const MethodChannel _channel = MethodChannel('my_plugin');

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}

```

### 2. GitHub 에 소스 코드 호스팅

플러그인 코드를 GitHub 레포지토리에 업로드하고 관리한다. 예를 들어, [`https://github.com/username/my_plugin`](https://github.com/username/my_plugin) 레포지토리에 호스팅한다.

### 3. 프로젝트에 플러그인 통합

`pubspec.yaml` 파일에 플러그인을 추가하여 프로젝트에서 사용할 수 있도록 한다.

```yaml
```yaml
**dependencies:
  flutter:
    sdk: flutter
  my_plugin:
    git:
      url: https://github.com/username/my_plugin**

```
```

### 

## `pubspec.yaml` 파일에 대해서

- pubspec.yaml 파일이 뭔지
    
    ## pubspec.yaml 파일이 뭔지
    
    `pubspec.yaml` 파일은 Flutter 와 Dart 프로젝트의 핵심 설정 파일이다. 이 파일은 프로젝트 메타데이터, 의존성, 자산 등을 정의하는 데 사용된다. 
    
    > **주요 섹션**
    > 
    1. **name**: 프로젝트의 이름을 지정합니다.
    2. **description**: 프로젝트에 대한 설명을 제공합니다.
    3. **version**: 프로젝트의 버전을 지정합니다.
    4. **environment**: Dart SDK의 버전 범위를 지정합니다.
    5. **dependencies**: 프로젝트가 의존하는 패키지들을 지정합니다.
    6. **dev_dependencies**: 개발 환경에서만 필요한 패키지들을 지정합니다.
    7. **flutter**: Flutter 관련 설정과 자산(asset)을 지정합니다.
    
    `pubspec.yaml` 파일은 Flutter와 Dart 프로젝트에서 매우 중요한 역할을 합니다. 이 파일을 통해 프로젝트의 의존성을 관리하고, 필요한 자산을 지정하며, 환경 설정을 할 수 있습니다. `pubspec.yaml` 파일을 적절히 관리하면 프로젝트의 구성을 체계적으로 유지하고, 필요한 패키지와 자산을 효과적으로 관리할 수 있습니다.
    
- pubspec.yaml 파일의 역할
    
    ## pubspec.yaml 파일의 역할
    
    1. **프로젝트 메타데이터**
    - 프로젝트의 이름, 설명, 버전 정보 등을 정의한다.
    
    1. **의존성 관리**
    - Flutter 및 Dart 패키지를 관리하여 프로젝트에 필요한 라이브러리를 정의한다.
    
    1. **개발 의존성**
    - 텍스트 및 개발에 필요한 패키지등을 정의한다.
    
    1. **환경 설정**
    - 프로젝트가 사용해야하는 Dart SDK 의 버전 범위를 설정한다.
    
    1. **자산 관리**
    - 프로젝트에서 사용되는 이미지, 폰트 등의 자산을 정의하고 관리한다.
    
    ### 예시 `pubspec.yaml` 파일
    
    ```yaml
    name: my_flutter_app
    description: A new Flutter application.
    
    version: 1.0.0+1
    
    environment:
      sdk: ">=2.12.0 <3.0.0"
    
    dependencies:
      flutter:
        sdk: flutter
      http: ^0.13.3
      provider: ^5.0.0
    
    dev_dependencies:
      flutter_test:
        sdk: flutter
    
    flutter:
      uses-material-design: true
    
      assets:
        - assets/images/
        - assets/icons/
    
      fonts:
        - family: Roboto
          fonts:
            - asset: fonts/Roboto-Regular.ttf
            - asset: fonts/Roboto-Bold.ttf
              weight: 700
    
    ```
    
    ### 네이티브 코드 관리
    
    네이티브 코드(Android 및 ios)는 `pubspec.yaml` 파일이 아닌, 프로젝트의 각 네이티브 플랫폼 디렉토리에서 관리한다. 다음은 Flutter 프로젝트에서 네이티브 코드를 관리하는 방법이다.
    
    예시) **Android 코드(kotlin) → Android 네이티브 플랫폼 디렉토리에 위치**
    
    ```kotlin
    // android/app/src/main/kotlin/com/example/my_flutter_app/MainActivity.kt
    package com.example.my_flutter_app
    
    import io.flutter.embedding.android.FlutterActivity
    
    class MainActivity: FlutterActivity() {
    }
    
    ```
    
    1. **ios 네이티브 코드 → ios 플랫폼 디렉토리에 위치**
    - **위치:** ‘ios’ 디렉토리 내에 위치한다.
    - **설정 파일:** ‘Profile’ 등을 통해 네이티브 코드의 빌드 설정을 관리한다.
    - **코드 작성:** ‘ios/Runner’ 디렉토리 내에 Swift 또는 Object-C 코드 작성
    
    예시) **ios 네이티브 코드(Swift)**
    
    ```swift
    // ios/Runner/AppDelegate.swift
    import UIKit
    import Flutter
    
    @UIApplicationMain
    @objc class AppDelegate: FlutterAppDelegate {
      override func application(
        _ application: UIApplication,
        didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?
      ) -> Bool {
        GeneratedPluginRegistrant.register(with: self)
        return super.application(application, didFinishLaunchingWithOptions: launchOptions)
      }
    }
    
    ```
    
    ### 네이티브 기능 통합
    
    네이티브 기능을 Flutter 와 통합하려면, **플러그인**이나 **Platform Channels 를 사용**한다. 이 방법을 통해 **Flutter 코드와 네이티브 코드 간의 상호작용**을 가능하게 한다. 
    
    **Platform Channels 예시**
    
    1. **Dart 코드:** Flutter 에서 네이티브 기능을 호출하는 코드
    
    ```dart
    import 'package:flutter/services.dart';
    
    class NativeFunctionality {
      static const platform = MethodChannel('com.example/native');
    
      Future<String?> getPlatformVersion() async {
        try {
          final String? result = await platform.invokeMethod('getPlatformVersion');
          return result;
        } catch (e) {
          print("Failed to get platform version: '${e.message}'.");
          return null;
        }
      }
    }
    
    ```
    
    1. **Android 코드(kotlin)**
    
    ```kotlin
    package com.example.my_flutter_app
    
    import io.flutter.embedding.engine.FlutterEngine
    import io.flutter.plugin.common.MethodChannel
    
    class MainActivity: FlutterActivity() {
        private val CHANNEL = "com.example/native"
    
        override fun configureFlutterEngine(flutterEngine: FlutterEngine) {
            super.configureFlutterEngine(flutterEngine)
            MethodChannel(flutterEngine.dartExecutor.binaryMessenger, CHANNEL).setMethodCallHandler { call, result ->
                if (call.method == "getPlatformVersion") {
                    result.success("Android ${android.os.Build.VERSION.RELEASE}")
                } else {
                    result.notImplemented()
                }
            }
        }
    }
    
    ```
    
    1. **ios 코드(Swift)**
    
    ```swift
    import Flutter
    import UIKit
    
    @UIApplicationMain
    @objc class AppDelegate: FlutterAppDelegate {
      override func application(
        _ application: UIApplication,
        didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?
      ) -> Bool {
        let controller: FlutterViewController = window?.rootViewController as! FlutterViewController
        let nativeChannel = FlutterMethodChannel(name: "com.example/native", binaryMessenger: controller.binaryMessenger)
        
        nativeChannel.setMethodCallHandler { (call: FlutterMethodCall, result: @escaping FlutterResult) in
            if call.method == "getPlatformVersion" {
                result("iOS " + UIDevice.current.systemVersion)
            } else {
                result(FlutterMethodNotImplemented)
            }
        }
    
        return super.application(application, didFinishLaunchingWithOptions: launchOptions)
      }
    }
    
    ```
    
    ### 결론
    
    `pubspec.yaml` 파일은 Flutter 프로젝트에서 중요한 설정 파일로, 프로젝트의 메타데이터, 의존성, 자산 등을 관리한다. 네이티브 코드(Android 및 ios) 는 각각 네이티브 플랫폼 디렉토리에서 관리되며, `pubspec.yaml` 파일은 이들을 직접적으로 관리하지 않는다. 네이티브 기능을 Flutter 와 통합하려면 플러그인이나 Platform Channels 를 사용하여 Flutter 코드와 네이티브 코드 간의 상호작용을 구현한다.
    
- pubspec.yaml 파일에 추가 요소들
    
    ## Pubspec.yaml 파일에 추가 요소들
    
    Flutter 프로젝트에서 외부 플러그인을 사용하려면 `pubspec.yaml` 파일에 플러그인의 의존성을 추가해야한다. 플러그인의 주소를 복사하여 `pubspec.yaml` 파일에 적절한 형식으로 추가하면 된다.
    
    [외부 플러그인](https://www.notion.so/90bd5b8d59d24068b1737556ce2bb0da?pvs=21)
    
    ### 플러그인의 의존성 추가 방법
    
    1. **공식 플러그인:** [Pub.dev](http://Pub.dev) 와 같은 공식 패키지 저장소에서 제공하는 플러그인
    2. **GitHub 플러그인** : GitHub에 호스팅된 플러그인
    3. **로컬 플러그인:** 로컨 파일 시스템에 저장된 플러그인
    - **예시**
        1. **공식 플러그인 추가**
            
            [pub.dev](http://pub.dev) 에서 제공하는 공식 플러그인을 `pubspec.yaml` 파일에 추가한다.
            
            ```yaml
            dependencies:
              flutter:
                sdk: flutter
              http: ^0.13.3
              provider: ^5.0.0
            
            ```
            
    
    1. **GitHub 플러그인 추가**
        
        GitHub에 호스팅된 플러그인을 사용하려면 플러그인의 GitHub URL 을 지정한다.
        
        ```yaml
        dependencies:
          flutter:
            sdk: flutter
          http: ^0.13.3
          provider:
            git:
              url: https://github.com/rrousselGit/provider.git
              ref: master  # 특정 브랜치나 커밋을 지정할 수 있습니다.
        
        ```
        
    
    1. **로컬 플러그인 추가**
        
        로컬 파일 시스템에 저장된 플러그인을 사용하려면 플러그인의 경로를 지정한다.
        
        ```yaml
        dependencies:
          flutter:
            sdk: flutter
          my_local_plugin:
            path: ../local_plugins/my_local_plugin
        
        ```
        
        ### 플러그인 사용 예시
        
        1. **`pubspec.ymal` 파일에 플러그인 추가**
        
        ```yaml
        name: my_flutter_app
        description: A new Flutter application.
        
        version: 1.0.0+1
        
        environment:
          sdk: ">=2.12.0 <3.0.0"
        
        dependencies:
          flutter:
            sdk: flutter
          http: ^0.13.3
          provider: ^5.0.0
          my_custom_plugin:
            git:
              url: https://github.com/yourusername/my_custom_plugin.git
              ref: main
        
        ```
        
        1. **플러그인 설치**
        - `pubspec.yaml` 파일을 수정한 후, 터미널에서 다음 명령어를 실행하여 의존성을 설치한다.
        
        ```bash
        flutter pub get
        ```
        
        1. **플러그인 사용**
        - 플러그인을 사용하여 필요한 기능을 구현한다.
        
        ```dart
        import 'package:flutter/material.dart';
        import 'package:http/http.dart' as http;
        import 'package:provider/provider.dart';
        
        void main() {
          runApp(MyApp());
        }
        
        class MyApp extends StatelessWidget {
          @override
          Widget build(BuildContext context) {
            return MultiProvider(
              providers: [
                ChangeNotifierProvider(create: (_) => MyModel()),
              ],
              child: MaterialApp(
                home: Scaffold(
                  appBar: AppBar(
                    title: Text('Flutter App'),
                  ),
                  body: Center(
                    child: FutureBuilder(
                      future: fetchData(),
                      builder: (context, snapshot) {
                        if (snapshot.connectionState == ConnectionState.waiting) {
                          return CircularProgressIndicator();
                        } else if (snapshot.hasError) {
                          return Text('Error: ${snapshot.error}');
                        } else {
                          return Text('Data: ${snapshot.data}');
                        }
                      },
                    ),
                  ),
                ),
              ),
            );
          }
        
          Future<String> fetchData() async {
            final response = await http.get(Uri.parse('https://jsonplaceholder.typicode.com/todos/1'));
            if (response.statusCode == 200) {
              return response.body;
            } else {
              throw Exception('Failed to load data');
            }
          }
        }
        
        class MyModel extends ChangeNotifier {
          // Your model code here
        }
        
        ```
        
        ### 결론
        
        `pubspec.yaml` 파일에 플러그인의 의존성을 추가하여 Flutter 프로젝트에서 플러그인을 사용할 수 있습니다. 이를 통해 프로젝트에서 필요한 기능을 쉽게 확장할 수 있습니다. 공식 패키지, GitHub 패키지, 로컬 패키지 모두 `pubspec.yaml` 파일에 적절한 형식으로 추가하여 사용할 수 있습니다.