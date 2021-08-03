$NetBSD: patch-src_3rdparty_chromium_extensions_common_image__util.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/extensions/common/image_util.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/extensions/common/image_util.cc
@@ -20,7 +20,7 @@
 #include "base/strings/stringprintf.h"
 #include "base/time/time.h"
 #include "base/timer/elapsed_timer.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkCanvas.h"
 #include "third_party/skia/include/core/SkColor.h"
