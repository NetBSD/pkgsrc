$NetBSD: patch-src_3rdparty_chromium_content_public_common_child__process__host.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/public/common/child_process_host.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/child_process_host.h
@@ -81,7 +81,7 @@ class CONTENT_EXPORT ChildProcessHost : 
     // No special behavior requested.
     CHILD_NORMAL = 0,
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // Indicates that the child execed after forking may be execced from
     // /proc/self/exe rather than using the "real" app path. This prevents
     // autoupdate from confusing us if it changes the file out from under us.
