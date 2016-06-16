$NetBSD: patch-media_libstagefright_frameworks_av_media_libstagefright_foundation_AString.cpp,v 1.3 2016/06/16 12:08:21 ryoon Exp $

* Fix build under NetBSD

--- media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp.orig	2016-05-12 17:13:17.000000000 +0000
+++ media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp
@@ -23,6 +23,10 @@
 #include "ADebug.h"
 #include "AString.h"
 
+#if defined(__NetBSD__) && defined(tolower)
+#undef tolower
+#endif
+
 namespace stagefright {
 
 // static
