$NetBSD: patch-src_startup__notification.c,v 1.1 2019/01/09 01:33:35 gutteridge Exp $

Crash fixer from Martin Husemann in PR pkg/53396:
sn_startup_sequence_get_last_active_time takes two long pointer
arguments, but xfce4-wm passes pointers to may-be-different types.

--- src/startup_notification.c.orig	2018-07-29 13:08:54.000000000 +0000
+++ src/startup_notification.c
@@ -128,6 +128,7 @@ sn_collect_timed_out_foreach (void *elem
     SnStartupSequence *sequence;
     time_t tv_sec;
     suseconds_t tv_usec;
+    long l_sec, l_usec;
     double elapsed;
 
     g_return_if_fail (data != NULL);
@@ -135,7 +136,8 @@ sn_collect_timed_out_foreach (void *elem
 
     sequence = element;
     ctod = (CollectTimedOutData *) data;
-    sn_startup_sequence_get_last_active_time (sequence, &tv_sec, &tv_usec);
+    sn_startup_sequence_get_last_active_time (sequence, &l_sec, &l_usec);
+    tv_sec = l_sec; tv_usec = l_sec;
 
     elapsed =
         ((((double) ctod->now.tv_sec - tv_sec) * G_USEC_PER_SEC +
