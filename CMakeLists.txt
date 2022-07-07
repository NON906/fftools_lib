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

  link_directories( mac/lib )

  include_directories( mac/include )
  include_directories( FFmpeg )

  add_library( ffmpegDll
               SHARED
               cmdutils.c ffmpeg.c ffmpeg_filter.c ffmpeg_hw.c ffmpeg_opt.c /*ffplay.c*/ ffprobe.c )

  target_link_libraries( ffmpegDll
                         avcodec avdevice avfilter avformat avutil swresample swscale )

else(WIN32)

  set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")

  link_directories( linux/lib )
  link_directories( /usr/lib )

  include_directories( FFmpeg )
  include_directories( linux/include )
  include_directories( /usr/include )

  add_library( ffmpegDll
               SHARED
               cmdutils.c ffmpeg.c ffmpeg_filter.c ffmpeg_hw.c ffmpeg_opt.c /*ffplay.c*/ ffprobe.c unitybuf2.c )

  target_link_libraries( ffmpegDll
                         avdevice avfilter avformat swresample swscale avcodec avutil
                         aom gif gmp gnutls gnutlsxx hogweed lilv-0 ltdl nettle ogg openh264 opus pcre pcrecpp pcreposix serd-0 sord-0 sratom-0
                         theora theoradec theoraenc vorbis vorbisenc vorbisfile vpx webp webpdecoder webpdemux webpmux yasm z 
                         sndio Xv dl mvec m c )

  find_package(ALSA REQUIRED)
  if (ALSA_FOUND)
      include_directories(${ALSA_INCLUDE_DIRS})
      target_link_libraries (ffmpegDll ${ALSA_LIBRARIES})
  endif(ALSA_FOUND)

  find_package(SDL2 REQUIRED)
  if (SDL2_FOUND)
      include_directories(${SDL2_INCLUDE_DIRS})
      target_link_libraries(ffmpegDll ${SDL2_LIBRARIES})
  endif(SDL2_FOUND)

endif(WIN32)