$NetBSD: patch-platform_media_ffvpx_config.h,v 1.1 2025/11/23 10:59:28 nia Exp $

Add pregenerated config for sparc64.
This has been accepted upstream.

--- platform/media/ffvpx/config.h.orig	2025-10-15 17:46:52.000000000 +0000
+++ platform/media/ffvpx/config.h
@@ -41,6 +41,8 @@
 #include "config_unix_aarch64.h"
 #elif defined(__powerpc__)
 #include "config_unix_ppc.h"
+#elif defined(__sparcv9) || defined(__sparcv9__)
+#include "config_unix_sparc64.h"
 #else
 #if defined(HAVE_64BIT_BUILD)
 #include "config_unix64.h"
