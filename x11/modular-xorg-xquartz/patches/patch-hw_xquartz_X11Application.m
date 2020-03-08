$NetBSD: patch-hw_xquartz_X11Application.m,v 1.1 2020/03/08 01:28:14 tnn Exp $

X11Application.m:404:17: error: use of undeclared identifier '_appFlags'

--- hw/xquartz/X11Application.m.orig	2015-05-21 14:23:54.000000000 +0000
+++ hw/xquartz/X11Application.m
@@ -401,7 +401,9 @@ message_kit_thread(SEL selector, NSObjec
                 /* FIXME: This is a hack to avoid passing the event to AppKit which
                  *        would result in it raising one of its windows.
                  */
+#if 0
                 _appFlags._active = YES;
+#endif
 
                 [self set_front_process:nil];
 
