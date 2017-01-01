$NetBSD: patch-mozilla_media_libstagefright_frameworks_av_media_libstagefright_foundation_AString.cpp,v 1.3 2017/01/01 16:14:08 ryoon Exp $

--- mozilla/media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp.orig	2016-12-14 02:07:21.000000000 +0000
+++ mozilla/media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp
@@ -23,6 +23,10 @@
 #include "ADebug.h"
 #include "AString.h"
 
+#if defined(__NetBSD__) && defined(tolower)
+#undef tolower
+#endif
+
 namespace stagefright {
 
 // static
