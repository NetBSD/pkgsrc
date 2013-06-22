$NetBSD: patch-plasma_generic_dataengines_time_timesource.h,v 1.1 2013/06/22 22:39:10 jperkin Exp $

Avoid "sun" re-definition.

--- plasma/generic/dataengines/time/timesource.h.orig	2013-05-03 04:36:45.790116404 +0000
+++ plasma/generic/dataengines/time/timesource.h
@@ -24,6 +24,8 @@
 
 #include <Plasma/DataContainer>
 
+#undef sun
+
 class Sun;
 class Moon;
 
