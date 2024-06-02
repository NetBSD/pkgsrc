$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_modules_audio__processing_aec3_reverb__model__estimator.h,v 1.1 2024/06/02 11:34:20 markd Exp $

ICU75 fix - from ArchLinux

--- src/3rdparty/chromium/third_party/webrtc/modules/audio_processing/aec3/reverb_model_estimator.h.orig	2023-05-05 08:39:51.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/modules/audio_processing/aec3/reverb_model_estimator.h
@@ -13,6 +13,7 @@
 
 #include <array>
 #include <vector>
+#include <memory>
 
 #include "absl/types/optional.h"
 #include "api/array_view.h"
