$NetBSD: patch-components_os__crypt_async_browser_secret__portal__key__provider.cc,v 1.19 2026/05/10 15:29:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/os_crypt/async/browser/secret_portal_key_provider.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/os_crypt/async/browser/secret_portal_key_provider.cc
@@ -5,7 +5,9 @@
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
 
 #include <fcntl.h>
+#if BUILDFLAG(IS_LINUX)
 #include <linux/limits.h>
+#endif
 
 #include <array>
 #include <utility>
