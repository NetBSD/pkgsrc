$NetBSD: patch-mozilla_dom_system_OSFileConstants.cpp,v 1.4 2014/06/22 08:54:39 ryoon Exp $

* NetBSD 5 does not support posix_spawn(3)

--- mozilla/dom/system/OSFileConstants.cpp.orig	2014-06-13 00:46:05.000000000 +0000
+++ mozilla/dom/system/OSFileConstants.cpp
@@ -9,22 +9,26 @@
 
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
 #include <linux/fadvise.h>
 #endif // defined(XP_LINUX)
 
-#if defined(XP_MACOSX)
+#if defined(XP_DARWIN)
 #include "copyfile.h"
-#endif // defined(XP_MACOSX)
+#endif // defined(XP_DARWIN)
 
 #if defined(XP_WIN)
 #include <windows.h>
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
