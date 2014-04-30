$NetBSD: patch-dom_system_OSFileConstants.cpp,v 1.2 2014/04/30 15:07:18 ryoon Exp $

* NetBSD 5 does not support posix_spawn(3)

--- dom/system/OSFileConstants.cpp.orig	2014-04-18 02:02:50.000000000 +0000
+++ dom/system/OSFileConstants.cpp
@@ -9,13 +9,17 @@
 
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
-#endif // !defined(ANDROID)
+#endif // !defined(ANDROID) && NetBSD 5.*
 #endif // defined(XP_UNIX)
 
 #if defined(XP_LINUX)
@@ -526,10 +530,10 @@ static const dom::ConstantSpec gLibcProp
   // The size of |time_t|.
   { "OSFILE_SIZEOF_TIME_T", INT_TO_JSVAL(sizeof (time_t)) },
 
-#if !defined(ANDROID)
+#if !defined(ANDROID) && (defined(__NetBSD_) && (__NetBSD_Version__ < 600000000))
   // The size of |posix_spawn_file_actions_t|.
   { "OSFILE_SIZEOF_POSIX_SPAWN_FILE_ACTIONS_T", INT_TO_JSVAL(sizeof (posix_spawn_file_actions_t)) },
-#endif // !defined(ANDROID)
+#endif // !defined(ANDROID) && NetBSD 5.*
 
   // Defining |dirent|.
   // Size
