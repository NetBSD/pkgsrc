$NetBSD: patch-Source_WebCore_plugins_gtk_PluginViewGtk.cpp,v 1.1 2012/04/19 21:08:04 joerg Exp $

- Changeset 97591: Fix clang build

--- Source/WebCore/plugins/gtk/PluginViewGtk.cpp.orig	2012-01-31 01:20:09.000000000 +0000
+++ Source/WebCore/plugins/gtk/PluginViewGtk.cpp
@@ -71,6 +71,7 @@
 #include <gtk/gtk.h>
 
 #if defined(XP_UNIX)
+#define String XtStringType
 #include "RefPtrCairo.h"
 #include "gtk2xtbin.h"
 #define Bool int // this got undefined somewhere
@@ -81,6 +82,7 @@
 #elif defined(GDK_WINDOWING_WIN32)
 #include "PluginMessageThrottlerWin.h"
 #include <gdk/gdkwin32.h>
+#undef String
 #endif
 
 using JSC::ExecState;
