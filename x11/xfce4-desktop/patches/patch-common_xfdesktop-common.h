$NetBSD: patch-common_xfdesktop-common.h,v 1.4 2019/01/18 14:34:48 youri Exp $

Use the blue background by default.

--- common/xfdesktop-common.h.orig	2018-06-07 19:37:55.000000000 +0000
+++ common/xfdesktop-common.h
@@ -35,7 +35,7 @@
 #include <stdarg.h>
 
 #define XFDESKTOP_CHANNEL        "xfce4-desktop"
-#define DEFAULT_BACKDROP         DATADIR "/backgrounds/xfce/xfce-teal.jpg"
+#define DEFAULT_BACKDROP         DATADIR "/backgrounds/xfce/xfce-blue.jpg"
 #define DEFAULT_ICON_FONT_SIZE   12
 #define DEFAULT_ICON_SIZE        48
 #define ITHEME_FLAGS             (GTK_ICON_LOOKUP_USE_BUILTIN)
