$NetBSD: patch-widget_gtk_nsAppShell.cpp,v 1.1 2026/10/08 20:57:15 ryoon Exp $

* Fix build without dbus option.

--- widget/gtk/nsAppShell.cpp.orig	2026-09-29 15:04:11.531003992 +0000
+++ widget/gtk/nsAppShell.cpp
@@ -30,8 +30,8 @@
 #ifdef MOZ_ENABLE_DBUS
 #  include <gio/gio.h>
 
-#  include "WidgetUtilsGtk.h"
 #endif
+#include "WidgetUtilsGtk.h"
 #include "HeadlessScreenHelper.h"
 #include "ScreenHelperGTK.h"
 #include "WakeLockListener.h"
