Blank 프로젝트 생성 및 실행 정리
===

### 1. 프로젝트 생성 :
특정 폴더의 터미널에서 아래 명령어를 실행하면, 해당 폴더에 **하위 폴더**가 생성된다.

```bash
npx create-expo-app StickerSmash --template blank
```

### 2. 하위 폴더로 이동 :
프로젝트가 생성되면 **`StickerSmash`** 라는 폴더가 생기고, 모든 파일이 그 안에 저장된다.

프로젝트를 실행하려면 **반드시** 하위 폴더로 이동해야 한다.

```bash
cd StickerSmash
```

### 3. 프로젝트 실행 :
하위 폴더로 이동한 후, 다음 명령어로  Metro Bundler를 시작할 수 있다.

```bash
npx expo start
```

### 4. 의존성 설치(필요시) :
`npx create-expo-app` 명령어로 프로젝트를 생성할 때, 필요한 모든 의존성이 자동으로 설치되낟.

만약 설치가 누락되었거나 의존성 문제가 발생한다면, 하위 폴더로 이동한 후 `npm install` 을 실행해 줘라:
```bash
npm install  # 의존성 문제가 있을 때만
```

**Tip :** `cd StickerSmash` 명령어를 잊지 않고 입력해야 올바른 위치에서 프로젝트를 실행할 수 있다.