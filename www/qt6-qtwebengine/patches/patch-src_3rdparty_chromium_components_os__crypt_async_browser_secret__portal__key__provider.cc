$NetBSD: patch-src_3rdparty_chromium_components_os__crypt_async_browser_secret__portal__key__provider.cc,v 1.1 2025/12/21 09:38:23 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/os_crypt/async/browser/secret_portal_key_provider.cc.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/components/os_crypt/async/browser/secret_portal_key_provider.cc
@@ -5,7 +5,9 @@
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
 
 #include <fcntl.h>
+#if BUILDFLAG(IS_LINUX)
 #include <linux/limits.h>
+#endif
 
 #include <array>
 #include <utility>
