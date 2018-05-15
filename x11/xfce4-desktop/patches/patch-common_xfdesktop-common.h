$NetBSD: patch-common_xfdesktop-common.h,v 1.3 2018/05/15 22:33:23 youri Exp $

Use the blue background by default.

--- common/xfdesktop-common.h.orig	2017-06-26 13:48:02.000000000 +0000
+++ common/xfdesktop-common.h
@@ -35,7 +35,7 @@
 #include <stdarg.h>
 
 #define XFDESKTOP_CHANNEL        "xfce4-desktop"
-#define DEFAULT_BACKDROP         DATADIR "/backgrounds/xfce/xfce-teal.jpg"
+#define DEFAULT_BACKDROP         DATADIR "/backgrounds/xfce/xfce-blue.jpg"
 #define DEFAULT_ICON_FONT_SIZE   12
 #define DEFAULT_ICON_SIZE        48
 #define ITHEME_FLAGS             (GTK_ICON_LOOKUP_USE_BUILTIN \
