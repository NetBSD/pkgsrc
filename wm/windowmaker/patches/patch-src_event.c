$NetBSD: patch-src_event.c,v 1.1 2015/02/02 11:30:37 jperkin Exp $

SunOS NAME_MAX compatibility.

--- src/event.c.orig	2014-08-30 12:29:09.000000000 +0000
+++ src/event.c
@@ -279,6 +279,9 @@ void DispatchEvent(XEvent * event)
 }
 
 #ifdef HAVE_INOTIFY
+#ifndef NAME_MAX
+#define NAME_MAX FILENAME_MAX
+#endif
 /*
  *----------------------------------------------------------------------
  * handle_inotify_events-
