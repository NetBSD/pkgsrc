$NetBSD: patch-common_xfdesktop-common.h,v 1.2 2017/06/18 22:48:17 youri Exp $

Use the blue background by default.

--- common/xfdesktop-common.h.orig	2017-04-20 15:38:05.000000000 +0000
+++ common/xfdesktop-common.h
@@ -35,7 +35,7 @@
 #include <stdarg.h>
 
 #define XFDESKTOP_CHANNEL        "xfce4-desktop"
-#define DEFAULT_BACKDROP         DATADIR "/backgrounds/xfce/xfce-teal.jpg"
+#define DEFAULT_BACKDROP         DATADIR "/backgrounds/xfce/xfce-blue.jpg"
 #define DEFAULT_ICON_FONT_SIZE   12
 #define DEFAULT_ICON_SIZE        48
 #define ITHEME_FLAGS             (GTK_ICON_LOOKUP_USE_BUILTIN)
