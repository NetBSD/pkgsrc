$NetBSD: patch-mozilla_media_libstagefright_frameworks_av_include_media_stagefright_foundation_AString.h,v 1.3 2016/03/30 12:56:53 ryoon Exp $

--- mozilla/media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h.orig	2016-01-19 02:46:50.000000000 +0000
+++ mozilla/media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h
@@ -18,6 +18,7 @@
 
 #define A_STRING_H_
 
+#include <cctype>
 #include <sys/types.h>
 
 namespace stagefright {
