$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_modules_include_module__common__types__public.h,v 1.1 2024/06/02 11:34:20 markd Exp $

ICU75 fix - from ArchLinux

--- src/3rdparty/chromium/third_party/webrtc/modules/include/module_common_types_public.h.orig	2023-05-05 08:39:51.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/modules/include/module_common_types_public.h
@@ -12,6 +12,7 @@
 #define MODULES_INCLUDE_MODULE_COMMON_TYPES_PUBLIC_H_
 
 #include <limits>
+#include <cstdint>
 
 #include "absl/types/optional.h"
 
