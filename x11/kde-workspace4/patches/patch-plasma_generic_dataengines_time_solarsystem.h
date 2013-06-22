$NetBSD: patch-plasma_generic_dataengines_time_solarsystem.h,v 1.1 2013/06/22 22:39:10 jperkin Exp $

Avoid "sun" re-definition.

--- plasma/generic/dataengines/time/solarsystem.h.orig	2013-05-03 04:36:45.790116404 +0000
+++ plasma/generic/dataengines/time/solarsystem.h
@@ -22,6 +22,8 @@
 #include <QPair>
 #include <QPointF>
 
+#undef sun
+
 /*
  *   Mathematics, ideas, public domain code used for these classes from:
  *   http://www.stjarnhimlen.se/comp/tutorial.html
