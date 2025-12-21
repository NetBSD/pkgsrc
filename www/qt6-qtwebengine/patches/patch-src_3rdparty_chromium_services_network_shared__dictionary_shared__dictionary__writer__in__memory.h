$NetBSD: patch-src_3rdparty_chromium_services_network_shared__dictionary_shared__dictionary__writer__in__memory.h,v 1.1 2025/12/21 09:38:38 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/network/shared_dictionary/shared_dictionary_writer_in_memory.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/services/network/shared_dictionary/shared_dictionary_writer_in_memory.h
@@ -9,6 +9,8 @@
 #include <string>
 #include <vector>
 
+#include <vector>
+
 #include "base/component_export.h"
 #include "base/functional/callback.h"
 #include "crypto/secure_hash.h"
