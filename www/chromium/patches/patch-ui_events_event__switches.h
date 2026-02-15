$NetBSD: patch-ui_events_event__switches.h,v 1.15 2026/02/15 09:04:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/events/event_switches.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/events/event_switches.h
@@ -13,7 +13,7 @@ namespace switches {
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 EVENTS_BASE_EXPORT extern const char kTouchSlopDistance[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
