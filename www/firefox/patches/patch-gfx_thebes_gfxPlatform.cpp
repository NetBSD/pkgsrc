$NetBSD: patch-gfx_thebes_gfxPlatform.cpp,v 1.5 2020/01/15 10:50:38 ryoon Exp $

* Hardware acceleration for up to 4K UHD.

--- gfx/thebes/gfxPlatform.cpp.orig	2020-01-08 01:23:32.000000000 +0000
+++ gfx/thebes/gfxPlatform.cpp
@@ -2935,7 +2935,7 @@ static void UpdateWRQualificationForInte
   const int64_t kMaxPixels = 1920 * 1200;  // WUXGA
 #    else
   // Allow up to 4k on Linux
-  const int64_t kMaxPixels = 3440 * 1440;  // UWQHD
+  const int64_t kMaxPixels = 3840 * 2160;  // 4K UHD
 #    endif
   if (aScreenPixels > kMaxPixels) {
     aFeature.Disable(
