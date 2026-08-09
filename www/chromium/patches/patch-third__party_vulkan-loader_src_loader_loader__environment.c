$NetBSD: patch-third__party_vulkan-loader_src_loader_loader__environment.c,v 1.2 2026/08/09 06:31:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/vulkan-loader/src/loader/loader_environment.c.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/vulkan-loader/src/loader/loader_environment.c
@@ -49,7 +49,7 @@ char *loader_getenv(const char *name, co
 }
 
 char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
