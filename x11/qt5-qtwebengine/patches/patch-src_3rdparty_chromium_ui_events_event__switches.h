$NetBSD: patch-src_3rdparty_chromium_ui_events_event__switches.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/events/event_switches.h.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/events/event_switches.h
@@ -13,7 +13,7 @@ namespace switches {
 
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
