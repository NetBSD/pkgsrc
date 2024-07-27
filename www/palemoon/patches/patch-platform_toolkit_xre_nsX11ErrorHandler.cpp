$NetBSD: patch-platform_toolkit_xre_nsX11ErrorHandler.cpp,v 1.1 2024/07/27 14:04:15 abs Exp $

Switch NS_RUNTIMEABORT to NS_WARNING to avoid crash seen on NetBSD with
"X_CopyArea: BadDrawable (invalid Pixmap or Window parameter);"

--- platform/toolkit/xre/nsX11ErrorHandler.cpp.orig	2024-07-10 08:54:53.000000000 +0000
+++ platform/toolkit/xre/nsX11ErrorHandler.cpp
@@ -131,7 +131,14 @@ X11Error(Display *display, XErrorEvent *
 #endif
 #endif
 
-  NS_RUNTIMEABORT(notes.get());
+  if (message.EqualsLiteral("62")) { // 62 == X_CopyArea
+    // Avoid NS_RUNTIMEABORT seen on NetBSD with
+    // "X_CopyArea: BadDrawable (invalid Pixmap or Window parameter);"
+    NS_WARNING(notes.get());
+  } else {
+    NS_RUNTIMEABORT(notes.get());
+  }
+
   return 0; // not reached
 }
 }
