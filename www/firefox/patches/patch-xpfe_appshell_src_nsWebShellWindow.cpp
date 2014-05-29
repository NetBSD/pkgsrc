$NetBSD: patch-xpfe_appshell_src_nsWebShellWindow.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- xpfe/appshell/src/nsWebShellWindow.cpp.orig	2014-05-06 22:56:40.000000000 +0000
+++ xpfe/appshell/src/nsWebShellWindow.cpp
@@ -71,7 +71,7 @@
 #include "mozilla/DebugOnly.h"
 #include "mozilla/MouseEvents.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "nsINativeMenuService.h"
 #define USE_NATIVE_MENUS
 #endif
