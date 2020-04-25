$NetBSD: patch-lxqt-config-input_keyboardlayoutconfig.h,v 1.1 2020/04/25 01:43:21 gutteridge Exp $

Adjust hard-coded path assumptions to pkgsrc norms.

--- lxqt-config-input/keyboardlayoutconfig.h.orig	2019-02-24 00:16:01.000000000 +0000
+++ lxqt-config-input/keyboardlayoutconfig.h
@@ -22,15 +22,7 @@
 #define KEYBOARDLAYOUTCONFIG_H
 
 #include <QtCore/QtGlobal>
-#ifdef Q_OS_LINUX
-#define XKBD_BASELIST_PATH "/usr/share/X11/xkb/rules/base.lst"
-#elif defined(Q_OS_FREEBSD)
-#define XKBD_BASELIST_PATH "/usr/local/share/X11/xkb/rules/base.lst"
-#elif defined(Q_OS_OPENBSD)
-#define XKBD_BASELIST_PATH "/usr/X11R6/share/X11/xkb/rules/base.lst"
-#else
-#define XKBD_BASELIST_PATH "/usr/local/share/X11/xkb/rules/base.lst"
-#endif
+#define XKBD_BASELIST_PATH "@X11BASE@/@XKBSUB@/X11/xkb/rules/base.lst"
 
 #include <QWidget>
 #include "keyboardlayoutinfo.h"
