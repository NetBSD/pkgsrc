$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_common__video_h264_pps__parser.h,v 1.1 2024/06/02 11:34:20 markd Exp $

ICU75 fix - from ArchLinux

--- src/3rdparty/chromium/third_party/webrtc/common_video/h264/pps_parser.h.orig	2023-05-05 08:39:51.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/common_video/h264/pps_parser.h
@@ -12,6 +12,7 @@
 #define COMMON_VIDEO_H264_PPS_PARSER_H_
 
 #include "absl/types/optional.h"
+#include <cstdint>
 
 namespace rtc {
 class BitBuffer;
