$NetBSD: patch-lxqt-config-input_keyboardlayoutconfig.h,v 1.2 2026/11/15 02:26:16 gutteridge Exp $

Adjust hard-coded path assumptions to pkgsrc norms.

--- lxqt-config-input/keyboardlayoutconfig.h.orig	2026-11-14 17:10:01.454761506 +0000
+++ lxqt-config-input/keyboardlayoutconfig.h
@@ -23,15 +23,7 @@
 
 #include <QtGlobal> // defines the Q_OS_* macros used below
 
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
