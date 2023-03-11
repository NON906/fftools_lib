# Build Tool for FFmpeg for Unity (on Windows and Linux)

日本語版は[README_JP.md](README_JP.md)にあります。

## What are these?

Here is the code to build the plugin file used in [FFmpeg for Unity](https://assetstore.unity.com/packages/tools/video/ffmpeg-for-unity-199811).
It's attached to that asset, so you don't usually need it.

## How to build (Windows)

Both Windows and Linux (Ubuntu20.04 LTS) are required.  
On Windows, "MSYS2 MinGW" is required, so please install it in advance.

1. Run the following in [THIS repository](https://github.com/NON906/ffmpeg-windows-build-helpers) on Linux.

```
./cross_compile_ffmpeg.sh --build-ffmpeg-static=n --build-ffmpeg-shared=y --enable-gpl=n --ffmpeg-git-checkout-version=n5.1.1
```

2. Clone this repository on Windows.

3. Replace the files as below.
- ``win/*.lib``, ``win/*.dll`` -> 
File with the same name in ``sandbox/redist/ffmpeg-N-***-***-win64-shared.7z``
- ``win/include/config.h`` -> ``sandbox/win64/ffmpeg_git_lgpl_n5.1.1_shared/config.h``
- ``win/include/config_components.h`` -> ``sandbox/win64/ffmpeg_git_lgpl_n5.1.1_shared/config_components.h``

4. Edit ``win/include/config.h`` as follows.
- ``#define HAVE_COMMANDLINETOARGVW 1`` -> ``0``
- ``#define HAVE_GETPROCESSMEMORYINFO 1`` -> ``0``

5. Run the following in "MSYS2 MinGW".

```
mkdir build
cd build
cmake .. -G "MSYS Makefiles"
make
```

6. Replace the dll files from ``Assets/FfmpegUnity/Plugins/Windows/x64``  of the Unity project to ``libffmpegDll.dll`` and file with the same name in ``sandbox/redist/ffmpeg-N-***-***-win64-shared.7z``.
