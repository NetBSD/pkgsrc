$NetBSD: patch-mozilla_dom_system_OSFileConstants.cpp,v 1.3 2014/03/30 04:13:17 ryoon Exp $

* NetBSD 5 does not support posix_spawn(3)

--- mozilla/dom/system/OSFileConstants.cpp.orig	2014-03-15 05:19:14.000000000 +0000
+++ mozilla/dom/system/OSFileConstants.cpp
@@ -9,11 +9,15 @@
 
 #include "prsystem.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #if defined(XP_UNIX)
 #include "unistd.h"
 #include "dirent.h"
 #include "sys/stat.h"
-#if !defined(ANDROID)
+#if !defined(ANDROID) && (defined(__NetBSD_) && (__NetBSD_Version__ < 600000000))
 #include <spawn.h>
 #endif // !defined(ANDROID)
 #endif // defined(XP_UNIX)
@@ -508,7 +512,7 @@ static const dom::ConstantSpec gLibcProp
   // The size of |time_t|.
   { "OSFILE_SIZEOF_TIME_T", INT_TO_JSVAL(sizeof (time_t)) },
 
-#if !defined(ANDROID)
+#if !defined(ANDROID) && (defined(__NetBSD_) && (__NetBSD_Version__ < 600000000))
   // The size of |posix_spawn_file_actions_t|.
   { "OSFILE_SIZEOF_POSIX_SPAWN_FILE_ACTIONS_T", INT_TO_JSVAL(sizeof (posix_spawn_file_actions_t)) },
 #endif // !defined(ANDROID)
