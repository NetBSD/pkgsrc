$NetBSD: patch-ui_ozone_common_features.cc,v 1.1 2025/02/06 09:58:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/common/features.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/common/features.cc
@@ -35,7 +35,7 @@ BASE_FEATURE(kWaylandSurfaceSubmissionIn
 // enabled.
 BASE_FEATURE(kWaylandFractionalScaleV1,
              "WaylandFractionalScaleV1",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -47,7 +47,7 @@ BASE_FEATURE(kWaylandFractionalScaleV1,
 // protocol is supported.
 BASE_FEATURE(kWaylandXdgToplevelDrag,
              "WaylandXdgToplevelDrag",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
