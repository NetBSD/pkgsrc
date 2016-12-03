$NetBSD: patch-media_libsoundtouch_src_soundtouch__perms.h,v 1.1 2016/12/03 09:58:26 ryoon Exp $

--- media/libsoundtouch/src/soundtouch_perms.h.orig	2016-05-12 17:13:16.000000000 +0000
+++ media/libsoundtouch/src/soundtouch_perms.h
@@ -12,7 +12,9 @@
 
 #pragma GCC visibility push(default)
 #include "SoundTouch.h"
+#ifndef MOZ_SYSTEM_SOUNDTOUCH
 #include "SoundTouchFactory.h"
+#endif
 #pragma GCC visibility pop
 
 #endif // MOZILLA_SOUNDTOUCH_PERMS_H
