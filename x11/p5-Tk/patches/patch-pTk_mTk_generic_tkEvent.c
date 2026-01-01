$NetBSD: patch-pTk_mTk_generic_tkEvent.c,v 1.1 2026/01/01 09:36:08 mef Exp $

gcc-14.3.0 flags as following

tkEvent.c: In function 'TkCurrentTime':
tkEvent.c:1154:1: error: type of 'fallbackCurrent' defaults to 'int' [-Wimplicit-int]
 1154 | TkCurrentTime(dispPtr, fallbackCurrent)
      | ^~~~~~~~~~~~~
*** Error code 1

--- pTk/mTk/generic/tkEvent.c.orig	2013-11-16 08:50:03.000000000 +0900
+++ pTk/mTk/generic/tkEvent.c	2026-01-01 17:49:38.242507990 +0900
@@ -1153,6 +1153,7 @@ TkEventDeadWindow(winPtr)
 Time
 TkCurrentTime(dispPtr, fallbackCurrent)
     TkDisplay *dispPtr;		/* Display for which the time is desired. */
+    int fallbackCurrent;
 {
     register XEvent *eventPtr;
     ThreadSpecificData *tsdPtr = (ThreadSpecificData *)
