$NetBSD: patch-third__party_dawn_third__party_renderdoc_renderdoc_api_app_renderdoc__app.h,v 1.18 2026/11/08 15:39:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/third_party/renderdoc/renderdoc/api/app/renderdoc_app.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/dawn/third_party/renderdoc/renderdoc/api/app/renderdoc_app.h
@@ -35,7 +35,7 @@
 
 #if defined(WIN32) || defined(__WIN32__) || defined(_WIN32) || defined(_MSC_VER)
 #define RENDERDOC_CC __cdecl
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__sun__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__sun__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #define RENDERDOC_CC
 #elif defined(__APPLE__)
 #define RENDERDOC_CC
