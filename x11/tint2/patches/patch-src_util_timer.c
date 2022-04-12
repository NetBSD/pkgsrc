$NetBSD: patch-src_util_timer.c,v 1.1 2022/04/12 13:45:58 tnn Exp $

for bzero(3) on SunOS

--- src/util/timer.c.orig	2021-12-04 09:46:45.000000000 +0000
+++ src/util/timer.c
@@ -20,6 +20,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <strings.h>
 
 #include "colors.h"
 #include "timer.h"
@@ -52,7 +53,7 @@ void init_timer(Timer *timer, const char
     if (debug_timers)
         fprintf(stderr, "tint2: timers: %s: %s, %p\n", __FUNCTION__, name, (void *)timer);
     bzero(timer, sizeof(*timer));
-    strncpy(timer->name_, name, sizeof(timer->name_));
+    strncpy(timer->name_, name, sizeof(timer->name_) - 1);
     if (!g_list_find(timers, timer)) {
         timers = g_list_append(timers, timer);
     }
