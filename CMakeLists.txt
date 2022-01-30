cmake_minimum_required(VERSION 3.6.0)

if(WIN32)

  link_directories( win )

  include_directories( win/include )
  include_directories( FFmpeg )

  add_library( ffmpegDll
               SHARED
               cmdutils.c ffmpeg.c ffmpeg_filter.c ffmpeg_hw.c ffmpeg_opt.c /*ffplay.c*/ ffprobe.c )

  target_link_libraries( ffmpegDll
                         avcodec-59 avdevice-59 avfilter-8 avformat-59 avutil-57 swresample-4 swscale-6
                         -static-libgcc -static-libstdc++)

elseif(APPLE)

else(WIN32)

  link_directories( linux/lib )

  include_directories( FFmpeg )
  include_directories( linux/include )

  add_library( ffmpegDll
               SHARED
               cmdutils.c ffmpeg.c ffmpeg_filter.c ffmpeg_hw.c ffmpeg_opt.c /*ffplay.c*/ ffprobe.c )

  target_link_libraries( ffmpegDll
                         avcodec avdevice avfilter avformat avutil swresample swscale )

endif(WIN32)