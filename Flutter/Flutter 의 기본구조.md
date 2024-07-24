Flutter 의 기본 구조
---

```elixir
import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('Flutter Demo')),
        body: Center(child: Text('Hello, Flutter!')),
      ),
    );
  }
}
```