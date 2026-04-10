$NetBSD: patch-content_browser_scheduler_responsiveness_native__event__observer.cc,v 1.17 2026/04/10 17:31:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/scheduler/responsiveness/native_event_observer.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ content/browser/scheduler/responsiveness/native_event_observer.cc
@@ -15,7 +15,7 @@
 
 #include "ui/events/platform/platform_event_source.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/events/platform/platform_event_source.h"
 #endif
 
@@ -38,7 +38,7 @@ NativeEventObserver::~NativeEventObserve
   DeregisterObserver();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void NativeEventObserver::RegisterObserver() {
   CHECK(ui::PlatformEventSource::GetInstance());
   ui::PlatformEventSource::GetInstance()->AddPlatformEventObserver(this);
