$NetBSD: patch-net_dns_dns__reloader.cc,v 1.1 2025/02/06 09:58:15 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/dns_reloader.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ net/dns/dns_reloader.cc
@@ -10,6 +10,7 @@
 // - there's not guarantee it exists at all. :(
 #if BUILDFLAG(IS_POSIX)
 
+#include <netinet/in.h>
 #include <resolv.h>
 
 // This code only works on systems where the C library provides res_ninit(3) and
@@ -31,7 +32,7 @@
 // an old musl bug that was fixed by musl c8fdcfe5, but Fuchsia's SDK doesn't
 // have that change.
 #if defined(__RES) && __RES >= 19991006 && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_FUCHSIA)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_NETBSD)
 // We define this so we don't need to restate the complex condition here twice
 // below - it would be easy for the copies below to get out of sync.
 #define USE_RES_NINIT
