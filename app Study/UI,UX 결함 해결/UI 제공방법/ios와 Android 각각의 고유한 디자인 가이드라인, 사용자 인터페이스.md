## ios(Cupertino) 디자인 가이드라인

**주요 UI 컴포넌트:**

1. **네비게이션 바 (Navigation Bar):** 화면 상단에 위치하며 제목, 탐색 제어 및 작업을 표시한다.
    - `CupertinoNavigationBar`
2. **버튼 (Button): 다양한 스타일의 버튼**
    - `CupertinoButton`
    - `CuperTinoDitalogAction`
3. **탭 바 (Tab Bar) :** 화면 하단에 위치하며 탭을 통해 서로 다른 화면으로 전환한다.
- `CupertinoTaBar`
1. **픽커 (Picker) :** 날짜와 시간을 선택할 때 사용한다. 
- `‘CupertinoDataPicker’`
- `CuperTinoPicker’`

1. **텍스트 필드 (Text Field)**: 텍스트 입력을 위한 필드.
    - `CupertinoTextField`
2. **알림 (Alert)**: 사용자에게 중요한 정보를 제공하거나 입력을 요청하는 모달 팝업.
    - `CupertinoAlertDialog`

**예제 코드**:

```dart
dart코드 복사
import 'package:flutter/cupertino.dart';

class MyIOSApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return CupertinoApp(
      home: CupertinoPageScaffold(
        navigationBar: CupertinoNavigationBar(
          middle: Text('iOS Style App'),
        ),
        child: Center(
          child: CupertinoButton(
            child: Text('Cupertino Button'),
            onPressed: () {},
          ),
        ),
      ),
    );
  }
}

```

### Android (Material) 디자인 가이드라인

**주요 UI 컴포넌트**:

1. **앱 바 (App Bar)**: 화면 상단에 위치하며 제목, 탐색 제어 및 작업을 표시합니다.
    - `AppBar`
2. **버튼 (Button)**: 다양한 스타일의 버튼.
    - `ElevatedButton`
    - `TextButton`
    - `OutlinedButton`
    - `FloatingActionButton`
3. **탭 바 (Tab Bar)**: 화면 상단 또는 하단에 위치하며 탭을 통해 서로 다른 화면으로 전환합니다.
    - `TabBar`
4. **다이얼로그 (Dialog)**: 사용자에게 중요한 정보를 제공하거나 입력을 요청하는 모달 팝업.
    - `AlertDialog`
5. **텍스트 필드 (Text Field)**: 텍스트 입력을 위한 필드.
    - `TextField`
6. **스낵바 (Snackbar)**: 간단한 피드백 메시지를 화면 하단에 표시합니다.
    - `Snackbar`

**예제 코드**:

```dart
dart코드 복사
import 'package:flutter/material.dart';

class MyAndroidApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('Android Style App'),
        ),
        body: Center(
          child: ElevatedButton(
            child: Text('Material Button'),
            onPressed: () {},
          ),
        ),
      ),
    );
  }
}

```

### 플랫폼별로 UI 컴포넌트 사용하기

**플랫폼 감지 및 조건부 UI**:

```dart
dart코드 복사
import 'dart:io';
import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';

class MyPlatformSpecificApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Platform.isIOS
          ? CupertinoPageScaffold(
              navigationBar: CupertinoNavigationBar(
                middle: Text('Cupertino App'),
              ),
              child: Center(
                child: CupertinoButton(
                  child: Text('Cupertino Button'),
                  onPressed: () {},
                ),
              ),
            )
          : Scaffold(
              appBar: AppBar(
                title: Text('Material App'),
              ),
              body: Center(
                child: ElevatedButton(
                  child: Text('Material Button'),
                  onPressed: () {},
                ),
              ),
            ),
    );
  }
}

void main() {
  runApp(MyPlatformSpecificApp());
}

```

### 결론

iOS와 Android는 각각 고유한 디자인 가이드라인을 가지고 있으며, 이를 따르는 컴포넌트를 사용하여 네이티브 사용자 경험을 제공할 수 있습니다. iOS는 주로 Cupertino 위젯을, Android는 Material 위젯을 사용합니다. Flutter는 이러한 플랫폼별 컴포넌트를 쉽게 사용할 수 있도록 도와줍니다.