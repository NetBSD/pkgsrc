$NetBSD: patch-mozilla_media_libstagefright_frameworks_av_include_media_stagefright_foundation_AString.h,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h.orig	2014-10-14 06:36:30.000000000 +0000
+++ mozilla/media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h
@@ -75,6 +75,9 @@ struct AString {
     bool startsWith(const char *prefix) const;
     bool endsWith(const char *suffix) const;
 
+#if defined(__NetBSD__) && defined(tolower)
+#undef tolower
+#endif
     void tolower();
 
 private:
