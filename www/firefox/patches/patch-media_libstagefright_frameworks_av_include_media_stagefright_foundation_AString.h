$NetBSD: patch-media_libstagefright_frameworks_av_include_media_stagefright_foundation_AString.h,v 1.3 2015/12/18 23:51:16 ryoon Exp $

--- media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h.orig	2015-12-08 18:06:36.000000000 +0000
+++ media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h
@@ -18,6 +18,7 @@
 
 #define A_STRING_H_
 
+#include <cctype>
 #include <sys/types.h>
 
 namespace stagefright {
