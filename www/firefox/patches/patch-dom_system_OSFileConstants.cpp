$NetBSD: patch-dom_system_OSFileConstants.cpp,v 1.5 2014/06/11 00:40:59 ryoon Exp $

* NetBSD 5 does not support posix_spawn(3)

* Replace XP_MACOSX with XP_DARWIN as the former is not defined when
  the toolkit is not cocoa.

--- dom/system/OSFileConstants.cpp.orig	2014-05-29 23:30:40.000000000 +0000
+++ dom/system/OSFileConstants.cpp
@@ -9,6 +9,10 @@
 
 #include "prsystem.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #if defined(XP_UNIX)
 #include "unistd.h"
 #include "dirent.h"
@@ -26,9 +30,9 @@
 #include <linux/fadvise.h>
 #endif // defined(XP_LINUX)
 
-#if defined(XP_MACOSX)
+#if defined(XP_DARWIN)
 #include "copyfile.h"
-#endif // defined(XP_MACOSX)
+#endif // defined(XP_DARWIN)
 
 #if defined(XP_WIN)
 #include <windows.h>
@@ -533,10 +537,10 @@ static const dom::ConstantSpec gLibcProp
   // The size of |fsblkcnt_t|.
   { "OSFILE_SIZEOF_FSBLKCNT_T", INT_TO_JSVAL(sizeof (fsblkcnt_t)) },
 
-#if !defined(ANDROID)
+#if !defined(ANDROID) && (defined(__NetBSD_) && (__NetBSD_Version__ < 600000000))
   // The size of |posix_spawn_file_actions_t|.
   { "OSFILE_SIZEOF_POSIX_SPAWN_FILE_ACTIONS_T", INT_TO_JSVAL(sizeof (posix_spawn_file_actions_t)) },
-#endif // !defined(ANDROID)
+#endif // !defined(ANDROID) && NetBSD 5.*
 
   // Defining |dirent|.
   // Size
@@ -596,7 +600,7 @@ static const dom::ConstantSpec gLibcProp
 
   { "OSFILE_SIZEOF_STATVFS", INT_TO_JSVAL(sizeof (struct statvfs)) },
 
-  { "OSFILE_OFFSETOF_STATVFS_F_BSIZE", INT_TO_JSVAL(offsetof (struct statvfs, f_bsize)) },
+  { "OSFILE_OFFSETOF_STATVFS_F_FRSIZE", INT_TO_JSVAL(offsetof (struct statvfs, f_frsize)) },
   { "OSFILE_OFFSETOF_STATVFS_F_BAVAIL", INT_TO_JSVAL(offsetof (struct statvfs, f_bavail)) },
 
 #endif // defined(XP_UNIX)
