$NetBSD: patch-common_xfdesktop-common.h,v 1.5 2019/08/17 19:40:25 gutteridge Exp $

Use the blue background by default.

--- common/xfdesktop-common.h.orig	2019-08-11 20:21:03.000000000 +0000
+++ common/xfdesktop-common.h
@@ -35,7 +35,7 @@
 #include <stdarg.h>
 
 #define XFDESKTOP_CHANNEL        "xfce4-desktop"
-#define DEFAULT_BACKDROP         DATADIR "/backgrounds/xfce/xfce-stripes.png"
+#define DEFAULT_BACKDROP         DATADIR "/backgrounds/xfce/xfce-blue.png"
 #define DEFAULT_ICON_FONT_SIZE   12
 #define DEFAULT_ICON_SIZE        48
 #define ITHEME_FLAGS             (GTK_ICON_LOOKUP_USE_BUILTIN)
