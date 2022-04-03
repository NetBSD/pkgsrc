$NetBSD: patch-Clock.c,v 1.1 2022/04/03 22:13:17 wiz Exp $

NetBSD does not provide sincos().

--- Clock.c.orig	2022-04-03 21:23:33.000000000 +0000
+++ Clock.c
@@ -1734,7 +1734,8 @@ erase_hands(ClockWidget w, struct tm *tm
 static void
 ClockAngle(double tick_units, double *sinp, double *cosp)
 {
-    sincos(tick_units * (M_PI / 180 / 10.0), sinp, cosp);
+    *sinp = sin(tick_units * (M_PI / 180 / 10.0));
+    *cosp = cos(tick_units * (M_PI / 180 / 10.0));
 }
 
 /*
