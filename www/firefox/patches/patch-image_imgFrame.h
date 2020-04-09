$NetBSD: patch-image_imgFrame.h,v 1.1 2020/04/09 14:01:26 ryoon Exp $

* For std::function

--- image/imgFrame.h.orig	2020-04-03 19:34:41.000000000 +0000
+++ image/imgFrame.h
@@ -8,6 +8,7 @@
 #define mozilla_image_imgFrame_h
 
 #include <utility>
+#include <functional>
 
 #include "AnimationParams.h"
 #include "MainThreadUtils.h"
