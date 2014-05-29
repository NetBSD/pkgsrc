$NetBSD: patch-dom_system_OSFileConstants.cpp,v 1.3 2014/05/29 15:38:19 pho Exp $

* NetBSD 5 does not support posix_spawn(3)

* Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/system/OSFileConstants.cpp.orig	2014-05-06 22:55:26.000000000 +0000
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
@@ -120,7 +124,7 @@ struct Paths {
   nsString winStartMenuProgsDir;
 #endif // defined(XP_WIN)
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   /**
    * The user's Library directory.
    */
@@ -130,7 +134,7 @@ struct Paths {
    * system.
    */
   nsString macLocalApplicationsDir;
-#endif // defined(XP_MACOSX)
+#endif // defined(MOZ_WIDGET_COCOA)
 
   Paths()
   {
@@ -147,10 +151,10 @@ struct Paths {
     winStartMenuProgsDir.SetIsVoid(true);
 #endif // defined(XP_WIN)
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     macUserLibDir.SetIsVoid(true);
     macLocalApplicationsDir.SetIsVoid(true);
-#endif // defined(XP_MACOSX)
+#endif // defined(MOZ_WIDGET_COCOA)
   }
 };
 
@@ -287,10 +291,10 @@ nsresult InitOSFileConstants()
   GetPathToSpecialDir(NS_WIN_PROGRAMS_DIR, paths->winStartMenuProgsDir);
 #endif // defined(XP_WIN)
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   GetPathToSpecialDir(NS_MAC_USER_LIB_DIR, paths->macUserLibDir);
   GetPathToSpecialDir(NS_OSX_LOCAL_APPLICATIONS_DIR, paths->macLocalApplicationsDir);
-#endif // defined(XP_MACOSX)
+#endif // defined(MOZ_WIDGET_COCOA)
 
   gPaths = paths.forget();
   return NS_OK;
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
@@ -836,7 +840,7 @@ bool DefineOSFileConstants(JSContext *cx
   // Note that we don't actually provide the full path, only the name of the
   // library, which is sufficient to link to the library using js-ctypes.
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   // Under MacOS X, for some reason, libxul is called simply "XUL",
   // and we need to provide the full path.
   nsAutoString libxul;
@@ -849,7 +853,7 @@ bool DefineOSFileConstants(JSContext *cx
   libxul.Append(NS_LITERAL_STRING(DLL_PREFIX));
   libxul.Append(NS_LITERAL_STRING("xul"));
   libxul.Append(NS_LITERAL_STRING(DLL_SUFFIX));
-#endif // defined(XP_MACOSX)
+#endif // defined(MOZ_WIDGET_COCOA)
 
   if (!SetStringProperty(cx, objPath, "libxul", libxul)) {
     return false;
@@ -897,7 +901,7 @@ bool DefineOSFileConstants(JSContext *cx
   }
 #endif // defined(XP_WIN)
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   if (!SetStringProperty(cx, objPath, "macUserLibDir", gPaths->macUserLibDir)) {
     return false;
   }
@@ -905,7 +909,7 @@ bool DefineOSFileConstants(JSContext *cx
   if (!SetStringProperty(cx, objPath, "macLocalApplicationsDir", gPaths->macLocalApplicationsDir)) {
     return false;
   }
-#endif // defined(XP_MACOSX)
+#endif // defined(MOZ_WIDGET_COCOA)
 
   // sqlite3 is linked from different places depending on the platform
   nsAutoString libsqlite3;
