$NetBSD: patch-mozilla_modules_libpref_init_all.js,v 1.2 2017/01/01 16:14:08 ryoon Exp $

--- mozilla/modules/libpref/init/all.js.orig	2016-12-14 02:09:59.000000000 +0000
+++ mozilla/modules/libpref/init/all.js
@@ -4601,7 +4601,7 @@ pref("device.sensors.enabled", true);
 pref("device.storage.enabled", false);
 
 // Toggle which thread the HTML5 parser uses for stream parsing
-pref("html5.offmainthread", true);
+pref("html5.offmainthread", false);
 // Time in milliseconds between the time a network buffer is seen and the
 // timer firing when the timer hasn't fired previously in this parse in the
 // off-the-main-thread HTML5 parser.
