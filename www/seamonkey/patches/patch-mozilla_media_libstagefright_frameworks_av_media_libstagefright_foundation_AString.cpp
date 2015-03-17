$NetBSD: patch-mozilla_media_libstagefright_frameworks_av_media_libstagefright_foundation_AString.cpp,v 1.2 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp.orig	2015-03-09 05:34:24.000000000 +0000
+++ mozilla/media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp
@@ -23,6 +23,17 @@
 #include "ADebug.h"
 #include "AString.h"
 
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 900506
+#  undef tolower
+# endif
+#endif
+
+#if defined(__NetBSD__) && defined(tolower)
+#undef tolower
+#endif
+
 namespace stagefright {
 
 // static
