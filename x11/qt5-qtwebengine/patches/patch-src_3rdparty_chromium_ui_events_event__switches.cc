$NetBSD: patch-src_3rdparty_chromium_ui_events_event__switches.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/events/event_switches.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/events/event_switches.cc
@@ -14,7 +14,7 @@ namespace switches {
 const char kCompensateForUnstablePinchZoom[] =
     "compensate-for-unstable-pinch-zoom";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
