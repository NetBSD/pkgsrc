$NetBSD: patch-ui_events_event.cc,v 1.14 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/events/event.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/events/event.cc
@@ -375,7 +375,7 @@ std::string LocatedEvent::ToString() con
 MouseEvent::MouseEvent(const PlatformEvent& native_event)
     : LocatedEvent(native_event),
       changed_button_flags_(GetChangedMouseButtonFlagsFromNative(native_event)),
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       movement_(GetMouseMovementFromNative(native_event)),
 #endif
       pointer_details_(GetMousePointerDetailsFromNative(native_event)) {
@@ -631,7 +631,7 @@ std::unique_ptr<Event> MouseWheelEvent::
   return std::make_unique<MouseWheelEvent>(*this);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This value matches Windows, Fuchsia WHEEL_DELTA, and (roughly) Firefox on
 // Linux.
 // static
@@ -894,7 +894,7 @@ void KeyEvent::InitializeNative() {
     SetFlags(flags() | EF_IS_REPEAT);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   NormalizeFlags();
 #elif BUILDFLAG(IS_WIN)
   // Only Windows has native character events.
