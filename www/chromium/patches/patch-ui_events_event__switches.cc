$NetBSD: patch-ui_events_event__switches.cc,v 1.1 2025/02/06 09:58:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/events/event_switches.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/events/event_switches.cc
@@ -21,7 +21,7 @@ const char kCompensateForUnstablePinchZo
 // value is a floating point number that is interpreted as a distance in pixels.
 const char kTouchSlopDistance[] = "touch-slop-distance";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
