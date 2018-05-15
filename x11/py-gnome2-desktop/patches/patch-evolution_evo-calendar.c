$NetBSD: patch-evolution_evo-calendar.c,v 1.1 2018/05/15 10:35:02 jperkin Exp $

Build against current libical API.

--- evolution/evo-calendar.c.orig	2010-02-09 12:46:26.000000000 +0000
+++ evolution/evo-calendar.c
@@ -239,7 +239,7 @@ evo_cal_component_set_modified(ECalCompo
 {
     struct icaltimetype tt;
 
-    tt = icaltime_from_timet(seconds, TRUE);
+    tt = icaltime_from_timet_with_zone(seconds, TRUE, NULL);
     e_cal_component_set_last_modified(obj, &tt);
 }
 
