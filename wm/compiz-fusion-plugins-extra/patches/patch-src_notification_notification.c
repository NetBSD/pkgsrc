$NetBSD: patch-src_notification_notification.c,v 1.1 2013/06/30 22:13:40 rodent Exp $

Needs HAVE_LIBNOTIFY_0_6_1 defined.

--- src/notification/notification.c.orig	2011-04-21 11:51:08.000000000 +0000
+++ src/notification/notification.c
@@ -27,6 +27,8 @@
 #include <unistd.h>
 #include <compiz-core.h>
 
+#include "config.h"
+
 #define NOTIFY_DISPLAY_OPTION_TIMEOUT   0
 #define NOTIFY_DISPLAY_OPTION_MAX_LEVEL 1
 #define NOTIFY_DISPLAY_OPTION_NUM       2
