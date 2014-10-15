$NetBSD: patch-media_libstagefright_frameworks_av_media_libstagefright_foundation_AString.cpp,v 1.1 2014/10/15 13:43:32 ryoon Exp $

--- media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp.orig	2014-10-11 09:06:39.000000000 +0000
+++ media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp
@@ -23,6 +23,13 @@
 #include "ADebug.h"
 #include "AString.h"
 
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 900506
+#  undef tolower
+# endif
+#endif
+
 namespace stagefright {
 
 // static
