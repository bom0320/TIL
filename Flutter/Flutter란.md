Flutter(플러터)란?
===
<img src="https://modulabs.co.kr/wp-content/uploads/2023/06/flutter-logo-sharing.png">
- Flutter 는 Google 에서 개발하고 관리하는 오픈 소스 모바일 앱(Application) 개발 프레임워크(Framework)이다.
- 이 프레임워크는 Android와 ios 등 다양한 플랫폼에서 동작하는 앱을 개발하기 위해 사용되며, 모바일 앱(Application)의 개발 속도를 높이기 위한 다양한 기능과 도구를 제공한다.

### Flutter의 주요 특징

1. **크로스 플랫폼 개발**
    - **한 번의 코드 작성, 여러 플랫폼에서 실행**: 한 번 코드를 작성하면 iOS, Android, 웹, Windows, macOS, Linux 등 여러 플랫폼에서 동작한다.
2. **빠른 개발**
    - **Hot Reload**: 코드 변경 시 애플리케이션을 다시 시작하지 않고도 실시간으로 변경 사항을 확인할 수 있다.
3. **높은 성능**
    - **네이티브 성능**: Flutter는 네이티브 ARM 코드로 컴파일되어 성능이 뛰어나다.
4. **우수한 UI**
    - **위젯 기반 아키텍처**: Flutter는 풍부하고 커스터마이징 가능한 위젯을 제공하여 복잡한 UI를 손쉽게 만들 수 있다.
    - **다양한 디자인 가능**: 머티리얼 디자인(Material Design)과 쿠퍼티노(Cupertino) 디자인을 모두 지원하여, Android와 iOS 스타일의 UI를 각각 구현할 수 있다.

### Flutter의 구성 요소

1. **Dart 언어**
    - **설명**: Flutter는 Dart 언어로 작성된다. Dart는 간결하고 안전한 언어로, JIT(Just-In-Time) 및 AOT(Ahead-Of-Time) 컴파일을 모두 지원한다.
2. **Flutter 엔진**
    - **설명**: Flutter 엔진은 Skia 그래픽 엔진을 사용하여 화면을 렌더링하며, 네이티브 코드와 상호작용할 수 있는 다양한 플러그인을 제공한다.
3. **위젯**
    - **설명**: Flutter의 모든 UI 요소는 위젯으로 구성된다. 위젯은 작은 구성 요소부터 전체 화면에 이르기까지 다양한 형태로 존재하며, 재사용이 가능하고 계층적으로 구성할 수 있다.
4. **플러그인과 패키지**
    - **설명**: Flutter는 커뮤니티에서 제공하는 수많은 플러그인과 패키지를 통해 기능을 확장할 수 있다. 예를 들어, 카메라, 위치 정보, 네트워크 요청 등을 처리할 수 있는 플러그인이 있다.

### Flutter 예제 코드

```dart
dart코드 복사
import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: MyHomePage(),
    );
  }
}

class MyHomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Flutter Demo Home Page'),
      ),
      body: Center(
        child: Text('Hello, Flutter!'),
      ),
    );
  }
}

```
