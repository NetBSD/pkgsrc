$NetBSD: patch-ui_ozone_platform_wayland_common_wayland__util.cc,v 1.1 2025/02/06 09:58:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -347,7 +347,7 @@ void TransformToWlArray(
 }
 
 base::TimeTicks EventMillisecondsToTimeTicks(uint32_t milliseconds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40287874): `milliseconds` comes from Weston that
   // uses timestamp from libinput, which is different from TimeTicks.
   // Use EventTimeForNow(), for now.
@@ -389,7 +389,7 @@ bool MaybeHandlePlatformEventForDrag(con
 }
 
 void RecordConnectionMetrics(wl_display* display) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   CHECK(display);
 
   // These values are logged to metrics so must not be changed.
