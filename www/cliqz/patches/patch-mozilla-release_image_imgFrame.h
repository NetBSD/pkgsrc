$NetBSD: patch-mozilla-release_image_imgFrame.h,v 1.1 2020/04/18 07:58:36 fox Exp $

* For std::function

Taken from www/firefox

--- mozilla-release/image/imgFrame.h.orig	2020-04-03 19:34:41.000000000 +0000
+++ mozilla-release/image/imgFrame.h
@@ -8,6 +8,7 @@
 #define mozilla_image_imgFrame_h
 
 #include <utility>
+#include <functional>
 
 #include "AnimationParams.h"
 #include "MainThreadUtils.h"
