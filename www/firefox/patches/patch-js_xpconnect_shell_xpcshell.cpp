$NetBSD: patch-js_xpconnect_shell_xpcshell.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- js/xpconnect/shell/xpcshell.cpp.orig	2014-05-06 22:55:51.000000000 +0000
+++ js/xpconnect/shell/xpcshell.cpp
@@ -12,7 +12,7 @@
 #include "mozilla/WindowsDllBlocklist.h"
 
 #include "nsXULAppAPI.h"
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "xpcshellMacUtils.h"
 #endif
 #ifdef XP_WIN
@@ -28,7 +28,7 @@
 int
 main(int argc, char** argv, char** envp)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     InitAutoreleasePool();
 #endif
 
@@ -42,7 +42,7 @@ main(int argc, char** argv, char** envp)
 
     int result = XRE_XPCShellMain(argc, argv, envp);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     FinishAutoreleasePool();
 #endif
 
