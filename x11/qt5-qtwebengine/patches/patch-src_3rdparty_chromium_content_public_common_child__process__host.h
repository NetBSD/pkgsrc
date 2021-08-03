$NetBSD: patch-src_3rdparty_chromium_content_public_common_child__process__host.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/public/common/child_process_host.h.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/child_process_host.h
@@ -80,7 +80,7 @@ class CONTENT_EXPORT ChildProcessHost : 
     // No special behavior requested.
     CHILD_NORMAL = 0,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Indicates that the child execed after forking may be execced from
     // /proc/self/exe rather than using the "real" app path. This prevents
     // autoupdate from confusing us if it changes the file out from under us.
