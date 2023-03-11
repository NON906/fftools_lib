# Build Tool for FFmpeg for Unity (on Windows and Linux)

## これは何？

[FFmpeg for Unity](https://assetstore.unity.com/packages/tools/video/ffmpeg-for-unity-199811)で使用するプラグインファイルをビルドするためのコードです。  
なお、そのアセットに標準に付いているので、通常は必要ありません。

## 使い方(Windows)

WindowsとLinux(Ubuntu20.04 LTS)の両方が必要になります。  
Windows側では「MSYS2 MinGW」が必要になるので、事前にインストールしてください。

1. Linuxで[こちら](https://github.com/NON906/ffmpeg-windows-build-helpers)のリポジトリで以下を実行してください

```
./cross_compile_ffmpeg.sh --build-ffmpeg-static=n --build-ffmpeg-shared=y --enable-gpl=n --ffmpeg-git-checkout-version=n5.1.1
```

2. Windowsでこのリポジトリをクローンしてください

3. クローンしたファイルを以下のように置き換えてください
- ``win/*.lib``, ``win/*.dll`` -> ``sandbox/redist/ffmpeg-N-***-***-win64-shared.7z``にある同名ファイル
- ``win/include/config.h`` -> ``sandbox/win64/ffmpeg_git_lgpl_n5.1.1_shared/config.h``
- ``win/include/config_components.h`` -> ``sandbox/win64/ffmpeg_git_lgpl_n5.1.1_shared/config_components.h``

4. ``win/include/config.h``を以下のように編集してください
- ``#define HAVE_COMMANDLINETOARGVW 1`` -> ``0``
- ``#define HAVE_GETPROCESSMEMORYINFO 1`` -> ``0``

5. 「MSYS2 MinGW」で以下を実行してください

```
mkdir build
cd build
cmake .. -G "MSYS Makefiles"
make
```

6. 生成した``libffmpegDll.dll``および``sandbox/redist/ffmpeg-N-***-***-win64-shared.7z``にあるdllファイルをUnityプロジェクトの``Assets/FfmpegUnity/Plugins/Windows/x64``にあるものと置き換えます
